#include<stdio.h>
#include<windows.h>
void Show(int n)
{
	int i ;
	for (i=1; i <= n; i++)//һ������
	{
		int j ;
		for (j=1; j <= i; j++)//ÿ�м���ʽ��
		{
			printf("%d*%d=%d  ", i, j, i*j);
		}
		printf("\n");
	}
}
int main()
{
	Show(9);
	system("pause");
	return 0;
}