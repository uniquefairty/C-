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
//容量相关方式
void TestString2()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	s.clear();//只清空string类中有效字符个数，不会改变底层空间的总大小

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
//功能：将string类中的有效字符改变到n个，多的字符采用ch进行填充。
//注意：1.如果是将string类中的有效元素缩小，只改变有效元素个数，不会改变底层空间大小
//2.如果是将string类中的有效元素增多，可能需要扩容。
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

//void reserve(size_t newcapacity);扩容
//newcapacity>oldcapacity(string类空间的大小）：空间增多->容量改变（最终容量大小>=newcapacity),有效字符个数不变
//newcapacity<oldcapacity(string类空间的大小）：空间缩小->该函数直接返回，除非newcapacity<15且有效字符<15容量才会减少到底层空间开辟的容量
//只改变容量的大小，不会改变有效元素隔宿
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
	//如果越界-assert触发
	//cout << s[10] << endl;

	cout << s.at(2) << endl;
	s.at(2) = 'L';
	//如果越界-抛出out_of_range异常
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
	s1.append("祖国");
	s1.append(3, '!');

}

//1.string类的扩容机制-vs-PJ 1.5倍
//2.如果提前知道大概要往string类存放多少空间，可以以提前通过reserve将空间提供好
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
	//int atoi(const char* str);//将字符串转化为整数
	//如果str中非空格字符的第一个序列不是有效的整数，由于str为空或仅包含空格字符而没有这样的序列
	//不执行任何转化，并返回零。
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

	//获取文件后缀
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
//判断旋转字符串
#include<iostream>
using namespace std;
#include<string>

//void Fun(string s1, string s2)
//{
//	s1 += s1;//可能因为空间存储不足出现问题
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
//借助string来解决浅拷贝问题
//string类动态管理字符串
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
			//申请空间
			_str = new char[strlen(str) + 1];
			//存放str中的字符
			strcpy(_str, str);
		}
		
		//将s对象中内容原封不动的拷贝到新的对象中去
		//值的拷贝--比特位的拷贝
		string(string& s)
			:_str(s._str)
		{}
		//编译器生成的默认构造函数--浅拷贝&资源泄漏
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
	//bite::string s3(s1);//默认的拷贝构造函数时浅拷贝
	//s2 = s1;//发生浅拷贝问题
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
		//拷贝构造函数
		string(string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		//赋值=运算符重载
		//
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char * tmp = new char[strlen(s._str) + 1];//1.开辟新空间
				strcpy(tmp, s._str);//2.拷贝元素
				delete[] _str;//3.释放旧空间
				_str = tmp;//4.指向新空间

				/*_str = new char[strlen(s._str) + 1];//会导致内存泄漏
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
	
	//拷贝构造函数
	String(const String& s)
		:_str(nullptr)//必须初始化：当前对象可能是随机值
	{
		String strTmp(s._str);
		swap(_str, strTmp._str);
	}

#if 0
	//赋值运算符重载
	String& operator=(String& s)
	{
		if (this != &s)
		{
			String strTmp(s);
			swap(_str, strTmp._str);//函数调完自动释放临时空间s
		}
		return *this;
#endif
		String& operator=(String s)
		{
			swap(_str, s._str);
			return *this;
		}//函数调完自动释放临时空间s
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
			//1.s2原来的资源将不再使用--应该给原来计数-1
			//2.s2应该与s1共享一份资源
			string & operator=(const string&s)
			{
				if (this != &s)
				{
					//让当前对象与其管理资源分离开
					if (0 == -*_pcount)
					{
						delete[] _str;
						delete _pcount;
					}
					//与s共享资源
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