#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <stdbool.h>
using namespace std;

const int N = 1e3 + 10;

int pro_num;            // 进程数
int res_num;            // 资源数
int Available[N];       // 可利用资源数

int Allocation[N][N];   // 已分配矩阵
int Max[N][N];          // 最大矩阵---------------------------------------------------------------------
int Need[N][N];         // 仍需求资源矩阵
						// Need[i][j] = Max[i][j] - Allocation[i][j]

int Work[N][N];         // 工作向量（系统可提供给进程继续运行所需的各类资源数目）
						// 为了存储整个过程的 Work 变化

int Work_add_All[N][N]; // 用来存储安全性检查过程中的Work+Allocation数据
int safe_list[N];       // 安全队列
int safe_count;         // 安全数列中元素个数
bool Finish[N];         // 标记系统是否有足够资源分配给进程并使之运行完成
int re_pro_num;         // 请求进程对应编号
int requset_res[N];     // 请求资源数

void get_res();         // 获取资源相关信息
void get_pro();         // 获取进程相关信息
void request();         // 请求资源
bool safe_check();      // 安全性检测
void menu();            // 菜单栏
void display();         // 展示资源分配状况


void get_res()			// 获取资源相关信息
{
	printf("请输入资源的类数： ");
	scanf("%d", &res_num);
	printf("请输入各类资源的总数：");
	for (int i = 1; i <= res_num; i++)
	{
		scanf("%d", &Available[i]);
	}
	printf("-------------------------------------------------\n");
}

