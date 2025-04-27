#pragma once

typedef struct Node {
	char data;
	struct Node* next;
} Node;

typedef struct Queue {
	Node* front;
	Node* rear;
} Queue;




