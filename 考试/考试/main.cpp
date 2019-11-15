#include<iostream>
using namespace std;

#if 0
//////消除字符后面重复的字符
#include<string>
int main()
{
	string s;
	while(cin >> s)
	{
		int a[256] = { 0 };//用256的数组进行标记
		for (size_t i = 0; i < s.size(); i++)
		{
			a[s[i]]++;
			if (a[s[i]] == 1)
			{
				cout << s[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
#endif


#if 0
#include<iostream>
using namespace std;
#include<string>

int main()
{
	string str("abcd1234ed125ss12345678");
	string str2;
	int count1 = 0, count2 = 0;
	int flag = 1;
	//cin >> str;
	auto it = str.begin();
	auto start1 = str.begin();

	while (it != str.end())
	{
		if ((*it <= '9'&&*it >= '0') && flag)
		{
			while (*it <= '9'&&*it >= '0'&&it!=str.end())
			{
				count1++;
				str2 += *it;
				it++;
			}
			flag = 0;
		}

		if ((*it <= '9'&&*it >= '0') && !flag)
		{
			count2 = 0;
			start1 = it;
			while (it != str.end()&&*it <= '9'&&*it >= '0')
			{
					it++;
					count2++;
			}
		}
		if (count1 < count2)
		{
			str2.erase(str2.begin(), str2.end());
			while (start1!=str.end()&&*start1<='9'&&*start1>='0')
			{
				str2 += *start1;
				start1++;
			}
		}
		if (it == str.end())
			break;
	   it++;
	}
	cout << str2 << endl;
	return 0;
}

#endif
#if 0
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string s1("abcd1234ed125ss12345678");
	string s2;
	for (size_t i = 0; i < s1.size(); i++)
	{
		while (s1[i] <= '9'&&s1[i] >= '0'&&i<s1.size())
		{
			int count1 = 0;
			s2 += s1[i];
			count1++;
			i++;
		}
	}
	
	return 0;
}
#endif

#if 0
#include<vector>
int Func(vector<int> v, int num)
{
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == num)
			count++;
	}
	return count;
}
int main()
{
	vector<int> v{ 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int res = v[0];
	for (int i=0; i < v.size(); i++)
	{
		int count=Func(v, v[i]);
		count >= v.size()/2 ? res = v[i] : res = 0;
	}
	cout << res;

	return 0;
}
#endif

#if 0
//数组中出现次数超过一半的数字
#include<vector>
class Solution {
public:
	size_t Func(vector<int> v, int num)
	{
		size_t count = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] == num)
				count++;
		}
		return count;
	}
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int res = numbers[0];
		for (size_t i = 0; i < numbers.size(); i++)
		{
			size_t count = Func(numbers, numbers[i]);
			count >= numbers.size() / 2 ? res = numbers[i] : res = 0;
		}
		cout << res << endl;
		return res;

	}
};
#endif

#if 0
//找数组次数超过一半的数
#include<iostream>
using namespace std;
#include<vector>
size_t Func(int* v, int val,int num)
{
	size_t count = 0;
	for (size_t i = 0; i < num; i++)
	{
		if (v[i] == val)
			count++;
	}
	return count;
}
int main()
{
	int num;
	cin >> num;
	int *arr=new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	
	int res = arr[0];
	for (size_t i = 0; i < num; i++)
	{
		size_t count = Func(arr, arr[i],num);
		count >= num/ 2 ? res = arr[i] : res = -1;
	}
	cout << res << endl;
	return 0;
}
#endif

#if 0
//反转字符串
class Solution {
public:
	void reverseString(vector<char>& s) {
		if (s.size()>0)
		{
			vector<char>::iterator p;
			vector<char>::iterator q;
			p = s.begin();
			q = s.end() - 1;
			while (p < q)
			{
				char tmp = *p;
				*p = *q;
				*q = tmp;
				p++;
				q--;
			}
		}
	}
};

