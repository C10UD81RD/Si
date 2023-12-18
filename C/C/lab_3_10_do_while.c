#include <stdio.h>
#include <math.h>

int main() {
    double x, h, f;

    // Ввод шага
    printf("Enter h -> ");
    scanf("%lf", &h);
    // Цикл для вычисления и вывода значений функции при x >= 0 && x <= 1
    if (h <= 2){
        printf("x\t             f(x)\t\n");
        printf("---------------------------------\n");
        x = 0 + h;
        do {
            f = -cos(exp(x));
            printf("x = %lf\t f(x) = %lf\n", x, f);
            x += h;
        } while (x >= 0 && x <= 1);

    // Цикл для вычисления и вывода значений функции при x > 1 && x <= 2
        x = 1 + h;
        do {
            f = log(2 * x + sin(x * x));
            printf("x = %lf\t f(x) = %lf\n", x, f);
            x += h;
        } while (x > 1 && x <= 2);
    } else printf("x is too big");


    return 0;
}
