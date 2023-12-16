#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand () % 101 - 50;
}
void max(int max1, int max2, int max3, int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] >= a[i+1]){
          max1 = a[i];
          max2 = a[i+1];
        }
        else if (a[i+1] >= a[i]){
          max1 = a[i+1];
          max2 = a[i];
        }
        else
}
int main()
{
    srand(time(NULL));
    int n;
    printf("n -> ");
    scanf("%d", &n);
    int A[n];
    fill(n, A);
    int i;
    for (i = 0; i < n; i++)
        printf("%4d", A[i]);
    printf("\n");
    return 0;
}
