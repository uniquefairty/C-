#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)


int main_1()
{
	int a[] = { 2,4,6,8,10,12,14,16,18,20,22,24 };
	int *q[4];
	int k;

	for (k = 0; k < 4; k++)
	{
		q[k] = &a[k * 3];
	}
	printf("%d\n",q[3][1]);
	
	system("pause");
	return 0;
}
int main()
{
	int i, j, a = 0;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (j % 2)
				break;
			a++;
		}
		a++;
	}
	printf("%d\n",a);

	system("pause");
	return 0;
}
#if 0
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
#endif


////�д���
//void Fun(char *a, int len)
//{
//	int i, j;
//	for (i = 0; i < len; i++)
//	{
//		if (a[i] == ' ')
//		{
//			for (j = i; j < len; j++)
//			{
//				a[i + 1] = a[i];
//			}
//			a[i] = '%20';
//		}
//	}
//}
//int main����()
//{
//	char *a = "abc defgx yz";
//	Fun(a, sizeof(a) / sizeof(a[0]));
//	putchar(a);
//	system("pause");
//	return 0;
//}