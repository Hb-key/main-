#include<stdio.h>
#include<stdlib.h>
int Add(int x, int y)
{
	return x+y; 
} 
int Sub(int x, int y)
{
	return x-y; 
} 
int Mul(int x, int y)
{
	return x*y; 
} 
int Div(int x, int y)
{
	return x/y; 
} 

int main(int argc, char *argv[], char *envp[])
{
	int ret = 0;
	if(argv != 4)
	{
		printf("输入有误！\n");
		break;
	}
	switch(*(argv[1]+1))
	{
		case 'a':
			ret = Add(atoi(argv[2]),atoi(argv[3]));
			break;
		case 's':
			ret = Sub(atoi(argv[2]),atoi(argv[3]));
			break;
		case 'm':
			ret = Mul(atoi(argv[2]),atoi(argv[3]));
			break;
		case 'd':
			ret = Div(atoi(argv[2]),atoi(argv[3]));
			break;	
		default:
		printf("输入有误:argv[1] = %s",argv[1]);
			break;	
	}
	printf("ret = %d\n",ret);
	return 0;
 } 



#include<stdio.h>
#include<string.h>
void Bubble_sort(char *arr[],int sz)
{
	int i,j;
	for(i=0;i<sz-1;i++)
	{
		for(j=0;j<sz-i-1;j++)
		{
			if(strcmp(arr[j],arr[j+1])>0)
			{
				char *tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	for(i=0;i<sz;i++)
	{
		printf("%s\n",*(arr+i));
	}
 } 
int main()
{
	char *arr[] = {"aaaaa","sssss","bbbbbb"};
	int sz = sizeof(arr)/sizeof(arr[0]);
	Bubble_sort(arr,sz); 
	return 0;
}


