#include<iostream>
using namespace std;


#if 0
namespace N1
{
	//�����ռ��е����ݣ����Զ��������Ҳ���Զ��庯��
	int a; 
	int Add(int left, int right)
	{
		return left + right;
	}
}
//2.�����ռ����Ƕ��
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
//3.ͬһ��������������ڶ�������ռ�
//����������ϳ�ͬһ�������ռ䡣
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

void TestFunc(int a = 0,int b=20,int c=30)//ȫȱʡ����
{
	cout <<"a="<<a<< endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
void TestFunc(int a, int b = 10, int c = 20)//��ȱʡ����
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
#endif

#if 0
//�������أ���������ͬ�������򣬺������ֱ�����ͬ�������б����������ͣ�����˳�򣩲�ͬ
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
//}//����������������Ƿ���ֵ��ͬ�����ܹ��ɺ�������
int main()
{
	//�������ڱ���׶Σ����ݶ�������ʵ�����͵����ݣ���������ʵ�ʽ��ѡ�����
	Add(10, 20);
	Add(10.0, 20.0);
	Add(1, (int)2.3);//��ʵ�ν�����ʽ����ת��
	return 0;
}
#endif
#if 0
//�����б�ͬ�������������������Ͳ�ͬ������������ͬ
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
//C�����в�֧�ֺ�������
//ԭ��C���Ա������Ժ������ֵ����ι���-��ֻ���ں�����ǰ���»���_
extern "C" int Add(int left, int right);//����������C������
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
//ͬ�����޲κ�����ȫȱʡ��������ͬʱ����
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
//C�����У������Ĵ����м��ַ�ʽ��  ��ֵ�ʹ�ַ
//��ֵ���ŵ㣺�����ĸ����ò���Ӱ���ⲿʵ�Ρ�
//ȱ�㣺�����Ҫͨ���βθı��ⲿʵ�Σ���ֵ������
//���ʵ�νϴ��βεĿ���--���ε�Ч�ʱȽϵͣ��Ƚ��˷ѿռ䡣
void Swap(int left, int right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
//��ַ���ŵ㣺����ͨ���βθı��ⲿ��ʵ�Σ�����Ч�ʸ�
//ȱ�㣺���������û�Ӱ���ⲿʵ�Σ���ȫ�Բ��ߣ��ɶ��Բ�

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
//���ñ����ʼ�����������ͱ��������ʵ����ͬ������
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
//�����������Ĳ���
void Swap(int& left, int& right)
{
	int tmp = left;
	left = right;
	right = tmp;
}
//����������ֵ
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
	//��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc1(&a);
	}
	size_t end1 = clock();

	//��������Ϊ��������
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
	//��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc1();
	}
	size_t end1 = clock();

	//��������Ϊ�����ķ���ֵ����
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
//���ú�ָ����ʲô����
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
//�������******************************
void Swap(int&ra, int&rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}
int main1()
{
	int a = 10;
	int*pb = NULL;//û�з����ڴ�

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
//��C�����У�const��һ��ȫ��ֻ�������������ⲿ���ӡ�
//�ֲ�const�����ջ������ͨ��ָ�����޸�const��ֵ��
//��C++�У����������ᱻconst�����ڴ档
//������const����ȡ��ַ��������Ϊextern�����Ϊ�䴴���ڴ棬
//��C���Բ�ͬ���ǣ�C++��const�����������ļ���Ĭ��Ϊ�ڲ����ӡ�
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
}//���Ӵ����������������ļ�������
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
	//auto e;//�޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
	system("pause");
	return 0;
}
#endif

#if 0
//��auto����ָ������ʱ����auto��auto*û���κ����𣬵���auto������������ʱ�����&

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
	//auto c = 3, d = 4.0;//����ʧ��
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
//���д���***************
#include<map>
#include<string>
int main()
{
	std::map<std::string, std::string>m{ { "apple", "ƻ��" }, { "peach", "����" } };
	//C++98�﷨
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
void TestFor(int array[])//�˻���ָ��  forѭ�������ķ�Χ������ȷ
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