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
        printf("������������ ���������� ����������� ����������!\n");
        return;
    }

    Computer newComputer;

    printf("������� ���������� � ����������:\n");

    printf("���������: ");
    scanf("%s", newComputer.processor);

    printf("����� ����������� ������ (� ��): ");
    scanf("%d", &newComputer.ram);

    printf("����� �������� ����� (� ��): ");
    scanf("%d", &newComputer.hdd);

    printf("������������: ");
    scanf("%s", newComputer.gpu);

    printf("����: ");
    scanf("%f", &newComputer.price);

    printf("��� �������: ");
    scanf("%d", &newComputer.year);

    computers[numComputers] = newComputer;
    numComputers++;

    printf("��������� ������� ��������!\n");
}

void deleteComputer() {
    int index;

    printf("������� ����� ����������, ������� ������ �������: ");
    scanf("%d", &index);

    if (index >= numComputers || index < 0) {
        printf("�������� ����� ����������!\n");
        return;
    }

    for (int i = index; i < numComputers - 1; i++) {
        computers[i] = computers[i + 1];
    }

    numComputers--;

    printf("��������� ������� ������!\n");
}

void displayComputers() {
    if (numComputers == 0) {
        printf("������ ����������� ����!\n");
        return;
    }

    printf("������ �����������:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < numComputers; i++) {
        printf("��������� %d:\n", i + 1);
        printf("���������: %s\n", computers[i].processor);
        printf("����� ����������� ������: %d ��\n", computers[i].ram);
        printf("����� �������� �����: %d ��\n", computers[i].hdd);
        printf("������������: %s\n", computers[i].gpu);
        printf("����: %.2f\n", computers[i].price);
        printf("��� �������: %d\n", computers[i].year);
        printf("--------------------------------------------------\n");
    }
}

void saveComputersToFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("������ ��� �������� ����� %s\n", FILENAME);
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
        printf("���� %s �� ������\n", FILENAME);
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
    // �������� ������ �� ����� ��� ������ ���������
    loadComputersFromFile();

    int choice;

    while (1) {
        printf("����:\n");
        printf("1. �������� ���������\n");
        printf("2. ������� ���������\n");
        printf("3. ������� ������ �����������\n");
        printf("4. ��������� ������ � ���� � �����\n");
        printf("�������� ����� ����: ");
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
                // ���������� ������ � ���� ����� ����������� ���������
                saveComputersToFile();
                printf("������ ������� ��������� � ���� %s\n", FILENAME);
                return 0;
            default:
                printf("�������� ����� ����!\n");
        }
    }
}