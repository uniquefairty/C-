#include<iostream>
using namespace std;


#if 0
namespace N1
{
	//命名空间中的内容，可以定义变量，也可以定义函数
	int a; 
	int Add(int left, int right)
	{
		return left + right;
	}
}
//2.命名空间可以嵌套
namespace N2
{
	int a;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}
}
namespace N3
{
	int c;
	int d;
	int sub(int left, int right)
	{
		return left - right;
	}
}
//3.同一个工程中允许存在多个命名空间
//编译器最后会合成同一个命名空间。
namespace N1
{
	int Mul(int left, int right)
	{
		return left * right;
	}
}
#endif
#if 0
namespace N
{
	int a=10; 
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
	int sub(int left, int right)
	{
		return left - right;
	}
}

//using N::b;
using namespace N;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", b);
	Add(10, 20);
	return 0;
}
#endif

#if 0
int main()
{
	int a;
	double b;
	char c;
	cin >> a;
	cin >> b >> c;
	cout << a << endl;
	cout << b << " " << c << endl;
	return 0;
}
#endif

#if 0

void TestFunc(int a = 0,int b=20,int c=30)//全缺省参数
{
	cout <<"a="<<a<< endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
void TestFunc(int a, int b = 10, int c = 20)//半缺省参数
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
#endif

#if 0
//函数重载：必须在相同的作用域，函数名字必须相同，参数列表（个数，类型，类型顺序）不同
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}
//int  Add(double left, double right)
//{
//	return left + right;
//}//如果两个函数仅仅是返回值不同，不能构成函数重载
int main()
{
	//编译器在编译阶段，根据对所传递实参类型的推演，根据推演实际结果选择调用
	Add(10, 20);
	Add(10.0, 20.0);
	Add(1, (int)2.3);//对实参进行隐式类型转化
	return 0;
}
#endif
#if 0
//参数列表不同：参数个数，参数类型不同，参数次数不同
void TestFunc()
{}
void TestFunc(int a)
{}
void TestFunc(int a, double b)
{}
void TestFunc(double a, int b)
{}
int main()
{
	return 0;
}
#endif

#if 0
//#include<stdio.h>
//#include<Windows.h>
//C语言中不支持函数重载
//原因：C语言编译器对函数名字的修饰规则-》只是在函数名前加下划线_
extern "C" int Add(int left, int right);//将函数按照C风格编译
//{
//	return left + right;
//}
//double Add(double a, double b);
int main()
{
	Add(1, 3);
	Add(1.0, 3.0);
	return 0;
}
#endif
#if 0
//同名的无参函数和全缺省函数不能同时存在
void TestFunc(int a = 10)
{}
void TestFunc()
{}
int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
//C语言中：函数的传参有几种方式？  传值和传址
//传值：优点：函数的副作用不会影响外部实参。
//缺点：如果想要通过形参改变外部实参，传值做不到
//如果实参较大，形参的拷贝--传参的效率比较低，比较浪费空间。
void Swap(int left, int right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
//传址：优点：可以通过形参改变外部的实参，传参效率高
//缺点：函数副作用会影响外部实参，安全性不高，可读性差

void Swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int main()
{
	int a = 10;
	int b = 20;
	
	Swap(a, b);
	Swap(&a, &b);
	return 0;

}
#endif

#if 0
void Swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
int main()
{
	int a = 10;
	int b = 20;
	Swap(a, b);

	int& ra = a;
	ra = 100;

	return 0;
}
#endif

#if 0
//引用必须初始化，引用类型必须和引用实体是同种类型
int main()
{
	int a = 10;
	int& ra = a;
	int& rra = a;
	int& rrra = ra;
	rrra = 100;
	return 0;
}
#endif
#if 0
int main()
{
	const int a = 10;
	const int& ra = a;
	const int& b = 100;
	double d = 12.34;
	const int &rd = d;
	d = 56.78;
	return 0;
}
#endif

#if 0
//引用做函数的参数
void Swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
//引用做返回值
int & TestReturn(int &a)
{
	a += 10;
	return a;
}

int &Add(int left, int right)
{
	int ret = left + right;
	return ret;
}
int Sub(int left, int right)
{
	int ret = left - right;
	return ret;
}
int main()
{

	//Swap(a, b);
	//TestReturn(a);
	int &r=Add(1, 2);
	Add(3, 4);
	cout << "Add(1,2) is " << r << endl;

	//Sub(10, 5);
	system("pause");
	return 0;
}
#endif

#if 0
int& TestFunc(int & ra)
{
	return ra;
}
int main()
{
	int a = 10;
	int &rra = TestFunc(a);
	return 0;
}
#endif

#if 0
#include<time.h>
struct A
{
	int a[10000];
};

void TestFunc1(A* a)
{}
void TestFunc2(A& a)
{}
void TestRefAndValue()
{
	A a;
	//以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc1(&a);
	}
	size_t end1 = clock();

	//以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc2(a);
	}
	size_t end2 = clock();

	cout << "TestFunc(int*) - time:" << end1 - begin1 << endl;
	cout << "TestFunc(int&) - time:" << end2 - begin2 << endl;

}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		TestRefAndValue();
	}
	system("pause");
	return 0;
}
#endif

