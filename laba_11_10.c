#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Computer {
    char processor[100];
    int ram;
    int hdd;
    char videoAdapter[100];
    float price;
    int year;
};

struct Computer computers[100];
int count = 0;

void addComputer() {
    printf("������� ������ � ����������: \n");
    printf("���������: ");
    scanf("%s", computers[count].processor);
    printf("����������� ������ (� ��): ");
    scanf("%d", &computers[count].ram);
    printf("������� ���� (� ��): ");
    scanf("%d", &computers[count].hdd);
    printf("������������: ");
    scanf("%s", computers[count].videoAdapter);
    printf("���������: ");
    scanf("%f", &computers[count].price);
    printf("��� �������: ");
    scanf("%d", &computers[count].year);

    count++;
}

void deleteComputer() {
    int index;

    printf("������� ������ ����������, ������� ������ �������: ");
    scanf("%d", &index);

    if (index >= 0 && index < count) {
        for (int i = index; i < count - 1; i++) {
            computers[i] = computers[i + 1];
        }
        count--;
        printf("��������� ������� ������.\n");
    } else {
        printf("�������� ������ ����������.\n");
    }
}

void showAllComputers() {
    printf("������ �����������: \n");

    for (int i = 0; i < count; i++) {
        printf("%d. ���������: %s, ����������� ������: %d ��, ������� ����: %d ��, ������������: %s, ���������: %.2f, ��� �������: %d\n",
               i, computers[i].processor, computers[i].ram, computers[i].hdd, computers[i].videoAdapter, computers[i].price, computers[i].year);
    }
}

void outdatedComputers() {
    printf("������ �����������, ��������� ����������:\n");

    for (int i = 0; i < count; i++) {
        if (computers[i].year < 2018) {
            printf("���������: %s, ����������� ������: %d ��, ������� ����: %d ��, ������������: %s, ���������: %.2f, ��� �������: %d\n",
                   computers[i].processor, computers[i].ram, computers[i].hdd, computers[i].videoAdapter, computers[i].price, computers[i].year);
        }
    }
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    int choice;

    do {
        printf("\n");
        printf("1. ����������� ������ �����������\n");
        printf("2. �������� ���������\n");
        printf("3. ������� ���������\n");
        printf("4. �������� ������ � �����������, ��������� ����������\n");
        printf("0. �����\n");
        printf("\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showAllComputers();
                break;
            case 2:
                addComputer();
                break;
            case 3:
                deleteComputer();
                break;
            case 4:
                outdatedComputers();
                break;
            case 0:
                printf("��������� ���������.\n");
                break;
            default:
                printf("�������� �����.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
