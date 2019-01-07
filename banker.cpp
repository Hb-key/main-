#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <stdbool.h>
using namespace std;

const int N = 1e3 + 10;

// ����
int pro_num;            // ������
int res_num;            // ��Դ��
int Available[N];       // ��������Դ��

int Allocation[N][N];   // �ѷ������
int Max[N][N];          // ������---------------------------------------------------------------------
int Need[N][N];         // ��������Դ����
						// Need[i][j] = Max[i][j] - Allocation[i][j]

int Work[N][N];         // ����������ϵͳ���ṩ�����̼�����������ĸ�����Դ��Ŀ��
						// Ϊ�˴洢�������̵� Work �仯

int Work_add_All[N][N]; // �����洢��ȫ�Լ������е�Work+Allocation����
int safe_list[N];       // ��ȫ����
int safe_count;         // ��ȫ������Ԫ�ظ���
bool Finish[N];         // ���ϵͳ�Ƿ����㹻��Դ��������̲�ʹ֮�������
int re_pro_num;         // ������̶�Ӧ���
int requset_res[N];     // ������Դ��

//����
void get_res();         // ��ȡ��Դ�����Ϣ
void get_pro();         // ��ȡ���������Ϣ
void request();         // ������Դ
bool safe_check();      // ��ȫ�Լ��
void menu();            // �˵���
void display();         // չʾ��Դ����״��


void get_res()			// ��ȡ��Դ�����Ϣ
{
	printf("��������Դ�������� ");
	scanf("%d", &res_num);
	printf("�����������Դ��������");
	for (int i = 1; i <= res_num; i++)
	{
		scanf("%d", &Available[i]);
	}
	printf("-------------------------------------------------\n");
}

void get_pro()			// ��ȡ���������Ϣ
{
	printf("��������̵ĸ����� ");
	scanf("%d", &pro_num);
	for (int i = 1; i <= pro_num; i++) 
	{
		printf("�������%d��������Ҫ��Դ�ĸ����� ", i);
		for (int j = 1; j <= res_num; j++)
		{
			scanf("%d", &Max[i][j]);
		}
		printf("�������%d�������Ѿ��������Դ�ĸ����� ", i);
		for (int j = 1; j <= res_num; j++) 
		{
			scanf("%d", &Allocation[i][j]);
			Need[i][j] = Max[i][j] - Allocation[i][j];
			Available[j] -= Allocation[i][j];
		}
		printf("\n");
	}
	printf("------------------------------------------------\n\n");
}

void show()    //��ʾ������Ϣ
{
	string str[15] = { "Work|","Need|","All|","Work+All|","Finish|","R","P()","Pro|","Res","","|" };
	cout << setw(10) << str[7] << setw(5) << str[9];
	for (int i = 1; i<safe_count; i++) 
		cout << setw(7) << "P(" + to_string(safe_list[i]) + ")";
	cout << endl;
	cout << setw(10) << str[10] << setw(5) << str[8] << endl;

	for (int i = 0; i<5; i++)
	{
		printf("------------------------------------------------\n");
		if (i == 4)
		{
			cout << setw(10) << str[i] << setw(5) << str[9];
			for (int j = 1; j<safe_count; j++)
			{
				int now = safe_list[j] + 1;
				cout << setw(6) << ((Finish[now] == true) ? "T" : "F") << " ";
			}
			printf("\n");
			break;
		}
		for (int j = 1; j <= res_num; j++)
		{
			cout << setw(10) << ((j == 1) ? str[i] : str[10]) << setw(5) << str[5] + to_string(j);
			if (i == 0) 
				for (int k = 1; k<safe_count; k++) 
					printf("%6d ", Work[k][j]);
			else if (i == 1)
				for (int k = 1; k<safe_count; k++)
					printf("%6d ", Need[safe_list[k] + 1][j]);
			else if (i == 2) 
				for (int k = 1; k<safe_count; k++) 
					printf("%6d ", Allocation[safe_list[k] + 1][j]);
			else
				for (int k = 1; k<safe_count; k++) 
					printf("%6d ", Work_add_All[k][j]);
			printf("\n");
		}
	}
}

