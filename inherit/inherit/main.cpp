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
	//��֤�������ཫ�����еĳ�Ա�����̳е�������
	cout << sizeof(Derived) << endl;
	//��֤�������еĳ�Ա�����Ƿ�����̳�
	Derived d;
	d.SetBase(10, 20, 30);
	d.PrintBase();
	return 0;
}
#endif

#if 0
//public�̳�
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
		//_pri = 4;//���뱨�����������в��ܷ��ʻ�����˽�еĳ�Ա����
	}
	//����Ȩ�ޣ��޶��ó�Ա�����Ƿ����ֱ����������е���
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
		//_pri = 4;//���뱨�����������в��ܷ��ʻ�����˽�еĳ�Ա����
	}
	//����Ȩ�ޣ��޶��ó�Ա�����Ƿ����ֱ����������е���
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
		//_pri = 4;//���뱨�����������в��ܷ��ʻ�����˽�еĳ�Ա����
	}
	//����Ȩ�ޣ��޶��ó�Ա�����Ƿ����ֱ����������е���
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
//class��struct��Ĭ�ϼ̳�Ȩ��
//classĬ�ϼ̳�Ȩ����private
//structĬ�ϼ̳�Ȩ����public
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
		//_pri = 4;//���뱨�����������в��ܷ��ʻ�����˽�еĳ�Ա����
	}
	//����Ȩ�ޣ��޶��ó�Ա�����Ƿ����ֱ����������е���
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
//��ֵ���ݹ���ǰ��--��public
//�����public�̳з�ʽ����������������֮����һ��--is-a�Ĺ�ϵ
//is-a����һ�����Խ�һ��������󿴳���һ���������
//�����õ���������λ�ö�����ʹ�����������д���
int main()
{
	B b;
	b.SetB(10);
	D d;
	d.SetB(20);
	d.SetD(20, 30);

	 //d = b;
	//һ������������ָ���������
	//һ�������ָ�벻��ֱ��ָ��һ������Ķ���
	b = d;
	B *pb = &d;
	B& rb = d;

	//һ������ָ��ָ��һ���������ǿת
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
//ͬ�����أ�������������о�����ͬ���Ƶĳ�Ա����Ա����||��Ա������
//���ͨ�����������ֱ�ӷ���ͬ���ڸ��Ա�����ȷ��ʵ��������Լ��ģ������
//ͯ����Ա����ֱ�ӷ��ʵ��������ཫ�����е�ͬ����Ա���أ�
//��Ա����������������Ƿ���ͬ�޹�
//��Ա���������Ա����ԭ���Ƿ���ͬ�޹�
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
	string _name; // ����
	string _sex; // �Ա�
	int _age; // ����
};
class Student : public Person
{
public:
	int _No; // ѧ��
};
void Test()
{
	Student sobj;
	// 1.���������Ը�ֵ���������/ָ��/����
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	//2.��������ܸ�ֵ�����������
	//sobj = pobj;
	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
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
//�������Ĺ���ʹ��д��в����Ĺ��캯�����û�������
//�����๹�캯����ʼ���б��λ����ʾ���ã�����ɻ��ಿ�ֳ�Ա�ĳ�ʼ��
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
//�������
//�����๹�캯������
//�����๹�캯������
//{}
//��������
//����������������)
//{
//	�ͷ���������Դ
//		�������������������������һ����Ч�������һ��������
//		call��������������
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
//ʵ��һ�����ܱ��̳е���
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
	string _name; // ����
};
class Student : public Person
{
protected:
	int _stuNum; // ѧ��
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
	//cout << d._d << endl;//���ⲻ�ܷ������еı�������
}
#endif

#if 0

//ͳ��һ���ഴ���˶��ٶ���
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
	Person p("111", "��", 18);
	Student s("222", "Ů", 34, 23);

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
	//d._b = 2; //���μ̳�ȱ�ݣ�����ڶ�����
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


// Car��BMW Car��Benz����is-a�Ĺ�ϵ
class Car{
protected:
	string _colour = "��ɫ"; // ��ɫ
	string _num = "��ABIT00"; // ���ƺ�
};
class BMW : public Car{
public:
	void Drive() { cout << "�ÿ�-�ٿ�" << endl; }
};
class Benz : public Car{
public:
	void Drive() { cout << "����-����" << endl; }
};
// Tire��Car����has-a�Ĺ�ϵ
class Tire{
protected:
	string _brand = "Michelin"; // Ʒ��
	size_t _size = 17; // �ߴ�
};
class Car{
protected:
	string _colour = "��ɫ"; // ��ɫ
	string _num = "��ABIT00"; // ���ƺ�
	Tire _t; // ��̥
};
