#define _CRT_SECURE_NO_WARNINGS

#include "调度.h"

void menu()
{
	printf("******************\n");
	printf("****  1.FCFS  ****\n");
	printf("****  2.SJF   ****\n");
	printf("****  3.RR    ****\n");
	printf("****  4.PSA   ****\n");
	printf("******************\n");
}

void Logic()
{
	Queue queue;

	PCB p1 = { 'A' ,0, 4, 0, 0, 0, 0 };
	PCB p2 = { 'B' ,1, 3, 0, 0, 0, 0 };
	PCB p3 = { 'C' ,2, 4, 0, 0, 0, 0 };
	PCB p4 = { 'D' ,3, 2, 0, 0, 0, 0 };
	PCB p5 = { 'E' ,4, 4, 0, 0, 0, 0 };

	PCB pcbs[] = { p1, p2, p3, p4, p5 };
	int size = sizeof(pcbs) / sizeof(pcbs[0]);
	QueueInit(&queue);
	int input = 0;
	menu();
	printf("Please input: ");
	scanf("%d", &input);

	switch (input)
	{
	case 1:
		FCFS(&queue, pcbs, size);
		break;
	case 2:
		SJF(&queue, pcbs, size);
		break;
	case 3:
		RR(&queue, pcbs, size);
		break;
	case 4:
		PSA(&queue, pcbs, size);
		break;
	default:
		printf("输入有误！\n");
		break;
	}
	QueueDestroy(&queue);
}

int main()
{
	Logic();
	return 0;
}