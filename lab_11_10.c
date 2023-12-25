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
    printf("-----------------------------------------------------------------------------------\n");
    printf("  No   |   ���������   |  RAM (��)  |   HDD (��)   |   HDD (��)   |  ��� �������   \n");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < numComputers; i++) {
        printf("  %-3d  | %-13s | %-10d | %-12d | %d\n", i, computers[i].processor, computers[i].ram, computers[i].hdd, computers[i].price, computers[i].year);
    }

    printf("-----------------------------------------------------------------------------------\n");
}

void checkForUpdate() {
    printf("����������, ��������� ����������:\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("  No   |   ���������   |  RAM (��)  |   HDD (��)   |   HDD (��)   |  ��� �������   \n");
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
        printf("����:\n");
        printf("1. ����������� ��� ����������\n");
        printf("2. �������� ���������\n");
        printf("3. ������� ���������\n");
        printf("4. ��������� ���������� �� ����������\n");
        printf("5. �����\n");
        printf("�������� ��������: ");
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
                printf("�������� �����, ���������� ��� ���!\n");
        }
    }
    return 0;
}
