#include<iostream>
using namespace std;

#if 0
class Date
{
	//初始化列表作用：初始化类中成员变量，并且每个成员变量只能在初始化列表出现一次
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
		, _a(10)
		, b(_year)
	{}
	//Date(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//	//_a = 10;//错误
	//}
private:
	int _year;
	int _month;
	int _day;
	const int _a;
	int &b;
};
int main()
{
	printf("%d", 10);
	system("pause");
	return 0;
}

#endif

#if 0
class Time
{
public:
	Time(int hour, int minute, int second)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year,int month,int day)
		:_year(year)
		, _month(month)
		, _day(day)
		//, _t()//不能初始化
		, _t(19,20,34)
	{}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int day)
		:_year(year)
		, _month(year)
		, _day(_month)
	{}
	Date (const Date& d)
		: _year(d._year)
		,_month(d._month)
		,_day(d._day)
	{}//拷贝构造函数初始化
private:
	int _year;
	int _day;
	int _month;
	
};
int main()
{
	Date d1(1999,4);
	return 0;
}
#endif

#if 0
class Array
{
public:
	Array(int size)
		:_size(size)
		,_array((int *)malloc(sizeof(int)*_size))
	{}
private:
	int *_array;
	int _size;
};
#endif

#if 0
class Date
{
public:
	 Date(int year)
		:_year(year)
	{}
	 Date &operator=(const Date &d)
	 {
		 if (this != &d)
		 {
			 _year = d._year;
			 _month = d._month;
			 _day = d._day;
		 }
		 return *this;
	 }
private:
	int _year;
	int _day;
	int _month;
};
int main()
{
	Date d1(1999);
	d1 = 2000;//调赋值运算符的重载：形参必须是两个类类型
	//把2000隐式转换Date类//先调了构造函数，然后进行复制
	//用2000创造了临时变量然后进行赋值
	return 0;
}
#endif

#if 0
int _count = 0;
class Date
{
public:
	Date(int year,int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}
	~Date()
	{
		_count--;
	}
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}//拷贝构造函数初始化
private:
	int _year;
	int _day;
	int _month;

};
void TestDate()
{
	Date d3(2023, 3, 4);
	Date d4(d3);
	Date d5(2019, 9, 13);
	cout << _count << endl;

}
int main()
{
	Date d1(2019, 9, 16);
	Date d2(d1);
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}
	~Date()
	{
		_count--;
	}
	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}//拷贝构造函数初始化
private:
	int _year;
	int _day;
	int _month;
public:
	static int _count;

};
int  Date::_count = 0;

void TestDate()
{
	Date d3(2023, 3, 4);
	Date d4(d3);
	Date d5(2019, 9, 13);
}
int main()
{
	Date d1(2019, 9, 16);
	Date d2(d1);
	//静态成员变量是所有类对象共享的成员变量
	//不属于某个具体的对象
	cout << &d1._count << " " << &d2._count << endl;
	//静态成员变量是类的属性
	cout << Date::_count << endl;
	cout << sizeof(Date) << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}
	~Date()
	{
		_count--;
	}
	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}//拷贝构造函数初始化

	/*void TestFunc()
	{
		_day++;
		cout << _count << endl;
	}*/
	static int GetCount()
	{
		return _count;
	}
private:
	int _year;
	int _day;
	int _month;
	static int _count;
};
int Date::_count = 0;

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 12);
    cout << Date::GetCount() << endl;
	//非静态成员引用必须用特定对象引用
	//静态成员函数可以用类类型引用
}
int main()
{
	Date d1(2019, 9, 15);
	Date d2(d1);
	//cout << Date::_count << endl;私有成员不能访问
	cout << d1.GetCount() << endl;
	TestDate();

	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}
	~Date()
	{
		_count--;
	}
	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}//拷贝构造函数初始化
	void TestFunc()
	{
	 _day++;
	 cout << _count << endl;
	}
	static int GetCount()
	{
		return _count;
	}
private:
	int _year;
	int _day;
	int _month;
	static int _count;
};
int Date::_count = 0;
void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 12);
	cout << Date::GetCount() << endl;
	//非静态成员引用必须用特定对象引用
	//静态成员函数可以用类类型引用
}
int main()
{
	Date d1(2019, 9, 15);
	Date d2(d1);
	//cout << Date::_count << endl;私有成员不能访问
	cout << d1.GetCount() << endl;
	TestDate();
	return 0;
}
#endif


#if 0
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	//将<<运算符如果重载成类的成员函数，其第一个参数为this
	//因此调用方式与常规的打印方式反的。
	ostream& operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
	
};
int main()
{
	Date d(2017, 12, 24);
	d << cout;
	return 0;
}
#endif

#if 0
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, const Date& d);
public:
	Date(int year=89, int month=0, int day=0)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
//必须重载全局函数
//第一个参数必须是ostream&，第二个参数为要输出的内容（自定义类型的对象)
//必须要有返回值->连续输出
ostream& operator<<(ostream& _cout,const Date& d)
{
	_cout << d._year << "-" << d._month << "-" <<d. _day;
	return _cout;
}
istream& operator>>(istream& _cin, const Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d1(1990, 4, 5);
	Date d;
	cin >> d1;
	cout << d1 << endl;
	return 0;
}
#endif

