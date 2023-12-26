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
            printf("%d. ���������: %s, ����������� ������: %d ��, ������� ����: %d ��, ������������: %s, ���������: %.2f, ��� �������: %d\n",
                   i, computers[i].processor, computers[i].ram, computers[i].hdd, computers[i].videoAdapter, computers[i].price, computers[i].year);
        }
    }
}

void saveDataToFile() {
    FILE *file = fopen("computers.txt", "w");

    if (file == NULL) {
        printf("������ ��� �������� �����.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %d %s %.2f %d\n", computers[i].processor, computers[i].ram, computers[i].hdd,
                computers[i].videoAdapter, computers[i].price, computers[i].year);
    }

    fclose(file);
}

void loadDataFromFile() {
    FILE *file = fopen("computers.txt", "r");

    if (file == NULL) {
        printf("������ ��� �������� �����.\n");
        return;
    }

    count = 0;
    while (fscanf(file, "%s %d %d %s %f %d\n", computers[count].processor, &computers[count].ram, &computers[count].hdd,
                  computers[count].videoAdapter, &computers[count].price, &computers[count].year) != EOF) {
        count++;
    }

    fclose(file);
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    loadDataFromFile();

    int choice;
    do {
        printf("����:\n");
        printf("1. �������� ���������\n");
        printf("2. ������� ���������\n");
        printf("3. �������� ��� ����������\n");
        printf("4. �������� ���������� ����������\n");
        printf("5. �����\n");
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
                showAllComputers();
                break;
            case 4:
                outdatedComputers();
                break;
            case 5:
                saveDataToFile();
                break;
            default:
                printf("�������� ����� ����.\n");
        }
    } while (choice != 5);

    return 0;
}
