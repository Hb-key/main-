#include"���̵���.h"

//void menu()
//{
//	printf("************************\n");
//	printf("****  1.�����ȷ���  ****\n");
//	printf("****  2.����ҵ����  ****\n");
//	printf("****  3.���ȼ�����  ****\n");
//	printf("****  4.ʱ��Ƭ��ת  ****\n");
//	printf("****  0.�˳�        ****\n");
//	printf("************************\n");
//}
//
//void Logic()
//{
//	menu();
//	int input;
//	printf("��ѡ������ʹ�õĽ��̵��ȵķ�ʽ��");
//	scanf("%d", &input);
//	switch (input)
//	{
//	case 0:
//		printf("�˳���\n");
//		break;
//	case 1:
//		printf("�����ȷ����㷨ģ��:\n");
//		GetInfo();
//		p = head;
//		FCFS();
//		break;
//	case 2:
//		printf("����ҵ�����㷨ģ��:\n");
//		GetInfo();
//		p = head;
//		SJF();
//		break;
//	case 3:
//		printf("���ȼ������㷨ģ��:\n");
//		GetInfo();
//		break;
//	case 4:
//		printf("ʱ��Ƭ��ת�㷨ģ��:\n");
//		GetInfo();
//		break;
//	default:
//		printf("������󣡣�\n");
//		break;
//	}
//}


int main()
{
	printf("�����ȷ����㷨ģ��:\n");
	GetInfo();
	p = head;
	FCFS();
	printf("����ҵ�����㷨ģ��:\n");
	GetInfo();
	p = head;
	SJF();
	return 0;
}