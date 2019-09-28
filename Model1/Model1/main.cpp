#include<iostream>
using namespace std;

#if 0
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Swap(double& left, double& right)
{
	double temp = left;
	left = right;
	right = temp;
}
void Swap(char& left, char& right)
{
	char temp = left;
	left = right;
	right = temp;
}
#endif 

#if 0
//与类型无关
//Add函数模板
template<class T>//模板参数列表
T Add(T left, T right)//参数列表
{
	cout << typeid(T).name() << endl;
	return left + right;
}

//template<class T1, class T2>
//T1 Add(T1 left,T2 right)
//{
//	cout << typeid(T1).name() << " " << typeid(T2).name() << endl;
//	return left + right;
//}
int main()
{
	//对函数模板进行实例化
	//在编译阶段，如果编译器检测到对某个函数模板进行了实例化
	//对实参的类型进行推演，根据推演结果，确认模板参数列表T的实际类型
	//结合函数模板生成具体类型的函数
	Add(1, 2);
	Add(1.0, 2.0);
	Add('1', '2');
	//模板参数一般不进行类型转化
	Add(1,(int) 1.0);//显式实例化

	Add<int>(1, 2.0);//编译器：可能进行隐式类型转化
	return 0;
}
#endif

#if 0
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	int a1 = 10, a2 = 20;
	double b1 = 2.0, b2 = 9.0;

	Add(a1, a2);
	Add(b1, b2);
	//显式实例化
	Add<int>(a1, b1);
	return 0;
}
#endif

#if 0
//一个非模板函数可以和一个同名的模板函数同时存在，
//而且该函数模板还可以被实例化为这个非模板函数
int Add(int left, int right)
{
	return left + right;
}

template<class T>
T Add(T left, T right)
{
	return left + right;
}

void Test()
{
	Add(1, 2);//与非模板函数匹配，编译器不需要转化
	Add<int>(1, 2);//调用编译器特定的Add的版本
}

int main()
{
	Test();
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T1,class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2);//与非函数模板类型完全匹配，不需要函数模板实例化
	Add(1, 2.0);//模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数

	return 0;
}
#endif

