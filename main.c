#include <stdio.h>
#include "queue.h"
#include "deque.h"
#include "functions.h"
#include <locale.h>
#include <conio.h>

int main() {

	setlocale(LC_ALL, "russian");
	puts("������� ����� �������:");
	puts("1 - ������� ������� � ������. � ������ ���������� ��������� ������� � ��������� ��������� ������� � ������� ��� �� ���������, � ������� ������ �������.");
	puts("2 - ��������� ������� � ��� ���������� ������ � �����. � ������ ���������� ���������� ������� � ��������� ���������������� ����� ���� ��� �� ���������.");
	puts("3 - ������� ������. ��������������� � ��������� ���������� ������, �������� �� ��� ����� � �������� � �������.�������� ���������� ������� �� ����� � ���������� ����� ���� �����.");
	puts("0 - �����");

	while (1) {
		char task = _getch();

		if (task == '1') {
			printf("Enter maximum size of queue: ");
			int maxSize = getIntNumber();
			Queue* q = createQueue();
			fillQueueFromKeyboard(q, maxSize);
			showCharQueue(q);
		}
		else if (task == '2') {
			Deque* d = createDeque();
			printf("Enter maximum size of deque: ");
			int maxSize = getIntNumber();
			fillDequeFromKeyboardAlternating(d, maxSize);
		}
		else if (task == '3') {
			char* input = inputString();

			Queue* q = extractNumbersToQueue(input);
			showIntQueue(q);
			int sum = sumQueue(q);
			printf("Sum: %d\n", sum);

			free(input);
			freeQueue(q);
		}
		else if (task == '0') break;
		puts(" ");
	}
	




	return 0;
}







	