void display()  //��ʾ��Դ������Ϣ
{
	printf("\n\n----------------��Դ�������----------------\n");
	string str[15] = { "Max|","All|","Need|","Avl|","R","P()","Pro|","Res","","|" };
	cout << setw(5) << str[6] << setw(5) << str[8];
	for (int i = 0; i<pro_num; i++) 
		cout << setw(6) << "P(" + to_string(i) + ")";
	cout << endl << setw(5) << str[9] << setw(5) << str[7] << endl;

	for (int i = 0; i<4; i++) 
	{
		printf("----------------------------------------\n");
		for (int j = 1; j <= res_num; j++)
		{
			cout << setw(5) << ((j == 1) ? str[i] : str[10]) << setw(5) << str[4] + to_string(j);
			if (i == 0)
			{
				for (int k = 1; k <= pro_num; k++)
					printf("%5d ", Max[k][j]);
			}
			else if (i == 1)
			{
				for (int k = 1; k <= pro_num; k++)
				{
					printf("%5d ", Allocation[k][j]);
				}
			}
			else if (i == 2)
			{
				for (int k = 1; k <= pro_num; k++)
				{
					printf("%5d ", Need[k][j]);
				}
			}
			else
			{
				printf("%5d ", Available[j]);
			}
			printf("\n\n");
		}
	}
}

bool safe_check()			//��ȫ�Լ��
{
	safe_count = 1;
	printf("-------------------��ȫ�Լ��-------------------\n");
	memset(Finish, false, sizeof Finish);
	for (int i = 1; i <= res_num; i++)
	{
		Work[1][i] = Available[i];
	}

	for (int i = 1; i <= pro_num; i++)
	{
		// ����Ƿ񻹴��� Finish[i] = false && Need[i][j]<=Work[j]
		bool flag = false;
		for (int j = 1; j <= pro_num; j++)
		{
			if (Finish[j])
				continue;
			// ��Ǹý����Ƿ����� Finish[i] = false && Need[i][j]<=Work[j]
			bool flag_satisfy = true;
			for (int k = 1; k <= res_num; k++)
			{
				if (Need[j][k] > Work[safe_count][k])
					flag_satisfy = false;
			}

			if (flag_satisfy)
			{
				//���ý�������������������밲ȫ���У�������Work����
				flag = Finish[j] = true;
				safe_list[i] = j - 1;
				printf("P(%d)", j - 1);
				for (int k = 1; k <= res_num; k++)
				{
					Work[safe_count + 1][k] = Work[safe_count][k] + Allocation[j][k];
					Work_add_All[safe_count][k] = Work[safe_count + 1][k];
				}
				safe_count++;
				printf("\t\tTRUE\n");
				break;
			}
		}
		if (flag == false && i <= pro_num)
		{
			show();
			return false;
		}
	}
	show();
	printf("\nϵͳ��ȫ,���ڰ�ȫ���У�");
 
	string str[15] = { "Work|","Need|","All|","Work+All|","Finish|","R","P()","Pro|","Res","","|" };
	for (int i = 1; i < safe_count - 1; i++)
		cout << setw(7) << "P(" + to_string(safe_list[i]) + ")-->";
	cout << "P(" + to_string(safe_list[safe_count - 1]) + ")";

	printf("\n");
	return true;

}

void request()					//��Դ����
{
	printf("������������Դ�Ľ��̣�");
	scanf("%d", &re_pro_num);
	printf("���������%d����Դ������:  ", re_pro_num); //��������Դ֮���ÿո���з�������, res_num

	bool flag1 = false;     // ����������Դ�����Ƿ񳬹�������Ҫ����Դ����
	bool flag2 = false;     // ����������Դ�����Ƿ񳬹��˵�ǰ�������õ���Դ����

	for (int i = 1; i <= res_num; i++)
	{
		scanf("%d", &requset_res[i]);
		if (requset_res[i] > Need[re_pro_num][i])
		{
			flag1 = true;
		}
		if (requset_res[i] > Available[i])
		{
			flag2 = true;
		}
	}
	if (flag1 || flag2)
	{
		if (flag1 && flag2)
		{
			printf("\n�������Դ��������������Ҫ����Դ�����͵�ǰ�������õ���Դ����!\n");
		}
		else if (flag1)
		{
			printf("\n�������Դ��������������Ҫ����Դ�������޷����㣡\n");
		}
		else
		{
			printf("\n�������Դ���������˵�ǰ�������õ���Դ����������ȴ�!\n");
		}
	}
	else
	{
		//�Է���
		for (int i = 1; i <= res_num; i++)
		{
			Available[i] -= requset_res[i];
			//���½�����Դ����״���������� All �� Need
			Allocation[re_pro_num][i] += requset_res[i];
			Need[re_pro_num][i] -= requset_res[i];
		}
		display();          //չʾ��ǰ��Դ����״��

		//���ϵͳ��ȫ��
		if (safe_check())
		{
			//ϵͳ��ȫ��������Դ�����̣�չʾ����״��
			display();      
		}
		else
		{
			//ϵͳ����ȫ���ָ�������Դǰ��������Դ����״̬
			printf("��ʱϵͳ����ȫ����Ϊ���� P(%d)������Դ������ȴ���\n", re_pro_num - 1);
			for (int i = 1; i <= res_num; i++)
			{
				//����Դ���»���ϵͳ
				Available[i] += requset_res[i];
				Allocation[re_pro_num][i] -= requset_res[i];
				Need[re_pro_num][i] += requset_res[i];
			}
		}
	}
	printf("------------------------------------------------\n");
}

