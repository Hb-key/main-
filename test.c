#define _CRT_SECURE_NO_WARNINGS
#include"Stu_ach_manage.h"

void menu()
{
	printf("***********************************************\n");
	printf("**********      学生成绩管理系统      *********\n");
	printf("***********************************************\n");
	printf("**********     1、录入学生信息系统    *********\n");
	printf("**********     2、删除学生信息系统    *********\n");
	printf("**********     3、修改学生信息系统    *********\n");
	printf("**********     4、查询学生信息系统    *********\n");
	printf("**********     5、输出学生信息系统    *********\n");
	printf("**********     6、退出系统            *********\n");
	printf("***********************************************\n");
}

void Logic(struct student *s)
{
	while (1)
	{
		menu();
		printf("请选择：");
		int input = 0;
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Entry(s);
			break;
		case 2:
			Delete(s);
			break;
		case 3:
			Modify(s);
			break;
		case 4:
			Search(s);
			break;
		case 5:
			Print(s);
			break;
		case 6:
			printf("退出系统！！！\n");
			break;
		default:
			printf("输入有误，请重新输入！");
			break;
		}
	}
}

int main()
{
	
	struct student s[info] = {
		{ "10001","zhang","Chinese",85,"male" },
	{ "10002","wang","C",83,"female" },
	{ "10003","liang","Chemist",74,"male" },
	{ "10004","dong","English",78,"female" },
	{ "10005","meng","Math",87,"male" }
	};

	Logic(s);
	return 0;
}