//�������
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int fun(string s)
//{
//	int res = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		res += s[i];
//	}
//	return res;
//}
//int main()
//{
//	string str1, str2, str3;
//	vector<string> v;
//	while (cin >> str1)
//	{
//		getline(cin, str2);
//		cin >> str3;
//		v.push_back(str1);
//		for (int i = 0; i < str2.size();i++)
//		{
//			string val="";
//			while (str2[i] != ' '||str2[i]=='\0')
//			{
//				val += str2[i];
//				i++;
//			}
//			v.push_back(val);
//		}
//		int total = fun(str1);
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (v[i].size() == str1.size()&& total==fun(v[i]))
//			{
//				cout << str3 << ' ';
//
//			}
//			else
//			{
//				cout << v[i] << ' ';
//			}
//			
//		}
//		
//
//	}
//	return 0;
//}


#if 0
//�������
#define CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
string& replace_all(string& str, const string& old_val, const string& new_val)
{
	while (true)
	{
		string::size_type pos(0);
		if ((pos = str.find(old_val)) != string::npos)
		{
			str.replace(pos, old_val.size(), new_val);
		}
		else break;
	}
	return str;
}
vector<string> f(char *str, int len, int n)
{
	int i;
	char tmp;
	char *p = (char *)malloc(len + 1);
	vector<string> v;
	if (n == len - 1)
	{
		v.push_back(str);
	}
	else
	{
		for (i = n; i < len; i++)
		{
			strcpy(p, str);
			tmp = *(str + n);
			*(str + n) = *(str + i);
			*(str + i) = tmp;
			f(str, len, n + 1);
			strcpy(str, p);
		}
	}
	free(p);
	return v;
}
int main()
{
	string str1, str2, str3;
	vector<string> v;
	/*while (cin >> str1)*/
	while (1)
	{
		cin >> str1;
		getchar();
		getline(cin, str2);
		//getchar();
		cin >> str3;
		vector<string> v;
		v = f(&str1[0], str1.size(), 0);
		//ȫ����
		for (int i = 0; i < v.size(); i++)
		{
			replace_all(str2, v[i], str3);
		}
		cout << str2 << endl;


	}
	return 0;
}
#endif

#if 0
//���д��滻--��ȷ
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	string str1, str2, str3;
	cin >> str1;
	getchar();
	getline(cin, str2);
	cin >> str3;

	vector<string> v;
	string tmp = "";
	for (int i = 0; i < str2.size(); i++)
	{
		if (str2[i] == ' ')
		{
			v.push_back(tmp);
			tmp = "";
		}
		else if (str2[i] == ',')
		{
			v.push_back(tmp);
			v.push_back(",");
			tmp = "";
		}
		else
		{
			tmp += str2[i];
		}
	}
	v.push_back(tmp);

	sort(str1.begin(), str1.end());
	for (int i = 0; i < v.size(); i++)
	{
		string s;
		s = v[i];
		sort(s.begin(), s.end());
		if (s == str1)
		{
			v[i].clear();
			v[i] = str3;
		}
	}
	string res;
	for (int i = 0; i < v.size(); i++)
	{
		res += v[i];
		res += ' ';
	}

	cout << res << endl;

	return 0;
}
#endif

#if 0
//����ϵͳϵͳ������·������
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//����
vector<string> result;
string temp="";
void backward(vector<string> part, int index)
{
	if (temp.size() == part.size())//ÿ������ĳ��ȵ��ڷָ������ĸ���
	{
		result.push_back(temp);
	}
	else if (temp.size()<part.size())
	{
		for (int i = 0; i < part[index].size(); i++)
		{

		}
	}
		

}

int main()
{
	string s, cache;
	getline(cin, s);
	vector<string> part;

	int i = 0;
	//�и��ַ���
	while (i < s.size())
	{
		if (s[i] == ' ')
		{
			part.push_back(cache);
			cache = "";
		}
		else
			cache.push_back(s[i]);

		i++;
	}
	part.push_back(cache);

	//����
	for (int i = 0; i < part[0].size(); i++)
	{
		temp.push_back(part[0][i]);
		backward(part, 1);
		temp.pop_back();
	}

	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

char ans[500];
int main()
{
	int n;
	std::cin >> n;

	int l = 0;
	while (n > 0)
	{
		ans[l++] = n % 36 > 9 ? n % 36 - 10 + 'a' : n % 36 + '0';
		n /= 36;
	}

	for (int i = l - 1; i >= 0; --i)
	{
		std::cout << ans[i];
	}
	return 0;
}
#endif


#include <iostream>
#include <string>
using namespace std;

long fun(int i)
{
	long res = 1;
	while (i)
	{
		res *= 36;
		i--;
	}
}

int main()
{
	string s;
	while (cin >> s)
	{
		long result = 0;
		string res = "";
		int flag = 1;
		int t = 1;
		int SIZE = s.size();
		if (s[0] == '-')
		{
			SIZE--;
		}
		
	
		for (int i = 0; i<s.size(); i++)
		{
			if (s[0] == '-')
			{
				continue;
				t = 0;
			}

			if (s[i] <= '9'&&s[i] >= '0')
			{
				result += (s[i] - '0')*fun(SIZE-i-1);
			}
			else if (s[i] >= 'a'&&s[i] <= 'z')
			{
				result += ((s[i] - 'a') + 10)*fun(SIZE - i - 1);
			}
			else
			{
				flag = 0;
				break;
				
			}
		}

		if (flag == 0)
		{
			cout << 0 << endl;
		}
		else if (t == 0)
		{
			//�������
			cout << '-' << result << endl;
		}
		else
		{
			cout << result << endl;
		}


	}
	return 0;
}
