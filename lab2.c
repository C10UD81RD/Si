#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand () % 101 - 50;
}
void max(int i, int max1_num, int max2_num, int max3_num, int n, int a[])
{
  int max1 = a[0];
  int max2 = a[0];
  int max3 = a[0];
  for (i=0; i<=n-1; i++) {
     if (a[i]>=max1) {
        max1=a[i];
        max1_num=i;
     }
  }
  for (i=0; i<=n-1; i++) {
      if (i!=max1_num && a[i]>=max2) {
       max2=a[i];
       max2_num=i;
    }
  }
  for (i=0; i<=n-1; i++) {
      if (i!=max2_num && a[i]>=max3) {
       max3=a[i];
       max3_num=i;
    }
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
    printf("%d max1 [%d]\n%d max2 [%d]\n%d max3 [%d]\n", max1, max1_num, max2, max2_num, max3_num);
    return 0;
}

// int main()
// {
//     int i, max1_num, max2_num, max3_num;
//     srand(time(NULL));
//     int A[n];
//     printf("n -> ");
//     scanf("%d", &n);
//
//     int max1 = A[0];
//     int max2 = A[0];
//     for (i=0; i<=N-1; i++) {
//        if (A[i]>=max1) {
//           max1=A[i];
//           max1_num=i;
//        }
//     }
//     for (i=0; i<=N-1; i++) {
//         if (i!=max1_num && A[i]>=max2) {
//          max2=A[i];
//          max2_num=i;
//       }
//    }
// printf("%d max1 [%d]\n%d max2 [%d]\n%d max3 [%d]\n", max1, max1_num, max2, max2_num, max3_num);
//
//     getchar();
//     return 0;
// }
