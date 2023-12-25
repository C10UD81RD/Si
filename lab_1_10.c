#include <stdio.h>
#include <locale.h>

float max(float a, float b, float c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

float min(float a, float b, float c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int main() {
    setlocale(LC_ALL, "");
    float d1, d2, d3;

    printf("������� �������� d1, d2, d3: ");
    scanf("%f%f%f", &d1, &d2, &d3);

    float maximum = max(d1, d2, d3);
    printf("���������� �������� -> %f\n", maximum);

    float minimum = min(d1, d2, d3);
    printf("���������� �������� -> %f\n", minimum);

    if (maximum == d1 || maximum == d3) {
        float difference = maximum - minimum;
        printf("�������� ����������� � ����������� ����������: %.2f\n", difference);
    } else {
        float quotient = minimum / maximum;
        printf("������� ����������� � ����������� ����������: %.2f\n", quotient);
    }

    return 0;
}
