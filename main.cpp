#include<iostream>
using namespace std;

#if 0
#include<string>
#endif
#if 0
void TestString1()
{
	string s1;
	string s2("hello");
	string s3(10, '$');
	string s4(s3);

	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

}
//������ط�ʽ
void TestString2()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	s.clear();//ֻ���string������Ч�ַ�����������ı�ײ�ռ���ܴ�С

	if (s.empty())
	{
		cout << "NULL string" << endl;
	}
	else
	{
		cout << "Not NULL string" << endl;
	}

}

//resize/reserve
//void resize(size_t n,char ch);
//���ܣ���string���е���Ч�ַ��ı䵽n��������ַ�����ch������䡣
//ע�⣺1.����ǽ�string���е���ЧԪ����С��ֻ�ı���ЧԪ�ظ���������ı�ײ�ռ��С
//2.����ǽ�string���е���ЧԪ�����࣬������Ҫ���ݡ�
void TestString3()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(10, '!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '8');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(6);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

//void reserve(size_t newcapacity);����
//newcapacity>oldcapacity(string��ռ�Ĵ�С�����ռ�����->�����ı䣨����������С>=newcapacity),��Ч�ַ���������
//newcapacity<oldcapacity(string��ռ�Ĵ�С�����ռ���С->�ú���ֱ�ӷ��أ�����newcapacity<15����Ч�ַ�<15�����Ż���ٵ��ײ�ռ俪�ٵ�����
//ֻ�ı������Ĵ�С������ı���ЧԪ�ظ���
void TestString4()
{
	string s(2, '$');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(40);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(24);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(13);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(1);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

}

void TestString5()
{
	string s("hello");
	cout << s[0] << endl;
	s[0] = 'H';
	//���Խ��-assert����
	//cout << s[10] << endl;

	cout << s.at(2) << endl;
	s.at(2) = 'L';
	//���Խ��-�׳�out_of_range�쳣
	//cout << s.at(10) << endl;
}
void TestString6()
{
	string s1;
	s1.push_back('I');

	s1 += "Love";
	string s2("you");
	s1 += s2;

	s1.append(1, ',');
	s1.append("���");
	s1.append(3, '!');

}

//1.string������ݻ���-vs-PJ 1.5��
//2.�����ǰ֪�����Ҫ��string���Ŷ��ٿռ䣬��������ǰͨ��reserve���ռ��ṩ��
void TestPushBack()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}
void TestString7()
{

	//string s("abcd");
	//const char *b = s.c_str();
	//s.append("cde");
	//cout << b << endl;//abcdcde

	string s("123s45");
	int ret = atoi(s.c_str());
	//int atoi(const char* str);//���ַ���ת��Ϊ����
	//���str�зǿո��ַ��ĵ�һ�����в�����Ч������������strΪ�ջ�������ո��ַ���û������������
	//��ִ���κ�ת�����������㡣
	cout << ret << endl;
}

void TestString8()
{
	string s("hello world");

	//size_t find(const string&str,size_t pos=0) const;
	size_t pos = s.find(' ');

	if (pos != string::npos)
	{
		cout << ' ' << "is in s" << pos << endl;
	}
	pos = s.find("world");
	if (pos != string::npos)
	{
		cout << "world" << "is in s" << pos << endl;
	}

	//��ȡ�ļ���׺
	string ss("20190923.cpp.cpp");
	pos = ss.rfind('.') + 1;

	//string substr (size_t pos = 0, size_t len = npos) const;
	string filepox = ss.substr(pos);
	cout << filepox << endl;
}

