#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
#define MAX 256
//14.判断是否为回文数121 1221 顺读逆读一样
int fun(num)
{
	num=

}
int main()
{
	int num = 121;

	fun(num);
}

//13.两个字符串，从第一个字符串中删除第二个字符串中所有的字符
char *DeleteChars(char *str1,char *str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	int hashtable[MAX] = { 0 };

	while ( *str2 != '\0')//将str2中字符对应的hashtable数组中的位置上的值设为1
	{
		hashtable[*str2] = 1;
		++str2;
	}

	char *p = str1;
	char *q = str1;

	while (*p != '\0')
	{
		if (!hashtable[*p])
		{
			*q = *p;
			q++;
		}
		p++;
	}
	*q = '\0';
	return str1;
}
int main13()
{
	char str1[] = "They are students.";
	char str2[]= "aeiou";
	printf("%s",DeleteChars(str1, str2));
	system("pause");
	return 0;
}
//12.找出数组中两个唯一出现一次的数字
int fun(int num)
{
	int count = 1;
	while (num)
	{
		if (num & 1 == 1)
		{
			return count;
		}
		num >>= 1;
		count++;
	}
}

int main12()
{
	int arr[] = { 1, 3, 5, 7, 1, 3, 5, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int add = 0;
	int pos = 0;
	int res1=0, res2=0;

	for (i = 0; i < len; i++)
	{
		add ^= arr[i];
	}

	pos=fun(add);


	for (i = 0; i < len; i++)
	{
		if ((arr[i] >> pos) & 1 ==1)
		{
		   res1^= arr[i];
		}
		else
		{
			res2^= arr[i];
		}
	}

	printf("%d,%d\n", res1, res2);
	system("pause");
	return 0;
}
//11.找出字符串中第一次重复出现的字符
int main11()
{
	char str[] = "qywyer23tdd";
	int i = 0;
	int arr[256] = { 0 };
	for (i = 0; i < strlen(str); i++)
	{
		arr[str[i]]++;
	}

	for (i = 0; i < strlen(str); i++)//c语言中的ascll码值一共256个
	{
		if (arr[str[i]] == 2)
		{
			printf("%c\n", str[i]);
			break;
		}
	}
	system("pause");
	return 0;
}

//10.找出字符串第一次出现一次的字符
int main10()
{
	char str[]="abaccdeff";
	int i = 0;
	int arr[256] = { 0 };//c语言中的ascll码值一共256个
	for (i = 0; i < strlen(str); i++)
	{
		arr[str[i]]++;
	}

	for (i = 0; i < strlen(str); i++)
	{
		if (arr[str[i]] == 1)
		{
			printf("%c\n", str[i]);
			break;
		}
	}
	/*for (i = 0; i < len-1; i++)
	{
		res ^= str[i];
	}
	printf("%c ", res);
	*/

	system("pause");
	return 0;
}
//9.数组中一个或连续的多个整数组成的子数组，求所有子树组的和的最大值
//因为时间复杂度为O(n)，则只能遍历一次数组，这里同时使用两个变量sum和max，
//其中sum保存的是当前的和，若sum<0，则从下一个位置从新记录，
//max记录的是历史的最大值，只有当sum>max时用sum替换max。
int FindAddMax(int *arr, int len)
{
	if (*arr == NULL || len == 0)
	{
		return;
	}
	int sum = 0;
	int max = arr[0];
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (sum <= 0)//上次循环所得的值<0,说明加的是负数
		{
			sum = arr[i];//从当前的数字重新开始累加
		}
		else
		{
			sum += arr[i];
		}

		if (sum>max)
		{
			max = sum;
		}
	}

	//for (i = 0; i < len; i++)
	//{
	//	sum +=arr[i];
	//	if (sum < 0)
	//	{
	//		sum = 0;//sum重新初始化
	//	}
	//	if (sum>max)
	//	{
	//		max = sum;
	//	}
	//}

	return max;
}

int main9()
{
	int arr[] = { 1. - 2, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int res = FindAddMax(arr, len);
	printf("%d", res);
	system("pause");
	return 0;
}
//8 求出现次数超过数组一半的数字
int main8()
{
	int a[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int num = sizeof(a) / sizeof(a[0]);
	int i = 0;

	int b[10] = { 0 };

	for (i = 0; i<num; i++)
	{
		b[a[i]]++;
	}
	for (i = 0; i<10; i++)
	{
		if (b[i]>num / 2)
		{
			printf("%d", i);

		}
	}

	system("pause");
	return 0;

}
//7.求数组前k个最小的值
int FunMin(int *arr,int k)
{
	int min = arr[0];
	int i = 0;

	for (i = 0; i < k; i++)
	{
		if (min>arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}

int main7()
{
	int arr[20] = { 3, 4, 5, 6, 34, 2 };
	int k = 4;
	int res=FunMin(arr, k);
	printf("%d", res);
	system("pause");
	return 0;
}
//4.求unsigned int 型变量x在内存中二进制1的个数
int main4_()
{
	unsigned int x = 236;
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);//每次消去一个1
	}
	printf("%d", count);
	system("pause");
	return 0;
}

int main4()
{
	unsigned int x = 236;
	int count = 0;
	for (; x > 0; x >>= 1)
	{
		if (x & 1 == 1)
		{  
			count++;
		}
	}
	printf("%d", count);
	system("pause");
	return 0;
}
//3.斐波那契数0 1 1 2 3 5 8
Print(int *a,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
int fib1(int n)//递归求第n个斐波那契数
{
	if (n <= 2)
	{
		return 1;
	}
	return fib1(n - 1) + fib1(n - 2);
}
int fib2(int n)//非递归求第n个斐波那契数
{
	int first = 0;
	int scend = 1;
	int third = 1;

	while (n > 2)
	{
		first = scend;
		scend = third;
		third = first + scend;
		n--;
	}

	return third;

}
void fib(int *a,int n)//非递归求前n个斐波那契数
{
	int i = 0;
	a[0] = 0;
	a[1] = 1;
	if (n < 2)
	{
		Print(a,n);
		return;
	}
	for (i= 2; i< n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	Print(a, n);
}

int main3()
{
	int n;
	//int arr[100] = { 0 };
	scanf("%d", &n);

	int res=fib2(n);
	printf("%d", res);

	//fib(arr,n);
	system("pause");
	return 0;
}

//****2**********************
void Move(char *str, int p,int num)
{
	for (num; num>p+1; num--)
	{
		str[num+1] = str[num - 1];
	}
	str[p] = '%';
	str[p + 1] = '2';
	str[p + 2] = '0';
}

int main2()
{
	char str[20] = "abc defgx yz";
	int num = strlen(str);
	int i = 0;
	for (; str[i];i++)
	{
		if (str[i]== ' ')
		{
			Move(str, i,num);
			num+=2;
		}
	}

	//puts(str);
	
	for (i = 0; i < num; i++)
	{
		printf("%c", str[i]);
	}
	system("pause");
	return 0;

}
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
int main——()
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
//1.在一个二维数组中，每一行都按照从左往右递增的顺序排序，请完成一个函数，
//输入这样的一个二维和一个整数，判断数组中是否有该整数。时间复杂度O（row+col）
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
			printf("有这个数字\n");
			return;
		}
	}
	printf("没有这个数字\n");
}

int main()
{
	int arr[ROW][COL] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int num=0;
	printf("请输入你要查找的数字：");
	scanf("%d",&num);	
	FunNum(arr, num, ROW, COL);
	system("pause");
	return 0;
}
#endif
