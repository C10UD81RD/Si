#include <math.h>
#include <stdio.h>
double
f(int n)
{
    double integral = 0.0;
    double h = 2.0 / n;
    double x;
    for(x = 1.0 / n; x <= 2.0; x += h)
    {
    double z;
        if(x <= 1.0)
            z = x * x * atan(x);
        else
            z = sin(1.0 / (x * x));
        integral += z;
    }
    integral *= h;
    return integral;
}
int main()
{
    double e;
    printf("введите точность e ");
    scanf("%lf", &e);
    int n = 1;
    double integral  = f(n);
    double integral = f(2 * n);
    while(fabs(intg2 - intg) / 3 >= e)
    {
        n = n * 2;
        intg  = intg2;
        intg2 = f(n);
    }
    printf("%lf", intg2);
    return 0;
}
