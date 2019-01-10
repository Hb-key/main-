#include<stdio.h>
#include<stdlib.h>
#define SIZE 640          // 内存初始大小
#define MINSIZE 5         // 碎片最小值
enum STATE { Free, Busy };

struct subAreaNode {
	intaddr;             // 起始地址
	intsize;             // 分区大小
	inttaskId;            //作业号
	STATEstate;           //分区状态
	subAreaNode *pre;      // 分区前向指针
	subAreaNode *nxt;      // 分区后向指针
}subHead;

// 初始化空闲分区链
void intSubArea()
{
	subAreaNode *fir = (subAreaNode*)malloc(sizeof(subAreaNode));
	fir->addr = 0;
	fir->size = SIZE;
	fir->state = Free;
	fir->taskId = -1;
	fir->pre = &subHead;
	fir->nxt = NULL;
	subHead.pre = NULL;
	subHead.nxt = fir;
}

// 首次适应算法
int firstFit(int taskId, int size)
{
	subAreaNode *p = subHead.nxt;
	while (p != NULL)
	{
		if (p->state == Free && p->size >= size) {
			if (p->size - size <= MINSIZE) {
				p->state = Busy;
				p->taskId = taskId;
			}
			else {
				subAreaNode *node = (subAreaNode*)malloc(sizeof(subAreaNode));
				node->addr = p->addr + size;
				node->size = p->size - size;
				node->state = Free;
				node->taskId = -1;  //修改分区链节点指针
				node->pre = p;
				node->nxt = p->nxt;
				if (p->nxt != NULL) {
					p->nxt->pre = node;
				}
				p->nxt = node;	//分配空闲区间
				p->size = size;
				p->state = Busy;
				p->taskId = taskId;
			}
			printf("内存分配成功！n");
			return 1;
		}
		p = p->nxt;
	}
	printf("找不到合适的内存分区，分配失败...n");
	return0;
}

// 最佳适应算法
int bestFit(int taskId, int size)
{
	subAreaNode *tar = NULL;
	inttarSize = SIZE + 1;
	subAreaNode *p = subHead.nxt;
	while (p != NULL)
	{
		if (p->state == Free && p->size >= size && p->size < tarSize) {
			tar = p;
			tarSize = p->size;
		}
		p = p->nxt;
	}
	if (tar != NULL) {
		if (tar->size - size <= MINSIZE) {
			tar->state = Busy;
			tar->taskId = taskId;
		}
		else {
			subAreaNode *node = (subAreaNode*)malloc(sizeof(subAreaNode));
			node->addr = tar->addr + size;
			node->size = tar->size - size;
			node->state = Free;
			node->taskId = -1;
			node->pre = tar;
			node->nxt = tar->nxt;
			if (tar->nxt != NULL) {
				tar->nxt->pre = node;
			}
			tar->nxt = node;
			tar->size = size;
			tar->state = Busy;
			tar->taskId = taskId;
		}
		printf("内存分配成功！n");
		return 1;
	}
	else {
		printf("找不到合适的内存分区，分配失败...n");
		return 0;
	}
}

// 回收内存
int freeSubArea(int taskId)
{
	intflag = 0;
	subAreaNode *p = subHead.nxt, *pp;
	while (p != NULL)
	{
		if (p->state == Busy && p->taskId == taskId) {
			flag = 1;
			if ((p->pre != &subHead &&p->pre->state == Free)
				&& (p->nxt != NULL && p->nxt->state == Free)) {
				//情况1：合并上下两个分区
				//先合并上区间
				pp = p;
				p = p->pre;
				p->size += pp->size;
				p->nxt = pp->nxt;
				pp->nxt->pre = p;
				free(pp);
				//后合并下区间
				pp = p->nxt;
				p->size += pp->size;
				p->nxt = pp->nxt;
				if (pp->nxt != NULL) {
					pp->nxt->pre = p;
				}
				free(pp);
			}
			else if ((p->pre == &subHead || p->pre->state == Busy)
				&& (p->nxt != NULL && p->nxt->state == Free)) {
				//情况2：只合并下面的分区
				pp = p->nxt;
				p->size += pp->size;
				p->state = Free;
				p->taskId = -1;
				p->nxt = pp->nxt;
				if (pp->nxt != NULL) {
					pp->nxt->pre = p;
				}
				free(pp);
			}
			else if ((p->pre != &subHead &&p->pre->state == Free)
				&& (p->nxt == NULL || p->nxt->state == Busy)) {
				//情况3：只合并上面的分区
				pp = p;
				p = p->pre;
				p->size += pp->size;
				p->nxt = pp->nxt;
				if (pp->nxt != NULL) {
					pp->nxt->pre = p;
				}
				free(pp);
			}
			else {
				//情况4：上下分区均不用合并
				p->state = Free;
				p->taskId = -1;
			}
		}
		p = p->nxt;
	}
	if (flag == 1) {
		printf("内存分区回收成功...n");
		return 1;
	}
	else {
		printf("找不到目标作业，内存分区回收失败...n");
		return 0;
	}
}

// 显示空闲分区链情况
void showSubArea()
{
	printf("*********************************************n");
	printf("**        当前的内存分配情况如下：      **n");
	printf("*********************************************n");
	printf("** 起始地址 | 空间大小 | 工作状态 | 作业号 **n");
	subAreaNode *p = subHead.nxt;
	while (p != NULL)
	{
		printf("**-----------------------------------------**n");
		printf("**");
		printf("%d  k |", p->addr);
		printf("%d  k |", p->size);
		printf("  %s   |", p->state == Free ? "Free" : "Busy");
		if (p->taskId> 0) {
			printf("%d  ", p->taskId);
		}
		else {
			printf("       ");
		}
		printf("**n");
		p = p->next;
	}
	printf("*********************************************n");
}

int main()
{
	intoption, ope, taskId, size;
	intSubArea();
	while (1)
	{
		printf("请选择要模拟的分配算法：
			0 表示首次适应算法，1 表示最佳适应算法n");
			scanf("%d", &option);
		if (option == 0) {
			printf("首次适应算法，下面进行算法的模拟n");
			break;
		}
		else if (option == 1) {
			printf("最佳适应算法，下面进行算法的模拟n");
			break;
		}
		else {
			printf("错误：请输入 0/1nn");
		}
	}
	while (1)
	{
		printf("n");
		printf("*********************************************n");
		printf("** 1: 分配内存    2:回收内存    0: 退出 **n");
		printf("*********************************************n");
		scanf("%d", &ope);
		if (ope == 0)break;
		if (ope == 1) {
			printf("请输入作业号： ");
			scanf("%d", &taskId);
			printf("请输入需要分配的内存大小(KB)： ");
			scanf("%d", &size);
			if (size <= 0) {
				printf("错误：分配内存大小必须为正值n");
				continue;
			}
			if (option == 0) {
				firstFit(taskId, size);
			}
			else {
				bestFit(taskId, size);
			}
			showSubArea();
		}
		else if (ope == 2) {
			printf("请输入要回收的作业号： ");
			scanf("%d", &taskId);
			freeSubArea(taskId);
			showSubArea();
		}
		else {
			printf("错误：请输入 0/1/2n");
		}
	}
	printf("分配算法模拟结束n");
	return0;
}
