#pragma once
//#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<stdlib.h>

typedef struct PCB      //定义进程控制块
{					     
	char name[10];        //进程名
	char state;           //进程状态
	int ArriveTime;       //进程到达时间
	int StartTime;        //进程开始时间
	int FinishTime;       //进程完成时间
	int ServiceTime;       //服务时间
	float WholeTime;       //周转时间
	float WeightWholeTime; //带权周转时间
	double AverageWT;    //平均带权周转时间
	double AverageWWT;   //带权平均周转时间
	struct PCB *next;    //指向下一个进程
}pcb;

double x = 0;
double y = 0;
int i;
int n = 0;   //进程数目
pcb *head = NULL;//进程链表指针
pcb *p = NULL;
pcb *q = NULL;

void FCFS()
{
	p = head;
	printf("作业名 到达时间 开始时间 服务时间 完成时间 周转时间 带权周转时间 平均周转时间 平均带全周转时间\n");
	printf("----------------------------------------------------------------------------------------------\n");
	for (int i = 0; i<n; i++)
	{
		if (p->state == 'F')
		{
			q = p;  //标记当前未完成的进程
			Run_FCFS(q);
		}
		p = p->next;
	}
}

void Run_FCFS(pcb *p1)   //运行未完成的进程
{
	int time = 0;		 //计时器
	time = p1->ArriveTime> time  ? p1->ArriveTime : time;
	p1->StartTime = time;
	time += p1->ServiceTime;
	p1->state = 'T';
	p1->FinishTime = time;
	p1->WholeTime = p1->FinishTime - p1->ArriveTime;
	p1->WeightWholeTime = p1->WholeTime / p1->ServiceTime;
	x += p1->WholeTime;
	y += p1->WeightWholeTime;
	p1->AverageWT = p1->WholeTime / n;
	p1->AverageWWT = p1->WeightWholeTime / n;
	printf("%4s %6d %8d %8d %8d %9.2f %10.2f %12.2f %12.2f\n",
		p1->name, p1->ArriveTime, p1->StartTime, p1->ServiceTime, p1->FinishTime,
		p1->WholeTime, p1->WeightWholeTime, p1->AverageWT, p1->AverageWWT);
}


void GetInfo()
{
	int time = 0;
	printf("进程个数:");
	scanf("%d", &n);
	for (int num = 0; num < n; num++)
	{
		p = (pcb *)malloc(sizeof(pcb));
		printf("进程名  到达时间  服务时间\n");
		scanf("%s%d%d", &p->name, &p->ArriveTime, &p->ServiceTime);
		if (head == NULL)
		{
			head = p;
			q = p;
			time = p->ArriveTime;
		}
		if (p->ArriveTime < time)
		{
			time = p->ArriveTime;
		}
		q->next = p;

		p->StartTime = 0;
		p->FinishTime = 0;
		p->WholeTime = 0;
		p->WeightWholeTime = 0;
		p->next = NULL;
		p->state = 'F';
		q = p;
	}
}