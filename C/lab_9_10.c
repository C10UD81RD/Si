#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_STR_LENGTH 1000

// Функция, которая проверяет, является ли символ буквой английского алфавита
int isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Функция, которая удаляет слова с наиболее часто повторяющейся длиной из строки
void removeMostFrequentLengthWords(char *str) {
    char words[MAX_STR_LENGTH][MAX_WORD_LENGTH];
    int count[MAX_STR_LENGTH] = {0};
    int len = strlen(str);
    int wordCount = 0;

    // Разделение строки на слова
    int i = 0;
    while (i < len) {
        // Пропуск пробелов и символов пунктуации
        while (i < len && !isLetter(str[i])) {
            i++;
        }

        // Формирование слова
        int j = 0;
        while (i < len && isLetter(str[i])) {
            words[wordCount][j++] = str[i++];
        }
        words[wordCount][j] = '\0';

        count[j - 1]++; // Увеличение счетчика для длины текущего слова
        wordCount++;
    }

    // Поиск наиболее часто повторяющейся длины слова
    int maxCountLength = 0;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (count[i] > count[maxCountLength]) {
            maxCountLength = i;
        }
    }

    // Вывод слов, кроме тех, чья длина наиболее часто повторяется
    for (i = 0; i < wordCount; i++) {
        if (strlen(words[i]) != maxCountLength + 1) {
            printf("%s ", words[i]);
        }
    }
    printf("\n");
}

int main() {
    char str[MAX_STR_LENGTH];
    printf("Enter text: ");
    fgets(str, sizeof(str), stdin);

    // Удаление символа новой строки, если присутствует
    int newline = strlen(str) - 1;
    if (str[newline] == '\n') {
        str[newline] = '\0';
    }

    removeMostFrequentLengthWords(str);

    return 0;
}