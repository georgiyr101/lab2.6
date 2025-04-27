#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include "deque.h"
#include "functions.h"

Deque* createDeque() {
	Deque* d = (Deque*)malloc(sizeof(Deque));
    if (!d) {
        perror("Failed to allocate memory for deque");
        exit(EXIT_FAILURE);
    }
    d->front = d->rear = NULL;
    return d;
}

int isDequeEmpty(Deque* d) {
    return d->front == NULL;
}

void pushFront(Deque* d, char data) {
    DequeNode* t = (DequeNode*)malloc(sizeof(DequeNode));
    if (!t) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }

    t->data = data;
    t->prev = NULL;
    t->next = d->front;

    if (isDequeEmpty(d)) {
        d->front = t;
        d->rear = t;
    }

    else {
        d->front->prev = t;
        d->front = t;
    }
}

void pushRear(Deque* d, char data) {
    DequeNode* t = (DequeNode*)malloc(sizeof(DequeNode));
    if (!t) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    t->data = data;
    t->next = NULL;
    t->prev = d->rear;

    if (isDequeEmpty(d)) {
        d->front = t;
        d->rear = t;
    }

    else {
        d->rear->next = t;
        d->rear = t;
    }
}

char popFront(Deque* d) {
    if (isDequeEmpty(d)) {
        puts("Deque is empty.Cannot pop.");
        return;
    }
    DequeNode* t = d->front;
    char data = t->data;
    d->front = d->front->next;
    free(t);

    if (d->front == NULL) {
        d->rear = NULL;
    }
    else {
        d->front->prev = NULL; 
    }
    return data;
}

char popRear(Deque* d) {
    if (isDequeEmpty(d)) {
        puts("Deque is empty.Cannot pop.");
        return;
    }
    DequeNode* t = d->rear;
    char data = t->data;
    d->rear = d->rear->prev;
    free(t);

    if (d->rear == NULL) {
        d->front = NULL;
    }
    else {
        d->rear->next = NULL; 
    }
    return data;
}

void showCharDeque(Deque* d) {
    if (isDequeEmpty(d)) {
        puts("Deque is empty!");
        return;
    }

    printf("Deque contents (front to rear): ");
    DequeNode* current = d->front;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    puts(" ");
}

void freeDeque(Deque* d) {
    DequeNode* current = d->front;
    DequeNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(d);
}

int getDequeSize(Deque* d) {
    int size = 0;
    DequeNode* current = d->front; 
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

