#include"进程调度.h"

//void menu()
//{
//	printf("************************\n");
//	printf("****  1.先来先服务  ****\n");
//	printf("****  2.短作业优先  ****\n");
//	printf("****  3.优先级调度  ****\n");
//	printf("****  4.时间片轮转  ****\n");
//	printf("****  0.退出        ****\n");
//	printf("************************\n");
//}
//
//void Logic()
//{
//	menu();
//	int input;
//	printf("请选择你想使用的进程调度的方式：");
//	scanf("%d", &input);
//	switch (input)
//	{
//	case 0:
//		printf("退出！\n");
//		break;
//	case 1:
//		printf("先来先服务算法模拟:\n");
//		GetInfo();
//		p = head;
//		FCFS();
//		break;
//	case 2:
//		printf("短作业优先算法模拟:\n");
//		GetInfo();
//		p = head;
//		SJF();
//		break;
//	case 3:
//		printf("优先级调度算法模拟:\n");
//		GetInfo();
//		break;
//	case 4:
//		printf("时间片轮转算法模拟:\n");
//		GetInfo();
//		break;
//	default:
//		printf("输入错误！！\n");
//		break;
//	}
//}


int main()
{
	printf("先来先服务算法模拟:\n");
	GetInfo();
	p = head;
	FCFS();
	printf("短作业优先算法模拟:\n");
	GetInfo();
	p = head;
	SJF();
	return 0;
}