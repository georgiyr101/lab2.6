#pragma once

typedef struct DequeNode {
	char data;
	struct DequeNode* next;
	struct DequeNode* prev;
} DequeNode;

typedef struct Deque {
	DequeNode* front;
	DequeNode* rear;
} Deque;