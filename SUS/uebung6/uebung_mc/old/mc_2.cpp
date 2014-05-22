/* Simple Metropolis Monte Carlo program 
 * written May 2003 by Emil Mittag, Zentrum fuer Bioinformatik,
 * Universitaet Hamburg, Hamburg Germany
 * This code or parts of this code may not be used for
 * commercial purposes without written permission from the author.
 */ 

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <iostream>

#define PI 3.141592654
#define NUMA 1000

void mc_io (void);
void mc_init (void);
void mc_main (void);
void calc_interact (void);
void calc_i (int, double[]);
void adjust (void);
void compute_averages (void);
void final_avg (void);
void inst_avg (void);
void initial_config (void);
void initial_output (void);
void initial_values (void);
void rescale (void);

typedef struct {
    double r[3];
} atoms;    


//----------Structure to contain instantaneous and time-averaged values--------
typedef struct {
    double PE, virial;
    double u, w;
    double VN, pres, inst_VN, inst_pres, av_VN, av_pres;
    int av;
} results;


//-------------Structure which will contain run parameters----------
typedef struct {
    double rcut, rcutsq; // cutoff value; square of cutoff
    double sigma;
    double volume;//the volume of the system
    double density;//the density of the system
    double drmax;//maximum displacement
    double sr3, sr9;//used for potential calculation
    double cube;//size of the cell
    double T, beta;//temperature and Boltzmann factor
    int change; // number of changes accepted
    int np; // number of particles
    int try1; // number of attempted changes
    int step; // number of steps before checking to see if
    int max_it; // the maximum number of iterations for the simulation
} LJ;


// global variables
LJ Simdat;
atoms Part[NUMA];
results Res;
atoms Temp;
int Avg=0;// AVG = 1, instantaneous values; =0 time average

ofstream write_out("mc2.res",ios::out);

//----------Main routine is here----------
int main (void)
{

    mc_io(); // read in required user-defined values

    mc_init(); // initialisation routines

    write_out<<"step\tenergy\t\tpressure"<<endl;

    initial_values();

    initial_config(); // setup the lattice

    calc_interact(); // calculate and store initial potential energy
    
    initial_output();

    cout<<"\nSteps\tAvg PE\t\tAvg Pres"<<endl;

    mc_main(); // main mc routine

    final_avg();

    write_out.close();

    return 0;
}


//----------Outputs the conditions before simulation runs----------
void initial_output (void)
{
    cout<<"V: "<<(Res.PE/(double)Simdat.np)<<"\tW: "<<
	(Res.virial/(double)Simdat.np)
	<<"\tP: "<<(Simdat.density*Simdat.T+(Res.virial/Simdat.volume))<<endl;
}


//----------Output some initial values----------
void initial_values (void)
{

    cout<<"Box: "<<Simdat.cube<<"\tVolume: "<<Simdat.volume<<endl;
}
	

//----------Output the time average----------
void final_avg (void)
{
    static int a;

    write_out.setf(ios::fixed);
    write_out.precision(8);
    write_out<<(Res.av/Simdat.np)<<"\t"<<(Res.av_VN/(double)Res.av)<<
	"\t"<<(Res.av_pres/(double)Res.av)<<endl;
}


//----------Output the instantaneous values for PE and pressure----------
void inst_avg (int i) 
{
    static int count;

    write_out.setf(ios::fixed);
    write_out.precision(8);
    write_out<<i<<"\t"<<Res.inst_VN<<"\t"<<
	Res.inst_pres<<endl;
}


