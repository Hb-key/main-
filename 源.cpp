#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable :4996 )
#define OUT_size 1000
#define MAX 500000

typedef struct Word
{
	char arr[40];
	int count;
	double frequency;
}Word;

typedef struct Num
{
	Word *brr;
	int length;
	int listsize;
}N;
int THE_size(char * src)//��ȡ�ļ����ҵõ��ļ�����
{
	FILE *fr = fopen(src, " r ");//
	if (!fr) return -1;

	fseek(fr, 0L, SEEK_END);
	int size = ftell(fr);

	fclose(fr);
	return size;
}
void Write(char *src, char *str)
{
	FILE *fr = fopen(src, "r");
	fread(str, sizeof(char), MAX, fr);//����ֵʵ�ʶ��ɹ�������
	printf("%s", str);
	printf("\n");
	fclose(fr);
}
void Count(N *t)
{
	for (int i = 0; i<(*t).length; i++)
	{
		(*t).brr[i].count = 0;
	}
}
void Output(char *str, N *t, int Size)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int flag = 0;
	char tmp[40];
	for (i = 0; i <= Size; i++)
	{
		if (isalpha(str[i]))//���Ϊ�ַ�
		{
			tmp[k] = str[i];
			k++;//���ַ������ƹ���
		}
		else//��������ַ��Ҳ�Ϊ��һ��(ʹ���ƹ����ĵ�һ�Ϊ��)
		{
			if (k>0)
			{
				flag = 1;
			}
			tmp[k] = '\0';//ʹ���ƹ�������һ��Ϊ'\0'		
		}
		if (flag == 1)//�õ�ÿ������
		{
			for (int m = 0; m<k + 1; m++)
			{
				(*t).brr[j].arr[m] = tmp[m];
				(*t).brr[j].count = 1;
			}
			(*t).length++;
			j++;
			flag = 0;
			k = 0;
		}
	}
	/*for(int l=0;l<Size;l++)
	{
	printf("%s",(*t).brr[l].arr);
	printf("\n");
	}*/
	printf("%d\n", (*t).length);
}
int  My_strcmp(const char *str1, const char *str2)//�ַ����ıȽ�strcmp
{
	assert(str1 != NULL && str2 != NULL);//���������ַ�����Ϊ��
	int tmp;//��ֵ  
	while (((tmp = *str1 - *str2) == 0) && (*str2 != '\0'))//������ֵ���Ϊ0���ҵڶ��Ϊ0
	{
		str1++;//����ָ��ͬʱ��ǰ��
		str2++;
	}
	return tmp;
}
void Docount(N *t)
{
	for (int i = 0; i<(*t).length; i++)
	{
		for (int j = i + 1; j <= (*t).length; j++)
		{
			if (My_strcmp((*t).brr[i].arr, (*t).brr[j].arr) == 0 && (*t).brr[i].count != 0)
			{
				(*t).brr[i].count++;
				(*t).brr[j].count = 0;

			}
		}
	}
}
int END(N *t)
{
	int i = 0;
	int n = 0;
	while (i <= (*t).length)
	{
		if ((*t).brr[i].count>0)
		{
			n++;
		}
		i++;
	}
	return n;
}
void InsertSort(N *t)
{                                    //Խ����Խ�죬�ȶ�

	int tmp = 0;
	int j;
	char tp[40];
	for (int i = 1; i <= (*t).length; i++)
	{
		tmp = (*t).brr[i].count;
		strcpy(tp, (*t).brr[i].arr);
		for (j = i - 1; j >= 0; j--)
		{
			if ((*t).brr[j].count>tmp)
			{
				(*t).brr[j + 1].count = (*t).brr[j].count;
				strcpy((*t).brr[j + 1].arr, (*t).brr[j].arr);
			}
			else
			{
				break;
			}
		}
		(*t).brr[j + 1].count = tmp;
		strcpy((*t).brr[j + 1].arr, tp);
	}
}

int partion(N *t, int low, int high)//һ�ο��������±�
{
	while ((high - low)<1000)
	{
		InsertSort(t);
	}
	int tmp = (*t).brr[low].count;
	char *tp[40] = { (*t).brr[low].arr };
	while (low<high)
	{
		while (low<high && (*t).brr[high].count >= tmp)
		{
			high--;
		}
		if (low >= high)
		{
			break;
		}
		else
		{
			(*t).brr[low].count = (*t).brr[high].count;
			strcpy((*t).brr[low].arr, (*t).brr[high].arr);
		}
		while (low<high && (*t).brr[low].count <= tmp)
		{
			low++;
		}
		if (low >= high)
		{
			break;
		}
		else
		{
			(*t).brr[high].count = (*t).brr[low].count;
			strcpy((*t).brr[low].arr, (*t).brr[high].arr);

		}
	}
	(*t).brr[low].count = tmp;
	strcpy((*t).brr[low].arr, *tp);
	return low;
}
void Quick(N *t, int low, int high, int len)//�õ������O(N*log 2 n);���������ΪO(n^2)����������� ,���ȶ�
{
	int par = partion(t, low, high);
	if (par>low + 1)
	{
		Quick(t, low, par - 1, len);
	}
	if (par<high - 1)
	{
		Quick(t, par + 1, high, len);
	}
}
void Show(N *t)
{
	int i = (*t).length;
	while (i >= 0)
	{
		if ((*t).brr[i].count>0)
		{
			printf("%s   ", (*t).brr[i].arr);
			printf("%d\n", (*t).brr[i].count);
		}
		i--;
	}
}
int main()
{
	char *src = "D:\\yingwen.txt";
	FILE *fr = fopen(src, "r");
	if (!fr)
	{
		return -1;
	}
	int size = THE_size(src);
	printf("%d\n", size);//����

	char str[MAX] = " ";
	Write(src, str);

	//Ssize(str);
	//int Size = Ssize(str);
	//printf("%d\n",Size);//����

	N t;
	t.brr = (Word*)malloc(size * sizeof(Word));//��Žṹ��word
	memset(t.brr, 0, size * sizeof(Word));
	t.length = 0;

	Output(str, &t, size);
	//Count(&t);
	Docount(&t);


	int len = END(&t);
	//Quick(&t,0,len,len);
	InsertSort(&t);
	printf("%d\n", len);
	Show(&t);
	return 0;
}