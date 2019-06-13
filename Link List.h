#pragma once
#include<assert.h>
#include<stdio.h>

typedef int DataType;

typedef struct ListNode {
	int data;
	struct ListNode *next;
}ListNode;

//从尾到头打印单链表
void TailToHead(ListNode *plist)
{
	assert(plist);
	if (plist == NULL)
	{
		return;
	}
	TailToHead(plist->next);
	printf("%d", plist->data);
}

//删除一个无头单链表非尾节点
void DeleteNoHead(ListNode *pos)
{
	assert(pos);
	ListNode *cur = pos;
	ListNode *next = pos->next;
	cur->data = next->data;
	cur->next = next->next;
}
