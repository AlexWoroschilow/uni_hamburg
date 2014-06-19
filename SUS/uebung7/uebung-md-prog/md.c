#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "md.h"

/* [ASSIGNMENT] calculate energy and forces of a WCA potential (a Lennard-Jones
   potential truncated at the minimum) */
real calc_energy_force(uint natom, rvec box, rvec *x, rvec *f) {
    uint i, j;
    real Epot, r, fscale;
    rvec rij;
    const real eps   = 2.0, sig = 1.5;
    const real rcut  = pow(2.0, 1.0/6.0) * sig;
    const real sig6  = pow(sig, 6);
    const real sig12 = pow(sig, 12);
    const real Eshift = eps;

    rvecary_set(natom, f, 0);
    Epot = 0;
    for (i = 0; i < natom; i++) {
        for (j = i + 1; j < natom; j++) {
            /* interaction of atoms i and j */
            /* Note: use rvec_sub_pbc(&rij, box, x[i], x[j]); to
               calculate the distance between atoms i and j */
        }
    }
    return Epot;
}

/* [ASSIGNMENT] calculate instantaneous temperature */
real calc_temperature(uint ndof, real Ekin, real kB) {
    return 1.0;
}

/* [ASSIGNMENT] calculate kinetic energy */
real calc_kinetic_energy(uint natom, rvec *v, real *m) {
    real Ekin = 0;
    return Ekin;
}

/* [ASSIGNMENT] leapfrog integration step */
real leapfrog_step(uint natom, rvec *x, rvec *v, rvec *f, real *m, real dt, rvec box) {
    real Epot = 0;
    /* x += dt * v */
    /* calc energy, forces */
    /* v += dt * f/m */
    return Epot;
}

static void print_header() {
    printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n",
           "step", "time", "E/Na", "Epot/Na", "Ekin/Na", "T", "Edrift/Na", "rel.Edrift", "vcom");
}

static void print_step_info(uint step, uint natom, real dt,
                     real E, real Epot, real Ekin, real Estart, real T, real vcom) {
    printf("%10u\t%10.5f\t%10.5f\t%10.5f\t%10.5f\t%10.5f\t%10.5f\t%10.5f\t%10.5f\n",
           step, step * dt, E/natom, Epot/natom, Ekin/natom, T,
           (E - Estart)/natom, (E - Estart)/Estart, vcom);
}

int main(int argc, char **argv) {
    uint  natom;          /* number of atoms */
    ulong nstep,          /* number of time steps to run simulation */
          nstep_print;    /* print simulation state every nstep_print steps */
    rvec  *x,             /* atom positions, x[i] is vector of coordinates of atom i */
          *v,             /* velocities */
          *f;             /* forces */
    real  *m;             /* atom masses */
    rvec  box;            /* simulation box side lengths */
    real  dt;             /* integrator timestep */

    uint  ndof;           /* number of degrees of freedom */
    real  volume,         /* simulation box volume */
          density,        /* system density = natom / volume */
          E,              /* total energy */
          Epot,           /* potential energy */
          Ekin,           /* kinetic energy */      
          Estart,         /* total energy at start of simulation */
          T,              /* instantaneous temperature */
          Tstart;         /* starting temperature */
    uint  step = 0;       /* integration step */
    real  vcom;           /* center of mass velocity */

    const real kB = 1.0;  /* Boltzmann's constant */
    const real default_mass = 3.0;
    const real max_rel_Edrift = 1.0;

    /* parse command-line args */
    if (argc != 7) {
        printf("usage: %s natom density Tstart dt nstep nstep_print\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    natom       = atoi(argv[1]);
    density     = atof(argv[2]);
    Tstart      = atof(argv[3]);
    dt          = atof(argv[4]);
    nstep       = atol(argv[5]);
    nstep_print = atol(argv[6]);

    /* allocate memory */
    x = calloc(natom, sizeof *x);
    v = calloc(natom, sizeof *v);
    f = calloc(natom, sizeof *f);
    m = calloc(natom, sizeof *m);
    if (x == NULL || v == NULL || f == NULL || m == NULL) {
        printf("error: couldn't allocate memory\n");
        exit(EXIT_FAILURE);
    }

    /* setup */
    ndof   = NDIM * natom;
    volume = natom / density;
    rvec_set(&box, pow(volume, 1.0/NDIM));
    setup_fcc_lattice(x, natom, box);
    apply_pbc(natom, box, x);
    for (uint i = 0; i < natom; i++)
        m[i] = default_mass;
    init_velocities(natom, v, m, ndof, kB, Tstart);

    /* print info */
    printf("simulation box: ");
    rvec_print(box);
    printf("[ x ]\n");
    rvecary_print(x, natom);
    printf("[ v ]\n");
    rvecary_print(v, natom);
    printf("[ f ]\n");
    rvecary_print(f, natom);

    /* calculate starting energy etc. */
    Epot = calc_energy_force(natom, box, x, f);
    Ekin = calc_kinetic_energy(natom, v, m); 
    T = calc_temperature(ndof, Ekin, kB);
    Estart = E = Epot + Ekin;
    vcom = com_velocity(natom, v, m);

    /* run simulation */
    printf("START\n");
    print_header();
    print_step_info(step, natom, dt, E, Epot, Ekin, Estart, T, vcom);
    for (step = 1; step <= nstep; step++) {
        /* leapfrog integration step */
        Epot = leapfrog_step(natom, x, v, f, m, dt, box);

        /* apply periodic boundary conditions, move all atoms back
           into box */
        apply_pbc(natom, box, x);

        /* calculate properties: kinetic energy, temperature */
        Ekin = calc_kinetic_energy(natom, v, m);
        T    = calc_temperature(ndof, Ekin, kB);
        E    = Epot + Ekin;
        vcom = com_velocity(natom, v, m);

        /* periodically print out info */
        if (step % nstep_print == 0) {
            print_step_info(step, natom, dt, E, Epot, Ekin, Estart, T, vcom);
        }

        /* check if system has exploded */
        if (fabs((E - Estart) / Estart) > max_rel_Edrift) {
            printf("error: relative energy drift too large\n");
            print_step_info(step, natom, dt, E, Epot, Ekin, Estart, T, vcom);
            exit(EXIT_FAILURE);
        }
    }

    /* clean up */
    free(x);
    free(v);
    free(f);
    free(m);

    return EXIT_SUCCESS;
}
