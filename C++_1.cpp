//#include<iostream>
//using namespace std;
//
////��ͨ�������ռ�
//namespace  N
//{
//	int a = 10;
//	int b = 20;
//	int add(int left, int right)
//	{
//		return left + right;
//	}
//	int sub(int left, int right)
//	{
//		return left - right;
//	}
//}
//using N::a;
//int main()
//{
//	printf("%d\n", a);
//	return 0;
//}
//Ƕ�������ռ�
//namespace N2
//{
//	int a = 20;
//	int sub(int left, int right)
//	{
//		return left - right;
//	}
//	namespace N3
//	{
//		int a = 30;
//		int mul(int left, int right)
//		{
//			return left * right;
//		}
//	}
//}
//
//namespace N1
//{
//	int Mul(int left, int right)
//	{
//		return left * right;
//	}
//}



//int main()
//{
//	int a = 10;
//	char b = 'b';
//	double c;
//	cin >> c;
//	cout << a << " " << b << " " << c << endl;
//	return 0;
//}
//
//extern "C" int add(int a, int b);
//
//int main()
//{
//	add(1, 2);
//	return 0;
//}

//void Test()
//{
//	int a = 10;
//	int &ra;//�ᱨ������ra��Ҫ��ʼ��
//	int &ra = a;
//	int &rra = a;
//	cout << &a << &ra << &rra << endl;
//}
//void Test()
//{
//	const int a = 10;
//	//int& ra = a;  // ����ʱ����aΪ���� 
//	const int& ra = a; 
//	//int& rb = b; // ����ʱ����bΪ���� 
//	const int& rb = b;
//	double c = 12.34;
//	//int &rc = c;   // ����ʱ�������Ͳ�ͬ 
//	const int &rc = c;
//}

//int &add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int &ret = add(1, 2);
//	add(3, 4);
//	cout << ret << endl;
//	return 0;
//}
//
//inline int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	return 0;
//}
//#include <time.h> 
//
//struct A
//{
//	int a[100000];
//};
//
//A a;
//
//A* TestFun1()
//{
//	return &a;
//}
//A& TestFun2()
//{
//	return a;
//}
//void TestRefAndPtr()
//{   
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFun1();
//	size_t end1 = clock();
//
//	// ��������Ϊ��������    
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFun2();
//	size_t end2 = clock();
//
//	// ���������������н������ʱ��    
//	cout << "TestFunc1(int*):" << end1 - begin1 << endl;
//	cout << "TestFunc2(int&):" << end2 - begin2 << endl;
//	cout << "=======================\n";
//}
//
//int main()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		TestRefAndPtr();
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
void test(int)
{
	cout << test() << endl;
}
void test(int *)
{
	cout << test(int *) << endl;
}
