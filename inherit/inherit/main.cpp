#include<iostream>
using namespace std;

#if 0 
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}
	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}
private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};
class Derived:public Base
{};
int main()
{
	//验证：派生类将基类中的成员变量继承到子类中
	cout << sizeof(Derived) << endl;
	//验证：基类中的成员函数是否被子类继承
	Derived d;
	d.SetBase(10, 20, 30);
	d.PrintBase();
	return 0;
}
#endif

#if 0
//public继承
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}
	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}
private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};
class Derived :public Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;
		_pub = 20;
		//_pri = 4;//编译报错，在派生类中不能访问基类中私有的成员变量
	}
	//访问权限：限定该成员变量是否可以直接在类外进行调用
private:
	int _priD;
protected:
	int _proD;
public:
	int _pubD;
};
class D :public Derived
{
public:
	void Test()
	{
		_pro = 10;
	}
};
int mian()
{
	Derived d;
	d._pub = 10;
	//d._pro = 10;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}
	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}
private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};
class Derived :protected Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;
		_pub = 20;
		_pro = 23;
		//_pri = 4;//编译报错，在派生类中不能访问基类中私有的成员变量
	}
	//访问权限：限定该成员变量是否可以直接在类外进行调用
private:
	int _priD;
protected:
	int _proD;
public:
	int _pubD;
};
class D :public Derived
{
public:
	void Test()
	{
		_pub = 10;
		_pro = 10;
	}
};
int mian()
{
	Derived d;
	//d._pub = 10;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}
	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}
private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};
class Derived :private Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;
		_pub = 20;
		_pro = 23;
		//_pri = 4;//编译报错，在派生类中不能访问基类中私有的成员变量
	}
	//访问权限：限定该成员变量是否可以直接在类外进行调用
private:
	int _priD;
protected:
	int _proD;
public:
	int _pubD;
};
class D :public Derived
{
public:
	void Test()
	{
		_//pub = 10;
		//_pro = 10;
	}
};
int mian()
{
	Derived d;
	//d._pub = 10;
	return 0;
}
#endif

#if 0
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_pri = pri;
		_pro = pro;
		_pub = pub;
	}
	void PrintBase()
	{
		cout << _pri << endl;
		cout << _pro << endl;
		cout << _pub << endl;
	}
private:
	int _pri;
protected:
	int _pro;
public:
	int _pub;
};
//class和struct的默认继承权限
//class默认继承权限是private
//struct默认继承权限是public
struct Derived : Base
{
public:
	void SetDerived(int priD, int proD, int pubD)
	{
		_priD = priD;
		_proD = proD;
		_pubD = pubD;
		_pub = 20;
		_pro = 23;
		//_pri = 4;//编译报错，在派生类中不能访问基类中私有的成员变量
	}
	//访问权限：限定该成员变量是否可以直接在类外进行调用
private:
	int _priD;
protected:
	int _proD;
public:
	int _pubD;
};

class D :public Derived
{
public:
	void Test()
	{
		_pub = 10;
		_pro = 10;
	}
};
int mian()
{
	Derived d;
	//d._pub = 10;
	return 0;
}
#endif

#if 0
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}
//protected:
	int _b;
};
class D :public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
		_d = d;
	}
//protected:
	int _d;
};
//赋值兼容规则：前提--》public
//如果是public继承方式：派生类与基类对象之间是一个--is-a的关系
//is-a：是一个可以将一个子类对象看成是一个基类对象
//所有用到基类对象的位置都可以使用子类对象进行代替
int main()
{
	B b;
	b.SetB(10);
	D d;
	d.SetB(20);
	d.SetD(20, 30);

	 //d = b;
	//一个基类对象可以指向子类对象
	//一个子类的指针不能直接指向一个基类的对象
	b = d;
	B *pb = &d;
	B& rb = d;

	//一个子类指针指向一个基类对象强转
	D* pd =(D*) &b;
	pd->_b = 40;
	pd->_d = 9;
	
	pb = &b;
	pd = (D*)pb;
	pd->_b = 40;
	pd->_d = 9;
	return 0;

}
#endif

