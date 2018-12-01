//#include<iostream>
//using namespace std;
//
////普通的命名空间
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
//嵌套命名空间
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
//	int &ra;//会报错，变量ra需要初始化
//	int &ra = a;
//	int &rra = a;
//	cout << &a << &ra << &rra << endl;
//}
//void Test()
//{
//	const int a = 10;
//	//int& ra = a;  // 编译时出错，a为常量 
//	const int& ra = a; 
//	//int& rb = b; // 编译时出错，b为常量 
//	const int& rb = b;
//	double c = 12.34;
//	//int &rc = c;   // 编译时出错，类型不同 
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
//	// 以引用作为函数参数    
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFun2();
//	size_t end2 = clock();
//
//	// 计算两个函数运行结束后的时间    
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
