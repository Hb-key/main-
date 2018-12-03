#pragma once
#include<assert.h>
#include<stdio.h>

typedef int DataType;

typedef struct ListNode {
	int data;
	struct ListNode *next;
}ListNode;

//��β��ͷ��ӡ������
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

//ɾ��һ����ͷ������ķ�β�ڵ�
void DeleteNoHead(ListNode *pos)
{
	assert(pos);
	ListNode *cur = pos;
	ListNode *next = pos->next;
	cur->data = next->data;
	cur->next = next->next;

}
