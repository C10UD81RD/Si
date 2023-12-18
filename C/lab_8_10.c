#include <stdio.h>
#include <conio.h>

int main() {
    printf("Enter text (Press F8 to stop):\n");

    while (1) {
        int ch = getch();

        if (ch == 0) {
            ch = getch();

            if (ch == 63) {
                break;
            }
        } else {
            if (ch >= 'a' && ch <= 'z') {
                ch -= ('a' - 'A');
            }

            putchar(ch);
        }
    }

    printf("\n");

    return 0;
}