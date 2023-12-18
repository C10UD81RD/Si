#include <stdio.h>
#include <stdlib.h>

void fail()
{
    printf("Memory allocation failed\n");
    exit(1);
}

int main()
{
    int n, m;
    printf("Enter size of matrix: ");
    scanf("%d %d", &n, &m);

    int **a = (int **)malloc(n * sizeof(int *));
    if (!a)
        fail();

    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
        if (!a[i])
            fail();
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = i * m + j + 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}