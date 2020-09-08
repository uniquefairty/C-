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
		//È«ÅÅÁÐ
		for (int i = 0; i < v.size(); i++)
		{
			replace_all(str2, v[i], str3);
		}
		cout << str2 << endl;


	}
	return 0;
}