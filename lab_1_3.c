#include <math.h>
#include <stdio.h>
int main()
{
    int a, b, c, x, min, sum, result;
    printf("Enter a -> ");
    scanf("%d", &a);
    printf("Enter b -> ");
    scanf("%d", &b);
    printf("Enter c -> ");
    scanf("%d", &c);
    printf("Enter x -> ");
    scanf("%d", &x);
    //нахождение минимального числа
    if ((a >= b) && (b >= c)) {
      min = c;
      sum = a + b;
    } else if ((b <= c) && (b <= a)) {
      min = b;
      sum = a + c;
    } else {
      min = a;
      sum = b + c;
    }
    printf("Minimim = %d\n", min);
    if ((min < x) && (min % 7 == 0))
    {
      printf("Result -> %d", min);
    }
    else
    {
      result = sum / min;
      printf("Result -> %d", result);
    }
    return 0;
}
