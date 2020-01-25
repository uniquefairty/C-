//#include<stdio.h>
//#include<Windows.h>
//#pragma warning(disable:4996)
//int BinSearch(int a[], int n, int x)
//{
//	int left = 0;
//	int right = n - 1;
//	while (left <= right){
//		int mid = (left + right) / 2;
//		if (x>a[mid])
//		{
//			left = mid + 1;
//		}
//		else if (x < a[mid])
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int num = sizeof(a) / sizeof(a[0]);
//	printf("Enter Your Data For Search:");
//	int x = 0;
//	scanf("%d", &x);
//	int sub = BinSearch(a, num, x);
//	if (sub>=0)
//	{
//		////printf("%d\n",sub);
//	}
//	else{
//		printf("-1\n");
//	}
//	system("pause");
//	return 0;
//}