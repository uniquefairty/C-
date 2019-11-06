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

#if 0
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
			string& operator[](size_t pos)
			{
				*_pcount--;
				_str = new char[strlen(_str) + 1];
             //


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

		s3 = s1;
		s4 = s1;

		s1[0] = 'H';

	}
	int main(){
		TestString();
		return 0;
	}
#endif

#if 0
	//��ת�ַ���
	class Solution {
	public:
		string reverseStr(string s, int k) {
			string::iterator it = s.begin();
			while (it<s.end() && it + k <= s.end())
			{
				reverse(it, it + k);
				it = it + 2 * k;
			}
			if (it + k>s.end())
				reverse(it, s.end());
			return s;
		}
	};
#endif

	/*class Solution {
	public:
		string reverseStr(string s, int k) {
			reverse(s.begin(), s.end());
		}
	};
*/
	
#if 0
	class Solution {
	public:
		string reverseWords(string s) {
			auto it = s.begin();

			while (it != s.end())
			{
				size_t i = 0;
				while (*(it + i) != ' ')
				{
					i++;
				}
				reverse(it, it + i - 1);
				it = it + i + 1;
			}
			return s;
		}
	};
#endif

#if 0
//#include<string>
	class String
	{
	public:
		String(const char*str = " ")
		{
			if (nullptr == str)
			{
				str = " ";
			}
			_str = new char[strlen(str) + 1];
		}
		String(const String& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}
		/*String(const String& s)
			:_str(nullptr)
		{
			String tmp(s._str);
			swap(_str, tmp._str);
		}
		String& operator=(String s)
		{
			swap(_str, s._str);
			return *this;

		}*/
		String& operator=(const String & s)
		{
			if (this != &s)
			{
				char* pStr = new char[strlen(s._str) + 1];
				strcpy(pStr, s._str);
				delete[] _str;
				_str = pStr;
			}
			return *this;
		}
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

	int main()
	{
		return 0;
	}
#endif



#if 0
#include<string>
	int main()
	{
		string url("http://www.cplusplus.com/reference/string/find");
		cout << url <<endl;
		size_t start = url.find("://");
		if (start == string::npos)
		{
			cout << "invalid url" << endl;
			return 0;
		}
		start += 3;
		size_t finish = url.find('/', start);
		string address = url.substr(start, finish - start);
		cout << address << endl;
		size_t pos = url.find("://");
		url.erase(0, pos + 3);
		cout << url << endl;
		return 0;
	}
#endif
	//////////////////////////////
	//ģ��ʵ��string��
#if 0

#include<iostream>
using namespace std;
#include<assert.h>
	class String
	{
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		static size_t npos;//��̬��Ա���������ⶨ��
	public:
		typedef char* iterator;
		
	public:
		////�������캯��
		String(const char* str = " ")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		String(size_t n, char ch)
			:_size(n)
			, _capacity(n)
			, _str(new char[n + 1])
		{
			memset(_str, ch, n);
			_str[n] = '\0';
		}
		String(const String&s)
			:_size(s._size)
			, _capacity(s._size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}
		String(char* begin, char* end)
		{
			_size = end - begin;
			_capacity = _size;
			_str = new char[_size + 1];
			strncpy(_str, begin, _size);
			_str[_size] = '\0';
		}
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				int len = strlen(s._str);
				char *p = new char[len + 1];
				strcpy(p, s._str);
				delete[] _str;

				_str = p;
				_size = len;
				_capacity = len;
			}
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_capacity = 0;
				_size = 0;
			}
		}
		/*String(const String& s)
		:_str(nullptr)
		, _size(0)
		, capacity(0)
		{
		String tmp(s);
		this->Swap(tmp);
		}
		*/
		////������
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//�޸Ĳ���
		void  PushBack(char c)
		{
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}

		String& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}
		String& operator+=(const char* str)
		{
			for (size_t i=0; i < strlen(str); i++)
			{
				PushBack(str[i]);
			}
			return *this;
		}
		String& operator+=(const String& s)
		{
			for (size_t i=0; i < s.Size(); i++)
			{
				PushBack(s[i]);
			}
			return *this;

		}
		void Append(const char* str)
		{
			for (size_t i=0; i < strlen(str); i++)
			{
				PushBack(str[i]);
			}
		}
		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char* C_str()const
		{
			return _str;
		}

		//��������
		size_t Size() const
		{
			return _size;
		}
		size_t Capacity()const
		{
			return _capacity;
		}
		bool Empty()const
		{
			return 0 == _size;
		}
		void Resize(size_t newSize,char c='h')//�ı���Ч�ַ�
		{
			size_t oldSize = _size;
			if (newSize>oldSize)
			{
				if (newSize > _capacity)
				{
					Reserve(newSize);
					memset(_str + _size, c, newSize - oldSize);
				}
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
		void Reserve(size_t newCapacity)//����
		{
			size_t oldCapacity = _capacity;
			if (newCapacity > oldCapacity)
			{
				char* str = new char[newCapacity+1];
				strcpy(str, _str);

				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}
		////���������
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		bool operator<(const String& s)
		{
			size_t minsize = _size<s.Size() ? _size : s.Size();
			while (s._str&&_str)
			{
				for (size_t i = 0; i < minsize; i++)
				{
					if (_str[i] < s[i])
					{
						return true;
					}
					else if (_str[i]>s[i])
					{
						return false;
					}
				}
			}
			if (Size() < s.Size())
			{
				return true;
			}
			return false;

		}
		bool operator<=(const String& s)
		{
			size_t minsize = _size<s.Size() ? _size: s.Size();
			while (s._str&&_str)
			{
				for (size_t i = 0; i < minsize; i++)
				{
					if (_str[i] < s[i])
					{
						return true;
					}
					else if (_str[i]>s[i])
					{
						return false;
					}
				}
			}
			if (Size() <= s.Size())
			{
				return true;
			}
			return false;
		}
		bool operator>(const String& s)
		{
			size_t minsize = _size<s.Size() ? _size : s.Size();
			while (s._str&&_str)
			{
				for (size_t i = 0; i < minsize; i++)
				{
					if (_str[i] >s[i])
					{
						return true;
					}
					else if (_str[i]<s[i])
					{
						return false;
					}
				}
			}
			if (Size() > s.Size())
			{
				return true;
			}
			return false;
		}
		bool operator>=(const String& s)
		{
			size_t minsize = _size<s.Size() ? _size : s.Size();
			while (s._str&&_str)
			{
				for (size_t i = 0; i < minsize; i++)
				{
					if (_str[i] >s[i])
					{
						return true;
					}
					else if (_str[i]<s[i])
					{
						return false;
					}
				}
			}
			if (Size() >= s.Size())
			{
				return true;
			}
			return false;
		}
		bool operator==(const String& s)
		{
			if (Size() == s.Size())
			{
				for (size_t i = 0; i < Size(); i++)
				{
					if (_str[i] != s._str[i])
						return false;
				}
			}
			return true;
		}
		bool operator!=(const String& s)
		{
			if (Size() == s.Size())
			{
				for (size_t i = 0; i < Size(); i++)
				{
					if (_str[i] != s._str[i])
						return true;
				}
			}
			return false;
		}
		//����
		//����ch��string�е�һ�γ��ֵ�λ��
		size_t Find(char ch, size_t pos = 0)const
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (ch == _str[i])
					return i;
			}
			return npos;
		}
		//�����Ӵ���string�е�һ�γ��ֵ�λ��
		size_t Find(const char*s, size_t pos = 0)const
		{
			//char *ret = strstr(_str, s);
			size_t i = 0;
			size_t j = 0;
			size_t len = strlen(s);
			while (i < _size&&j <len )
			{
				if (_str[i] == s[j])
				{
					i++;
					j++;
				}
				else
				{
					i++;
					j = 0;
				}
			}
			if (j == len)
				return i-j;
			else
				return -1;

		}
		//��posλ��ǰ��ch
		size_t RFind(char ch, size_t pos = npos)
		{
			if (pos == npos)
				pos = _size - 1;

			for (int i = pos; i >= 0; i--)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}
			return npos;
		}
		//��str��posλ�ÿ�ʼ��ȡn���ַ�
		String substr(size_t pos = 0, size_t n = npos)
		{
			if (n == npos)
				n = _size;
			String temp(_str + pos, _str + pos + n);//���乹��
			return temp;
		}

		String& Insert(size_t pos, char c)
		{
			if (pos < _size)
			{
				if (_size + 1 < _capacity)
					Reserve(_capacity * 2);

				for (int i = _size-1; i >= pos; i--)
				{
					_str[i + 1] = _str[i];
				}
			}
				_str[pos] = c;
				_size++;
				_str[_size] = '\0';
				return *this;
		}
		String& Insert(size_t pos, char* str)
		{
			while (_size + strlen(str) > _capacity)
			{
				Reserve(_capacity * 2);
			}
			for (size_t i = _size - 1, j = _size + strlen(str) - 1; i >= pos; i--, j--)
			{
				_str[j] = _str[i];
			}
			
			for (size_t i = pos, j = 0; j <strlen(str); i++, j++)
			{
				_str[i] = str[j];
			}
			_size += strlen(str);
		
			_str[_size] = '\0';

			return *this;
		}

		//ɾ��posλ�õ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		String& Erase(size_t pos, size_t len);

		friend ostream& operator<<(ostream& _cout, const String& s)
		{
			_cout << s.C_str();
			return _cout;
		}

	};
	size_t String::npos = -1;
	void TestString()
	{
		String s1("hello");
		String s2("xixi");
		s1.PushBack(' ');
		s1.PushBack('b');

		s1.Append("it");

		s1 += "hehe";
		s1 += s2;

		if (s1 > s2)
		{
			cout << "s1>s2" << endl;
		}
		else
		{
			cout << "s1<s2" << endl;
		}

		cout << s1 << endl;

		size_t pos1 = s1.Find('e');
		cout << pos1 << endl;
		size_t pos2= s1.Find("ll");
		cout << pos2 << endl;

		cout << s2.RFind('x') << endl;
	
		s1.Insert(4, 'j');
		s2.Insert(2, "jiang");


		cout << s1 << endl;
		cout << s2 << endl;


	}
	int main()
	{
		TestString();
		return 0;
	}
