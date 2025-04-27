#include <stdio.h>
#include "queue.h"
#include "functions.h"


Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        perror("Failed to allocate memory for queue");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void push(Queue* q, char data) {
    Node* t = (Node*)malloc(sizeof(Node));
    if (!t) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    t->data = data;
    t->next = NULL;

    if (isEmpty(q)) {
        q->front = t;
        q->rear = t;
    }

    else {
        q->rear->next = t;
        q->rear = t;
    }
}

char pop(Queue* q) {
    if (isEmpty(q)) {
        puts("Queue is empty. Cannot pop.");
        return 1;
    }

    Node* t = q->front;
    char data = t->data;
    q->front = q->front->next;
    free(t);

    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}

void showCharQueue(Queue* q) {
    if (isEmpty(q)) {
        puts("Queue is empty!");
        return;
    }

    printf("Queue contents: ");
    Node* current = q->front;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    puts(" ");
}

void showIntQueue(Queue* q) {
    if (isEmpty(q)) {
        puts("Queue is empty!");
        return;
    }

    printf("Queue contents: ");
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    puts(" ");
}

void freeQueue(Queue* q) {
    Node* current = q->front;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(q);
}

int getLengthQueue(Queue* q) {
    int length = 0;
    Node* current = q->front;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}






