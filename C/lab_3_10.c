#include <stdio.h>
#include <math.h>

int main()
{
    double f, h, x;
    x = 0.0;
    printf("Enter step h -> ");
    scanf("%lf", &h);
    if (h > 0.0) {

        printf("x\t             f(x)\t\n");
        printf("---------------------------------\n");

        do {
            if ( x > 1 && x < 2.0 ){
                x += h;
                f = log((2.0 * x) + sin(x*x));
                printf("x = %lf\t f(x) = %lf\n", x, f);
            }
            else if( x <= 1.0 )
                x += h;
                f = -1.0 * cos(exp(x));
                printf("x = %lf\t f(x) = %lf\n", x, f);
        } while (x < 2.0);
    }
    else
    {
        printf("Error, x must be positive");
    }

    return 0;
}
