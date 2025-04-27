#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include "queue.h"
#include "deque.h"
#include "functions.h"

void fillQueueFromKeyboard(Queue* q, int maxSize) {
    if (!q) {
        printf("Error: Queue is not initialized.\n");
        return;
    }

    puts("Enter characters to fill the queue (enter '.' to stop):");
    char ch;

    while (1) {
        printf("Enter char: ");
        ch = getChar();

        if (ch == '.') {
            printf("Finished filling the queue.\n");
            break;
        }

        if (!isEmpty(q) && q->rear != NULL && ch == q->rear->data) {
            pop(q);
        }
        else {
            if (getLengthQueue(q) < maxSize) {
                push(q, ch);
            }
            else {
                printf("Queue is full. Cannot enqueue '%c'.\n", ch);
                break;
            }
        }
        showCharQueue(q);
    }
}

Queue* extractNumbersToQueue(char* str) {
    Queue* numberQueue = createQueue();
    int currentNumber = 0;

    printf("Found numbers in string:\n");

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            currentNumber = currentNumber * 10 + (str[i] - '0');
        }
        else {
            if (currentNumber != 0) {
                push(numberQueue, currentNumber);
                printf("%d ", currentNumber);
                currentNumber = 0;
            }
        }
    }

    if (currentNumber != 0) {
        push(numberQueue, currentNumber);
        printf("%d ", currentNumber);
    }

    printf("\n");
    return numberQueue;
}

int sumQueue(Queue* q) {
    int sum = 0;
    Queue* tempQueue = createQueue();

    while (!isEmpty(q)) {
        int num = pop(q);
        sum += num;
        push(tempQueue, num);
    }

    while (!isEmpty(tempQueue)) {
        push(q, pop(tempQueue));
    }

    freeQueue(tempQueue);
    return sum;
}

void fillDequeFromKeyboardAlternating(Deque* d, int maxSize) {
    if (!d) {
        printf("Error: Deque is not initialized.\n");
        return;
    }

    puts("Enter characters to fill the deque (enter '.' to stop):");
    char ch;
    int leftSide = 1; 

    while (getDequeSize(d) < maxSize) {
        printf("Enter char: ");
        ch = getChar();

        if (ch == '.') {
            printf("Finished filling the deque.\n");
            break;
        }

        if (leftSide) {
            if (!isDequeEmpty(d) && d->front != NULL && ch == d->front->data) {
                printf("Character '%c' matches front. Not adding.\n", ch);
            }
            else {
                pushFront(d, ch);
                printf("Added '%c' to front.\n", ch);
            }
        }
        else {
            if (!isDequeEmpty(d) && d->rear != NULL && ch == d->rear->data) {
                printf("Character '%c' matches rear. Not adding.\n", ch);
            }
            else {
                pushRear(d, ch);
                printf("Added '%c' to rear.\n", ch);
            }
        }

        showCharDeque(d);
        leftSide = !leftSide; 
    }

    if (getDequeSize(d) == maxSize && ch != '.') {
        printf("Deque is full. Further input ignored.\n");
        while (getchar() != '\n') continue;
    }
}



