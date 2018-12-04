#pragma once
#define _CRT_SECURE_NO_WARNINGS 

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


void Run_FCFS(pcb *p1)   //运行未完成的进程
{
	int time = 0;		 //计时器
	time = p1->ArriveTime> time ? p1->ArriveTime : time;
	p1->StartTime = time;
	time += p1->ServiceTime;
	p1->state = 'T';
	p1->FinishTime = time;

	p1->WholeTime = (float)p1->FinishTime - (float)p1->ArriveTime;
	p1->WeightWholeTime = p1->WholeTime / p1->ServiceTime;
	x += p1->WholeTime;
	y += p1->WeightWholeTime;
	p1->AverageWT = p1->WholeTime / n;
	p1->AverageWWT = p1->WeightWholeTime / n;

	printf("%4s %6d %8d %8d %8d %9.2f %10.2f %12.2f %12.2f\n",
		p1->name, p1->ArriveTime, p1->StartTime, p1->ServiceTime, p1->FinishTime,
		p1->WholeTime, p1->WeightWholeTime, p1->AverageWT, p1->AverageWWT);
}
void FCFS()
{
	printf("作业名 到达时间 开始时间 服务时间 完成时间 周转时间 带权周转时间 平均周转时间 平均带权周转时间\n");
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


void Psort(pcb *p2, int N)
{
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < i; j++)
		{
			if (p2[i].ArriveTime < p2[j].ArriveTime)
			{
				pcb Temp = p2[i];
				p2[i] = p2[j];
				p2[j] = Temp;
			}
		}
	}
	
	for (int k = 0; k < N - 1; k++)
	{
		if (k == 0)
		{
			p2[k].StartTime = p2[k].ArriveTime;
			p2[k].FinishTime = p2[k].ArriveTime + p2[k].ServiceTime;
		}
		else
		{
			p2[k].StartTime = p2[k - 1].FinishTime;
			p2[k].FinishTime = p2[k].StartTime + p2[k].ServiceTime;
		}
		//选择最短作业执行
		int m = 0;
		for (int t = k + 1; t <= N - 1; t++)
		{
			if (p2[t].ArriveTime <= p2[k].FinishTime)
				m++;
		}
		float min = p2[k + 1].ServiceTime;
		int next = k + 1;
		for (int q = k + 1; q < k + m; q++)
		{
			if (p2[q + 1].ServiceTime < min)
			{
				min = p2[q + 1].ServiceTime;
				next = q + 1;
			}
			pcb Temp = p2[k + 1];
			p2[k + 1] = p2[next];
			p2[next] = Temp;
		}
	}
}
void Pdeal(pcb *p2, float ArriveTime, float ServiceTime, float StartTime, 
	float FinishTime, float &WholeTime, float&WeightWholeTime, int N)
{
	for (int k = 0; k < N; k++)
	{
		if (k == 0)
		{
			p[k].StartTime = p[k].ArriveTime;
			p[k].FinishTime = p[k].ArriveTime + p[k].ServiceTime;
		}
		else
		{
			p[k].StartTime = p[k - 1].FinishTime
				p[k].FinishTime = p[k].StartTime + p[k].ServiceTime;
		}
	}
	for (int k = 0; k<N; k++)
	{
		p[k].WholeTime = p[k].FinishTime - p[k].ArriveTime;
		p[k].WeightWholeTime = p[k].WholeTime / p[k].ServiceTime;
	}

}
void SJF(pcb *p2, int N)
{
	Psort(p2, N);
	Pdeal(p2, ArriveTime, ServiceTime, StartTime, FinishTime, WholeTime, WeightWholeTime, N);
	Poutput(p2, N);
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

//ABC　０１５　３１２
//ABC　００３　２２２