void get_pro()			// 获取进程相关信息
{
	printf("请输入进程的个数： ");
	scanf("%d", &pro_num);
	for (int i = 1; i <= pro_num; i++) 
	{
		printf("请输入第%d个进程需要资源的个数： ", i);
		for (int j = 1; j <= res_num; j++)
		{
			scanf("%d", &Max[i][j]);
		}
		printf("请输入第%d个进程已经分配的资源的个数： ", i);
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

void show()    //显示进程信息
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

void display()  //显示资源分配信息
{
	printf("\n\n----------------资源分配情况----------------\n");
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

bool safe_check()			//安全性检测函数
{
	safe_count = 1;
	printf("-------------------安全性检测------------------\n");
	memset(Finish, false, sizeof Finish);
	for (int i = 1; i <= res_num; i++)
	{
		Work[1][i] = Available[i];
	}

	for (int i = 1; i <= pro_num; i++)
	{
		// 标记是否还存在 Finish[i] = false && Need[i][j]<=Work[j]
		bool flag = false;
		for (int j = 1; j <= pro_num; j++)
		{
			if (Finish[j])
				continue;
			// 标记该进程是否满足 Finish[i] = false && Need[i][j]<=Work[j]
			bool flag_satisfy = true;
			for (int k = 1; k <= res_num; k++)
			{
				if (Need[j][k] > Work[safe_count][k])
					flag_satisfy = false;
			}

			if (flag_satisfy)
			{
				//若该进程满足条件，则将其加入安全序列，并更新Work向量
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
	printf("\n系统安全,存在安全序列：");
 
	string str[15] = { "Work|","Need|","All|","Work+All|","Finish|","R","P()","Pro|","Res","","|" };
	for (int i = 1; i < safe_count - 1; i++)
		cout << setw(7) << "P(" + to_string(safe_list[i]) + ")-->";
	cout << "P(" + to_string(safe_list[safe_count - 1]) + ")";

	printf("\n");
	return true;

}

void request()					//资源请求
{
	printf("请输入请求资源的进程：");
	scanf("%d", &re_pro_num);
	printf("请输入进程%d对资源的请求:  ", re_pro_num); //（两种资源之间用空格或换行符隔开）, res_num

	bool flag1 = false;     // 标记请求的资源数量是否超过了所需要的资源数量
	bool flag2 = false;     // 标记请求的资源数量是否超过了当前所能利用的资源数量

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
			printf("\n请求的资源数量超过了所需要的资源数量和当前所能利用的资源数量!\n");
		}
		else if (flag1)
		{
			printf("\n请求的资源数量超过了所需要的资源数量，无法满足！\n");
		}
		else
		{
			printf("\n请求的资源数量超过了当前所能利用的资源数量，让其等待!\n");
		}
	}
	else
	{
		//试分配
		for (int i = 1; i <= res_num; i++)
		{
			Available[i] -= requset_res[i];
			//更新进程资源分配状况，即更新 All 和 Need
			Allocation[re_pro_num][i] += requset_res[i];
			Need[re_pro_num][i] -= requset_res[i];
		}
		display();          //展示当前资源分配状况

		//检查系统安全性
		if (safe_check())
		{
			//系统安全，分配资源给进程，展示分配状况
			display();      
		}
		else
		{
			//系统不安全，恢复分配资源前可利用资源分配状态
			printf("此时系统不安全，不为进程 P(%d)分配资源，让其等待！\n", re_pro_num - 1);
			for (int i = 1; i <= res_num; i++)
			{
				//将资源重新还给系统
				Available[i] += requset_res[i];
				Allocation[re_pro_num][i] -= requset_res[i];
				Need[re_pro_num][i] += requset_res[i];
			}
		}
	}
	printf("------------------------------------------------\n");
}

void menu()				//菜单函数
{
	printf("\n\n");
	printf("---------------------------------------\n");
	printf("----	1.请求资源               ------\n");
	printf("----	2.显示当前资源分配情况	 ------\n");
	printf("----	3.退出               	 ------\n");
	printf("---------------------------------------\n");
}

void Logic()				//逻辑函数
{
	while (1)
	{
		printf("--------------------银行家算法--------------------\n");
		get_res();                  // 获取资源信息
		get_pro();                  // 获取进程信息
		display();					// 显示进程信息
		printf("\n检查T0时刻的系统安全性：\n\n");
		bool safe = safe_check();   // 检查T0时刻的系统安全性
		bool over = false;          // 结束的标志
		while (!over)
		{
			menu();
			int ope = 0;                // 选择操作
			printf("请输入要执行的操作：");
			scanf("%d", &ope);
			if (!safe)
				printf("系统处于不安全状态！\n");
			switch (ope)
			{
			case 1:
				request();      // 请求资源
				break;
			case 2:
				display();      // 展示当前资源分配状况
				break;
			case 3:
				over = true;    // 结束此次算法
				exit(0);
				break;
			default:
				printf("操作无效!\n");
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
//bool Safe()    //安全性算法
//{
//	int i, j, k, l = 0;
//	int Work[MAX_RESOURCE]; //工作数组,他表示系统可提供给进程继续运行所需的各类资源数目  
//	int Finish[MAX_PROCESS];  //系统是否有足够的资源分配给进程，使之运行完成 
//	for (i = 0; i<m; i++)   //工作数组初始化 
//	{
//		Work[i] = Available[i];
//	}
//	//Finish每个进程是否安全
//
//	memset(Finish, 0, sizeof(Finish));
//	int l = 0;
//	int p[100] = { 0 };
//for (int i = 0; i<pro_num; i++)
//		{
//			if (Finish[i]) continue;
//			for (int j = 0; j<res_num; j++)//循环查找第i个进程需要的各个资源数是否超过系统现有的对应的资源数  
//			{
//				第i个进程需要的第j个资源数 ＞ 系统现有的第j个资源数 
//				if (Need[i][j] > Work[j]) break;
//			}
//			if (int j == res_num)//如果第i个进程所需的各个资源数都没有超过系统现有的对应资源数  
//			{
//				Finish[i] = 1;//给该进程的FINISH标记为true  
//				for (int k = 0; k<res_num; k++)
//				{
//					Work[k] = Work[k] + Allocation[i][k];//将Work赋值为第i个进程各个已分配资源数＋系统现有的对应资源数(因为当改进程全部资源数都满足时线程结束并将资源返还给系统)  
//				}
//				p[l++] = i;//记录进程号  
//				i = -1;
//			}
//			else continue; //如果超过继续循环下一个进程 
//			if (l == pro_num)//当所有进程都能够被满足运行时  
//			{
//				printf("系统是安全的\n");
//				printf("安全序列为:\n");
//				for (int k = 0; k<l - 1; k++)
//				{
//					printf("%d-->", p[k]);
//				}
//				printf("%d\n", p[l - 1]);
//				return true;
//			}
//		}
//		printf("系统是不安全的\n");
//		return false;
//	}
//}
