#include<iostream>
using namespace std;

class Date
{
public:
	/*Date(int year,int month,int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}*/
	Date(int year, int month, int day)
	{
	//构造函数体中：赋初值
		_year = year;
		_month = _month;
		_day = day;
		_a = day;
		b = month;
	}
private:
	int _year;
	int _month;
	int _day;
	const int a;
	int &b;
};

int main()
{
	printf("%d", 10);
	system("pause");
	return 0;
}