void TestString9()
{
	string s("hello");
	for (auto e : s)
	{
		cout << e;
	}
	cout << endl;

	for (size_t i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	cout << endl;

	//C++98
	//string::iterator it = s.begin();

	//C++11
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

void reversestring(string& s)
{
	//reverse(s.begin(), s.end());

	char* begin = (char *)s.c_str();
	char* end = begin + s.size() - 1;
	while (begin < end)
	{
		swap(*begin ,*end);
		begin++;
		end--;
	}
}

int main()
{
	string s;
	cin >> s;
	//getline(cin, s);
	cout << s << endl;
	
	//TestString1();
	//TestString2();
	//TestString3();
	//TestString4();
	//TestString5();
	//TestString6();
	//TestString7();
	//TestString8();
	//TestString9();

	//string s("hello world");
	//reversestring(s);
	//cout << s << endl;
	return 0;
}
#endif

#if 0
//�ж���ת�ַ���
#include<iostream>
using namespace std;
#include<string>

//void Fun(string s1, string s2)
//{
//	s1 += s1;//������Ϊ�ռ�洢�����������
//	int pos = s1.find(s2);
//	if (pos != string::npos)
//	{
//		cout << "YES" << endl;
//	}
//	else{
//		cout << "No" << endl;
//	}
//}
void Fun(string s1, string s2, size_t size1, size_t size2)
{
	int pos = s1.find(s2[0]);

	int i = 0;
	for (i = 0; i<size2; i++)
	{
		if (s1[pos] == s2[i])
		{
			pos++;
			if (pos == size1)
			{
				pos = 0;
			}
		}
		else{
			cout << "NO" << endl;
			break;
		}
	}
	if (i == size2)
	{
		cout << "YES" << endl;
	}

}

int main()
{
	string s1;
	string s2;
	size_t size1, size2;
	cin >> size1 >> size2;
	cin >> s1;
	cin >> s2;
	if (size1 == size2)
	{
		Fun(s1, s2, size1, size2);
	}
	else
	{
		cout << "No" << endl;
	}
}

void Fun(string s1, string s2)
{
	s1 += s1;
	int pos = s1.find(s2);
	if (pos != string::npos)
	{
		cout << "YES" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<string>

void Fun(string s1, string s2, size_t size1, size_t size2)
{
	if (size1 == size2)
	{
		size_t i = 0;
		for (i = 0; i<size1; i++)
		{
			size_t pos = s2.find(s1[i]);

				if (pos == string::npos)
				{
					cout << false << endl;
					break;
				}
				s2[pos] -= '0';
		}
		if (i == size1)
		{
			cout << "true" << endl;
		}
	
	}
	else
		cout << "false "<< endl;
}
int main()
{
	size_t size1, size2;
	cin >> size1 >> size2;

	string s1, s2;
	cin >> s1 >> s2;
	Fun(s1, s2, size1, size2);
	return 0;
}
#endif

#if 0
//����string�����ǳ��������
//string�ද̬�����ַ���
//#include<assert.h>
#include<string.h>
namespace bite
{

	class string
	{
	public:
		string(const char * str = "")
		{
			if (nullptr == str)
				str = "";
			//����ռ�
			_str = new char[strlen(str) + 1];
			//���str�е��ַ�
			strcpy(_str, str);
		}
		
		//��s����������ԭ�ⲻ���Ŀ������µĶ�����ȥ
		//ֵ�Ŀ���--����λ�Ŀ���
		string(string& s)
			:_str(s._str)
		{}
		//���������ɵ�Ĭ�Ϲ��캯��--ǳ����&��Դй©
		string& operator=(const string& s)
		{
			_str = s._str;
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
	
}
void TestString()
{
	bite::string s1("hello");
	bite::string s2(nullptr);
	//bite::string s3(s1);//Ĭ�ϵĿ������캯��ʱǳ����
	//s2 = s1;//����ǳ��������
}
int main()
{
	TestString();
	return 0;
}
#endif

#if 0
#include<string.h>
namespace bite
{
	class string
	{
	public:
		string(const char * str = "")
		{
			if (nullptr == str)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		//�������캯��
		string(string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		//��ֵ=���������
		//
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char * tmp = new char[strlen(s._str) + 1];//1.�����¿ռ�
				strcpy(tmp, s._str);//2.����Ԫ��
				delete[] _str;//3.�ͷžɿռ�
				_str = tmp;//4.ָ���¿ռ�

				/*_str = new char[strlen(s._str) + 1];//�ᵼ���ڴ�й©
				strcpy(_str, s._str);*/
			}
			
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};

}
void TestString()
{
	bite::string s1("hello");
	bite::string s2(nullptr);
	bite::string s3(s1);
	s2 = s1;
}

int main()
{
	TestString();
	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	
	//�������캯��
	String(const String& s)
		:_str(nullptr)//�����ʼ������ǰ������������ֵ
	{
		String strTmp(s._str);
		swap(_str, strTmp._str);
	}

#if 0
	//��ֵ���������
	String& operator=(String& s)
	{
		if (this != &s)
		{
			String strTmp(s);
			swap(_str, strTmp._str);//���������Զ��ͷ���ʱ�ռ�s
		}
		return *this;
#endif
		String& operator=(String s)
		{
			swap(_str, s._str);
			return *this;
		}//���������Զ��ͷ���ʱ�ռ�s
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
			
		}
private:
	char* _str;
};

	void TestString()
	{
		String s1("hello");
		String s2(s1);
		String s3 = s1;
	}

	int main()
	{
		TestString();
		return 0;
	}
#endif

	namespace bite
	{

		class string
		{
		public:
			string(char* str = "")
				:_pcount(new int(1))
			{
				if (nullptr==str)
				   str = "";
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);
			}
			
			string(const string&s)
				:_str(s._str)
				, _pcount(s._pcount)
			{
				++*(_pcount);
			}
			//s2=s1
			//1.s2ԭ������Դ������ʹ��--Ӧ�ø�ԭ������-1
			//2.s2Ӧ����s1����һ����Դ
			string & operator=(const string&s)
			{
				if (this != &s)
				{
					//�õ�ǰ�������������Դ���뿪
					if (0 == -*_pcount)
					{
						delete[] _str;
						delete _pcount;
					}
					//��s������Դ
					_pcount = s._pcount;
					_str = s._str;
					++(*_pcount);
				}
				return *this;
			}
			
			
			~string()
			{
				if (_str && 0 == --*_pcount)
				{
					delete[] _str;
					_str = nullptr;

					delete _pcount;
					_pcount = nullptr;
				}
			}
		private:
			char *_str;
			int* _pcount;

		};

	}
	void TestString()
	{
		bite::string s1("hello");
		bite::string s2(s1);
		bite::string s3("world");
		bite::string s4(s3);

	}
	int main(){
		TestString();
		return 0;
	}