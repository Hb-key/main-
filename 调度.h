#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct PCB {
	char name;               //进程名
	int ArrivalTime;	     //进程状态
	int ServiceTime;     	 //进程到达时间
	int StartTime;		    //进程开始时间
	int FinishTime;		    //进程完成时间
	int WholeTime;          //周转时间
	int weightWholeTime;    //带权周转时间
}PCB;

typedef PCB DataType;
typedef struct Node {
	DataType data;
	struct Node *next;
}Node;

typedef struct Queue {
	Node *front;
	Node *rear;
	int size;			//队列中的元素个数
}Queue;


void QueueInit(Queue *pqueue) //初始化
{			
	assert(pqueue != NULL);
	pqueue->front = NULL;
	pqueue->rear = NULL;
	pqueue->size = 0;
}

//销毁
void QueueDestroy(Queue *pqueue)
{
	Node *cur = NULL;
	Node *del = NULL;
	assert(pqueue != NULL);
	if (pqueue->front == NULL)
	{
		return;
	}
	cur = pqueue->front;
	while (cur != NULL)
	{
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
}

Node *CreatNode(DataType data)
{
	Node *ret = (Node *)malloc(sizeof(Node));
	if (ret == NULL) 
	{
		exit(0);
	}
	ret->data = data;
	ret->next = NULL;
	return ret;
}

void QueuePush(Queue *pqueue, DataType data)
{
	assert(pqueue != NULL);
	Node *temp = CreatNode(data);
	if (pqueue->front == NULL)
	{
		pqueue->front = temp;
		pqueue->rear = temp;
		pqueue->size++;
	}
	else 
	{
		pqueue->rear->next = temp;
		pqueue->rear = pqueue->rear->next;
		pqueue->size++;
	}
}

void QueuePop(Queue *pqueue)
{
	assert(pqueue != NULL);
	Node *del = NULL;
	assert(pqueue != NULL);
	if (pqueue->front == NULL) 
	{
		return;
	}
	del = pqueue->front;
	pqueue->front = pqueue->front->next;
	free(del);
	del = NULL;
	pqueue->size--;
}

Node *QueueTop(Queue *pqueue)
{
	return pqueue->front;
}

bool QueueEmpty(const Queue *pqueue)
{
	return pqueue->front == NULL;
}

int getPcb(PCB pcbs[], int size, int time)
{
	for (int i = 0; i < size; i++)
	{
		if (time == pcbs[i].ArrivalTime)
		{
			return i;
		}
	}
	return -1;
}

void FCFS(Queue *pqueue, PCB pcbs[], int size)
{
	int pcbid = 0;
	int curPcbServiceTime = 0;
	Node *cur = NULL;
	int time = 0;

	while (1)
	{
		//等待进程
		if ((pcbid = getPcb(pcbs, size, time)) == -1 && QueueEmpty(pqueue))
		{
			printf("进程执行完毕！\n");
			break;
		}
		printf("time is %d \n", time);
		if (pcbid != -1)
		{
			QueuePush(pqueue, pcbs[pcbid]);
		}
		//执行进程
		if (curPcbServiceTime == 0)
		{
			if (time != 0)
			{
				printf("PCB %c finish time is %d\n", QueueTop(pqueue)->data.name, time);
				QueuePop(pqueue);
			}
			if (!QueueEmpty(pqueue))
			{
				curPcbServiceTime = QueueTop(pqueue)->data.ServiceTime;
			}
		}
		curPcbServiceTime--;
		time++;
	}
}

void RR(Queue *pqueue, PCB pcbs[], int size)
{
	//时间片的大小
	int q = 2;
	//当前时间片的剩余时间
	int lessq = 0;
	int pcbid = 0;

	//表示本进程还需要的服务时间
	int curPcbServiceTime = 0;
	Node *cur = NULL;
	int time = 0;

	while (1)//等待进程
	{

		if ((pcbid = getPcb(pcbs, size, time)) == -1 && QueueEmpty(pqueue))
		{
			printf("进程执行完毕！\n");
			break;
		}
		printf("Time is %d \n", time);
		if (pcbid != -1)
		{
			QueuePush(pqueue, pcbs[pcbid]);
		}
		//执行进程
		if (lessq == 0)
		{
			if (curPcbServiceTime == 0)
			{
				if (time != 0)
				{
					printf("PCB %c finish time is %d\n", QueueTop(pqueue)->data.name, time);
					QueuePop(pqueue);
				}
			}
			else
			{
				QueueTop(pqueue)->data.ServiceTime = curPcbServiceTime;
				pqueue->rear->next = pqueue->front;
				pqueue->rear = pqueue->rear->next;
				pqueue->front = pqueue->front->next;
				pqueue->rear->next = NULL;
			}
			if (!QueueEmpty(pqueue))
			{
				curPcbServiceTime = QueueTop(pqueue)->data.ServiceTime;
			}
			lessq = 2;
		}
		else
		{
			if (curPcbServiceTime == 0)
			{
				printf("PCB %c finish time is %d\n", QueueTop(pqueue)->data.name, time);
				QueuePop(pqueue);
				if (!QueueEmpty(pqueue))
				{
					curPcbServiceTime = QueueTop(pqueue)->data.ServiceTime;
					lessq = 2;
				}
			}
		}
		lessq--;
		curPcbServiceTime--;
		time++;
	}
}

void SJF(Queue *pqueue, PCB pcbs[], int size)
{
	int i = 0, j = 0;
	int time = 0;
	int pcb_id = 0;
	int minTime = 0;	// 最短运行时间

	QueuePush(pqueue, pcbs[pcb_id]);
	while (1)
	{
		if (time == 0)
		{
			printf("PCB %c finish time is %d\n", QueueTop(pqueue)->data.name, time);
			QueuePop(pqueue);
		}
		else
		{
			if (!QueueEmpty(pqueue))
			{
				for (i = (QueueTop(pqueue));; i++)
				{
					for (j = (QueueTop(pqueue) + 1);; j++)
					{

					}
				}
			}
		}
		time += QueueTop(pqueue)->data.ServiceTime;
	}
}

void PSA(Queue *pqueue, PCB pcbs[], int size)
{
	int i = 0;
	int j = 0;
	int time = 0;
	int pcb_id = 0;
	int PriorityTime = 0;		//优先级		
	QueuePush(pqueue, pcbs[pcb_id]);
	while (1)
	{
		if (time == 0)
		{
			printf("PCB %c finish time is %d\n", QueueTop(pqueue)->data.name, time);
			QueuePop(pqueue);
		}
		else
		{
			if (!QueueEmpty(pqueue))
			{
				for (i = (QueueTop(pqueue));; i++)
				{
					for (j = (QueueTop(pqueue) + 1);; j++)
					{

					}
				}
			}
		}
		time += QueueTop(pqueue)->data.ServiceTime;
	}
}
