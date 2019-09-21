#include<iostream>
using namespace std;

#if 0
class Date
{
	//��ʼ���б����ã���ʼ�����г�Ա����������ÿ����Ա����ֻ���ڳ�ʼ���б����һ��
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
	//	//_a = 10;//����
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
		//, _t()//���ܳ�ʼ��
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
	{}//�������캯����ʼ��
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
	d1 = 2000;//����ֵ����������أ��βα���������������
	//��2000��ʽת��Date��//�ȵ��˹��캯����Ȼ����и���
	//��2000��������ʱ����Ȼ����и�ֵ
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
	}//�������캯����ʼ��
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

#if 1
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
	}//�������캯����ʼ��
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
	//��̬��Ա�����������������ĳ�Ա����
	//������ĳ������Ķ���
	cout << &d1._count << " " << &d2._count << endl;
	//��̬��Ա�������������
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
	}//�������캯����ʼ��

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
	//�Ǿ�̬��Ա���ñ������ض���������
	//��̬��Ա��������������������
}
int main()
{
	Date d1(2019, 9, 15);
	Date d2(d1);
	//cout << Date::_count << endl;˽�г�Ա���ܷ���
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
	}//�������캯����ʼ��

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
	//�Ǿ�̬��Ա���ñ������ض���������
	//��̬��Ա��������������������
}
int main()
{
	Date d1(2019, 9, 15);
	Date d2(d1);
	//cout << Date::_count << endl;˽�г�Ա���ܷ���
	cout << d1.GetCount() << endl;
	TestDate();

	return 0;
}
#endif


class Time
{
public:
	Time(int hour=0,int minute=0,int second=0)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}
	//��<<�����������س���ĳ�Ա���������һ������Ϊthis
	//��˵��÷�ʽ�볣��Ĵ�ӡ��ʽ���ġ�
	/*void operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day;
	}*/
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
	
};
//ostream& operator<<(ostream& _cout, const Date &d)
//{
//
//}