#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

#define ROW 4
#define COL 4
//1.��һ����ά�����У�ÿһ�ж����մ������ҵ�����˳�����������һ��������
//����������һ����ά��һ���������ж��������Ƿ��и�������ʱ�临�Ӷ�O��row+col��

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
			printf("���������\n");
			return;
		}
	}
	printf("û���������\n");
}

int main()
{
	int arr[ROW][COL] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int num=0;
	printf("��������Ҫ���ҵ����֣�");
	scanf("%d",&num);	
	FunNum(arr, num, ROW, COL);
	system("pause");
	return 0;
}