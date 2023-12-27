#include <stdio.h>
#include <math.h>

int main() {
    double x, h, f;

    // Ввод шага
    printf("Enter h: ");
    scanf("%lf", &h);
    if (h > 0 && h <= 2){
      printf("x\t             f(x)\t\n");
      printf("---------------------------------\n");

      // Цикл для вычисления и вывода значений функции при x >= 0 && x <= 1
      for (x = 0 + h; x >= 0 && x <= 1; x += h) {
          f = -cos(exp(x));
          printf("x = %lf\t f(x) = %lf\n", x, f);
      }
      // Цикл для вычисления и вывода значений функции при x > 1 && x <= 2
      for (x = x; x > 1 && x <= 2+1*1e-10; x += h) {
          f = log(2 * x + sin(x * x));
          printf("x = %lf\t f(x) = %lf\n", x, f);
      }
    } else printf("h is incorrect");


    return 0;
}
