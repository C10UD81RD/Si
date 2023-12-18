#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 40
#define MIN_VALUE -19
#define MAX_VALUE 20

void findUniqueElements(int A[], int B[], int C[], int sizeA, int sizeB) {
    bool isPresent[MAX_VALUE - MIN_VALUE + 1] = {false}; // Инициализируем массив-флаг

    // Помечаем элементы массива A как присутствующие
    printf("Array A: ");
    for (int i = 0; i < sizeA; i++) {
        isPresent[A[i] - MIN_VALUE] = true;
        printf("%d ", A[i]);
    }
    printf("\n");

    // Помечаем элементы массива B как присутствующие
    printf("Array B: ");
    for (int i = 0; i < sizeB; i++) {
        isPresent[B[i] - MIN_VALUE] = true;
        printf("%d ", B[i]);
    }
    printf("\n");

    // Формируем массив C из элементов, не присутствующих одновременно в массивах A и B
    int index = 0;
    for (int i = MIN_VALUE; i <= MAX_VALUE; i++) {
        if (!isPresent[i - MIN_VALUE]) {
            C[index++] = i;
        }
    }
}

int main() {
    int A[ARRAY_SIZE];
    int B[ARRAY_SIZE];
    int C[ARRAY_SIZE] = {0};

    int sizeA = sizeof(A) / sizeof(int);
    int sizeB = sizeof(B) / sizeof(int);

    // Заполняем массивы A и B случайными числами
    srand(time(NULL));
    printf("Enter size of arrays: n -> ");
    scanf("%d", &n);
    int A[n];
    int B[n];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        A[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        B[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    findUniqueElements(A, B, C, sizeA, sizeB);

    printf("Unique elements there are no in A and B:\n");
    for (int i = 0; C[i] != 0; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}
