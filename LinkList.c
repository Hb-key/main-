#include"LinkList.h"


void LinkListInit(pFirst *ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

void LinkListDestroy(pFirst *ppFirst)
{
	Node *cur = NULL;
	Node *del = NULL;
	assert(ppFirst != NULL);
	cur = *ppFirst;
	while (cur != NULL)
	{
		del = cur;
		cur = cur->next;
		free(del);
	}
	*ppFirst = NULL;
}

static Node *CreateNode(DataType data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void PrintLinkList(Node *pFirst)
{
	Node *cur = pFirst;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void LinkListPushFront(Node **ppFirst, DataType data)
{
	assert(ppFirst);
	Node *newNode = CreateNode(data);
	newNode->next = *ppFirst;
	*ppFirst = newNode;
}

void LinkListPushBack(Node **ppFirst, DataType data)
{
	Node *newNode = CreateNode(data);
	Node *cur = *ppFirst;
	assert(ppFirst != NULL);
	if (*ppFirst == NULL)
	{
		*ppFirst = newNode;
		return;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newNode;
}  

void LinkListPopFront(Node **ppFirst, DataType data)
{
	assert(ppFirst);
	assert(*ppFirst);
	Node *del = *ppFirst;
	*ppFirst = del->next;
	free(del);
 }

void ReverseLinkList(Node *pFirst)
{
	Node *result = NULL;
	Node *cur = pFirst;
	Node *node;
	while (cur != NULL)
	{
		node = cur;
		cur = cur->next;
		node->next = result;
		result = node;
	}
	PrintLinkList(pFirst);
}
//自身逆置
//void ReverseLinkList(pFirst *pFirst)
//{
//	Node *p1, *p2, *p3;
//	p1 = NULL, p2 =(*pFirst), p3 = (*pFirst)->next;
//	while (p2 != NULL)
//	{
//		p2->next = p1;
//		p1 = p2;
//		p2 = p3;
//	}
//	if (p3 != NULL)
//	{
//		p3 = p3->next;
//	}
//	PrintLinkList(*pFirst);
//}

void JocephCircle(pFirst *ppFirst, int n)
{
	int i = 0;
	Node *prev = NULL;
	Node *cur = NULL;
	assert(ppFirst);
	if (*ppFirst == NULL)
		return;
	if ((*ppFirst)->next != NULL)
	{
		cur = *ppFirst;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = *ppFirst;
		prev = cur;
		cur = *ppFirst;
		while (cur->next != NULL)
		{
			for (i = 0; i < n - 1; i++)
			{
				prev = cur;
				cur = cur->next;
			}
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
	}
	cur->next = NULL;
	*ppFirst = cur;
	printf("JocephCircle:%d,%d", n, cur->data);
}

Node *ReturnNode(pFirst pfirst, int n)
{
	int i = n;
	Node *prev = NULL;
	Node *cur = NULL;
	if (pfirst == NULL || pfirst->next == NULL)
	{
		return pfirst;
	}
	cur = pfirst;
	prev = pfirst;
	while (i--)
	{
		cur = cur->next;
	}
	while (cur != NULL)
	{

		prev = prev->next;
		cur = cur->next;
	}
	printf("要求返回的是第%d个节点  %d", n, prev->data);
	return pfirst;
}



Node *Merge(pFirst list1, pFirst list2)       
{
	Node *new = NULL;
	Node *newcur = NULL;
	Node *cur1 = NULL;
	Node *cur2 = NULL;
	assert(list1 && list2);
	cur1 = list1;
	cur2 = list2;
	while (cur1 != NULL && cur2 != NULL) 
	{
		if (cur1->data <= cur2->data) 
		{
			if (new == NULL)
			{
				new = cur1;
			}
			else
			{
				newcur->next = cur1;
			}
			newcur = cur1;
			cur1 = cur1->next;
		}
		else
		{
			if (new == NULL)
			{
				new = cur2;
			}
			else 
			{
				newcur->next = cur2;
			}
			newcur = cur2;
			cur2 = cur2->next;
		}
	}
	newcur->next = NULL;
	if (cur1 == NULL)
	{
		newcur->next = cur2;
	}
	if (cur2 == NULL) 
	{
		newcur->next = cur1;
	}
	PrintLinkList(new);
	return new;
}

SNode *CreatSNode(DataType data)
{
	SNode *NewNode = (SNode*)malloc(sizeof(SNode));
	NewNode->data = data;
	NewNode->random = NULL;
	NewNode->next = NULL;
	return NewNode;
}

SNode *SNodeCopy(pSFirst pSFirst)
{
	SNode *cur = NULL;
	SNode *next = NULL;
	SNode *New = NULL;
	SNode *newcur = NULL;
	SNode *newnext = NULL;
	SNode *newnode = NULL;
	
	cur = pSFirst;
	while (cur != NULL)
	{
		next = cur->next;
		newnode = CreatSNode(cur->data);
		newnode->next = next;
		cur->next = newnode;
		cur = next;
	}
	cur = pSFirst;
	newcur = pSFirst->next;
	while (cur != NULL)
	{
		if (cur->random == NULL)
		{
			newcur->random = cur->random;
		}
		else 
		{
			newcur->random = cur->random->next;
		}
		cur = newcur->next;
		if (cur != NULL) 
		{
			newcur = cur->next;
		}
	}
	cur = pSFirst;
	New = pSFirst->next;
	newcur = New;
	while (cur != NULL)
	{

		cur->next = newcur->next;
		next = newcur->next;
		if (next == NULL) 
		{
			break;
		}
		newcur->next = next->next;
		newcur = newcur->next;
	}
	return New;
}