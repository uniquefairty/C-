#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)
/*1. 给定两个整形变量的值，将两个值的内容进行交换。
2. 不允许创建临时变量，交换两个数的内容（附加题） 
3.求10 个整数中最大值。 
4.将三个数按从大到小输出。 
5.求两个数的最大公约数。*/ 

#if 0
void JudgeLeapYear(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	{
		printf("%d is Leap year", y);
	}
	else{
		printf("%d is not Leap year", y);
	}
}
int main()
{
	int year = 0;
	scanf("%d",&year);
	JudgeLeapYear(year);
	system("pause");
	return 0;
}
#endif


#include<stdio.h>
#include<windows.h>
int Max()
{
	int a[] = { 34, 54, 67, 89, 456, 7456 };
	int num = sizeof(a) / sizeof(a[0]);
	int i = 1;
	int max = a[0];//最好不要引用其他数，（如0，负数）
	int second = a[0];
	for (; i < num; i++)
	{
		if (max < a[i]){
			second = max;
			max =a[i];
		}
	}
	printf("second:%d\n", second);
	return max;
}
void ThreeData(int x, int y, int z)
{
	if (x >y){
		if (z > x){//zxy
			printf("%d %d %d", z, x, y);
		}
		else if (z > y){//xzy
			printf("%d %d %d",x, z, y);
		}
		else{//xyz
			printf("%d %d %d", x,y,z);
		}
	}
	else{//y>=x
		if (z > y){//zyx
			printf("%d %d %d", z, y, x);
		}
		else if (z > x){//yzx
			printf("%d %d %d", y, z, x);
		}
		else{//yxz
			printf("%d %d %d", y, x,z);
		}
	}
}
int CommonDivision(int x, int y)
{
#if 0
	while (x*y!=0){
		if (x > y){
			x %= y;
		}
		else if (y > x){
			y %= x;
		}
		else{
			return x;
		}
	}
	return x == 0 ? y : x;
#else 
	while (1){
		if (x > y)
		{
			x = x - y;
		}
		else if (y > x)
		{
			y = y - x;
		}
		else
		{
			break;
		}
	}
	return x;

	//int min = x > y ? y : x;
	//while (min > 1){
	//	if (y%min == 0&&x%min==0){
	//		break;
	//	}
	//	min--;
	//}
	//return min;
#endif
}


int main()
{
	int x = CommonDivision(2, 3);
	//int x = CommonDivision(32, 24);
	printf("%d\n", x);
	//ThreeData(67, 89, 45);
	//printf("%d", Max());
	//int x = 100;
	//int y = 200;
	//printf("before:%d %d\n", x, y);
	//x = x + y;
	//y = x - y;
	//x = x - y;
	////x ^= y;//x=x^y;            x->x^y
	////y ^= x;//y=y^x-> y=y^x^y   y->x    支持交换律
	////x ^= y;//x=x^y-> x=x^y^x   x->y
	//printf("after:%d %d\n", x, y);
	system("pause");
	return 0;
}