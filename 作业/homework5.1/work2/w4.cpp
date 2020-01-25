#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#pragma warning (disable:4996)
void menue()
{
	printf("*****************\n");
	printf("**1.Play 2.Exit**\n");
	printf("*****************\n");
}
void game()
{
	srand((unsigned int)time(NULL));
	int randnum = rand() % 100;
	int num = 0;
	printf("随机数%d", randnum);
	while (1)
	{
		printf("请输入你要猜的数字\n");
		scanf("%d", &num);
		if (num == randnum)
		{
			printf("恭喜老铁猜对了");
		}
		else if (num <= randnum)
		{
			printf("猜小了");
		}
		else if (num <= randnum)
		{
			printf("猜大了");
		}
	}
}

int binarySearch(int arr[], int key, int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] == key)
		{
			return mid;
		}
		else{
			left = mid +1;
		}
	}
	return -1;
}
int Fabonico(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else{
		return Fabonico(n-2) + Fabonico(n - 1);
	}
}
//循坏
int Fabonico1(int n)
{
	int i=0;
	int f1 = 1;
	int f2 = 1;
	int f3 = 0;
	for (i = 0; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}
int Pow(int n,int k)
{
	if (k == 0)
	{
		return 1;
	}
	else{
		return n*Pow(n, --k);
	}
}
int DigitSum(unsigned int n)
{
	if (n > 9)
	{
		return DigitSum(n/10)+n%10;
	}
	else{
		return n;
	}

}
void binarySearch(int arr, int key, int left, int right)
{
	int num;
	scanf("%d", &num);
	if (num <key)
	{
		printf("猜小了");


	}
	else if (num>key)
	{
		printf("猜大了");
	}
	else{
		printf("猜对了");
	}

}

int main()
{

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = len - 1;
	//binarySearch(int arr, int key, int left, int right);


	//printf("%d", DigitSum(1729));


	/*int result = Pow(3, 4);
	printf("%d", result);*/

	/*int res = Fabonico1(40);
	printf("%d", res);*/


	/*char ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a'&&ch <= 'z')
		{
			putchar(ch - 32);
		}
		else if (ch >= 'A'&&ch <= 'Z')
		{
			putchar(ch + 32);
		}
		else if (ch >= '0'&&ch <= '9')
		{
			putchar(ch);
		}
	}*/



	//char password[20];
	//int count = 3;//登录次数
	//while (count)
	//{
	//	printf("请输入密码：");
	//	scanf("%s", &password);
	//	if (strcmp(password, "123456") == 0)
	//	{
	//		printf("登陆成功\n");
	//		break;
	//	}
	//	else{
	//		count--;
	//		printf("您还有%d次机会",count);
	//	}
	//	
	//}

//no
   





	/*
	int input = 0;
	do
	{
		menue();
		printf("请输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出");
			break;
		default:
			printf("输入错误");
			break;
		}

	} while (input);*/


	/*int a = 0;
	int n = 0;
	int i = 0;
	int tmp = 0;
	int sum = 0;
	scanf("%d%d", &a, &n);
	for (i = 1; i <= n; i++)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	printf("%d", sum);
*/

	//int i = 0;
	//for (i = 100; i <= 999999; i++)
	//{
	//	int count = 1;
	//	int sum = 0;
	//	int tmp = i;
	//	while (tmp/10)
	//	{
	//		count++;
	//		tmp = tmp/ 10;
	//	}
	//	tmp = i;
	//	while (tmp)
	//	{
	//		sum=sum+pow((double)(tmp % 10), count);//第一个参数
	//		tmp = tmp / 10;
	//	}
	//	if (sum == i)
	//	{
	//		printf("%d\n", i);
	//	}

	//}


	/*int line = 0;
	scanf("%d", &line);
	int i = 0;
	int j = 0;
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < line - 1-i;j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < line-1; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i); j++)
		{
			printf("*");
		}
		printf("\n");

	}*/
	system("pause");
	return 0;
	
}
