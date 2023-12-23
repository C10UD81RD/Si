#include <math.h>
#include <stdio.h>

double f(int n) {
    double intg = 0.0;
    double h = 2.0 / n;
    double x;

    for (x = 1.0 / n; x <= 2.0; x += h) {
        double z;
        if (x <= 1.0)
            z = -cos(exp(x));
        else
            z = log(2 * x + sin(x * x));
        intg += z;
    }

    intg *= h;
    return intg;
}

int main() {
    double e;
    printf("Введите e: ");
    scanf("%lf", &e);

    int n = 1;
    double intg = f(n);
    double intg2 = f(2 * n);

    while (fabs(intg2 - intg) / 3 >= e) {
        n = n * 2;
        intg = intg2;
        intg2 = f(n);
    }

    printf("%lf\n", intg2);
    return 0;
}