//----------The main Metropolis MC routine----------
void mc_main(void) 
{
    int i=0,j=0, iterations=0;
    double cube_inv = (1.0/Simdat.cube);
    double u_old=0, w_old=0;
    double del_u=0, del_w=0, del_u_beta=0;
    double move=0, check=0;
    int accept=0;


    //maximum number of steps is Simdat.max_it
    for (iterations=0;iterations<Simdat.max_it;iterations++) {

	// walk through the list of particles and use the
	// Metropolis MC algorithm

	for (i=0;i<Simdat.np;i++) {
	    calc_i(i,Part[i].r); // get energy with original coordinates
	    //store potential energy of the particle in the old position
	    u_old = Res.u; 
	    w_old = Res.w;

	    // perturb coordinates 
	    //(randomly move particle in all three directions)
	    for (j=0;j<3;j++) {
		Temp.r[j]=Part[i].r[j];//don't change original coordinates yet
		// generate random number
		move = drand48();

		//add random displacement to particle in the j direction
		Temp.r[j]+= move*Simdat.drmax;
	       
		// periodic boundary conditions
		Temp.r[j] -= (Simdat.cube*rint(Temp.r[j]*cube_inv));

	    }
	    // calculate energy of interaction of the particle with its new coordinates
	    // and all other particles
	    calc_i(i,Temp.r);


	    //calculate energy differences
	    del_u = Res.u - u_old;//difference in potential energy
	    del_w = Res.w - w_old;//difference in virial
	    //calculate Boltzmann factor
	    del_u_beta = exp(-Simdat.beta * del_u);

	    //
	    if (del_u_beta > 1.0) {//check for acceptance
		accept = 1;//accept the trial move
	    } 
	    else {//rejected, now generate a random number
		//check if less than Boltzmann factor
		if (drand48() < del_u_beta) {
		    accept = 1;//if less, accept trial move
		}
	    }
	    if (accept == 1) {//if trial move has been accepted
		accept = 0;//reset the flag for the next trial move

		//increment the total potential energy of the system
		Res.PE += del_u;
		//increment the virial of the system
		Res.virial += del_w;

		//copy the coordinates of the accepted trial position over the old coordinates
		for (j=0;j<3;j++) {
		    Part[i].r[j] = Temp.r[j];
		}
		Simdat.change++;//update the number of accepted moves
	    }
	    //update the number of trial moves (whether accepted or rejected)
	    Simdat.try1++;

	    compute_averages(); // average phase properties

	} // end of loop over one particle

	if (iterations%Simdat.step == 0) {
	    // now check to see if the magnitude of random
	    // movement should be adjusted
	    adjust();
	}
	if (Avg)
	    inst_avg(iterations);//display instantaneous averages
	else
	    final_avg();//display time averages
	
	Res.inst_pres = Res.inst_VN = 0;//reset counters
    }// end one complete cycle through all particles
    
    if (Avg == 1) final_avg();
}

   

//----------Time averages are accumulated here----------
void compute_averages (void) 
{
    Res.av       += 1; // how many times we have averaged
    //the instantaneous potential energy per particle
    Res.VN        = Res.PE/(double)Simdat.np;
    //instantaneous pressure
    Res.pres      = Simdat.density*Simdat.T+(Res.virial/Simdat.volume);
    Res.inst_VN   = Res.VN;
    Res.inst_pres = Res.pres;
    Res.av_VN    += Res.VN;//add PE to the total PE for the simulation
    Res.av_pres  += Res.pres;//add Pressue to total Pressure
}

//----------Change the maximum random displacement allowed----------
void adjust(void) 
// check to see if magnitude of random step should be
// adjusted.
{//the purpose of this routine is to try and keep the number of
 //states accepted close to about 50%
    double ratio=0;
    
    
    ratio = (double)Simdat.change/(double)(Simdat.step*Simdat.np);
    if (ratio > 0.5) {
	Simdat.drmax *= 1.05;
    } else {
	Simdat.drmax *= 0.95;
    }
    
    Simdat.change = 0;
}

//----------Get input data----------
void mc_io() 
{
    int part=0;
    double dens=0, sig=0, cut=0;
    char str[80];

    ifstream read_in("in_mc",ios::in);
    if (!read_in) {
	cout<<"Cannot open input file in_mc. Exiting."<<endl;
	exit(1);
    }
    read_in.precision(16); read_in.width(8);
    read_in>>str; Simdat.density = atof(str); read_in>>str;
    read_in>>str; Simdat.np = atoi(str); read_in>>str;
    read_in>>str; Simdat.T = atof(str); read_in>>str;
    read_in>>str; Simdat.max_it = atoi(str); read_in>>str;
    read_in>>str; Avg = atoi(str);

    read_in.close();

    printf("n: %f\tN: %d\tsigma: %f\trcut: %f\tT: %f\n",Simdat.density,
	   Simdat.np,Simdat.sigma,Simdat.rcut,Simdat.T);
}

//----------initialise all variables----------
void mc_init() 
{
    //set cutoff
    Simdat.rcut = 1.12246;
    //set sigma
    Simdat.sigma = 1.0;
    //the cutoff value
    Simdat.rcutsq = pow(Simdat.rcut,2.0);
    //the volume
    Simdat.volume = ((double) Simdat.np)/Simdat.density;
    //the cell size
    Simdat.cube   = pow(Simdat.volume,(1.0/3.0));
    
    //constants used in interaction potential computation
    Simdat.sr3 = pow((1.0/Simdat.rcut),3.0);
    Simdat.sr9 = pow(Simdat.sr3,3.0);

    //the 
    Simdat.drmax = 0.5; 

    //the Boltzmann factor. Note that k is set to 1 here
    Simdat.beta  = (1.0/Simdat.T);
    Simdat.change = 0;
    Simdat.try1 = 0;
    Simdat.step = 3;

    Res.PE = Res.virial = Res.u = Res.w = 0;
    Res.VN = Res.pres = Res.inst_VN = Res.inst_pres = 0;
    Res.av_VN = Res.av_pres = 0;
    Res.av = 0;

    if (Simdat.rcut > (Simdat.cube/2.0)) {
	Simdat.rcut = Simdat.cube/2.0;
	cout<<"Cutoff changed to cube/2. Is now "<<Simdat.rcut<<endl;
	exit(1);
    }

    // seed the random number generator
    srand48(10101);
}

