#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
#define MAX 256
//14.�ж��Ƿ�Ϊ������121 1221 ˳�����һ��
int fun(num)
{
	num=

}
int main()
{
	int num = 121;

	fun(num);
}

//13.�����ַ������ӵ�һ���ַ�����ɾ���ڶ����ַ��������е��ַ�
char *DeleteChars(char *str1,char *str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	int hashtable[MAX] = { 0 };

	while ( *str2 != '\0')//��str2���ַ���Ӧ��hashtable�����е�λ���ϵ�ֵ��Ϊ1
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
//12.�ҳ�����������Ψһ����һ�ε�����
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
//11.�ҳ��ַ����е�һ���ظ����ֵ��ַ�
int main11()
{
	char str[] = "qywyer23tdd";
	int i = 0;
	int arr[256] = { 0 };
	for (i = 0; i < strlen(str); i++)
	{
		arr[str[i]]++;
	}

	for (i = 0; i < strlen(str); i++)//c�����е�ascll��ֵһ��256��
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

//10.�ҳ��ַ�����һ�γ���һ�ε��ַ�
int main10()
{
	char str[]="abaccdeff";
	int i = 0;
	int arr[256] = { 0 };//c�����е�ascll��ֵһ��256��
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
//9.������һ���������Ķ��������ɵ������飬������������ĺ͵����ֵ
//��Ϊʱ�临�Ӷ�ΪO(n)����ֻ�ܱ���һ�����飬����ͬʱʹ����������sum��max��
//����sum������ǵ�ǰ�ĺͣ���sum<0�������һ��λ�ô��¼�¼��
//max��¼������ʷ�����ֵ��ֻ�е�sum>maxʱ��sum�滻max��
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
		if (sum <= 0)//�ϴ�ѭ�����õ�ֵ<0,˵���ӵ��Ǹ���
		{
			sum = arr[i];//�ӵ�ǰ���������¿�ʼ�ۼ�
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
	//		sum = 0;//sum���³�ʼ��
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
//8 ����ִ�����������һ�������
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
//7.������ǰk����С��ֵ
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
//4.��unsigned int �ͱ���x���ڴ��ж�����1�ĸ���
int main4_()
{
	unsigned int x = 236;
	int count = 0;
	while (x)
	{
		count++;
		x = x&(x - 1);//ÿ����ȥһ��1
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
//3.쳲�������0 1 1 2 3 5 8
Print(int *a,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
int fib1(int n)//�ݹ����n��쳲�������
{
	if (n <= 2)
	{
		return 1;
	}
	return fib1(n - 1) + fib1(n - 2);
}
int fib2(int n)//�ǵݹ����n��쳲�������
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
void fib(int *a,int n)//�ǵݹ���ǰn��쳲�������
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
int main����()
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
//1.��һ����ά�����У�ÿһ�ж����մ������ҵ�����˳�����������һ��������
//����������һ����ά��һ���������ж��������Ƿ��и�������ʱ�临�Ӷ�O��row+col��
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
			printf("���������\n");
			return;
		}
	}
	printf("û���������\n");
}

int main()
{
	int arr[ROW][COL] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int num=0;
	printf("��������Ҫ���ҵ����֣�");
	scanf("%d",&num);	
	FunNum(arr, num, ROW, COL);
	system("pause");
	return 0;
}
#endif
