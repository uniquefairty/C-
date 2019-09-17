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

int main()
{
	Date d1();
	Date d2(2019, 9, 14);
	system("pause");
	return 0;
}