#endif

#if 0
	class Solution {
	public:
		void reverseString(vector<char>& s) {
			if (s.size()>0)
			{

				auto start = s.begin();
				auto end = s.end() - 1;

				while (start != end)
				{
					char temp = *start;
					*start = *end;
					*end = temp;
					start++;
					end--;
				}

			}


		}
	};

#endif

#if 0
#include<string>
	class Solution {
	public:
		string reverseVowels(string s) {

			string a;
			a.append("aoeiuAOEIU");

			size_t i = 0;
			size_t j = s.size() - 1;

			while (i<j)
			{
				if (a.find(s[i]) && a.find(s[j]))
					swap(s[i++], s[j--]);
				else
				{
					i++;
					j--;
				}
			}

			return s;

		}
	};
		
	int main()
	{
		string s("hello");
		string a;
		a.append("aoeiuAOEIU");

		size_t i = 0;
		size_t j = s.size() - 1;

		while (i<j)
		{
			while (a.find(s[i]) == string::npos&&i<j)
				i++;
			
			while (a.find(s[j]) == string::npos&&i<j)
				j--;
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			//swap(s[i++], s[j--]);
			i++;
			j--;

			
			/*if (a.find(s[i]) != string::npos && a.find(s[j]) != string::npos)
				swap(s[i++], s[j--]);
			else
			{
				i++;
				j--;
			}*/
		}
		cout << s << endl;
		return 0;
	}

	class Solution {
	public:
		string reverseVowels(string s) {

			string a;
			a.append("aoeiuAOEIU");

			size_t i = 0;
			size_t j = s.size() - 1;



			while (i<j)
			{
				while (a.find(s[i]) == string::npos&&i<j)
					i++;

				while (a.find(s[j]) == string::npos&&i<j)
					j--;
				swap(s[i++], s[j--]);

			}
			return s;
		}
	};

	class Solution {

	public:
		bool Test(char c)
		{
			return c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u'
				|| c == 'A' || c == 'O' || c == 'E' || c == 'I' || c == 'U';
		}
		string reverseVowels(string s) {
			int left = 0;
			int right = s.size() - 1;

			while (left<right)
			{
				if (Test(s[left]))
				{
					if (Test(s[right]))
					{
						swap(s[left++], s[right++]);
					}
					else
					{
						right++;
					}
				}
				else
				{
					left++;
				}

			}

			return s;
		}
	};


	class Solution {

	public:

		string reverseVowels(string s) {

			int left = 0, right = s.size() - 1;
			while (left < right)
			{
				if (isVowel(s[left]) && isVowel(s[right]))
				{
					swap(s[left++], s[right--]);
				}
				else if (isVowel(s[left]))
				{
					--right;
				}
				else
				{
					++left;
				}
			}
			return s;
		}

		bool isVowel(char c)
		{
			return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
				|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
		}

	};
