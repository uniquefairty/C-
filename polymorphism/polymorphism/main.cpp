#include<iostream>
using namespace std;
#include<string>
#if 0
//��Ʊ
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
		cout << "ȫ��Ʊ" << endl;
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
		cout << "���Ʊ" << endl;
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
		cout << "���" << endl;
	}
protected:
	string _rank;
};
//�ڴ�������ʱ������p��ָ���ʵ�ʶ���ѡ����ö�Ӧ����麯��
//�����̬��ʵ������û����ȫ���㣺
//1.��дʧ�ܣ����ຯ�������麯��������ԭ�Ͳ�һ�£�
//2.û��ͨ�������ָ��������õ����麯��
void TestBuyTicket(Person& p)
{
	p.BuyTicket();
}
int main()
{
	Person p("peter", "��", 23);
	Student st("jl", "Ů", 12, 122);
	Soilder so("Ӣ��", "��", 34, "����");
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
		cout << "Benz-����" << endl;
	}
};

class BMW :public Car
{
public:
	virtual void Drive()
	{
		cout << "BMW-�ٿ�" << endl;
	}
};

void Test()
{
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;	pBMW->Drive();
}int main(){	Test();	return 0;}#endif