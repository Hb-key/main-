#pragma once

typedef int DataType;


#define MAX_SIZE (100)

typedef struct SeqList{
	DataType array[MAX_SIZE];
	int		 size;
}SeqListR;

void SeqListInit(SeqListR *pSeq);
void SeqListDestory(SeqListR *pSeq);

void SeqListPushFront(SeqListR  *pSeq, DataType data);
void SeqListPushBack(SeqListR *pSeq, DataType data);

void SeqListPrint(const SeqListR *pSeq);