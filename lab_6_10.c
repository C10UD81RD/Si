#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

// Функция для проверки, содержится ли элемент в массиве
bool contains(int* array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

// Функция для формирования массива из элементов, не встречающихся  обоих массивах
int* getUniqueElements(int* arrayA, int sizeA, int* arrayB, int sizeB, int* resultSize) {
    // Создание массива с максимально возможной длиной
    int* result = malloc(sizeof(int) * (sizeA + sizeB));
    int count = 0;

    // Проверка каждого элемента массива A
    for (int i = 0; i < sizeA; i++) {
        int element = arrayA[i];

        // Если элемент не содержится в массиве B, добавляем его в результат
        if (!contains(arrayB, sizeB, element)) {
            result[count++] = element;
        }
    }

    // Проверка каждого элемента массива B
    for (int i = 0; i < sizeB; i++) {
        int element = arrayB[i];

        // Если элемент не содержится в массиве A, добавляем его в результат
        if (!contains(arrayA, sizeA, element)) {
            result[count++] = element;
        }
    }

    // Изменяем размер результирующего массива до фактического размера
    result = realloc(result, sizeof(int) * count);
    *resultSize = count;

    return result;
}

int main() {
    int sizeA, sizeB;

    printf("Введите количество элементов в массиве A: ");
    scanf("%d", &sizeA);

    printf("Введите количество элементов в массиве B: ");
    scanf("%d", &sizeB);

    // Создание массивов A и B с заданным количеством элементов
    int arrayA[MAX_SIZE];
    int arrayB[MAX_SIZE];

    // Заполнение массива A случайными числами
    srand(time(NULL));
    for (int i = 0; i < sizeA; i++) {
        arrayA[i] = rand() % 40 - 19;
    }

    // Заполнение массива B случайными числами
    for (int i = 0; i < sizeB; i++) {
        arrayB[i] = rand() % 40 - 19;
    }

    printf("Массив A: ");
    for (int i = 0; i < sizeA; i++) {
        printf("%d ", arrayA[i]);
    }
    printf("\n");

    printf("Массив B: ");
    for (int i = 0; i < sizeB; i++) {
        printf("%d ", arrayB[i]);
    }
    printf("\n");

    int resultSize;
    int* result = getUniqueElements(arrayA, sizeA, arrayB, sizeB, &resultSize);

    printf("Результат: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
