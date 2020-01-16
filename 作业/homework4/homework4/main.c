#include<stdio.h>
#include<Windows.h>
#include<math.h>
//2.求出0～999之间的所有“水仙花数”并输出。
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，
//如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。
///*
//在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、
//阿姆斯壮数或阿姆斯特朗数（Armstrong number），是指一N位数，
//其各个数之N次方和等于该数。
//例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
//153 = 1^3 + 5^3 + 3^3。
//370 = 3^3 + 7^3 + 0^3。
//371 = 3^3 + 7^3 + 1^3。
//407 = 4^3 + 0^3 + 7^3。
//*/
//3.
//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
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
	}//上半部分
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