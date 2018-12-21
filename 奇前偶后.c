//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10]={1,2,3,4,5,6,7,8,9,0};
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int left = 0;
//	int right = sz-1;
//	while(left<right)
// 	{
// 		while((left<right) && (arr[left]%2 ==1))
// 		{
// 			left++;
// 		}
// 		while((left<right) && (arr[right]%2 == 0))
// 		{
// 			right--;
// 		}
// 		if(left<right)
// 		{
// 			int tmp = arr[left];
// 			arr[left] = arr[right];
// 			arr[right] = tmp;
// 		}
// 	}
// 	printf("数组变换后：\n");
//	for(i=0; i<sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	return 0;
//}



// void Print(int arr[], int sz)
// {
// 	int i = 0;
// 	for(i=0; i<sz; i++)
// 	{
// 		printf("%d ", arr[i]);
// 	}
// }
// void Move(int arr[], int sz)
// {
// 	int left = 0;
// 	int right = sz-1;
// 
// 	//
// 	while(left<right)
// 	{
// 		while((left<right) && (arr[left]%2!=0))
// 		{
// 			left++;
// 		}
// 		while((left<right) && (arr[right]%2 == 0))
// 		{
// 			right--;
// 		}
// 		if(left<right)
// 		{
// 			int tmp = arr[left];
// 			arr[left] = arr[right];
// 			arr[right] = tmp;
// 		}
// 	}
// }
// int main()
// {
// 	int arr[] = {1,2,3,4,5,6,7,8,9,0};
// 	int sz = sizeof(arr)/sizeof(arr[0]);
// 	Move(arr, sz);
// 	Print(arr, sz);
// 	return 0;
// }


//#include<stdio.h>
//int Find(int arr[3][3], int *px, int *py, int k)
//{
//	int x = 0;
//	int y = *py-1;
//	while((x<*px) && (y>=0))
//	{
//		if(arr[x][y]<k)
//		{
//			x++;
//		}
//		else if(arr[x][y]>k)
//		{
//			y--;
//		}
//		else
//		{
//			*px = x + 1;
//			*py = y + 1;
//			return 1;
//		}
//	}
//	*px = -1;
//	*py = -1;
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = {1,2,3,4,5,6,7,8,9};
//	int k = 0;
//	int x = 3;
//	int y = 3;
//	printf("请输入要查找的数:");
//	scanf("%d",&k); 
//	int ret = Find(arr, &x, &y, k);
//	printf("横坐标为:%d 纵坐标为:%d\n", x, y);
//	return 0;
//}
//





