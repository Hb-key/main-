//#include<iostream>
//using namespace std;
//
//#define min(a,b) a>b?a:b
//
//int Fibonacci(int n)
//{
//	if (n < 0)
//		return ;
//	else
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//
//int main()
//{
//	int x = 0;
//	cin >> x;
//	int n = min((x - 1), (x + 1));
//
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int N;
//	cin >> N;
//	int f_0 = 0;
//	int f_1 = 1;
//	int f_2;
//	while (1)
//	{
//		if (N >= f_0 && N <= f_1)
//		{
//			int minDis;
//			minDis = min(abs(N - f_0), abs(N - f_1));
//			cout << minDis << endl;
//			break;
//		}
//		f_2 = f_0 + f_1;
//		f_0 = f_1;
//		f_1 = f_2;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//
////6 -2 -3 7 -15 1 2
//
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		// if (array.size() == 0) 
//		//   return 0; 
//		int curSum = 0;
//		int maxSum = array[0];
//		for (int i = 0; i < array.size(); i++)
//		{
//			curSum += array[i];
//			if (curSum > maxSum)
//				maxSum = curSum;
//			if (curSum < 0)
//				curSum = 0;
//		}
//		return maxSum;
//	}
//};


#include<iostream>
using namespace std;
//coco
int main()
{
	char str[] = "coco";
	getchar();
	
}