void menu()				//�˵�
{
	printf("\n\n");
	printf("---------------------------------------\n");
	printf("----	1.������Դ               ------\n");
	printf("----	2.��ʾ��ǰ��Դ�������	 ------\n");
	printf("----	3.�˳�               	 ------\n");
	printf("---------------------------------------\n");
}

void Logic()				//�߼�����
{
	while (1)
	{
		printf("--------------------���м��㷨--------------------\n");
		get_res();                  // ��ȡ��Դ��Ϣ
		get_pro();                  // ��ȡ������Ϣ
		display();					// ��ʾ������Ϣ
		printf("\n���T0ʱ�̵�ϵͳ��ȫ�ԣ�\n\n");
		bool safe = safe_check();   // ���T0ʱ�̵�ϵͳ��ȫ��
		bool over = false;          // �����ı�־
		while (!over)
		{
			menu();
			int ope = 0;                // ѡ�����
			printf("������Ҫִ�еĲ�����");
			scanf("%d", &ope);
			if (!safe)
				printf("ϵͳ���ڲ���ȫ״̬��\n");
			switch (ope)
			{
			case 1:
				request();      // ������Դ
				break;
			case 2:
				display();      // չʾ��ǰ��Դ����״��
				break;
			case 3:
				over = true;    // �����˴��㷨
				exit(0);
				break;
			default:
				printf("������Ч!\n");
				break;
			}
		}
	}
}

int main()
{
	Logic();
	return 0;
}










//
//bool Safe()    //��ȫ���㷨
//{
//	int i, j, k, l = 0;
//	int Work[MAX_RESOURCE]; //��������,����ʾϵͳ���ṩ�����̼�����������ĸ�����Դ��Ŀ  
//	int Finish[MAX_PROCESS];  //ϵͳ�Ƿ����㹻����Դ��������̣�ʹ֮������� 
//	for (i = 0; i<m; i++)   //���������ʼ�� 
//	{
//		Work[i] = Available[i];
//	}
//	//Finishÿ�������Ƿ�ȫ
//
//	memset(Finish, 0, sizeof(Finish));
//	int l = 0;
//	int p[100] = { 0 };
//for (int i = 0; i<pro_num; i++)
//		{
//			if (Finish[i]) continue;
//			for (int j = 0; j<res_num; j++)//ѭ�����ҵ�i��������Ҫ�ĸ�����Դ���Ƿ񳬹�ϵͳ���еĶ�Ӧ����Դ��  
//			{
//				��i��������Ҫ�ĵ�j����Դ�� �� ϵͳ���еĵ�j����Դ�� 
//				if (Need[i][j] > Work[j]) break;
//			}
//			if (int j == res_num)//�����i����������ĸ�����Դ����û�г���ϵͳ���еĶ�Ӧ��Դ��  
//			{
//				Finish[i] = 1;//���ý��̵�FINISH���Ϊtrue  
//				for (int k = 0; k<res_num; k++)
//				{
//					Work[k] = Work[k] + Allocation[i][k];//��Work��ֵΪ��i�����̸����ѷ�����Դ����ϵͳ���еĶ�Ӧ��Դ��(��Ϊ���Ľ���ȫ����Դ��������ʱ�߳̽���������Դ������ϵͳ)  
//				}
//				p[l++] = i;//��¼���̺�  
//				i = -1;
//			}
//			else continue; //�����������ѭ����һ������ 
//			if (l == pro_num)//�����н��̶��ܹ�����������ʱ  
//			{
//				printf("ϵͳ�ǰ�ȫ��\n");
//				printf("��ȫ����Ϊ:\n");
//				for (int k = 0; k<l - 1; k++)
//				{
//					printf("%d-->", p[k]);
//				}
//				printf("%d\n", p[l - 1]);
//				return true;
//			}
//		}
//		printf("ϵͳ�ǲ���ȫ��\n");
//		return false;
//	}
//}