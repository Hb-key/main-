#define _CRT_SECURE_NO_WARNINGS
#include"Stu_ach_manage.h"

void menu()
{
	printf("***********************************************\n");
	printf("**********     学生成绩管理系统       *********\n");
	printf("***********************************************\n");
	printf("**********     1、录入学生信息系统    *********\n");
	printf("**********	   2、修改学生信息系统    *********\n");
	printf("**********	   3、删除学生信息系统    *********\n");
	printf("**********	   4、查询学生信息系统    *********\n");
	printf("**********     5、输出学生信息系统    *********\n");
	printf("**********     6、退出系统            *********\n");
	printf("***********************************************\n");
}

void show(struct student *s)
{
	int i = 0;
	printf("*******		输入学号		********\n");
	scanf("%s", s[i].num);
	printf("*******		输入姓名		********\n");
	scanf("%s", s[i].name);
	printf("*******		输入科目		********\n");
	scanf("%s", s[i].spec);
	printf("*******		输入成绩		********\n");
	scanf("%d", &s[i].grade);
	printf("*******		输入性别		********\n");
	scanf("%s", s[i].sex);
}

void Entry(struct student *s)
{
	printf("*******		欢迎进入查询学生系统		********\n");
	int n, i;
	char d;
	printf("*******		请输入学生的数量		********\n");
	scanf("%d", &n);
	for (i = 5; i<n + 5; i++)
	{
		printf("*******		请输入学生的学号		********\n");
		show(s);
		getchar();
		system("cls");
	}
	printf("\t学号\t姓名\t科目\t成绩\t性别");
	printf("\n\t-------------------------------------");
	for (i = 0; i<n + 5; i++)
	{
		printf("%-8s%-8s%-8s%-8d%-8s", 
			s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
	}
	printf("返回首页（请按任意键）：");
	scanf("%c", &d);
	system("cls");
}


void Modify(struct student *s)
{
	char a[20], d;
	int i;
	printf("*******		请输入要修改学生的姓名：		********\n");
	scanf("%s", a);
	for (i = 0; i<5; i++)
	{
		if (!strcmp(s[i].name, a))
		{
			show(s);
			getchar();
			system("cls");
		}
	}
	printf("\t学号\t姓名\t科目\t成绩\t性别");
	for (i = 0; i<5; i++)
	{
		printf("\t%-8s%-8s%-8s%-8d%-8s",
			s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
	}
	printf("返回首页（请按任意键）：");
	scanf("%c", &d);
	system("cls");
}

void Delete(struct student *s)
{
	char a[20], d;
	int i, k;
	printf("*******		请输入要删除学生的姓名：		********\n");
	scanf("%s", a);
	for (i = 0; i<5; i++)
	{
		if (!strcmp(s[i].name, a))
		{
			s[i] = s[i + 1];
			printf("此学生的信息：\n");
			printf("\t学号\t姓名\t科目\t成绩\t性别");
			for (k = 0; k<4; k++)
			{
				printf("\t%-8s%-8s%-8s%-8d%-8s\n",
					s[k].num, s[k].name, s[k].spec, s[k].grade, s[k].sex);
			}
		}
		if (i == 4)
		{
			printf("查无此人！");
		}
	}
	printf("返回首页（请按任意键）：");
	getchar();
	scanf("%c", &d);
	system("cls");
}


void number(struct student *s)
{
	char a[20], d;
	int i;
	printf("*******		请输入要查询学生的学号(10001~10005)：		********\n");
	scanf("%s", a);
	for (i = 0; i<5; i++)
	{
		if (!strcmp(s[i].num, a))
		{
			printf("此学生的信息");
			printf("\t学号\t姓名\t科目\t成绩\t性别");
			printf("\n\n\t\t%-8s%-8s%-8s%-8d%-8s\n",
				s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
		}

		if (i == 4 && s[i].num != "10005")
		{
			printf("查无此人！");

		}
	}
	printf("返回首页（请按任意键）：");
	getchar();
	scanf("%c", &d);
	system("cls");
}


void classes(struct student *s)
{
	int i, a;
	char d;
	printf("*******		请输入要查询学生的班级(12~14)：		********\n");

	scanf("%d", &a);
	for (i = 0; i<5; i++)
	{
		if (a == s[i].grade)
		{
			printf("此学生的信息：\n");
			printf("\t学号\t姓名\t科目\t成绩\t性别");
			printf("\n\n\t\t%-8s%-8s%-8s%-8d%-8s\n",
				s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
		}
		if (i == 4 && s[i].grade != a)
		{
			printf("查无此人！");

		}
	}
	printf("返回首页（请按任意键）：");
	getchar();
	scanf("%c", &d);
	system("cls");
}

void Search(struct student *s)
{
	int input;
	printf("************************************************\n");
	printf("*******		欢迎进入查询学生系统		********\n");
	printf("************************************************\n");
	printf("*******		1、按学号查询学生信息系统	********\n");
	printf("*******		2、按班级查询学生信息系统	********\n");
	printf("************************************************\n");
	printf("***** 请选择你要的服务（按数字1~2进入）： ******\n");
	printf("************************************************\n");
	scanf("%d", &input);
	system("cls");
	if (input == 1)
	{
		printf("*******		1、按学号查询学生信息系统	********\n");
		number(s);
	}
	else if (input == 2)
	{
		printf("*******		2、按班级查询学生信息系统	********\n");
		classes(s);
	}
	else
	{
		printf("输入有误！\n");
	}
}

void Print(struct student *s)
{
	int i;
	char d;
	printf("欢迎进入输出学生系统");
	printf("\t学号\t姓名\t科目\t成绩\t性别");
	for (i = 0; i<5; i++)
	{
		printf("\t%-8s%-8s%-8s%-8d%-8s",
			s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
	}
	printf("返回首页（请按任意键）：");
	scanf("%c", &d);
	getchar();
	system("cls");
}

void Logic(struct student *s)
{
	menu();
	printf("请选择你要的服务（按数字1~6进入）：\n");
	int input = 0;
	scanf("%d", &input);
	while (1)
	{
		switch (input)
		{
		case 1:
			Entry(s);
			break;
		case 2:
			Modify(s);
			break;
		case 3:
			Delete(s);
			break;
		case 4:
			printf("*******		欢迎进入修改学生系统		********\n");
			Search(s);
			break;
		case 5:
			Print(s);
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("输入有误，请重新输入！");
			break;
		}
	}
}

void main()
{
	struct student s[t] = {
		{ "10001","zhang","Chinese",85,"male" },
	{ "10002","wang","C",83,"female" },
	{ "10003","liang","Chemist",74,"male" },
	{ "10004","dong","English",68,"female" },
	{ "10005","meng","Math",87,"male" }
	};
	Logic(s);
}