#if 0
class Date;//函数说明
class Time
{
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year=1990, int month=1, int day=1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;

};

int main()
{
	Date d(2017, 12, 24);
	
	return 0;
}
#endif

#if 0
class A
{
public:
	A(int a)
		:_a(a)
	{}
	class B
	{
	public:
		B(int b)
			:_b(b)
		{}
		void TestFun()
		{
			A a(1);
			a._a = 10;
			A::_c = 10;
			_c = 2;
		}
	private:
		int _b;
	};
private:
	int _a;
	static int _c;
};
int A::_c = 1;

int main()
{
	A::B B(10);
	//注意：内部类是一个独立的类，没有包含在外部类中
	cout << sizeof(A) << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year=1900, int month=1, int day=1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		//如果所输入的年不符合实际要求进行初始化
		if (!(_year>0&&
			_month>0&&_month<13&&
			_day>0 && _day<GetMonthOfYear(_year, _month)))
		{
			_year = 1;
			_month = 1;
			_day = 1;
		}
	}
	Date(const Date&d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	//=
	Date& operator=(const Date d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//+
	Date operator+(int days)
	{
		if (days < 0)
		{
			return *this - (0 - days);
		}
		Date tmp(*this);
		tmp._day += days;

		int daysofMonth = 0;

		while (tmp._day > (daysofMonth = tmp.GetMonthOfYear(tmp._year, tmp._month)))
		{
			tmp._day -= daysofMonth;
			tmp._month++;
			if (tmp._month > 12)
			{
            tmp._year++;
            tmp._month = 1;
			}
		}
		return tmp;
	}

	//Date& operator+(int days)
	//{
	//  if (days < 0)
	//  {
	//     return *this - (0 - days);
	//	}
	//	_day += days;
	//	while (_day > GetMonthOfYear(_year,_month))
	//	{
	//		_day -= GetMonthOfYear(_year, _month);
	//		if (_month==12)
	//		{
	//			_year++;
	//			_month = 1;
	//		}
	//		else
	//		{
	//		_month++;
	//		}
	//	}
	//	return *this;
	//}

	//-
	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}

		Date tmp(*this);
		tmp._day -= days;

		while (tmp._day <= 0)
		{
			tmp._month--;
			if (tmp._month < 0)
			{
				tmp._year--;
				tmp._month = 12;
			}
			tmp._day += tmp.GetMonthOfYear(tmp._year, tmp._month);
		}
		return tmp;

	}
	/*Date& operator-(int days)
	{
	if (days < 0)
	{
	return *this + (0 - days);
	}
	_day -= days;
	while (_day < 0)
	{
	if (_month == 1)
	{
	_year--;
	_month = 12;
	}
	else
	{
	_month--;
	}
	_day += GetMonthOfYear(_year, _month);
	}
	return *this;
	}*/
	int operator-(const Date d)//两个日期间相差了多少天
	{
		Date minDate(*this);
		Date maxDate(d);
		if (*this > d)
		{
			swap(minDate, maxDate);
		}
		size_t count = 0;
		while (minDate != maxDate)
		{
			count++;
			minDate++;
		}
		return count;
	}
	Date& operator++()//	前置++
	{
		*this = *this + 1;
		return *this;
	}
	Date operator++(int)//后置++，先返回再运算 注意返回值不能用引用
	{
		Date tmp(*this);
		*this = *this + 1;
		return tmp;
	}
	Date& operator--()
	{
		*this = *this-1;
		return *this;
	}
	Date operator--(int)
	{
		Date tmp(*this);
		*this = *this - 1;
		return tmp;
	}
		
	bool operator>(const Date d)
	{
		if (_year > d._year
			|| _year == d._year&&_month > d._month
			|| _year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		return false;
	}
	bool operator==(const Date d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
	bool operator!=(const Date d)
	{
		return !(*this == d);
	}

	friend ostream& operator<<(ostream&_cout, const Date &d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day << endl;
		return _cout;
	}
	void swap(Date& minDate, Date& maxDate)
	{
		Date tmp;
		tmp = minDate;
		minDate = maxDate;
		maxDate = tmp;
	}
	int GetMonthOfYear(int year, int month)
	{
		int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2&&IsLeapYear(year))
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				days[_month] = 29;
			}
		}
		return days[month];
	}
	bool IsLeapYear(int year)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return true;
		}
		
		return false;
	}
	
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2019,9,18);
	Date d2(2000, 9, 1);
	cout << d2 - d1 << endl;
	d1 = d1 - 999;
	//d1 = d1 + 100;
	//d1 + 100;
	cout << d1<< endl;
	system("pause");
	return 0;
}
#endif

#if 0
class  B
{
public:
	B(int b=0)
		:_b(b)
	{}
	int _b;
};
class A
{
public:
	void Print()
	{
		cout << a << endl;
		cout << b._b << endl;
		cout << p << endl;
	}
private:
	//非静态成员变量，可以在成员声明时给缺省值。
	int a = 10;
	B b = 20;
	int *p = (int *)malloc(4);
	static int n;
};
int A::n = 10;
int main()
{
	A a;
	a.Print();
	return 0;
}
#endif