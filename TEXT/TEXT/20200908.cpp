//错误代码
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
//错误代码
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
		//全排列
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
//敏感词替换--正确
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
//订单系统系统工作流路径解析
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//回溯
vector<string> result;
string temp="";
void backward(vector<string> part, int index)
{
	if (temp.size() == part.size())//每个结果的长度等于分割后数组的个数
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
	//切割字符串
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

	//回溯
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

#if 0
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
			//输出负数
			cout << '-' << result << endl;
		}
		else
		{
			cout << result << endl;
		}


	}
	return 0;
}
#endif

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//	int add(vector<int>& candies, vector<int>& coin, int n, int index)
//	{
//		int tmp = 0;
//		while (n)
//		{
//			if (coin[i] == 1)
//			{
//				tmp += candies[index];
//			}
//			index++;
//			n--;
//		}
//	}
//	int maxCandies(vector<int>& candies, vector<int>& coin, int n) {
//		// write code here
//		if (candies.size() == 0)
//			return 0;
//		int res = 0;
//		int max = 0;
//
//		for (int i = 0; i<candies.size(); i++)
//		{
//			//碰到反面时，连续n个数反面的糖果数量
//			if (coin[i] == 0)
//			{
//				result += coin[i];
//			}
//
//			if (coin[i] == 1)
//			{
//				//反面
//				int a = add(candies, coin, n, i);
//				if (a>max)
//				{
//					max = a;
//				}
//
//			}
//		}
//
//		cout << res << endl;
//	}

#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxCandies(vector<int>& candies, vector<int>& coin, int n) {
	// write code here
	if (candies.size() == 0)
		return 0;
	int res = 0;
	int max = 0;

	for (int i = 0; i<candies.size(); i++)
	{
		//碰到反面时，连续n个数反面的糖果数量
		if (coin[i] == 0)
		{
			res += candies[i];
		}

		if (coin[i] == 1)
		{
			//反面
			int index = i;
			int tmp = 0;
			int count = n;
			while (index<candies.size() && count)
			{
				if (coin[index] == 1)
				{
					tmp += candies[index];
				}
				
				index++;
				count--;
			}

			if (tmp>max)
			{
				max = tmp;
			}
		}
	}
	res += max;
	cout << res << endl;
}
int main()
{
	vector<int> candies={ 3, 5, 7, 2, 8, 8, 15, 3 };
	vector<int> coin={ 1, 0, 1, 0, 1, 01, 0 };
	maxCandies(candies, coin, 3);
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{

	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		string res, tmp;
		int arr[256] = { 0 };
		for (int i = 0; i<s.size(); i++)
		{
			if (arr[s[i]] == 0)
			{
				tmp += s[i];
				arr[s[i]] = 1;
			}
			else
			{
				if (tmp.size()>res.size())
				{
					res = tmp;
					tmp = "";
				}

			}
		}
		cout << res << endl;
	}
	return 0;
}
#endif
#if 0

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string str, s;
	while (cin >> str >> s)
	{
		for (int i = 0; i<s.size();i++)
		{
			if (s[i] == str[0])
			{
				for (int j = 1; j < str.size(); )
				{
					i++;
					if (s[i] == str[j])
					{
						i++; j++;
					}
					else if (s[i] == '*')
					{
						char last = s[i + 1];
						char pre = s[i - 1];
						while (str[j] == pre&&str[j]!=last)
						{
							j++;
							if (j == str.size())
							{
								cout << "true" << endl;
								break;
							}
						}
						//1.str[j]==last  2.str[j]!=last&&str[j]!=per

						if (i<str.size()&&str[j] == last)
						{
							i++;
						}
						else if (str[j] != pre&&last!='.')
						{
							cout << "false" << endl;
							break;
						}

						if (i == str.size())
						{
							cout << "false" << endl;
							break;
						}

					}
					else if (i<str.size()&&s[i] == '.')
					{
						char last = s[i + 1];
						while (str[j] != last)
						{
							j++;
							if (j == str.size())
							{
								cout << "true" << endl;
							}
						}
					}
				}
			}
		}


	}
	return 0;
}
#endif

