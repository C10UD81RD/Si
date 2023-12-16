#include <stdio.h>
#include <math.h>

int main()
{
    double h;
    printf("Enter step h -> ");
    scanf("%lf", &h);
    printf("%-17sf(x)\n", "x");
    printf("---------------------------------\n");
    int step_h = (int)(2 / h);
    double f;
    for (int i = 0; i <= step_h; i++)
    {
        double x = i*h;
        if (1.0 < x && x <= 2.0)
            f = sin(1 / (x * x));
        else
            f = x * x * atan(x);
          printf("x = %lf\t f(x) = %lf\n", x, f);
    }
    return 0;
}
