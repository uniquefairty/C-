#include<stdio.h>
#include<math.h>
#include<Windows.h>
//1. 打印100~200之间的素数
//2. 输出乘法口诀表
//3. 判断1000年-- - 2000年之间的闰年
int IsPrime(int  x)
{
	int i ;
	double top = sqrt((float)x);
	for (i=2; i<=top; i++)
	{
		if (x%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int x ;
	for (x=100; x <= 200; x++)
	{
		if (IsPrime(x)){
			printf("%d  ", x);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}