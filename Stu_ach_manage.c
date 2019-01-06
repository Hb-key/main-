#define _CRT_SECURE_NO_WARNINGS
#include"Stu_ach_manage.h"

int member = 5;
int stu_num = 0;

void Input(struct student *s)   //����ѧ����Ϣ
{
	int i = 0;
	printf("����ѧ�ţ�");
	scanf("%s", s[i].num);
	printf("����������");
	scanf("%s", s[i].name);
	printf("�����Ŀ��");
	scanf("%s", s[i].spec);
	printf("����ɼ���");
	scanf("%d", &s[i].score);
	printf("�����Ա�");
	scanf("%s", s[i].sex);
}

void Print(struct student *s)   //��ʾѧ����Ϣ
{
	printf("\n*****        ѧ����Ϣ����        *****\n\n");
	printf("ѧ��\t����\t��Ŀ\t�ɼ�\t�Ա�");
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
	printf("������Ҫ��ӵ�ѧ��������");
	scanf("%d", &stu_num);
	printf("������ѧ������Ϣ��\n");
	while (stu_num > 0)
	{
		Input(s);
	}
	
	for (int i = 0; i < stu_num + member; i++)
	{
		if (s[i].num == number)
		{
			Print(s);
			printf("��ѧ���Ѵ��ڣ�\n");
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
	printf("������Ҫɾ��ѧ����ѧ�ţ�");
	scanf("%s", number);
	//�жϸ�ѧ����Ϣ�Ƿ���¼��
	for (int i = 0; i< stu_num + member; i++)
	{
		if (s[i].num == number)
		{
			Print(s);
			//ɾ��
			s[i] = s[i + 1];
			member--;
			printf("��ѧ����ɾ����\n");
			return;
		}
	}
	printf("��ѧ�������ڣ�\n");
}

void Modify(struct student *s)
{
	int number = 0;
	printf("������Ҫ�޸�ѧ����ѧ�ţ�");
	scanf("%d", &number);
	//�жϸ�ѧ����Ϣ�Ƿ���¼��
	for (int i = 0; i< stu_num + member; i++)
	{
		if (s[i].num == number)
		{
			Print(s);
			printf("��ѧ������Ϣ¼�룺\n");
			Input(s);
			Print(s);
			return;
		}
	}
	printf("��ѧ�������ڣ�\n");
}

void menu_search()
{
	printf("************************************\n");
	printf("*******     1����ѧ�Ų�ѯ   ********\n");
	printf("*******     2�����ɼ���ѯ   ********\n");
	printf("************************************\n");
	printf("��ѡ��");
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
			return;
		}
		else 
		{
			printf("���޴��ˣ�\n");
		}
	}
}


void Score(struct student *s)
{
	int score = 0;
	printf("������Ҫ��ѯѧ���ĳɼ���");
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
		Number(s);
		break;
	case 2:
		Score(s);
		break;
	default:
		printf("��������\n");
		break;
	}
}
