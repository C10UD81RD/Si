#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_COMPUTERS 100
#define FILENAME "computers.txt"

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
    printf("--------------------------------------------------\n");
    for (int i = 0; i < numComputers; i++) {
        printf("Компьютер %d:\n", i + 1);
        printf("Процессор: %s\n", computers[i].processor);
        printf("Объём оперативной памяти: %d ГБ\n", computers[i].ram);
        printf("Объём жесткого диска: %d ГБ\n", computers[i].hdd);
        printf("Видеоадаптер: %s\n", computers[i].gpu);
        printf("Цена: %.2f\n", computers[i].price);
        printf("Год закупки: %d\n", computers[i].year);
        printf("--------------------------------------------------\n");
    }
}

void saveComputersToFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла %s\n", FILENAME);
        return;
    }

    for (int i = 0; i < numComputers; i++) {
        fprintf(file, "%s %d %d %s %.2f %d\n",
                computers[i].processor, computers[i].ram, computers[i].hdd,
                computers[i].gpu, computers[i].price, computers[i].year);
    }

    fclose(file);
}

void loadComputersFromFile() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Файл %s не найден\n", FILENAME);
        return;
    }

    numComputers = 0;
    Computer computer;

    while (fscanf(file, "%s %d %d %s %f %d\n",
                  computer.processor, &computer.ram, &computer.hdd,
                  computer.gpu, &computer.price, &computer.year) != EOF) {
        computers[numComputers] = computer;
        numComputers++;
    }

    fclose(file);
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    // Загрузка данных из файла при старте программы
    loadComputersFromFile();

    int choice;

    while (1) {
        printf("Меню:\n");
        printf("1. Добавить компьютер\n");
        printf("2. Удалить компьютер\n");
        printf("3. Вывести список компьютеров\n");
        printf("4. Сохранить данные в файл и выйти\n");
        printf("Выберите пункт меню: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addComputer();
                break;
            case 2:
                deleteComputer();
                break;
            case 3:
                displayComputers();
                break;
            case 4:
                // Сохранение данных в файл перед завершением программы
                saveComputersToFile();
                printf("Данные успешно сохранены в файл %s\n", FILENAME);
                return 0;
            default:
                printf("Неверный пункт меню!\n");
        }
    }
}