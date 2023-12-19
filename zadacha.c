#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");
    double x1, y1, x2, y2, v1, v2, distance, time;

    printf("Введите координаты точки A (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Введите координаты точки B (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);

    printf("Введите скорость в нижней половине (v1): ");
    scanf("%lf", &v1);

    printf("Введите скорость в верхней половине (v2): ");
    scanf("%lf", &v2);

    // Расчет расстояния между точками A и B
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // Расчет времени пути в зависимости от положения точек
    if (y1 <= 0 && y2 <= 0) {
        time = distance / v1;
    } else if (y1 > 0 && y2 > 0) {
        time = distance / v2;
    } else {
        double time1 = fabs(y1 / v1); // Время движения от A до y = 0
        double time2 = fabs(y2 / v2); // Время движения от y = 0 до B
        double time3 = distance / v1; // Время движения по нижней половине
        time = time1 + time2 + time3;
    }

    printf("Кратчайший путь от точки A до точки B: %.2lf метров\n", distance);
    printf("Время пути: %.2lf секунд\n", time);

    return 0;
}
