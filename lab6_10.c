#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Функция для проверки, содержится ли элемент в массиве.
bool contains(int* array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

// Функция для генерации случайных чисел в заданном диапазоне.
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Функция для формирования массива из элементов, не встречающихся в массивах A и B одновременно.
int* generateUniqueArray(int* arrayA, int sizeA, int* arrayB, int sizeB, int* sizeResult) {
    // Вычисляем максимальный размер результирующего массива:
    int maxSizeResult = (sizeA + sizeB > 40) ? 40 : sizeA + sizeB;

    // Выделяем память под результирующий массив:
    int* result = (int*) malloc(maxSizeResult * sizeof(int));

    // Переменная для учета текущего размера результирующего массива:
    int currentSizeResult = 0;

    // Проверяем каждое значение из заданного диапазона:
    for (int value = -19; value <= 20; value++) {
        // Если значение не содержится ни в массиве arrayA, ни в массиве arrayB, добавляем его в результирующий массив:
        if (!contains(arrayA, sizeA, value) && !contains(arrayB, sizeB, value)) {
            result[currentSizeResult] = value;
            currentSizeResult++;

            // Если достигли максимального размера результирующего массива, выходим из цикла:
            if (currentSizeResult >= maxSizeResult) {
                break;
            }
        }
    }

    // Обновляем значение размера результирующего массива:
    *sizeResult = currentSizeResult;

    return realloc(result, currentSizeResult * sizeof(int));
}

int main() {
    int sizeA, sizeB;
    printf("Enter size A: ");
    scanf("%d", &sizeA);
    printf("Enter size B: ");
    scanf("%d", &sizeB);

    // Выделяем память под массивы A и B:
    int* arrayA = (int*) malloc(sizeA * sizeof(int));
    int* arrayB = (int*) malloc(sizeB * sizeof(int));

    // Заполняем массивы A и B случайными числами из заданного диапазона:
    for (int i = 0; i < sizeA; i++) {
        arrayA[i] = generateRandomNumber(-19, 20);
    }

    for (int i = 0; i < sizeB; i++) {
        arrayB[i] = generateRandomNumber(-19, 20);
    }
    printf("A: ");
    for (int i = 0; i < sizeA; i++) {
        printf("%d ", arrayA[i]);
    }
    printf("\n");
    printf("B: ");
    for (int i = 0; i < sizeB; i++) {
        printf("%d ", arrayB[i]);
    }
    printf("\n");
    // Формируем массив из элементов, не встречающихся одновременно в массивах A и B:
    int sizeResult;
    int* result = generateUniqueArray(arrayA, sizeA, arrayB, sizeB, &sizeResult);

    // Выводим результат:
    printf("Result:\n");
    for (int i = 0; i < sizeResult; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Освобождаем память:
    free(arrayA);
    free(arrayB);
    free(result);

    return 0;
}