#if 0
#include<time.h>
struct A
{
	int a[10000];
};

A a;
A TestFunc1()
{
	return a;
}
A& TestFunc2()
{
	return a;
}
void TestRefAndValue()
{
	//以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc1();
	}
	size_t end1 = clock();

	//以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc2();
	}
	size_t end2 = clock();

	cout << "TestFunc1- time:" << end1 - begin1 << endl;
	cout << "TestFunc2 - time:" << end2 - begin2 << endl;

}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		TestRefAndValue();
	}
	system("pause");
	return 0;
}
#endif

#if 0
//引用和指针有什么区别？
void Swap(int *pa, int*pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void Swap(int&ra, int&rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}
int main()
{
	int a = 10;
	int b = 20;

	int&ra = a;
	ra = 20;

	int *pa = &a;
	*pa = 20;

	Swap(&a, &b);
	Swap(a, b);
	return 0;
}
#endif

#if 0
//错误代码******************************
void Swap(int&ra, int&rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}
int main1()
{
	int a = 10;
	int*pb = NULL;//没有分配内存

	Swap(a, *pb);
	return 0;
}
#endif

#if 0
//#include<stdio.h>
//#include<Windows.h>

int main()
{
	const int a = 10;
    int *pa = (int *)&a;

	*pa = 100;

	printf("%d", a);
	printf("%d", *pa);

	system("pause");
	return 0;
}//C:100100  c++:10100
//在C语言中，const是一个全局只读变量，且是外部连接。
//局部const存放在栈区，可通过指针间接修改const的值。
//在C++中，编译器不会被const分配内存。
//但若对const进行取地址操作或定义为extern，则会为其创建内存，
//与C语言不同的是，C++将const作用于整个文件，默认为内部连接。
#endif

#if 0
inline int Add(int left, int right)
{
	return left + right;
}
int main()
{
	int ret = 0;
	ret = Add(1, 2);
	return 0;
}
#endif

#if 0
#include "a.h"

int main()
{
	f(10);
	system("pause");
	return 0;
}//链接错误：内联函数具有文件作用域。
#endif

#if 0
int TestAuto()
{
	return 10;
}
int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	//auto e;//无法通过编译，使用auto定义变量时必须对齐进行初始化
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
	system("pause");
	return 0;
}
#endif

#if 0
//用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时必须加&

//void TestFunc(auto a)
//{}
int main()
{
	int x = 10;
	auto a = &x;
	auto* b = &x;
	auto& c = x;

	//auto arr[]={1,2,3};
	auto f = 1, e = 2;
	//auto c = 3, d = 4.0;//编译失败
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;

	*a = 20;
	*b = 30;
	c = 40;

	system("pause");
	return 0;
}
#endif

#if 0
//运行错误***************
#include<map>
#include<string>
int main()
{
	std::map<std::string, std::string>m{ { "apple", "苹果" }, { "peach", "桃子" } };
	//C++98语法
	std::map<std::string, std::string>::iterator it = m.begin();
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}
	cout << endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
	{
		e *= 2;
	}
	for (auto e : array)
	{
		cout << e << " ";
	}
	system("pause");
	return 0;
}
#endif

#if 0
void TestFor(int array[])//退化成指针  for循环迭代的范围必须明确
{
	for (auto& e : array)
	{
		cout << e << " ";
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };

	TestFor(arr);

	return 0;
}
#endif

void Test(int)
{
	cout << "Test(int)" << endl;
}

void Test(int *)
{
	cout <<"Test()" << endl;
}

int  main()
{
	int *p = nullptr;
	Test(0);
	Test(NULL);
	Test(nullptr);
	return 0;
}