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
    A &a = b;   //ȱʡ�������ڱ���ʱ��Ϊȱʡ����ʵ�ڱ����ڼ䴦��ģ�
	//�����ڼ� A a��A�࣬���������У��麯����̬��ָ��B���fun����������number��ֵΪ10��
	a.Fun();  //���B::Fun with number 10
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


