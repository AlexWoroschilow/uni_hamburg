#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


void output (int zahl) {
  
     if(zahl >= 33 && zahl <= 126) {
       printf("%3d  %-4c", zahl, zahl);      
       return;
     }
     printf("%3d  \\%-4d", zahl, zahl);          
    return;     
}
  
int main(int argc, char *argv[])
{
  int x;
  int y;
  
  
   for (x=0, y=0; x < UCHAR_MAX/4; x++, y++) {
     
          
     output(UCHAR_MAX/4 + x);
     printf("\t");                 
     
     output(UCHAR_MAX/4 * 2 + x);
     printf("\t");                 
     
     output(UCHAR_MAX/4 * 3 + x);
     printf("\t");                 

     output(UCHAR_MAX/4 * 4 + x);
     printf("\t");                 
     
     printf("\n");                 
     

  }
  
  
  return 0;
}
