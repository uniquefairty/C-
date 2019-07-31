#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

#define ROW 4
#define COL 4
//1.在一个二维数组中，每一行都按照从左往右递增的顺序排序，请完成一个函数，
//输入这样的一个二维和一个整数，判断数组中是否有该整数。时间复杂度O（row+col）

int FunNum(int arr[][COL], int num,int row,int col)
{
	int i = 0;
	int j = col-1;

	while (j>=0&&i<row)
	{
		if (num < arr[i][j])
		{
			j--;
		}
		else if (num >arr[i][j])
		{
			i++;
		}
		else
		{
			printf("有这个数字\n");
			return;
		}
	}
	printf("没有这个数字\n");
}

int main()
{
	int arr[ROW][COL] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int num=0;
	printf("请输入你要查找的数字：");
	scanf("%d",&num);	
	FunNum(arr, num, ROW, COL);
	system("pause");
	return 0;
}