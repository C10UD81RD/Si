#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPUTERS 100

typedef struct {
    char processor[50];
    int ram;
    int hdd;
    char gpu[50];
    float price;
    int year;
} Computer;

Computer computers[MAX_COMPUTERS];
int numComputers = 0;

void addComputer() {
    if (numComputers >= MAX_COMPUTERS) {
        printf("Максимальное количество компьютеров достигнуто!\n");
        return;
    }

    Computer newComputer;

    printf("Введите информацию о компьютере:\n");

    printf("Процессор: ");
    scanf("%s", newComputer.processor);

    printf("Объём оперативной памяти (в ГБ): ");
    scanf("%d", &newComputer.ram);

    printf("Объём жесткого диска (в ГБ): ");
    scanf("%d", &newComputer.hdd);

    printf("Видеоадаптер: ");
    scanf("%s", newComputer.gpu);

    printf("Цена: ");
    scanf("%f", &newComputer.price);

    printf("Год закупки: ");
    scanf("%d", &newComputer.year);

    computers[numComputers] = newComputer;
    numComputers++;

    printf("Компьютер успешно добавлен!\n");
}

void deleteComputer() {
    int index;

    printf("Введите номер компьютера, который хотите удалить: ");
    scanf("%d", &index);

    if (index >= numComputers || index < 0) {
        printf("Неверный номер компьютера!\n");
        return;
    }

    for (int i = index; i < numComputers - 1; i++) {
        computers[i] = computers[i + 1];
    }

    numComputers--;

    printf("Компьютер успешно удален!\n");
}

void displayComputers() {
    if (numComputers == 0) {
        printf("Список компьютеров пуст!\n");
        return;
    }

    printf("Список компьютеров:\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("  No   |   Процессор   |  RAM (ГБ)  |   HDD (ГБ)   |   HDD (ГБ)   |  Год закупки   \n");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < numComputers; i++) {
        printf("  %-3d  | %-13s | %-10d | %-12d | %d\n", i, computers[i].processor, computers[i].ram, computers[i].hdd, computers[i].price, computers[i].year);
    }

    printf("-----------------------------------------------------------------------------------\n");
}

void checkForUpdate() {
    printf("Компьютеры, требующие обновления:\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("  No   |   Процессор   |  RAM (ГБ)  |   HDD (ГБ)   |   HDD (ГБ)   |  Год закупки   \n");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < numComputers; i++) {
        if (computers[i].year < 2018) {
            printf("  %-3d  | %-13s | %-10d | %-12d | %d\n", i, computers[i].processor, computers[i].ram, computers[i].hdd, computers[i].price, computers[i].year);
        }
    }

    printf("-----------------------------------------------------------------------------------\n");
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    int choice;

    while (1) {
        printf("Меню:\n");
        printf("1. Просмотреть все компьютеры\n");
        printf("2. Добавить компьютер\n");
        printf("3. Удалить компьютер\n");
        printf("4. Проверить компьютеры на обновление\n");
        printf("5. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayComputers();
                break;
            case 2:
                addComputer();
                break;
            case 3:
                deleteComputer();
                break;
            case 4:
                checkForUpdate();
                break;
            case 5:
                exit(0);
            default:
                printf("Неверный выбор, попробуйте еще раз!\n");
        }
    }
    return 0;
}
