#include<stdio.h>


float f(int x,int y,int z)
{
  return (3*x+y-z);
}

float g(int x,int y,int z)
{
  return (2*x-y+z);
}


int main()
{
 float x0, y0,z0, xn, h, yn, k1, k2, k3, k4, k;
 int i, n;
 printf("Enter Initial Condition\n");
 printf("x0 = ");
 scanf("%f", &x0);
 printf("y0 = ");
 scanf("%f", &y0);
 printf("z0 = ");
 scanf("%f", &z0);
 printf("h = ");
 scanf("%f", &h);

 n = (xn-x0)/h;

 printf("\nx0\ty0\tyn\n");
 for(i=0; i < n; i++)
 {
  k1 = h * (f(x0, y0));
  k2 = h * (f((x0+h/2), (y0+k1/2)));
  k3 = h * (f((x0+h/2), (y0+k2/2)));
  k4 = h * (f((x0+h), (y0+k3)));
  k = (k1+2*k2+2*k3+k4)/6;
  yn = y0 + k;
  printf("%0.4f\t%0.4f\t%0.4f\n",x0,y0,yn);
  x0 = x0+h;
  y0 = yn;
 }

 printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);

 return 0;
}
