#pragma once
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

typedef int DataType;

typedef struct Node {
	struct Node *next;
	DataType data;
}Node,*pFirst;

typedef struct SNode {
	struct SNode *next;
	struct SNode *random;
	DataType data;
}SNode, *pSFirst;

void LinkListInit(Node **ppFirst);
void LinkListDestroy(Node **ppFirst);
void PrintLinkList(Node *pFirst);
static Node *CreateNode(DataType data);
void LinkListPushBack(Node **ppFirst, DataType data);
void LinkListPopFront(Node **ppFirst, DataType data);
void ReverseLinkList(Node **pFirst);