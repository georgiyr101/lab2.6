#include <stdio.h>
#include "queue.h"
#include "deque.h"
#include "functions.h"
#include <locale.h>
#include <conio.h>

int main() {

	setlocale(LC_ALL, "russian");
	puts("Введите номер задания:");
	puts("1 - Вводить символы с экрана. В случае совпадения вводимого символа с последним элементом очереди в очередь его не добавлять, а удалять первый элемент.");
	puts("2 - Добавлять символы в дек поочередно справа и слева. В случае совпадения введенного символа с элементом соответствующего конца дека его не добавлять.");
	puts("3 - Введите строку. Проанализировав в программе содержимое строки, выберите из нее числа и занесите в очередь.Выведите содержимое очереди на экран и посчитайте сумму этих чисел.");
	puts("0 - Выход");

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







	

