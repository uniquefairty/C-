#include<stdio.h>
#include<Windows.h>
#include<math.h>
//2.���0��999֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ�������
//�磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������
///*
//�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ����������������
//��ķ˹׳����ķ˹��������Armstrong number������ָһNλ����
//�������֮N�η��͵��ڸ�����
//����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
//153 = 1^3 + 5^3 + 3^3��
//370 = 3^3 + 7^3 + 0^3��
//371 = 3^3 + 7^3 + 1^3��
//407 = 4^3 + 0^3 + 7^3��
//*/
//3.
//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
void p1(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
#if 0
		for (j = 1; j <= n-i; j++)
		{
			putchar(' ');
		}
		for (j = 1; j <= 2 * i - 1; j++)
		{
			putchar('*');
		}
#else
		for (j = 1; j<n + i; j++)
		{
			putchar(j<=n - i ? ' ' : '*');
		}
		putchar('\n');
#endif
	}//�ϰ벿��
	for (i = n - 1; i > 0; i--)
	{
		for (j = 1; j < n + i; j++)
		{
			putchar(j<=n - i ? ' ' : '*');
		}
		putchar('\n');
	}
}

void p2()
{
	int i;
	int j;
	int num = 0;
	int modflag = 1;
	int sum = 0;
	for (i = 0; i < 1000; i++)
	{
		if (i%modflag == 0)
		{
			num++;
			modflag *= 10;
		}
		for (j = i; j; j /= 10)
		{
			sum += pow(j % 10, num);
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
		sum = 0;
	}
}
void p5(int m,int n)
{
	if (n == 1)
	{
		return m;
	}
	return p5()
}
int main()
{
	//p1(5);
	p2();
	p3(2,5);
	system("pause");
	return 0;
}