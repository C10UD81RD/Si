#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    double x1, y1, x2, y2, v1, v2, distance, time;

    printf("������� ���������� ����� A (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("������� ���������� ����� B (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);

    printf("������� �������� � ������ �������� (v1): ");
    scanf("%lf", &v1);

    printf("������� �������� � ������� �������� (v2): ");
    scanf("%lf", &v2);

    // ������ ���������� ����� ������� A � B
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // ������ ������� ���� � ����������� �� ��������� �����
    if (y1 <= 0 && y2 <= 0) {
        time = distance / v1;
    } else if (y1 > 0 && y2 > 0) {
        time = distance / v2;
    } else {
        double time1 = fabs(y1 / v1); // ����� �������� �� A �� y = 0
        double time2 = fabs(y2 / v2); // ����� �������� �� y = 0 �� B
        double time3 = distance / v1; // ����� �������� �� ������ ��������
        time = time1 + time2 + time3;
    }

    printf("���������� ���� �� ����� A �� ����� B: %.2lf ������\n", distance);
    printf("����� ����: %.2lf ������\n", time);

    return 0;
}