#if 0
class B
{
public:
	void SetB(int b)
	{
		_b = b;
	}
	void Test(int a)
	{}
	char _b;
};
//同名隐藏：基类和派生类中具有相同名称的成员（成员变量||成员函数）
//如果通过派生类对象直接访问同名内阁成员，优先访问到派生类自己的，基类的
//童名成员不能直接访问到（派生类将基类中的同名成员隐藏）
//成员变量：与变量类型是否相同无关
//成员函数：与成员函数原型是否相同无关
class D :public B
{
public:
	void SetD(int b, int d)
	{
		_b = b;
		_d = d;
	}
	void Test()
	{
		cout << _d << endl;
	}
//protected:
	int _b;
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;
	D d;
	d._b = '1';
	d.B::_b = '2';
	d.Test();
	d.B::Test(10);
	//d.Test(10);
	d.SetD(1, 2);
	return 0;
}
#endif

#if 0
class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};
class Student : public Person
{
public:
	int _No; // 学号
};
void Test()
{
	Student sobj;
	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	//2.基类对象不能赋值给派生类对象
	//sobj = pobj;
	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_No = 10;
}
int main()
{
	Test();
	return 0;
}
#endif

#if 0
class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}
protected:
	int _b;
};
class D :public B
{
public:
	D()
	{
		cout << "D()" << endl;
	}
protected:
	int _d;
};
int main()
{
	D d;
	return 0;
}
#endif

#if 0
class B
{
public:
	B(int b)
	{
		_b = b;
		cout << "B()" << endl;
	}
protected:
	int _b;
};
//如果基类的构造和带有带有参数的构造函数，用户必须在
//派生类构造函数初始化列表的位置显示调用，已完成基类部分成员的初始化
class D :public B
{
public:
	D()
		:B(4)
	{
		cout << "D()" << endl;
	}
protected:
	int _d;
};
int main()
{
	D d;
	return 0;
}
#endif

#if 0
class B
{
public:
	B(int b)
		:_b(b)
	{
		cout << "B(int)" << endl;
	}
	~B()
	{
		cout << "B::~B()" << endl;
	}
	B(const B& b)
		:_b(b._b)
	{}
	B& operator=(const B& b)
	{
		if (this != &b)
		{
			_b = b._b;
		}
		return *this;
	}
protected:
	int _b;
};

class D :public B
{
public:
	D(int b,int d)
		:B(b)
		, _d(d)
	{
		cout << "D(int,int)" << endl;
	}
	~D()
	{
		cout << "D::~D()" << endl;
	}
	D(const D& d)
		:B(d)
		, _d(d._d)
	{}
	D& operator=(const D& d)
	{
		if (this != &d)
		{
			B::operator=(d);
			_d = d._d;
		}
		return *this;
	}
protected:
	int _d;
};
void TestD()
{
	D d(1, 2);
}
//构造次序：
//派生类构造函数（）
//：基类构造函数（）
//{}
//析构次序：
//派生类析构函数（)
//{
//	释放派生类资源
//		编译器在派生类析构函数最后一条有效语句后插入一条汇编代码
//		call基类析构函数；
//}

int main()
{
	D d1(1, 2);
	D d2(d1);
	D d3(3, 4);
	d2 = d3;
	TestD();
	return 0;
}
#endif

#if 0
class Base
{
public:
	Base(int b=7)
		:_b(b)
	{}
	void SetBase(int b)
	{
		_b = b;
	}
protected:
	int _b;
};

class Derived :public Base
{
public:
	void SetDervied(int b, int d)
	{
		_b = b;
		_d = d;
	}
protected:
	int _d;
};

int main()
{
	Base b;
	Derived d;
	return 0;
}
#endif
#if 0
class Base
{
public:
	Base(int b)
		:_b(b)
	{}
	void SetBase(int b)
	{
		_b = b;
	}
protected:
	int _b;
};

class Derived :public Base
{
public:
	Derived(int b,int d)
		:Base(b)
		, _d(d)
	{}
	void SetDervied(int b, int d)
	{
		_b = b;
		_d = d;
	}
protected:
	int _d;
};
int main()
{
	Base b(10);
	Derived d(10, 20);
	return 0;
}
#endif

