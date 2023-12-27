// #include <stdio.h>
// #include <math.h>
// // #include <locale.h>
//
// int main()
// {
//     // setlocale(LC_ALL,"");
//     double x, y, z;
//
//     printf("Enter x: ");
//     scanf("%lf", &x);
//
//     if (x <= 0 || x >= 1)
//     {
//         printf("x value must be in (0, 1)\n");
//         return 0;
//     }
//
//     y = sqrt(x) / sin(M_PI * x);
//     z = (y >= 0) ? 1 : -1;
//
//     printf("y(x) = %lf\n", y);
//     printf("z(y) = %lf\n", z);
//
//     return 0;
// }
#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;

    printf("Enter x: ");
    scanf("%lf", &x);

    if (sin(M_PI * x) == 0)
    {
        printf(" sin(pi*x) must be != 0\n");
        return 0;
    }

    y = sqrt(x) / sin(M_PI * x);
    z = (y >= 0) ? 1 : -1;

    printf("y(x) = %lf\n", y);
    printf("z(y) = %lf\n", z);

    return 0;
}
