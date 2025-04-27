#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include "queue.h"
#include "deque.h"

int getIntNumber();

char getChar();

Queue* createQueue();

int isEmpty(Queue* q);

void push(Queue* q, char data);

char pop(Queue* q);

void showCharQueue(Queue* q);

void showIntQueue(Queue* q);

void freeQueue(Queue* q);

int getLengthQueue(Queue* q);

void fillQueueFromKeyboard(Queue* q, int maxSize);

Queue* extractNumbersToQueue(const char* str);

int sumQueue(Queue* q);

char* inputString();

Deque* createDeque();

int isDequeEmpty(Deque* d);

void pushFront(Deque* d, char data);

void pushRear(Deque* d, char data);

char popFront(Deque* d);

char popRear(Deque* d);

void showCharDeque(Deque* d);

void freeQueue(Deque* d);

int getDequeSize(Deque* d);

void fillDequeFromKeyboardAlternating(Deque* d, int maxSize);




