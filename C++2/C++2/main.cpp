#include <iostream>
using namespace std;
//#pragma warning(disable:4996)
//#include<string.h>

#if 0
//��
struct Student
{
	//��Ա����||��Ϊ
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
	//��Ա����||����
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s;
	s.SetStudentInfo("Peter", "��", 31);
	s.PrintfStudetInfo();
	system("pause");
	return 0;
}
#endif

//��������������ԣ���װ �̳� ��̬
//��װ����һ��������ڲ�ʵ��ϸ�������������ṩһЩ���еĽӿڣ��ö���֮����н���

//C++ʵ�ַ�װ���ࣨͨ���ཫ��������Ժ���Ϊ��װ��һ��
//����Ȩ�ޣ�private protect public
//public����public���εĳ�Ա������ֱ����������з��ʡ�
//protected/private:����ֱ��������ֱ�ӷ���

//void SetStudentInfo(const char *name, const char *gender, int age)
//{}//�����������Ǻ������ء���������Ҫ��ͬһ��������

#if 0
class Student
{
public:
	//��Ա����||��Ϊ
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
	//��Ա����||����
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s;
	s.SetStudentInfo("Peter", "��", 31);
	s.PrintfStudetInfo();
	system("pause");
	return 0;
}
#endif

#if 0
class Student
{
public:
	//��Ա����||��Ϊ
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
	//��Ա����||����
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1,s2,s3;

	cout << sizeof(s1) << endl;
	s1.SetStudentInfo("Peter", "��", 31);
	s2.SetStudentInfo("Peter2", "��", 31);
	s3.SetStudentInfo("Peter3", "Ů", 31);

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
	//��Ա����||��Ϊ
	void SetStudentInfo(char *name,char *gender, int age)
	{
		//Student * const//thisָ�������
		//this = nullptr;thidָ�벻���޸� 
		cout <<this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		_age = age;
	}
	void PrintfStudetInfo()
	{
		cout <<this-> _name << ": " << this->_gender << " :" << this->_age << endl;
	}
	void TestFunc(...)//��������
	{
		cout << this << endl;
	}
private:
	//��Ա����||����
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1, s2, s3;
	s1.TestFunc(10);
	//cout << sizeof(s1) << endl;
	s1.SetStudentInfo("Peter", "��", 31);
	cout << &s1 << endl;
	s2.SetStudentInfo("Peter2", "��", 31);
	cout << &s2 << endl;
	s3.SetStudentInfo("Peter3", "Ů", 31);
	cout << &s3 << endl;
	return 0;
}
#endif

#if 0
class Student
{
public:
	//��Ա����||��Ϊ
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
	//��Ա����||����
	char _name[20];
	char _gender[3];
	int _age;
};
int main()
{
	Student s1, s2, s3;
	s1.SetStudentInfo("Peter", "��", 31);
	cout << &s1 << endl;
	s2.SetStudentInfo("Peter2", "��", 31);
	cout << &s2 << endl;
	s3.SetStudentInfo("Peter3", "Ů", 31);
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
*///�������еı���ʱ�����������
	void show()
	{
		cout << "Show����" << endl;
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