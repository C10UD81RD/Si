#include <math.h>
#include <stdio.h>
int main()
{
  double x;
  printf("Enter x -> ");
  scanf("%lf", &x);
  //диапозон значения x, при которых возможны решения функций
  if(x <= 1.8999 && x >= -1.8999)
  {
    double y = (pow(2.0, x) + pow(2.0, -x))/2.0;
    double z = sqrt ((2.0 + y) - y * y);
    printf("y(x) = %lf\nz(y) = %lf\n", y, z);
  }
  else
    printf("x value is incorrect!\n");
  return 0;
}
