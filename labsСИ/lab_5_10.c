#include <stdio.h>

// Функция для умножения двух чисел с использованием цикла
int multiplyWithLoop(int num1, int num2) {
    int result = 0;

    while (num2 > 0) {
        result += num1;
        num2--;
    }

    return result;
}

// Функция для умножения двух чисел с использованием рекурсии
int multiplyWithRecursion(int num1, int num2) {
    if (num2 == 0) {
        return 0;
    }

    return num1 + multiplyWithRecursion(num1, num2 - 1);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Использование функции умножения с циклом
    int resultWithLoop = multiplyWithLoop(num1, num2);
    printf("result with cycle: %d\n", resultWithLoop);

    // Использование функции умножения с рекурсией
    int resultWithRecursion = multiplyWithRecursion(num1, num2);
    printf("result with recursion: %d\n", resultWithRecursion);

    return 0;
}
