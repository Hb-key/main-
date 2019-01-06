#define _CRT_SECURE_NO_WARNINGS
#include"Stu_ach_manage.h"

int member = 5;
int stu_num = 0;

void Input(struct student *s)   //输入学生信息
{
	int i = 0;
	printf("输入学号：");
	scanf("%s", s[i].num);
	printf("输入姓名：");
	scanf("%s", s[i].name);
	printf("输入科目：");
	scanf("%s", s[i].spec);
	printf("输入成绩：");
	scanf("%d", &s[i].score);
	printf("输入性别：");
	scanf("%s", s[i].sex);
}

void Print(struct student *s)   //显示学生信息
{
	printf("\n*****        学生信息如下        *****\n\n");
	printf("学号\t姓名\t科目\t成绩\t性别");
	printf("\n------------------------------------------\n");
	for (int i = 0; i< stu_num + member; i++)
	{
		printf("%s\t%s\t%s\t%d\t%s\n",
			s[i].num, s[i].name, s[i].spec, s[i].score, s[i].sex);
	}
}

void Entry(struct student *s)
{
	char number[20];
	printf("请输入要添加的学生数量：");
	scanf("%d", &stu_num);
	printf("请输入学生的信息：\n");
	while (stu_num > 0)
	{
		Input(s);
	}
	
	for (int i = 0; i < stu_num + member; i++)
	{
		if (s[i].num == number)
		{
			Print(s);
			printf("该学生已存在！\n");
			break;
		}
		else
		{
			for (int i = 0; i < stu_num; i++)
			{
				Input(s);
				printf("\n");
				member++;
			}
		}
	}
	for (int i = 0; i< stu_num + member; i++)
	{
		printf("%s\t%s\t%s\t%d\t%s\n",
			s[i].num, s[i].name, s[i].spec, s[i].score, s[i].sex);
	}
}

void Delete(struct student *s)
{
	char number[20];
	printf("请输入要删除学生的学号：");
	scanf("%s", number);
	//判断该学生信息是否已录入
	for (int i = 0; i< stu_num + member; i++)
	{
		if (s[i].num == number)
		{
			Print(s);
			//删除
			s[i] = s[i + 1];
			member--;
			printf("该学生已删除！\n");
			return;
		}
	}
	printf("该学生不存在！\n");
}

void Modify(struct student *s)
{
	int number = 0;
	printf("请输入要修改学生的学号：");
	scanf("%d", &number);
	//判断该学生信息是否已录入
	for (int i = 0; i< stu_num + member; i++)
	{
		if (s[i].num == number)
		{
			Print(s);
			printf("新学生的信息录入：\n");
			Input(s);
			Print(s);
			return;
		}
	}
	printf("该学生不存在！\n");
}

void menu_search()
{
	printf("************************************\n");
	printf("*******     1、按学号查询   ********\n");
	printf("*******     2、按成绩查询   ********\n");
	printf("************************************\n");
	printf("请选择：");
}

void Number(struct student *s)
{
	int number = 0;
	printf("请输入要查询学生的学号：");
	scanf("%d", &number);
	for (int i = 0; i< stu_num + 5; i++)
	{
		if (s[i].num == number)
		{
			Print(s);
			return;
		}
		else 
		{
			printf("查无此人！\n");
		}
	}
}


void Score(struct student *s)
{
	int score = 0;
	printf("请输入要查询学生的成绩：");
	scanf("%d", &score);
	for (int i = 0; i< stu_num + 5; i++)
	{

		if (score == s[i].score)
		{
			Print(s);
			break;
		}
		else 
		{
			printf("查无此人！\n");

		}
	}
}

void Search(struct student *s)
{
	int input = 0;
	menu_search();
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		Number(s);
		break;
	case 2:
		Score(s);
		break;
	default:
		printf("输入有误！\n");
		break;
	}
}
