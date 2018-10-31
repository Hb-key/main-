#pragma once
#include"LinkList.h"

//void Test()
//{
//	SeqListR seqList;
//	SeqListInit(&seqList);
//	SeqListPushBack(&seqList, 1);
//	SeqListPushBack(&seqList, 2);
//	SeqListPushBack(&seqList, 3);
//	SeqListPrint(&seqList);
//	SeqListPushFront(&seqList, 11);
//	SeqListPushFront(&seqList, 12);
//	SeqListPushFront(&seqList, 13);
//	SeqListPrint(&seqList);
//}

void Test()
{
	pFirst ppFirst = NULL;
	pFirst pFirst = NULL;
	LinkListInit(&ppFirst);

	LinkListPushBack(&ppFirst, 1);
	LinkListPushBack(&ppFirst, 2);
	LinkListPushBack(&ppFirst, 3);
	LinkListPushBack(&ppFirst, 4);
	PrintLinkList(pFirst);
	ReverseLinkList(&pFirst);
	LinkListDestroy(&ppFirst);
}

int main()
{
	//Test();
	Test();
	return 0;
}