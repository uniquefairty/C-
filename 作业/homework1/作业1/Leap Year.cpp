#include<stdio.h>
#include<Windows.h>
int IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int year = 1000;
	for (; year <= 2000; year++)
	{
		if (IsLeapYear(year))
		{
			printf("%d  ", year);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}