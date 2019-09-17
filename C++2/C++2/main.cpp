#include <iostream>
using namespace std;
//#pragma warning(disable:4996)
//#include<string.h>

#if 0
//类
struct Student
{
	//成员方法||行为
	void SetStudentInfo(const char *name, const char *gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintfStudetInfo()
	{
		cout << _name << ": " << _gender << " :" << _age << endl;
	}
	//成员变量||属性
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s;
	s.SetStudentInfo("Peter", "男", 31);
	s.PrintfStudetInfo();
	system("pause");
	return 0;
}
#endif

//面向队象三大特性：封装 继承 多态
//封装：将一个事物的内部实现细节隐藏起来，提供一些公有的接口，让对象之间进行交互

//C++实现封装：类（通过类将对象的属性和行为包装在一起）
//访问权限：private protect public
//public：被public修饰的成员，可以直接在类外进行访问。
//protected/private:不能直接在类外直接访问

//void SetStudentInfo(const char *name, const char *gender, int age)
//{}//两个函数不是函数重载。函数重载要在同一个作用域。

#if 0
class Student
{
public:
	//成员方法||行为
	void SetStudentInfo(const char *name, const char *gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintfStudetInfo()
	{
		cout << _name << ": " << _gender << " :" << _age << endl;
	}
private:
	//成员变量||属性
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s;
	s.SetStudentInfo("Peter", "男", 31);
	s.PrintfStudetInfo();
	system("pause");
	return 0;
}
#endif

#if 0
class Student
{
public:
	//成员方法||行为
	void SetStudentInfo(const char *name, const char *gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintfStudetInfo()
	{
		cout << _name << ": " << _gender << " :" << _age << endl;
	}
private:
	//成员变量||属性
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1,s2,s3;

	cout << sizeof(s1) << endl;
	s1.SetStudentInfo("Peter", "男", 31);
	s2.SetStudentInfo("Peter2", "男", 31);
	s3.SetStudentInfo("Peter3", "女", 31);

	s1.PrintfStudetInfo();
	s2.PrintfStudetInfo();
	s3.PrintfStudetInfo();


	system("pause");
	return 0;
}
#endif

#if 0
class A
{
public:
	void Test();
};
class B
{};
int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	return 0;
}
#endif

#if 0
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};
void SetStudentInfo(Student *ps,char *name,char *gender, int age)
{
	strcpy(ps->_name, name);
	strcpy(ps->_gender, gender);
	ps->_age = age;
}

void PrintfStudetInfo(Student *ps)
{
	printf("%s %s %s", ps->_name, ps->_gender, ps->_age);
}
#endif

#if 0
class Student
{
public:
	//成员方法||行为
	void SetStudentInfo(char *name,char *gender, int age)
	{
		//Student * const//this指针的类型
		//this = nullptr;thid指针不能修改 
		cout <<this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		_age = age;
	}
	void PrintfStudetInfo()
	{
		cout <<this-> _name << ": " << this->_gender << " :" << this->_age << endl;
	}
	void TestFunc(...)//不定参数
	{
		cout << this << endl;
	}
private:
	//成员变量||属性
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1, s2, s3;
	s1.TestFunc(10);
	//cout << sizeof(s1) << endl;
	s1.SetStudentInfo("Peter", "男", 31);
	cout << &s1 << endl;
	s2.SetStudentInfo("Peter2", "男", 31);
	cout << &s2 << endl;
	s3.SetStudentInfo("Peter3", "女", 31);
	cout << &s3 << endl;
	return 0;
}
#endif

#if 0
class Student
{
public:
	//成员方法||行为
	/*void SetStudentInfo( Student *const this,char *name, char *gender, int age)
	{
	strcpy(this->_name, name);
	strcpy(this->_gender, gender);
	this->_age = age;
	}*/
	void SetStudentInfo(char *name, char *gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	
	/*void PrintfStudetInfo(Student * const this)
	{
	cout << this->_name << ": " << this->_gender << " :" << this->_age << endl;
	}*/
	void PrintfStudetInfo()
	{
		cout << this->_name << ": " << this->_gender << " :" << this->_age << endl;
	}
	
private:
	//成员变量||属性
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1, s2, s3;
	s1.SetStudentInfo("Peter", "男", 31);
	cout << &s1 << endl;
	s2.SetStudentInfo("Peter2", "男", 31);
	cout << &s2 << endl;
	s3.SetStudentInfo("Peter3", "女", 31);
	cout << &s3 << endl;
	return 0;
}
#endif

class A
{
public:
	/*void PrintA()
	{
		cout << _a << endl;
	}
*///访问类中的变量时，程序崩溃。
	void show()
	{
		cout << "Show（）" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = NULL;
	//p->PrintA();
	p->show();

	return 0;
}