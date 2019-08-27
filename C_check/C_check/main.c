#include<stdio.h>
#include<string.h>
#include<Windows.h>
#pragma warning(disable:4996)

int main8_5()
{
	char s[] = "\\123456\123456\t";
	printf("%d\n", strlen(s));
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