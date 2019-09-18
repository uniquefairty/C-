#include<iostream>
using namespace std;

#if 0
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1l;
		_day = 1;
	}
	Date(int year,int month,int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Data(int,int,int):" << this << endl;
	}
	//构造函数可以重载

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	Date d2(2019, 9, 14);

}
int main()
{
	int a;
	a = 10;
	int b = 10;
	int c(10);

	Date d1;
	//d1.SetDate(2019, 9, 14);
	//d1.Display();
	TestDate();
	system("pause");
	return 0;
}
#endif

#if 0
//类中没有显示（用户没有显示提供构造）任何构造函数
//编译器将自动生成无参的构造函数
class Date
{
public:
	/*Date()
	{
		_year = 1900;
		_month = 1l;
		_day = 1;
	}*/
	Date(int year=1900, int month=1, int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Data(int,int,int):" << this << endl;
	}
	//无参的构造函数和全缺省函数都是默认构造函数
	//默认构造函数只能有一个。
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
//	Date d2(2019, 9, 14);//错误需要带参的构造函数
	system("pause");
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int hour=0, int minute=0,int second = 0)
	{
		cout << "Time(int,int,int)" << endl;
		_hour = hour;
		_minute = minute;
		_second = second;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	Date d1;
	system("pause");
	return 0;
}
#endif

#if 0
#include<assert.h>
#include<malloc.h>
typedef int DataType;
class SeqList
{
public:
	SeqList(size_t capacity = 10)
	{
		cout << "SeqList(size_t)" << endl;
		_array = (DataType *)malloc(capacity*sizeof(DataType));
		if (nullptr == _array)
		{
			assert(0);
		    return;
	    }
		_size = 0;
		_capacity = capacity;

	}
	~SeqList()//无返回值无参数--不能重载
	{
		if (_array)
		{
			cout << "~SeqList()" << endl;
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;

};

void TestSeqList()
{
	SeqList s;
}
int main()
{
	TestSeqList();
	//_CrtDumpMemoryLeaks();
	return 0;
}
#endif

#if 0
//关于编译器生成默认的析构函数
class String
{
public:
	String(const char*str = "")
	{
		if (nullptr == str)
			str = "";
		_str = (char *)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
private:
	char *_str;
};
class Person
{
private:
	String _name;
	String _gender;
	int _age;
};
void TestPerson()
{
	Person p;
}
int main()
{
	TestPerson();

	return 0;
}
#endif

#if 0
//拷贝函数没有显示生成，编译器默认生成拷贝构造函数
class String
{
public:
	String(const char*str = "")
	{
		if (nullptr == str)
			str = "";
		_str = (char *)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
private:
	char *_str;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Data(int,int,int):" << this << endl;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void TestDate()
{
	Date d1;
	Date d2(2019, 9, 14);
	Date d3(d2);
}

void TestString()
{
	String s1("hello");
	String s2(s1);//错误

}

int main()
{
	
	TestString();
	TestDate();
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Data(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d2(2019, 9, 14);
	Date d1(d2);//函数声明，没有定义对象，返回类型的函数

	system("pause");
	return 0;
}
#endif

#if 0
//什么是运算符重载？
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	bool operator>(const Date&d)
	{
		if (_year > d._year ||
			_year == d._year&&_month > d._month ||
			_year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator==(const Date&d)
	{
		return _year == d._year&&_month == d._month
			&&_day == _day;
	}
	bool operator!=(const Date&d)
	{
		return !(*this == d);
	}
	/*bool operator@(int a, int b)//5个字符不能重载：.* :: sizeof ?: ,
	{
		return true;
	}*/
	//int operator+(int a, int b)//至少要有一个类类型的对象
	//{
	//	return a + b;
	//}
	Date operator+(Date a)//至少要有一个类类型的对象
	{
		return a;
	}
	bool IsGreater(const Date& d)
	{
		if (_year > d._year ||
			_year == d._year&&_month > d._month ||
			_year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 9, 14);
	Date d2(2019, 9, 15);
	Date d3(2020, 9, 14);
	d3 = d1;

	//if (d1.IsGreater(d2) )
	if(d1>d2)
	{
		cout << "d1>d2" << endl;
	}
	else
	{
		cout << "d1<=d2" << endl;
	}
	return 0;
}
#endif

#if 0
//赋值运算符重载：如果用户没有显示提供，编译器会生成默认的一份运算符重载
//如果类中涉及资源管理，用户必须显示提供
class String
{
public:
	String(const char*str = "")
	{
		if (nullptr == str)
			str = "";
		_str = (char *)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
private:
	char *_str;
};
void TestString()
{
	String s1("hello");
	String s2("world");

	s1 = s2;//会内存泄漏
}

int main()
{
	TestString();
	return 0;
}
#endif

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	Date& operator=(const Date&d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		

		return *this;
	}
	bool operator>(const Date&d)
	{
		if (_year > d._year ||
			_year == d._year&&_month > d._month ||
			_year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator==(const Date&d)
	{
		return _year == d._year&&_month == d._month
			&&_day == _day;
	}
	bool operator!=(const Date&d)
	{
		return !(*this == d);
	}
	//前置++
	Date&  operator++()
	{
		_day += 1;
		return *this;
	}
	//后置++
	Date  operator++(int)
	{
		Date tmp(*this);
		_day += 1;

		return tmp;//旧值在栈上//引用不能反悔栈上的值
	}
	Date &operator--()
	{
		_day -= 1;
		return *this;
	}
	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}
	bool IsGreater(const Date& d)
	{
		if (_year > d._year ||
			_year == d._year&&_month > d._month ||
			_year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;

	a = b = c;
	c++;
	++b;

	Date d1(2019, 9, 14);
	Date d2(2019, 9, 15);
	Date d3(2019, 9, 13);
	d2=d3++;
	d2.operator=(d3.operator++(5));//随便传一个参数

	d2=++d3;
	d2.operator=(d3.operator++());
	d3 = d3;
	d2 = d1;
	d2.operator=(d1);

	d3 = (d2 = d1);
	d3.operator=(d2.operator=(d1));//赋值运算符重载必须给返回值

	
	return 0;
}