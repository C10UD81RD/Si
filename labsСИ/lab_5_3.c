#include <stdio.h>
#include <stdbool.h>
// функция проверяет - простое ли число n
bool isPrime(unsigned int n)
{
    // если n > 1
    if (n > 1)
    {
        // в цикле перебираем числа от 2 до n - 1
        for (int i = 2; i < n; i++)
            if (n % i == 0) // если n делится без остатка на i - возвращаем false (число не простое)
                return false;
        // если программа дошла до данного оператора, то возвращаем true (число простое) - проверка пройдена
        return true;
    }
    else // иначе возвращаем false (число не простое)
        return false;
}
int main()
{
    // в данной переменной будем хранить число, которое необходимо проверить на простоту
    int n;
    // вывод текста в консоль
    printf("Input a number: ");
    // читаем число n
    scanf_s("%d", &n);
    // выводим информацию о том, простое ли число n: 1 - да, 0 - нет
    printf("Is prime: %d\n", isPrime(n));
}
