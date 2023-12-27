// #include <stdio.h>
// #include <math.h>
// #include <locale.h>
//
// #define M_PI 3.14159
//
// int main() {
//     setlocale(LC_ALL, "");
//     double x, y, z, pi;
//     printf("Введите значение x: ");
//     scanf("%lf", &x);
//
//     if (x != 0 && (sin(M_PI * x) != 0 || x != 0.5 || x != -0.5)) {
//
//         y = sqrt(x) / sin(M_PI * x);
//         z = (y >= 0) ? 1 : -1;
//
//         printf("y(x) = %.2f\n", y);
//         printf("z(y) = %f\n", z);
//
//     } else printf("Недопустимое значение x.\n");
//
//     return 0;
// }
// #include <stdio.h>
// #include <math.h>
// #include <locale.h>
//
// // #define M_PI 3.14159
//
// int main() {
//     setlocale(LC_ALL, "");
//     double x, y, z;
//     printf("Введите значение x: ");
//     scanf("%lf", &x);
//
//     if (x > 0.0 && x < 1.0) {
//         y = sqrt(x) / sin(M_PI * x);
//         z = y >= 0 ? 1 : -1;
//
//         printf("y(x) = %lf\n", y);
//         printf("z(y) = %lf\n", z);
//         printf("Функции y(x) и z(y) определены для введенного значения x.\n");
//     } else {
//         printf("Функции y(x) и z(y) не определены для введенного значения x.\n");
//     }
//
//     return 0;
// }
#include <stdio.h>
#include <math.h>
#include <locale.h>
#define M_PI 3.14159
int main() {
    setlocale(LC_ALL, "");
    double x, y, z;
    printf("Введите значение x: ");
    scanf("%lf", &x);
    // Преобразование угла из градусов в радианы
    // double radians = M_PI * x / 180.0;0
    double radians = M_PI * x / 180.0;

    if (x >= 0 && x <= 1) {
        y = sqrt(x) / sin(3.14*x);
        z = y >= 0 ? 1 : -1;

        printf("y(x) = %lf\n", y);
        printf("z(y) = %lf\n", z);
        printf("Функции y(x) и z(y) определены для введенного значения x.\n");
    } else {
        printf("Функции y(x) и z(y) не определены для введенного значения x.\n");
    }

    return 0;
}
