#define _CRT_SECURE_NO_WARNINGS
#include"Stu_ach_manage.h"

int member = 5;
int stu_num = 0;

void Input(struct student *s)   //����ѧ����Ϣ
{
	int i = 0;
	printf("����ѧ�ţ�");
	scanf("%d", &s[i].num);
	printf("����������");
	scanf("%s", s[i].name);
	printf("�����Ŀ��");
	scanf("%s", s[i].spec);
	printf("����ɼ���");
	scanf("%d", &s[i].grade);
	printf("�����Ա�");
	scanf("%s", s[i].sex);
}

void Print(struct student *s)   //��ʾѧ����Ϣ
{
	printf("��ѧ������Ϣ��\n");
	printf("ѧ��\t����\t��Ŀ\t�ɼ�\t�Ա�");
	printf("\n------------------------------------------\n");
	for (int i = 0; i< stu_num + member; i++)
	{
		printf("%d\t%s\t%s\t%d\t%s\n",
			s[i].num, s[i].name, s[i].spec, s[i].grade, s[i].sex);
	}
}

void Entry(struct student *s)
{
	printf("��ʼ¼�룬����Ҫ¼���ѧ��������");
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
	printf("������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%d", &number);
	//�жϸ�ѧ����Ϣ�Ƿ���¼��
	for (int i = 0; i< stu_num + 5; i++)
	{
		if (s[i].num == number)
		{
			Print(s);
			//ɾ��
			printf("�Ƿ����Ҫɾ����Y/N����");
			if (getchar() == 'Y')
			{
				s[i] = s[i + 1];
			}
			member--;
		}
		else
		{
			printf("��ѧ�������ڣ�\n");
		}
	}
}

void Modify(struct student *s)
{
	char name[20];
	printf("������Ҫ�޸�ѧ����������");
	scanf("%s", name);
	for (int i = 0; i< stu_num + 5; i++)
	{
		if (s[i].name == name)
		{
			Print(s);
			printf("��ѧ������Ϣ¼�룺\n");
			Input(s);
			Print(s);
		}
		else
		{
			printf("��ѧ�������ڣ�\n");
		}
	}
}

void menu_search()
{
	printf("************************************************\n");
	printf("*******      ��ӭ�����ѯѧ��ϵͳ       ********\n");
	printf("************************************************\n");
	printf("*******     1����ѧ�Ų�ѯѧ����Ϣϵͳ   ********\n");
	printf("*******     2�����༶��ѯѧ����Ϣϵͳ   ********\n");
	printf("************************************************\n");
	printf("��ѡ��\n");
}

void Number(struct student *s)
{
	int number = 0;
	printf("������Ҫ��ѯѧ����ѧ�ţ�");
	scanf("%d", &number);
	for (int i = 0; i< stu_num + 5; i++)
	{
		if (s[i].num == number)
		{
			Print(s);
		}
		else 
		{
			printf("���޴��ˣ�\n");
		}
	}
}


void Grade(struct student *s)
{
	int grade = 0;
	printf("������Ҫ��ѯѧ���İ༶��");
	scanf("%d", &grade);
	for (int i = 0; i< stu_num + 5; i++)
	{

		if (grade == s[i].grade)
		{
			Print(s);
		}
		else 
		{
			printf("���޴��ˣ�\n");

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
		printf("��ѧ�Ų�ѯѧ����Ϣϵͳ��\n\n");
		Number(s);
		break;
	case 2:
		printf("���༶��ѯѧ����Ϣϵͳ��\n\n");
		Grade(s);
		break;
	default:
		printf("��������\n");
		break;
	}
}
