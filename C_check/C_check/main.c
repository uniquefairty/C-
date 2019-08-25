#include<stdio.h>
#include<Windows.h>


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
int main()
{
	/*int result = f(2, 4);
	printf("%d\n", result);*/

	/*unsigned char a = 0xa5;
	unsigned char b = ~a >> 4 + 1;
	printf("%d\n", b);*/

	printf("%d\n",fun("goodbye!"));

	system("pause");
	return 0;
}