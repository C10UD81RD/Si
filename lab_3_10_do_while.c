#include <stdio.h>
#include <math.h>

int main() {
    double x, h, f;

    // Ввод шага
    printf("Enter h -> ");
    scanf("%lf", &h);

    if (h <= 2 && h > 0){
        printf("x\t             f(x)\t\n");
        printf("---------------------------------\n");
        x = 0 + h;
        do {
            f = -cos(exp(x));
            printf("x = %lf\t f(x) = %lf\n", x, f);
            x += h;
        } while (x >= 0 && x <= 1);


        do {
            f = log(2 * x + sin(x * x));
            printf("x = %lf\t f(x) = %lf\n", x, f);
            x += h;
        } while (x <= 2.0000000001);
    } else printf("h is incorrect");


    return 0;
}
