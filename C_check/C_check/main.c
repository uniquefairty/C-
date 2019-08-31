#include<stdio.h>
#include<string.h>
#include<Windows.h>
#pragma warning(disable:4996)
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d\n", strlen(a));
	system("pause");
	return 0;
}
char *mystring10_1()
{
	char buffer[6] = { 0 };
	char *s = "hello world!";
	for (int i = 0; i < sizeof(buffer)-1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
int main10_1()
{
	printf("%s\n", mystring());
	system("pause");
	return 0;
}


int main10_2()
{
	char *str[3] = { "stra", "strb", "strc" };
	char *p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s ", p++);
		i++;
	}
	system("pause");
	return 0;
}


int main9_3()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p1 = (int *)(&a + 1);
	int *p2 = (int *)((int)a + 1);
	int *p3 = (int *)(a + 1);
	printf("%d,%x,%d\n", p1[-1], p2[0], p3[1]);
	system("pause");
	return 0;
}
void func(char str_arg[2])
{
	int m = sizeof(str_arg);
	int n = strlen(str_arg);
	printf("%d\n", m);//4首先数组名作为实参传递，退化为指针，传递的是地址，
	//而接收的形参虽然写成数组形式，但同样也看成指针，所以里面的2没有任何意义。
	printf("%d\n", n);//5
    //sizeof一个指针，在32位系统里面永远都是4个字节。strlen则求的是实际字符串的长度，不包括最后的'\0'。
}
int main9_1()
{
	char str[]="Hello";
	func(str);
	system("pause");
	return 0;
}

void foo(int b[][3])
{
	++b;
	b[1][1] = 9;
}
int main———()
{
	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	foo(a);
	printf("%d", a[2][1]);
	system("pause");
	return 0;
}
int main17_2_3()
{
	int i = 10;
	long long t = sizeof(i++);
	printf("%d", i);
	system("pause");
	return 0;
}
int main17_1_3()
{
	char *str = "abcde";
	str += 2;
	printf("%lu\n", str);

	system("pause");
	return 0;
}
#pragma pack(8)
int main4()
{
	struct t
	{
		int a;
		char d;
		short b;
		short c;

		/*char c1;
		int i;
		char c2;*/

		/*short a;
		char d;
		long b;
		long c;*/
	};

	struct t t1;

	printf("%d", sizeof(t1));
	system("pause");
	return 0;
}
#pragma pack()

int main8_()
{
	typedef char str[255];//str代表 一个数组类型是char [255]
	str s;//s是字符数组变量
}
int main8_5()
{
	//char s[] = "\\123456\123";

	char s[] = "\\123456\123456\t";
	printf("%d\n", strlen(s));//12
	puts(s);
	system("pause");
	return 0;
}
int main8()
{
	unsigned long ula = 0x11000000;
	printf("%x\n", *(unsigned char *)&ula);
	system("pause");
	return 0;
}
int main11_1()
{
	unsigned char a = 0xa5;
	unsigned char b =(~a) >>4 + 1;
	printf("%d\n", b);

	system("pause");
	return 0;
}
int main15()
{
	unsigned short sht = 0;
	sht--;
	printf("%d", sht);
	system("pause");
	return 0;
}
int main15_3()
{
	int x = 1, y = 012;
	printf("%d", y*x++);
	system("pause");
	return 0;
}
int main15_1_()
{
	int j = 4;
	int i = j;
	for (; i <= 2 * j; i++)
	{
		switch (i / j)
		{
		case 0:
		case 1:
			printf("*");
			break;
		case 2:
			printf("#");
		}
	}
	system("pause");
	return 0;
}
int main15_1()
{
	unsigned int a = 0xFFFFFFF7;
	unsigned char i = (unsigned char)a;
	char *b = (char *)&a;//地址类型发生改变，使a的地址完全存入b中，但没有改变里面的内容

	printf("%08x,%08x", i, *b);//000000f7 fffffff7
	system("pause");
	return 0;
}
int main15_2()
{
	char str[] = "ABCDEFG";
	char *p1, *p2;
	p1 = "abcd"; p2 = "efgh";

	strcpy(str + 1, p2 + 1);
	strcpy(str + 3, p1 + 3);
	printf("%s\n", str);
	system("pause");
	return 0;
}
int main14_3()
{
	int arr[] = { 6, 7, 8, 9, 10 };
	int *ptr = arr;
	*ptr++ += 123;
	printf("%d,%d\n", *ptr, *++ptr);

	printf("%d", arr[0]);
	system("pause");
	return 0;
}
int f(int x, int y)
{
	return  (x&y) + ((x^y) >> 1);
}
int fun(char *s)
{
	char *p = s;
	while (*p != '\0')
	{
		p++;
	}
	return(p - s);
}
int main1()
{
	/*int result = f(2, 4);
	printf("%d\n", result);*/

	unsigned char a = 0xa5;
	unsigned char b = ~a >> 4 + 1;
	printf("%d\n", b);

	//printf("%d\n",fun("goodbye!"));

	system("pause");
	return 0;
}