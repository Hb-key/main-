#define _CRT_SECURE_NO_WARNINGS
#include"Stu_ach_manage.h"

int member = 5;
int stu_num = 0;

void Input(struct student *s)   //输入学生信息
{
	int i = 0;
	printf("输入学号：");
	scanf("%d", &s[i].num);
	printf("输入姓名：");
	scanf("%s", s[i].name);
	printf("输入科目：");
	scanf("%s", s[i].spec);
	printf("输入成绩：");
	scanf("%d", &s[i].grade);
	printf("输入性别：");
	scanf("%s", s[i].sex);
}

void Print(struct student *s)   //显示学生信息
{
	printf("此学生的信息：\n");
	printf("学号\t姓名\t科目\t成绩\t性别");
	printf("\n------------------------------------------\n");
	for (int i = 0; i< stu_num + member; i++)
	{
		printf("%d\t%s\t%s\t%d\t%s\n",
			s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
	}
}

void Entry(struct student *s)
{
	printf("开始录入，输入要录入的学生数量：");
	scanf("%d", &stu_num);
	for (int i = 0; i< stu_num; i++)
	{
		Input(s);
		member++;
	}
	Print(s);
}

void Delete(struct student *s)
{
	int number = 0;
	printf("请输入要删除学生的学号：");
	scanf("%d", &number);
	//判断该学生信息是否已录入
	for (int i = 0; i< stu_num + 5; i++)
	{
		if (s[i].num == number)
		{
			Print(s);
			//删除
			printf("是否真的要删除（Y/N）？");
			if (getchar() == 'Y')
			{
				s[i] = s[i + 1];
			}
			member--;
		}
		else
		{
			printf("该学生不存在！\n");
		}
	}
}

void Modify(struct student *s)
{
	char name[20];
	printf("请输入要修改学生的姓名：");
	scanf("%s", name);
	for (int i = 0; i< stu_num + 5; i++)
	{
		if (s[i].name == name)
		{
			Print(s);
			printf("新学生的信息录入：\n");
			Input(s);
			Print(s);
		}
		else
		{
			printf("该学生不存在！\n");
		}
	}
}

void menu_search()
{
	printf("************************************************\n");
	printf("*******      欢迎进入查询学生系统       ********\n");
	printf("************************************************\n");
	printf("*******     1、按学号查询学生信息系统   ********\n");
	printf("*******     2、按班级查询学生信息系统   ********\n");
	printf("************************************************\n");
	printf("请选择：\n");
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
		}
		else 
		{
			printf("查无此人！\n");
		}
	}
}


void Grade(struct student *s)
{
	int grade = 0;
	printf("请输入要查询学生的班级：");
	scanf("%d", &grade);
	for (int i = 0; i< stu_num + 5; i++)
	{

		if (grade == s[i].grade)
		{
			Print(s);
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
		printf("按学号查询学生信息系统：\n\n");
		Number(s);
		break;
	case 2:
		printf("按班级查询学生信息系统：\n\n");
		Grade(s);
		break;
	default:
		printf("输入有误！\n");
		break;
	}
}
