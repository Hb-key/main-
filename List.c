//void DlistPushBack(DNode *head, int data)
//{
//	DNode *node = CreateDNode(data);
//	head->prev->next = node;
//	head->prev = node;
//	node->perv = head->prev;
//	node->next = head;
//
//} 

#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void SeqListInit(SeqListR *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
}

void SeqListDestory(SeqListR *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
}

void SeqListPushFront(SeqListR *pSeq, DataType data)
{

	assert(pSeq != NULL);
	if (pSeq->size == MAX_SIZE)
	{
		printf("ÒÑÂú\n");
		return;
	}
	for (int i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->array[i + 1] = pSeq->array[i];
	}
	pSeq->array[0] = data;
	pSeq->size++;
}

void SeqListPushBack(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAX_SIZE)
	{
		printf("ÒÑÂú\n");
		return;
	}
	pSeq->array[pSeq->size] = data;
	pSeq->size += 1;
}

void SeqListPrint(SeqListR *pSeq)
{
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}
