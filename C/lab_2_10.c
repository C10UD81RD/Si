#include <stdio.h>
#include <math.h>
#include <locale.h>

#define M_PI 3.14159

int main() {
    setlocale(LC_ALL, "");
    double x, y, z, pi;
    printf("Введите значение x: ");
    scanf("%lf", &x);
    
    if (x != 0 && (sin(M_PI * x) != 0 || x != 0.5 || x != -0.5)) {
        y = sqrt(x) / sin(M_PI * x);
        z = (y >= 0) ? 1 : -1;
        
        printf("y(x) = %.2f\n", y);
        printf("z(y) = %f\n", z);
    } else {
        printf("Недопустимое значение x.\n");
    }
    
    return 0;
}