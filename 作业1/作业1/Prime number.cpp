#include<stdio.h>
#include<math.h>
#include<Windows.h>
//1. ��ӡ100~200֮�������
//2. ����˷��ھ���
//3. �ж�1000��-- - 2000��֮�������
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