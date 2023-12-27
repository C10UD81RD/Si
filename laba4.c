#include <stdio.h>
#include <math.h>

double f(double x) {
    if (x >= 0 && x <= 1) {
        return -cos(exp(x));
    } else if (x > 1 && x <= 2+1*1e-10) {
        return log(2 * x + sin(x * x));
    } else {
        return 0;
    }
}

double calculate_integral(double a, double b, double h) {
    double sum = 0;
    double x;

    for (x = a + h/2; x < b; x += h) {
        sum += f(x);
    }

    return sum * h;
}

double runge_rule(double a, double b, double h, double e) {
    double I_h = calculate_integral(a, b, h);
    double I_h_half = calculate_integral(a, b, h/2);
    double epsilon = fabs(I_h - I_h_half) / 3;

    while (epsilon > e) {
        h /= 2;
        I_h = calculate_integral(a, b, h);
        I_h_half = calculate_integral(a, b, h/2);
        epsilon = fabs(I_h - I_h_half) / 3;
    }

    return I_h;
}

int main() {
    double a = 0;
    double b = 2;
    double h;
    double e;

    printf("Enter h: ");
    scanf("%lf", &h);

    printf("Enter e: ");
    scanf("%lf", &e);

    if (h > 0 && h <= b - a) {
        double result = runge_rule(a, b, h, e);
        printf("Approximate value of the integral: %lf\n", result);
    } else {
        printf("Invalid value of h\n");
    }

    return 0;
}
