#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) 
{
  double r, area, perimeter;
  
  r = 12;
  
  area = r*r;
  perimeter = r+r+r+r;
  
  area_kreis = 3.14 * r * r;
  perimeter_kreis = 2 * 3.14 * r;

  
  printf("Die Flaeche eines Quadrats mit Kantenlaenge r: %f ist: %f\n", area);
  printf("Die Umfang eines Quadrats mit Kantenlaenge r: %f ist: %f\n", perimeter);

  printf("Die Flaeche eines Kreises mit Kantenlaenge r: %f ist: %f\n", area_kreis);
  printf("Die Umfang eines Kreises mit Kantenlaenge r: %f ist: %f\n", perimeter_kreis);
  
}