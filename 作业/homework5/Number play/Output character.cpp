#include<stdio.h>
#include<Windows.h>
#pragma warning (disable:4996)
int Judge(char x)
{
	if (x>='A'&& x<='Z'){
		x = x + 32;
		printf("The output character is: %c\n", x);

	}
	else if (x>='a'&&x<='z'){
		x = x - 32;
		printf("The output character is:%c\n", x);
	}
	return 1;
}
int main()
{

	char c;
	printf("Please Input character:");
	scanf("%c", &c);
	Judge(c);
	system("pause");
	return 0;
}