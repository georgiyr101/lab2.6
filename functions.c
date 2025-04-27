#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include "queue.h"
#include "functions.h"

int getIntNumber()
{
    int n;
    while (1) {
        if (scanf_s("%d", &n) != 0) {
            if ((getchar()) != '\n' || n > INT_MAX || n < INT_MIN) {
                printf("Error: enter the correct number!\n");
                while ((getchar()) != '\n')
                    continue;
            }
            else {
                break;
            }
        }
        else {
            printf("Error: enter the correct number!\n");
            while ((getchar()) != '\n')
                continue;
        }
    }
    return n;
}

char getChar() {
    char c;
    int result;
    while (1) {
        result = scanf_s("%c", &c); 
        if (result == 1) {
            if (getchar() == '\n') { 
                break;
            }
            else {
                printf("Error: enter only one character!\n");
                while (getchar() != '\n')
                    continue;
            }
        }
        else {
            printf("Error: invalid input. Please enter a character.\n");
            while (getchar() != '\n')
                continue;
        }
    }
    return c;
}

char* inputString() {
    char buffer[100];
    printf("Enter string: ");
    gets(buffer);

    int length = 0;
    while (buffer[length] != '\0') {
        length++;
    }

    char* str = (char*)malloc((length + 1) * sizeof(char));
    if (str == NULL) {
        puts("Ошибка выделения памяти!");
        return 0;
    }

    for (int i = 0; i <= length; i++) {
        str[i] = buffer[i];
    }
    return str;
}



