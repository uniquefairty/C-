#include<stdio.h>
#include<Windows.h>
//¼ÆËã1/1-1/2+1/3-1/4+1/5 ¡­¡­ + 1/99 - 1/100 µÄÖµ¡£
int main()
{
	int i = 0;
	int flag = 1;
	double sum = 0;
	for (i = 1; i < 100; i++)
	{
		sum += flag*1.0 / i;
		flag *= -1;
	}
	printf("%.8f\n", sum);
	system("pause");
	return 0;
}