#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265358979323846

int main (int argc, char *argv[]) 
{
  double r, area, perimeter;

  r = 12;

  area = r*r;
  perimeter = r+r+r+r;

  printf("Die Flaeche eines Quadrats mit Kantenlaenge r: %lf ist: %f\n", r, area);
  printf("Die Umfang eines Quadrats mit Kantenlaenge r: %lf ist: %f\n", r, perimeter);

  area = PI * r * r;
  perimeter = 2 * PI * r;

  printf("Die Flaeche eines Kreises mit Kantenlaenge r: %lf ist: %f\n", r, area);
  printf("Die Umfang eines Kreises mit Kantenlaenge r: %lf ist: %f\n", r, perimeter);



  int n = 1234;
  float x = -1113.1472;
  char m[] = "           hello";

  printf("n = %3d, x = %8.4f, m = \"%-15s\"\n", n, x, m);

  int a, b, c, d, e, f, g;

  a = 6;
  b = a + 3 * 4;
  c = b - b % 4;
  d = b/3;
  e = a + b/2;
  f = (a + b/2 + c)/3;
  g = a - b + c - d + 4 - f;


  printf("a=%d, b=%d, c=%d, d=%d, e=%d, f=%d, g=%d\n", a, b, c, d, e, f, g);


}