#endif

#if 0
	
#include<string>

	bool isLetterOrNumber(char ch)
	{
		return (ch >= '0'&&ch <= '9') || (ch>'a'&&ch<'z');
	}
	bool isPalindrome(string s)
	{
		int left = 0;
		int right = s.size() - 1;

		for (int i = 0; i<s.size(); i++)
		{
			if (s[i]>'A'&&s[i]<'Z')
			{
				s[i] = s[i] + 32;
			}
		}



		while (left < right)
		{
			if (isLetterOrNumber(s[left]) && left <= right)
			{
				if (isLetterOrNumber(s[right]) && left <= right)
				{
					if (s[left] == s[right])
					{
						left++;
						right--;
					}
					else
					{
						return false;
					}
				}
				else
				{
					right--;
				}
			}
			else
			{
				left++;
			}
		}
		return true;

	}


	int main()
	{
		string s("race a car");
		isPalindrome(s);
		cout << isPalindrome(s);
		return 0;
	}
#endif

#if 0
	//�ַ������
	class Solution {
	public:
		string addStrings(string num1, string num2) {
			string s;
			int end1 = num1.size() - 1;
			int end2 = num2.size() - 1;
			int value1 = 0, value2 = 0, count = 0;

			while (end1 >= 0 || end2 >= 0)
			{
				//num1ʮ���Ƶ���ֵ
				if (end1 >= 0)
					value1 = num1[end1--] - '0';
				else
					value1 = 0;

				//num2ʮ���Ƶ���ֵ
				if (end2 >= 0)
					value2 = num2[end2--] - '0';
				else
					value2 = 0;

				int sum = value1 + value2 + count;
				if (sum>9)
				{
					count = 1;
					sum -= 10;
				}
				else
				{
					count = 0;
				}
				s.insert(s.begin(), sum + '0');
			}



			if (count == 1)
				s.insert(s.begin(), '1');


			return s;

		}
	};

#endif
	//�ַ������
	//����num1��ÿ��������num2����һ��string��
	//push_back('0')
	//���ַ������
	string multiply(string num1, string num2)
	{
		string s;
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;

		int value1= 0, value2 = 0;
		//int count = 0;

		for (; end1 >= 0;end1--)
		{
			value1 = num1[end1]-'0';
			int sum = 0, next = 0;
			for (; end2 >= 0; end2--)
			{
				
				value2 = num2[end2] - '0';
				sum = value1*value2+next;

				while (sum > 9)
				{
					sum -= 10;
					next++;
				}
				s += (sum + '0');
			}
		}
		
	}