class Solution {
public:
	void reverseString(vector<char>& s) {

		if (s.size()>0)
		{
			size_t start = 0;
			size_t end = s.size() - 1;

			while (start != end)
			{
				char temp = s[start];
				s[start] = s[end];
				s[end] = temp;
				start++;
				end--;
			}
		}


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
//#include<iostream>
//using namespace std;
#include<stdio.h>
#include<vector>
int main()
{
	int n = 0;
	cin >> n;
	int count = n * 3;
	int sum = 0;
	vector<int> v;
	v.reserve(n * 3);
	while (count--)
	{
		int val;
		//scanf("%d", &val);
		cin >> val;
		v.push_back(val);
	}
	//qsort(v.begin(), v.end());//排序

	for (auto i = v.begin(); i != v.end(); i++)
	{
		for (auto j = i + 1; j != v.end(); j++)
		{
			if (*i > *j)
			{
				swap(*i, *j);
			}
		}
	}
	auto rit = v.begin() + n;
	while (n--)
	{
		sum += *rit;
	}
	cout << sum;

	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<string>

////////c错误
int main()
{
	string s1;
	string s2;
	//cin >> s1;
	//cin >> s2;
	s1 += "i an jiangliang";
	s2 += "ang";

	for (int i = 0; i < s2.size(); i++)
	{
		int pos = s1.find(s2[i]);
		if (pos != string::npos)
		{
			s1.erase(pos, 1);
			pos = s1.find(s2[i]);
		}
	}

	cout << s1 << endl;

	return 0;
}

#endif

#if 0
#include<string>
int main()
{
	string s1;
	string s2;
	while (getline(cin, s1))
	{
		getline(cin, s2);
		for (int i = 0; i < s2.size(); i++)
		{
			int pos = s1.find(s2[i]);
			while (pos != string::npos)
			{
				s1.erase(pos, 1);
				pos = s1.find(s2[i]);
			}
		}
		cout << s1 << endl;
	}

	return 0;
}
#endif

#if 0
//反转字符串中的单词
#include<iostream>
using namespace std;
#include<string>

int main()
{
	string s1;
	string s2;
	//while (getline(cin, s1))
	//{
	getline(cin, s1);
	while (!s1.empty())
	{
		size_t pos = s1.rfind(" ");
		if (pos != string::npos)
		{
			s2 += s1.substr(pos);
			s2 += ' ';
			s1.erase(pos);
		}
		else
		{
			s2.append(s1.begin(), s1.end());
			break;
		}
	}
	s2 += '\0';
	cout << s2 << endl;
	//}
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int num;
	int count = 0;
	vector<int> v;
	cin >> num;
	//v.reserve(num);
	for (int i = 0; i<num; i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}
	auto it = v.begin() + 1;
	while (it != v.end())
	{
		while (*(it - 1) < *it&&it != v.end()) it++;
		count++;
		while (*(it - 1) >= *it&&it != v.end())  it++;
		count++;
	}
	cout << count << endl;

	return 0;
}

#endif












#if 0
//分糖果
#include<iostream>
using namespace std;
int main()
{
	int num1, num2, num3, num4;
	cin >> num1 >> num2 >> num3 >> num4;
	int a = (num1 + num3) / 2;
	int c = (num4 - num2) / 2;
	int b1 = (num3 - num1) / 2;
	int b2 = (num2 + num4) / 2;
	if (b1 != b2)
		cout << "No";
	else
		cout << a << " " << b1 << " " << c;
	return 0;
}
int main1()
{
	int a, b, c;
	int num1, num2, num3, num4;
	while (cin >> num1 >> num2 >> num3 >> num4)
	{
		//用两组不同的数据计算的b值要相同。
		//如果相等就说明数字有效，但如果不相等，则说明给出的数字是有误的，不满足题意
		if ((num3 - num1) / 2 == (num4 + num2) / 2)
		{
			a = (num1 + num3) / 2;
			b = num3 - a;
			c = num4 - b;
			cout << a << " " << b << " " << c;
		}
		else
		{
			cout << "No" << endl;
		}
	}


	return 0;
}

#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int m=7, n=2;
	//cin >> m >> n;
	int count = 1;
	vector<int> v;
	while (m%n)
	{
		v.push_back(m % (n*count));
		count++;
		m = m - m%n;
	}
	return 0;
}
#endif

#if 0
int main(void)
{
	printf("%s , %5.3s\n", "computer", "computer");
	return 0;
}
#endif

#if 0
int main()
{
	int year = 1009;
	int* p = &year;
	//*p +=1;
	*p++;
	cout << p<<endl;
	cout << year;
	return 0;

}
#endif

////11.10///////////////////////////////////////////////
#if 0
//统计回文
#include<iostream>
using namespace std;
#include<string>
bool Func(string s)
{
	size_t start = 0, end = s.size() - 1;
	for (; start <= end; start++, end--)
	{
		if (s[start] != s[end])
			return false;
	}
	return true;
}
int main()
{
	string str1, str2, str3;
	while (cin >> str1 >> str2)
	{
		int count = 0;
		int i = 0;
		str3 = str1;
		if (str1.empty() || str2.empty())
			return 0;
		while (i <= str1.size())
		{
			if (!str3.empty())
			{
				str3.erase(str3.begin(), str3.end());
			}
			str3 = str1;
			str3.insert(i, str2);
			if (Func(str3))
				count++;
			i++;
		}
		cout << count << endl;
	}
	return 0;
}

#endif

#if 0
//连续最大和
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n;
	vector<int> v;
	cin >> n;
	v.resize(n);
	for (size_t i = 0; i<n; i++)
		cin >> v[i];
	int sum = v[0], res = v[0];
	for (size_t i = 1; i<n; i++)
	{
		sum += v[i];
		if (sum<v[i])
			sum = v[i];
		if (sum>res)
			res = sum;
	}
	cout << res << endl;
	return 0;
}
#endif
/////////11.11/////////////////////
#if 0
//字符串转整数
class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;
		int symbol = 1;
		if (str[0] == '-')
		{
			symbol = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			symbol = 1;
			str[0] = '0';
		}

