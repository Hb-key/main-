#define _CRT_SECURE_NO_WARNINGS
#include"Stu_ach_manage.h"

void menu()
{
	printf("***********************************************\n");
	printf("**********      ѧ���ɼ�����ϵͳ      *********\n");
	printf("***********************************************\n");
	printf("**********     1��¼��ѧ����Ϣϵͳ    *********\n");
	printf("**********     2��ɾ��ѧ����Ϣϵͳ    *********\n");
	printf("**********     3���޸�ѧ����Ϣϵͳ    *********\n");
	printf("**********     4����ѯѧ����Ϣϵͳ    *********\n");
	printf("**********     5�����ѧ����Ϣϵͳ    *********\n");
	printf("**********     6���˳�ϵͳ            *********\n");
	printf("***********************************************\n");
}

void Logic(struct student *s)
{
	while (1)
	{
		menu();
		printf("��ѡ��");
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
			printf("�˳�ϵͳ������\n");
			break;
		default:
			printf("�����������������룡");
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