#include <stdlib.h>
#include <stdio.h>

/**
 * Calculate potenz fuer eine Zahl
 * @return int
 */
static int potenz(int zahl1, int zahl2)
{
  int c, temp = 1;  
  
  for(c = 0; c < zahl2; c++) {
     temp *= zahl1;
  }  
  return temp;
}

/**
 * Get value from user
 * @return int
 */
int input ()
{
  int zahl;
  
  printf("input number\n");
  if(scanf("%d",&zahl) != 1 || zahl <= 0) {
    fprintf(stderr,"wrong input\n");
    exit (EXIT_FAILURE);
  }
  return zahl;
}


int main ()
{
  int zahl1, zahl2;

  zahl1 = input ();
  zahl2 = input ();
      
  printf("result is %d\n", potenz(zahl1, zahl2));
  
  return( EXIT_SUCCESS );
}
