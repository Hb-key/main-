#define _CRT_SECURE_NO_WARNINGS
#include"Stu_ach_manage.h"

void menu()
{
	printf("***********************************************\n");
	printf("**********     ѧ���ɼ�����ϵͳ       *********\n");
	printf("***********************************************\n");
	printf("**********     1��¼��ѧ����Ϣϵͳ    *********\n");
	printf("**********	   2���޸�ѧ����Ϣϵͳ    *********\n");
	printf("**********	   3��ɾ��ѧ����Ϣϵͳ    *********\n");
	printf("**********	   4����ѯѧ����Ϣϵͳ    *********\n");
	printf("**********     5�����ѧ����Ϣϵͳ    *********\n");
	printf("**********     6���˳�ϵͳ            *********\n");
	printf("***********************************************\n");
}

void show(struct student *s)
{
	int i = 0;
	printf("*******		����ѧ��		********\n");
	scanf("%s", s[i].num);
	printf("*******		��������		********\n");
	scanf("%s", s[i].name);
	printf("*******		�����Ŀ		********\n");
	scanf("%s", s[i].spec);
	printf("*******		����ɼ�		********\n");
	scanf("%d", &s[i].grade);
	printf("*******		�����Ա�		********\n");
	scanf("%s", s[i].sex);
}

void Entry(struct student *s)
{
	printf("*******		��ӭ�����ѯѧ��ϵͳ		********\n");
	int n, i;
	char d;
	printf("*******		������ѧ��������		********\n");
	scanf("%d", &n);
	for (i = 5; i<n + 5; i++)
	{
		printf("*******		������ѧ����ѧ��		********\n");
		show(s);
		getchar();
		system("cls");
	}
	printf("\tѧ��\t����\t��Ŀ\t�ɼ�\t�Ա�");
	printf("\n\t-------------------------------------");
	for (i = 0; i<n + 5; i++)
	{
		printf("%-8s%-8s%-8s%-8d%-8s", 
			s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
	}
	printf("������ҳ���밴���������");
	scanf("%c", &d);
	system("cls");
}


void Modify(struct student *s)
{
	char a[20], d;
	int i;
	printf("*******		������Ҫ�޸�ѧ����������		********\n");
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
	printf("\tѧ��\t����\t��Ŀ\t�ɼ�\t�Ա�");
	for (i = 0; i<5; i++)
	{
		printf("\t%-8s%-8s%-8s%-8d%-8s",
			s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
	}
	printf("������ҳ���밴���������");
	scanf("%c", &d);
	system("cls");
}

void Delete(struct student *s)
{
	char a[20], d;
	int i, k;
	printf("*******		������Ҫɾ��ѧ����������		********\n");
	scanf("%s", a);
	for (i = 0; i<5; i++)
	{
		if (!strcmp(s[i].name, a))
		{
			s[i] = s[i + 1];
			printf("��ѧ������Ϣ��\n");
			printf("\tѧ��\t����\t��Ŀ\t�ɼ�\t�Ա�");
			for (k = 0; k<4; k++)
			{
				printf("\t%-8s%-8s%-8s%-8d%-8s\n",
					s[k].num, s[k].name, s[k].spec, s[k].grade, s[k].sex);
			}
		}
		if (i == 4)
		{
			printf("���޴��ˣ�");
		}
	}
	printf("������ҳ���밴���������");
	getchar();
	scanf("%c", &d);
	system("cls");
}


void number(struct student *s)
{
	char a[20], d;
	int i;
	printf("*******		������Ҫ��ѯѧ����ѧ��(10001~10005)��		********\n");
	scanf("%s", a);
	for (i = 0; i<5; i++)
	{
		if (!strcmp(s[i].num, a))
		{
			printf("��ѧ������Ϣ");
			printf("\tѧ��\t����\t��Ŀ\t�ɼ�\t�Ա�");
			printf("\n\n\t\t%-8s%-8s%-8s%-8d%-8s\n",
				s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
		}

		if (i == 4 && s[i].num != "10005")
		{
			printf("���޴��ˣ�");

		}
	}
	printf("������ҳ���밴���������");
	getchar();
	scanf("%c", &d);
	system("cls");
}


void classes(struct student *s)
{
	int i, a;
	char d;
	printf("*******		������Ҫ��ѯѧ���İ༶(12~14)��		********\n");

	scanf("%d", &a);
	for (i = 0; i<5; i++)
	{
		if (a == s[i].grade)
		{
			printf("��ѧ������Ϣ��\n");
			printf("\tѧ��\t����\t��Ŀ\t�ɼ�\t�Ա�");
			printf("\n\n\t\t%-8s%-8s%-8s%-8d%-8s\n",
				s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
		}
		if (i == 4 && s[i].grade != a)
		{
			printf("���޴��ˣ�");

		}
	}
	printf("������ҳ���밴���������");
	getchar();
	scanf("%c", &d);
	system("cls");
}

void Search(struct student *s)
{
	int input;
	printf("************************************************\n");
	printf("*******		��ӭ�����ѯѧ��ϵͳ		********\n");
	printf("************************************************\n");
	printf("*******		1����ѧ�Ų�ѯѧ����Ϣϵͳ	********\n");
	printf("*******		2�����༶��ѯѧ����Ϣϵͳ	********\n");
	printf("************************************************\n");
	printf("***** ��ѡ����Ҫ�ķ��񣨰�����1~2���룩�� ******\n");
	printf("************************************************\n");
	scanf("%d", &input);
	system("cls");
	if (input == 1)
	{
		printf("*******		1����ѧ�Ų�ѯѧ����Ϣϵͳ	********\n");
		number(s);
	}
	else if (input == 2)
	{
		printf("*******		2�����༶��ѯѧ����Ϣϵͳ	********\n");
		classes(s);
	}
	else
	{
		printf("��������\n");
	}
}

void Print(struct student *s)
{
	int i;
	char d;
	printf("��ӭ�������ѧ��ϵͳ");
	printf("\tѧ��\t����\t��Ŀ\t�ɼ�\t�Ա�");
	for (i = 0; i<5; i++)
	{
		printf("\t%-8s%-8s%-8s%-8d%-8s",
			s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
	}
	printf("������ҳ���밴���������");
	scanf("%c", &d);
	getchar();
	system("cls");
}

void Logic(struct student *s)
{
	menu();
	printf("��ѡ����Ҫ�ķ��񣨰�����1~6���룩��\n");
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
			printf("*******		��ӭ�����޸�ѧ��ϵͳ		********\n");
			Search(s);
			break;
		case 5:
			Print(s);
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("�����������������룡");
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