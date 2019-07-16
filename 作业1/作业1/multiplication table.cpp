#include<stdio.h>
#include<windows.h>
void Show(int n)
{
	int i ;
	for (i=1; i <= n; i++)//一共几行
	{
		int j ;
		for (j=1; j <= i; j++)//每行几个式子
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