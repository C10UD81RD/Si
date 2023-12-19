#include <stdio.h>
#include <locale.h>

// ������� ��� ������ ���� ����� �������
void swapRows(double matrix[][100], int row1, int row2, int cols) {
    for (int i = 0; i < cols; ++i) {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

// ������� ��� ������ �������
void printMatrix(double matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ������� ��� ���������� ������� � ������������ ����
void reduceToRowEchelonForm(double matrix[][100], int rows, int cols) {
    int lead = 0;
    for (int r = 0; r < rows; ++r) {
        if (cols <= lead)
            return;

        int i = r;
        while (matrix[i][lead] == 0) {
            ++i;
            if (rows == i) {
                i = r;
                ++lead;
                if (cols == lead)
                    return;
            }
        }

        swapRows(matrix, i, r, cols);

        double div = matrix[r][lead];
        for (int j = 0; j < cols; ++j)
            matrix[r][j] /= div;

        for (int k = 0; k < rows; ++k) {
            if (k != r) {
                double mult = matrix[k][lead];
                for (int j = 0; j < cols; ++j)
                    matrix[k][j] -= mult * matrix[r][j];
            }
        }

        ++lead;
    }
}

int main() {
    setlocale(LC_ALL, "");
    int rows, cols;
    printf("������� ���������� ����� �������: ");
    scanf("%d", &rows);

    printf("������� ���������� �������� �������: ");
    scanf("%d", &cols);

    double matrix[100][100];
    printf("������� �������� �������:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("�������� �������:\n");
    printMatrix(matrix, rows, cols);

    reduceToRowEchelonForm(matrix, rows, cols);

    printf("������� � ����������� ����:\n");
    printMatrix(matrix, rows, cols);

    return 0;
}