#if 0

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
void calculate(string input)
{
	// write code here
	stack<char> s;
	stack<int> num;
	int res = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
		{
			continue;
		}
		if (input[i] >= '0'&&input[i] <= '9')
		{
			num.push(input[i] - '0');
		}
		else if (input[i] == '+' || input[i] == '-')
		{
			s.push(input[i]);
		}
		else if (input[i] == '*' || input[i] == '/')
		{
			int num1 = num.top();
			num.pop();
			
			int num2 = input[i+2] - '0';
			if (input[i] == '*')
			{
				int tmp = num1*num2;
				num.push(tmp);
			}
			else if (input[i] == '/')
			{
				int tmp = num1 / num2;
				num.push(tmp);
			}
			i += 2;
		}
	}

		while (!s.empty())
		{
			char c = s.top();
			s.pop();
			int num1 = num.top();
			num.pop();
			int num2 = num.top();
			num.pop();
			if (c == '+')
			{
				int tmp = num1 + num2;
				num.push(tmp);
			}
			else if (c == '-')
			{
				int tmp = num1 - num2;
				num.push(tmp);
			}
		}

		cout << num.top() << endl;

	}

int main()
{
	
	string input = "1 +2 * 3";
	calculate(input);
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
//bool fun(int m)
//{
//	int tmp = m;
//	int res = 0;
//	while (tmp)
//	{
//		res += res * 10 + tmp % 10;
//		tmp /= 10;
//	}
//
//	if (res == m)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}



int main()
{
	int m;
	int v;
	while (cin >> m)
	{
		m++;
		int tmp = m;
		int res = 0;
		int a = tmp / 1000;//前面两位数12
		int b = tmp % 100;//后面两位数21
		int mid = tmp % 1000 - b;//300

		int aa = (a % 10) * 10 + (a / 10);//21
		if (b < aa)
		{
			res = m + aa - b;
		}
		else if (b>aa)
		{
			res = tmp + 100 - (b - aa);
		}
		//while (1)
		//{
		///*	m++;
		//	if (fun(m))
		//	{
		//		v = m / 2;
		//		break;
		//	}
		//	else
		//	{
		//		m++;
		//	}*/
		//}

		cout << (res-m)/2+1 << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int V, n;
	while (cin >> V)
	{
		cin >> n;
		vector<int> v;
		v.resize(n);
		int dp[10001];
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i<n; i++)
		{
			for (int j = V; j >= v[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
			}
		}
		cout << V - dp[V] << endl;
	}
	return 0;
}
#endif


# if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	vector<int> v;
	while (cin >> str)
	{
		int tmp = 0, max = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] != ',')
			{
				v.push_back(str[i] - '0');
			}
			
		}

		for (int i = 0; i<v.size(); i++)
		{
			if (i % 2 == 0)
			{
				if (i == v.size() - 1 && i % 2 != 0)
				{
					;
				}
				tmp += v[i];
			}
			else if (i % 2 != 0)
			{
					max += v[i];

			}
		}
		max = max>tmp ? max : tmp;
		cout << max << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		int len = str.size();
		int res = 1;
		int a = 0, b = 0, ab;
		for (int i = 0; i<str.size() - 1; ++i)
		{
			a = str[i] - '0';
			b = str[i + 1] - '0';
			ab = a * 10 + b;
			if (ab<26)
			{
				res++;
			}
		}


		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int a = 1, b = 1;
		for (int i = m; i >= m - n + 1;-- i)
		{
			a *= i;
		}
		for (int i = 1; i <= n; ++i)
		{
			b *= i;
		}

		cout << a / b << endl;

	}
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int FindPos(vector<char> b, char c,int* tmp)
{
	for (int i = *tmp; i < b.size(); i++)
	{
		if (b[i] == c)
		{
			*tmp = i;
			return i;
		}
	}
	return -1;
}
int fun(vector<char> a, vector<char> b,int pos)
{
	int count = 1;
	int tmp = 0;
	for (int i = pos; i < a.size(); i++)
	{
		int pos = FindPos(b, a[i],&tmp);
		if (pos>=0)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<char> v1, v2;
		v1.resize(n);
		v2.resize(n);
		int count = 0;
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v1[i];
		}

		for (int i = 0; i < n; i++)
		{
			cin >> v2[i];
		}

		for (int i = 0; i < v1.size(); i++)
		{
			count = fun(v1, v2, i);
			if (count > max)
			{
				max = count;
			}
		}
		cout << max << endl;
	}
	return 0;
}
#endif
