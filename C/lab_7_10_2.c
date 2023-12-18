#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100

// Функция для заполнения массива случайными числами
void fillArray(int arr[][MAX_SIZE], int size){
    srand(time(NULL)); // Инициализация генератора случайных чисел

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            arr[i][j] = rand() % 101 - 50; // Заполняем массив случайными числами от -50 до 50
        }
    }
}

// Функция для печати массива
void printArray(int arr[][MAX_SIZE], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Функция для нахождения максимального по модулю элемента матрицы
int findMaxAbsolute(int arr[][MAX_SIZE], int size){
    int maxAbs = abs(arr[0][0]); // Предполагаем, что первый элемент матрицы имеет максимальное значение по модулю

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(abs(arr[i][j]) > maxAbs){
                maxAbs = abs(arr[i][j]);
            }
        }
    }

    return maxAbs;
}

// Функция для разделения элементов диагоналей на максимальный по модулю элемент
void divideDiagonals(int arr[][MAX_SIZE], int size, int maxAbs){
    for(int i = 0; i < size; i++){
        arr[i][i] /= maxAbs; // Главная диагональ
        arr[i][size-i-1] /= maxAbs; // Побочная диагональ
        
        if(i > 0){
            arr[i-1][i] /= maxAbs; // Левый сосед с главной диагональю
            arr[i][i-1] /= maxAbs; // Правый сосед с главной диагональю
            arr[i-1][size-i-1] /= maxAbs; // Левый сосед с побочной диагональю
            arr[i][size-i] /= maxAbs; // Правый сосед с побочной диагональю
        }
    }
}

int main(){
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int matrix[MAX_SIZE][MAX_SIZE];
    fillArray(matrix, size);

    printf("Origin matrix:\n");
    printArray(matrix, size);

    int maxAbs = findMaxAbsolute(matrix, size);
    printf("Max module value: %d\n", maxAbs);

    divideDiagonals(matrix, size, maxAbs);

    printf("Final matrix:\n");
    printArray(matrix, size);

    return 0;
}