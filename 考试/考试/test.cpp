#include<iostream>
using namespace std;

//#if 1
//class Test{
//public:
//	int a;
//	int b;
//	virtual void fun() {}
//	Test(int temp1 = 0, int temp2 = 0)
//	{
//		a = temp1;
//		b = temp2;
//	}
//	int getA()
//	{
//		return a;
//	}
//	int getB()
//	{
//		return b;
//	}
//};
//int main()
//{
//	Test obj(5, 10);
//	// Changing a and b
//	int* pInt = (int*)&obj;
//	*(pInt + 0) = 100;
//	*(pInt + 1) = 200;
//	cout << "a=" << obj.getA() << endl;
//	cout << "b = " << obj.getB() << endl;
//	return 0;
//}
////a=200 b=10
//#endif 

#if 0 
class A 
{ 
public:  
	virtual void Fun(int number = 10) 
	{ 
		std::cout << "A::Fun with number " << number;
	}
};  
class B : public A
{ 
public:  
	virtual void Fun(int number = 20)  
	{ 
		std::cout << "B::Fun with number " << number; 
	}
};   
int main() 
{
	B b;    
    A &a = b;   //缺省参数是在编译时因为缺省参数实在编译期间处理的，
	//编译期间 A a是A类，但在运行中，虚函数动态的指向B类的fun函数，但是number的值为10。
	a.Fun();  //输出B::Fun with number 10
	return 0;
}
#endif

#if 0
class AB
{
public:
	AB(int a)
	{
		count++;
	}
	static int count;
};
int AB::count = 0;

int main()
{
	AB a(4), b(5), c(3), *p[2] = { &a, &b };
	cout << AB:: count;
}
#endif

#if 0
class A
{
public:
	A() :m_iVal(0){ test(); }
	virtual void func() { std::cout << m_iVal << ' '; }
	void test(){ func(); }
public:
	int m_iVal;
};
class B : public A
{
public:
	B(){ test(); }
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal << ' ';
	}
};
int main(int argc, char* argv[])
{
	A*p = new B;
	p->test();
	return 0;
}
#endif

#if 0
int main()
{
	int *p[3][4];
	int *(*a)[3][4];
	int ** c[3][4];
	printf("sizeof(p)=%d\n", sizeof(p));
	printf("sizeof(a)=%d\nsizeof(*a)=%d\n", sizeof(a), sizeof(*a));
	printf("sizeof(c)=%d\nsizeof(*c)=%d\n", sizeof(c), sizeof(*c));
	return 0;
}
#endif

#if 0
template<class T> class Foo{
	T tVar;
public:
	Foo(T t) : tVar(t) { }
};
template<class T> class FooDerived :public Foo<T>
{
};
int main()
{
	return 0;
}
#endif

#if 0
struct A
{
	int a;
	short b;
	int c;
	char d;
};

struct B
{
	int a;
	short b;
	char c;
	int d;
};
int main()
{
	cout << sizeof(A) << endl;//16
	cout << sizeof(B) << endl;//12
	return 0;
}
#endif

#if 0
class A
{
public:
	virtual void func(int val = 1)
	{
		std::cout << "A->" << val << std::endl;
	}
	virtual void test()
	{
		func();
	}
};
class B : public A
{
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};
int main(int argc, char* argv[])
{
	B*p = new B;
	p->test();
	return 0;
}
#endif

#if 0
class A
{
public:
	void foo()
	{
		printf("1");
	}
	virtual void fun()
	{
		printf("2");
	}
};
class B : public A
{
public:
	void foo()
	{
		printf("3");
	}
	void fun()
	{
		printf("4");
	}
};
int main(void)
{
	A a;
	B b;
	A *p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	A *ptr = (A *)&b;
	ptr->foo();
	ptr->fun();
	return 0;
}
#endif

#if 0
struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};
void fool()
{
	st_task task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}
#endif

#if 0
#include <iostream>
using namespace std;
//void func(int v1, int v2)
void func(const int& v1, const int& v2)
{
	cout << v1 << ' ' << &v1 << endl;
	cout << v2 << ' ' << &v2 << endl;
}
int main()
{
	int i = 0;
	//func(++i, i++);
	func(++i, i);
	return 0;
}
#endif