//----------calculate all interparticle interactions----------
void calc_interact() 
{
    int i=0, j=0, k=0;
    double rij=0, rijsq=0;
    double sr2=0,sr6=0;
    double cube_inv=(1.0/Simdat.cube);
    double vij, wij;
    double rij_ci=0;
    double rijx=0, rijy=0, rijz=0;
    double rijz1=0;
    double rminsq = pow(0.7,2.0);

    for (i=0; i<Simdat.np-1;i++) {
	for (j=i+1;j<Simdat.np;j++) {
	    //Find difference 
	    rijx = (Part[i].r[0]-Part[j].r[0]);
	    rijy = (Part[i].r[1]-Part[j].r[1]);
	    rijz = (Part[i].r[2]-Part[j].r[2]);

	    //calculate the minimum image
	    rijx -= Simdat.cube*rint(rijx*cube_inv);
	    rijy -= Simdat.cube*rint(rijy*cube_inv);
	    rijz -= Simdat.cube*rint(rijz*cube_inv);

	    rijsq = pow(rijx,2.0)+pow(rijy,2.0)+pow(rijz,2.0);
	    
	    //check for overlap
	    if (rijsq < rminsq) {
		cout<<"Overlap in config."<<endl;
		exit(1);
	    }
	    
	    if (rijsq < Simdat.rcutsq) {
		sr2 = 1.0/rijsq ;
		sr6 = sr2*sr2*sr2;
		vij = sr6*(sr6-1.0);
		wij = sr6*(sr6-0.5);
		Res.PE += vij;
		Res.virial += wij;
	    }
	}
    }
    Res.PE *= 4.0;
    Res.virial *= (48.0/3.0);
}

//----------calculate interactions of one particle only
//with all other particles----------
void calc_i (int i, double *coord) 
{
    int j=0, k=0;
    double rij=0, rijsq=0;
    double sr2=0,sr6=0;
    double cube_inv=(1.0/Simdat.cube);
    double vij, wij;
    double rijx=0, rijy=0, rijz=0;

    Res.u = Res.w = 0;

    for (j=0;j<Simdat.np;j++) {
	if (i != j) {
	    //Find difference 
	    rijx = (coord[0]-Part[j].r[0]);
	    rijy = (coord[1]-Part[j].r[1]);
	    rijz = (coord[2]-Part[j].r[2]);

	    rijx -= Simdat.cube*rint(rijx*cube_inv);
	    rijy -= Simdat.cube*rint(rijy*cube_inv);
	    rijz -= Simdat.cube*rint(rijz*cube_inv);

	    rijsq = pow(rijx,2.0)+pow(rijy,2.0)+pow(rijz,2.0);

	    if (rijsq < Simdat.rcutsq) {
		sr2 = 1.0/rijsq ;
		sr6 = sr2*sr2*sr2;
		vij = sr6*(sr6-1.0);
		wij = sr6*(sr6-0.5);
		Res.u += vij;
		Res.w += wij;
	    }
	}
    }

    Res.u *= 4.0;
    Res.w *= (48.0/3.0);
}
	    

//----------Set initial configuration of all particles----------
void initial_config (void) 
{
    int num_cell=0, nc_cube=0;
    int index=0;
    double x_pos=0,y_pos=0,z_pos=0;
    int i=0,j=0,k=0;


    num_cell = (int) pow((double)Simdat.np,(1.0/3.0));
    nc_cube = (int)pow(num_cell,3.0);
    if (nc_cube < Simdat.np) 
	num_cell++;
    for (i=0;i<num_cell;i++) {
	x_pos=(i/(double)(num_cell)-0.50)*Simdat.cube;
	for (j=0;j<num_cell;j++) {
	    y_pos=(j/(double)(num_cell)-0.50)*Simdat.cube;
	    for(k=0;k<num_cell;k++) {
		z_pos=(k/(double)(num_cell)-0.50)*Simdat.cube;
		Part[index].r[0]=x_pos;
		Part[index].r[1]=y_pos;
		Part[index++].r[2]=z_pos;
	    }
	}
    }
}


