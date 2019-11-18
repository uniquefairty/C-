#include<iostream>
using namespace std;
#include<string>
#if 0
//买票
class Person
{
public:
	Person(const string& name,const string& gender,int age)
		:_name(name)
		, _gender(gender)
		, _age(age)
	{}
	virtual void BuyTicket()
	{
		cout << "全价票" << endl;
	}
protected:
	string _name;
	string _gender;
	int _age;
};
class Student :public Person
{
public:
	Student(const string& name,const string& gender,int age,int stuld)
		:Person(name,gender,age)
		, _stuld(stuld)
	{}
	virtual void BuyTicket()
	{
		cout << "半价票" << endl;
	}
protected:
	int _stuld;
};
class Soilder :public Person
{
public:
	Soilder(const string& name ,const string& gender,const int age,const string& rank)
		:Person(name,gender,age)
		, _rank(rank)
	{}
	virtual void BuyTicket()
	{
		cout << "免费" << endl;
	}
protected:
	string _rank;
};
//在代码运行时，根据p所指向的实际对象选择调用对应类的虚函数
//如果多态的实现条件没有完全满足：
//1.重写失败（基类函数不是虚函数，函数原型不一致）
//2.没有通过基类的指针或者引用调用虚函数
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person p("peter", "男", 23);
	Student st("jl", "女", 12, 122);
	Soilder so("英雄", "男", 34, "连长");
	TestBuyTicket(p);
	TestBuyTicket(st);
	TestBuyTicket(so);
	return 0;
}
#endif

#if 0
struct A{};
struct B :public A {};

class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2(int)
	{
		cout << "Base::TestFunc2()" << endl;
	}
	void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}
	virtual Base* TestFunc5()
	{
		cout << "Base::TestFun5()" << endl;
		return this;
	}
	virtual A& TestFunc6(A& a)
	{
		cout << "Base::TestFun6()" << endl;
		return a;
	}
};
class Derived :public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFun1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}
	void TestFunc4()
	{
		cout << "Base::TestFunc4()" << endl;
	}
	virtual Derived* TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
		return this;
	}
	virtual B& TestFunc6(A& a)
	{
		cout << "Derived::TestFun6()" << endl;
		return *(new B);
	}
		
};
void TestVirtualFunc(Base* pb)
{
	pb->TestFunc1();
	pb->TestFunc2(3);
	pb->TestFunc3();
	pb->TestFunc4();
	pb->TestFunc5();
	A a;
	pb->TestFunc6(a);
}
int main()
{
	Base b;
	Derived d;
	TestVirtualFunc(&b);
	TestVirtualFunc(&d);

	return 0;
}
#endif

#if 1
class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-舒适" << endl;
	}
};

class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-操控" << endl;
	}
};

void Test()
{
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;	pBMW->Drive();
}int main(){	Test();	return 0;}#endif