		int sum = 0;
		for (int i = 0; i<str.size(); i++)
		{
			if (str[i]<'0' || str[i]>'9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return symbol*sum;
	}
};
#endif

#if 0
////分蛋糕
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& e : a)
		e.resize(h, 1);

	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j<h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				if ((i + 2)<w)
					a[i + 2][j] = 0;
				if ((j + 2)<h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << res;
	return 0;
}

#endif

#if 0

//在32位cpu上选择缺省对齐的情况下，有如下结构体定义：
struct A{
	unsigned a : 19;
	unsigned b : 11;
	unsigned c : 4;
	unsigned d : 29;
	char index;
};
int main(){
	cout << sizeof(struct A) << endl;
	return 0;
}
//则sizeof（struct A）的值为（）
#endif

#if 0
////////////f斐波那契额
#include<iostream>
using namespace std;
#include<vector>
//1.排列出数jv  2.找区间  3.找差值
int main()
{
	int N, res1, res2, i;
	cin >> N;
	vector<int> v;
	if (N == 1)
		cout << 0;
	v.push_back(0);
	v.push_back(1);
	for (i = 2; i<N; i++)
	{
		v.push_back(v[i - 1] + v[i - 2]);
		if (v[i] == N)
		{
			cout << "0";
			break;
		}
		else if (v[i]>N)
		{
			res1 = v[i] - N;
			res2 = N - v[i - 1];
			if (res1<res2)
				cout << res1;
			else cout << res2;

			break;
		}
	}
	return 0;
}
#endif

#if 0
///////匹配括号
bool chkParenthesis(string A, int n) {
	// write code here
	int left = 0;
	int right = 0;
	for (int i = 0; i<n; i++)
	{
		if (A[i] == '(')
			left++;
		else if (A[i] == ')')
			right++;
		else return false;

		if (right>left)
			return false;
	}
	if (left == right)
		return true;
}
int main()
{
	int res=chkParenthesis("()(w))", 6);
	cout << res;
	return 0;
}
#endif

#if 0 
//最小公倍数
#include<iostream>
using namespace std;
//两个数相乘除以他俩的公倍数
int main()
{
	int A, B;
	cin >> A >> B;
	int min = A;
	int max = B;
	int tmp;
	if (A>B)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	tmp = min;
	//计算出公约数
	for (; tmp; tmp--)
	{
		if (min%tmp == 0 && max%tmp == 0)
		{
			break;
		}
	}
	cout << min*max / tmp;
	return 0;
}
#endif

#if 1
/////////////////错误////////////////////////
#include<iostream>
using namespace std;
#include<vector>
#include<string>
//1.按字典排序--》strcmp
bool Func1(vector<vector<char>> v,int n)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < v[j].size(); j++)
	{
		for (i = 0; i < v.size()-1; i++)
		{
			if (v[i][j] > v[i+1][j])
			{
				return false;
			}
		}
		if (j == v[n-1].size() - 1)
			return true;
	}
}
//2，按长度排序的
bool Func2(vector<vector<char>> v,int n)
{
	for (int i = 0; i < v.size()-1&&i<n; i++)
	{
		if (v[i].size()>v[i + 1].size())
			return false;
	}
}
int main()
{
	int n;
	cin >> n;
	int i = 0;
	int j = 0;
	vector<vector<char>> v;
	v.resize(n);
	for (i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (j = 0; j < s.size(); j++)
		{
			//v[i].push_back(s[j]);
			v[i].resize(s.size());
			v[i][j] = s[j];
		}
	}

	Func1(v, n);
	/*if (Func1(v,n) && Func2(v,n))
		cout << "both";
	else if (Func1(v,n))
		cout << "lexicographically";
	else if (Func2(v,n))
		cout << "lengths";
	else cout << "none";
	*/
	return 0;
}
#endif


#if 0
int addAB(int A, int B) {
	// write code here
	//分别异或：保留 
	//与运算：扩大两倍
	int res;
	int a = A&B;//相同的部分
	int b = A^B;//不同的部分
	for (; a || b; a = A&B, b = A^B)
	{
		if (a != 0 && b != 0)
		{
			a <<= 1;
			A = a;
			B = b;
		}
		else if (a == 0)
		{
			res = b;
			return res;
		}
		else if (b == 0)
		{
			res = a;
			return res;
		}
	}
}

int main()
{
	cout << addAB(2, 3);
	return 0;
}
#endif

#if 0
//只能往向下和向右走
#include<iostream>
using namespace std;
int Func(int n, int m)
{
	if ((n >= 1) && (m == 1) || (n == 1) && (m >= 1))
		return n + m;
	else if (n>1 && m>1)
		return Func(n - 1, m) + Func(n, m - 1);
	else return 0;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
		cout << Func(n, m) << endl;
	return 0;
}
#endif