#if 0
//实现一个不能被继承的类
class Base
{
public:
	static Base GetObject(int b)
	{
		return Base(b);
	}
private:
	Base(int b)
		:_b(b)
	{}
protected:
	int _b;
};
class Base final
{};
#endif

#if 0
class Student;
class Person
{
public:
	friend void Display();
protected:
	string _name; // 姓名
};
class Student : public Person
{
protected:
	int _stuNum; // 学号
};
void Display()
{

	//cout << p._name << endl;
	//cout << s._stuNum << endl;
}
void main()
{
	Person p;
	Student s;
	//Display(p, s);
}
#endif

#if 0
class Base
{
	friend void Print();
public:
	Base(int b)
		:_b(b)
	{}
	int GetB()
	{
		return _b;
	}
protected:
	int _b;
};
class Derived :public Base
{
public:
	Derived(int b,int d)
		:Base(b)
		, _d(d)
	{}
protected:
	int _d;
};
void Print()
{
	Base b(10);
	cout << b._b << endl;
	cout << b.GetB() << endl;
	Derived d(10, 2);
	//cout << d._d << endl;//类外不能访问类中的保护变量
}
#endif

#if 0

//统计一个类创建了多少对象
class Person
{
public:
	Person(const string& name, const string& gender, int age)
		:_name(name)
		, _gender(gender)
		, _age(age)
	{
		++_count;
	}
	Person(const Person& p)
		:_name(p._name)
		, _gender(p._gender)
		, _age(p._age)
	{
		++_count;
	}
	~Person()
	{
		--_count;
	}
protected:
	string _name;
	string _gender;
	int _age;
public:
	static size_t _count;
};
size_t Person::_count = 0;

class Student :public Person
{
public:
	Student(const string& name,const string& gender,int age,int stuld)
		:Person(name,gender,age)
		, _stuld(stuld)
	{}
	Student(const Student& s)
		:Person(s)
		, _stuld(s._stuld)
	{}
protected:
	int _stuld;
};
class Teacher :public Person
{
public:
	Teacher(const string& name,const string gender,int age,int stuld)
		:Person(name,gender,age)
		, _stuld(stuld)
	{}
	Teacher(const Teacher& s)
		:Person(s)
		, _stuld(s._stuld)
	{}
protected:
	int _stuld;
};

void TestPerson()
{
	Person p("111", "男", 18);
	Student s("222", "女", 34, 23);

	cout << Person::_count << endl;
	cout << Student::_count << endl;
	Student::_count = 0;
	cout << Person::_count << endl;

	cout << &Person::_count << endl;
	cout << &Student::_count << endl;
	cout << &Teacher::_count << endl;
}
int main()
{
	TestPerson();
	return 0;
}
#endif 


#if 0
class B
{
public:
	int _b;
};

class C1 :public B
{
public:
	int _c1;
};

class C2 :public B
{
public:
	int _c2;
};

class D :public C1, public C2
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;
	D d;
	//d._b = 2; //菱形继承缺陷：会存在二义性
	d.C1::_b = 1;
	d._c1 = 4;

	d.C2::_b = 3;
	d._c2 = 5;

	d._d = 5;
	return 0;

}
#endif

#if 0
class B
{
public:
	int _b;
};

class C1 :virtual public B
{
public:
	int _c1;
};

class C2 :virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};
int main()
{
	cout << sizeof(D) << endl;
	D d;
	d._b = 1; 
	d._c1 = 2;
	d._c2 = 3;
    d._d = 4;
	return 0;

}
#endif


// Car和BMW Car和Benz构成is-a的关系
class Car{
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
};
class BMW : public Car{
public:
	void Drive() { cout << "好开-操控" << endl; }
};
class Benz : public Car{
public:
	void Drive() { cout << "好坐-舒适" << endl; }
};
// Tire和Car构成has-a的关系
class Tire{
protected:
	string _brand = "Michelin"; // 品牌
	size_t _size = 17; // 尺寸
};
class Car{
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
	Tire _t; // 轮胎
};
