#include <stdio.h>
#include <math.h>

int main()
{
    double f, h, x, c;
    x = 0.0;
    printf("Enter step h -> ");
    scanf("%lf", &h);
    if (h>0) {
        printf("x\t             f(x)\t\n");
        printf("---------------------------------\n");
        while (c <= 2.0)
        {
            if (1.0 < x && x <= 2.0){
                f = log(x + 1.0) - sqrt(4.0 - x * x);
                x = x + h;
                c = c + h;
                printf("x = %lf\t f(x) = %lf\n", x, f);

            }
            else if( x <= 1.0 )
                f = cos(x) * exp(pow(-x, 2.0));
                x = x + h;
                c = c + h;
                printf("x = %lf\t f(x) = %lf\n", x, f);
        }
    }
    else
    {
        printf("Error, x must be positive");
    }

    return 0;
}
