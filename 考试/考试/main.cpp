#include<iostream>
#include<algorithm>
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
//斐波那契额数中距离这个数最小差值
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
//斐波那契额数中距离这个数最小差值
#include<iostream>
using namespace std;
int main()
{
	int N, res1 = 0, res2 = 0, f, f0 = 0, f1 = 1;
	cin >> N;
	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		if (f<N)
		{
			res1 = N - f;
		}
		else
		{
			//找到比N大的数
			res2 = f - N;
			break;
		}
	}

	if (res1>res2) cout << res2 << endl;
	else cout << res1 << endl;
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
//匹配括号
#include<stack>
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> sc;
		for(auto ele:A)
		{
			switch(ele)
			{
			case '(':
				sc.push(ele);
				break;
			case')':
			{
				if(sc.empty()||sc.top()!='(')
					return false;
				else 
					sc.pop();
			}
			break;
			default:
				return false;
			}
		}
		return true;
	}
};
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
/*int gcd(int a, int b)
{
int r;
while(r = a%b){
a = b;
b = r;
}
return b;
}*///辗转相除法
//碾转相除法进行最大公约数的求解：即a与b的
//最大公约数可以转化为a、b之间的余数为两者之间最小的数之间的公约数。所以对于输入的两个
//数进行连续求余，直到余数为0，求余的分母即为结果。
#endif

#if 0
//字典排序问题
#include<iostream>
using namespace std;
#include<string>
#include<vector>
int main()
{
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);

	for (auto& str : v)
		cin >> str;

	bool lenSym = true, lexSym = true;
	//从i-1开始遍历，前后比较，比较长度
	for (size_t i = 0; i<v.size(); i++)
	{
		if (v[i - 1].size() >= v[i].size())
		{
			lenSym = false;
			break;
		}
	}
	//比较ASCII码
	for (size_t i = 0; i<v.size(); i++)
	{
		if (v[i - 1] >= v[i])
		{
			lexSym = false;
			break;
		}
	}
	if (lenSym&&lexSym)
		cout<<"both"<<endl;
	else if(!lenSym&&lexSym)
		cout<<"lexicographically"<<endl;
	else if(lenSym&&!lexSym)
		cout<<"lengths"<<endl;
	else if(!lenSym&&!lexSym)
		cout<<"none"<<endl;
	return 0;
}
#endif


#if 0
int addAB(int A, int B) {
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


#if 0
////////////////////////////////cuowu 
//下棋
//class Board {
//	//三竖 三横 两条对角线
//public:
//	bool checkWon(vector<vector<int> > board) {
//		int i = 0, j = 0;
//		if (board[1][1] == 1)
//		{
//			if (board[0][0] == 1 && board[2][2] == 1 ||
//				board[0][2] == 1 && board[2][0] == 1 ||
//				board[1][0] == 1 && board[1][2] == 1 ||
//				board[0][1] == 1 && board[2][1] == 1)
//				return true;
//		}
//		if (board[0][0] == 1)
//		{
//			if (board[0][1] == board[0][2] == 1 ||
//				board[1][0] == board[2][0] == 1)
//				return true;
//		}
//		if (board[2][2] == 1)
//		{
//			if (board[0][2] == board[1][2] == 1 ||
//				board[2][0] == board[2][1] == 1)
//				return true;
//		}
//		return false;
//	}
//};

#endif


#if 0
///密码保护问题
#include<iostream>
using namespace std;
#include<string>
int numchar(string str,int k)
{
	int small = 0;
	int big = 0;
	for (int i = 0; i<k; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			big++;
		else if (str[i]>97 && str[i] <= 122)
			small++;
	}
	if ((small + big) == 0)
		return 0;
	else if (small == k || big == k)
		return 10;
	else if (small>0 && big>0)
		return 20;

	return 0;
}

int numNumber(string str, int k)
{
	int num = 0;
	for (int i = 0; i<k; i++)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
			num++;
	}
	if (num == 0)
		return 0;
	else if (num == 1)
		return 10;
	else return 20;
}

int numSymbal(string str, int k)
{
	int num = 0;
	for (int i = 0; i<k; i++)
	{
		if (!(str[i] >= 65 && str[i] <= 90)
			&& !(str[i] >= 97 && str[i] <= 122)
			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			num++;
	}
	if (num == 0) return 0;
	else if (num == 1)
		return 10;
	else return 25;
}

int main()
{
	string s;
	cin >> s;
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum4 = 0, sum5 = 0;
	int k = s.size();
	if (k<5) sum1 += 5;
	else if (k < 8)sum1 += 10;
	else sum1 += 25;

	sum2 = numchar(s, k);
	sum3 = numNumber(s, k);
	sum4 = numSymbal(s, k);

	if ((sum2>0) && (sum3>0) && (sum4>0))
	{
		if (sum2 == 10)
		{
			sum5 = 3;
		}
		else sum5 = 5;
	}
	else if (sum2>0 && sum3>0 && sum4 == 0)
		sum5 = 3;

	int sum = sum1 + sum2 + sum3 + sum4 + sum5;
	if (sum >= 90) cout << "VERY_SECURE" << endl;
	else if (sum >= 80) cout << "SECURE" << endl;
	else if (sum >= 70) cout << "VERY_STRONG" << endl;
	else if (sum >= 60) cout << "STRONG" << endl;
	else if (sum >= 50) cout << "AVERAGE" << endl;
	else if (sum >= 25) cout << "WEAK" << endl;
	else cout << "VERY_WEAK" << endl;

	return 0;

}
#endif

#if 0
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string s;
	cin >> s;
	int i;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a' || s[i] == 'o' ||
			s[i] == 'e' || s[i] == 'i' || s[i] == 'u')
		{
			cout << s[i];
			break;
		}
	}
	if (i == s.size())
	{
		cout << "n";
	}
	return 0;
}
#endif

#if 0
////6.
#include<iostream>
using namespace std;
bool Func(int num)
{
	for (;num; num /= 10)
	{
		if (num % 10 == 2)
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	int num;
	int count = 0;
	for (num = 1; num <= n; num++)
	{
		if (Func(num))
			count++;
	}
	cout << count;
	return 0;
}
#endif

#if 0
///6
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n, a, b, c, i;
	int count = 0;
	cin >> n;
	cin >> a>>b>> c;

	for (i = 1; i <= n; i++)
	{
		if (i%a != 0 && i%b != 0 && i%c != 0)
			count++;
	}
	cout << count;
	return 0;
}
#endif


//int main()
//{
//	int n, m, r, c;
//	cin >> n >> m;
//	cin >> r >> c;
//	
//
//	return 0;
//}


#if 0
//修水道的题
#include<iostream>
using namespace std;
#include<vector>

//长度
double len(vector<int> a, vector<int> b)
{
	double sum = pow(b[0] - a[0], 2) + pow(b[1] - a[1], 2) + pow(b[2] - a[2], 2);
	return sqrt(sum);
}
bool Fun(vector<int> a, vector<int> b)
{
	if (a[2] > b[2])
		return true;
}
int  main()
{
	int n,d;
	double res=0;
	double length = 0;
	cin >> n;
	vector<vector<int>> v;
	v.resize(n);
	for (int i = 0; i < v.size(); i++)
	{
		v[i].resize(3);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> v[i][j];
		}
	}
	cin >> d;

	//排序数组

	for (int i = 1; i < v.size(); i++)
	{
		length = 0;
		length = len(v[0], v[i]);
		if (length <= d)
		{
			//res += length;
			for (int j = i + 1; j < v.size() && i < v.size(); j++, i = j)
			{
				if (len(v[i], v[j]) <= d&&Fun(v[i], v[j]))
					length += len(v[i], v[j]);
			}
		}
		if (length > res)
		{
			res = length;
		}
	}

		/*for (int j = i + 1; j < v.size(); j++)
		{
			length += len(v[i], v[j]);
		}
		if (length > res)
		{
			res = length;
		}*/
	//}


	/*for (int i = 0; i < v.size(); i++)
	{
		for (int j = i+1; j < v.size(); j++)
		{
			if (Fun(v[i], v[j]))
			{
				double length = len(v[i], v[j]);
				if (length <= d)
				{
					if (length > res)
					{
						res = length;
					}
				}
			}
			
		}
	}*/
	
	cout << res;
	//两个点之间的距离>d;

	return 0;
}
#endif



#if 0
#include<iostream>
#include<string>
using namespace std;
int main(){
	int n, m, k;
	double sum = 0;
	int arr[10][3], a[10] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	cin >> k;
	double ree;
	for (int i = 0; i < n; ++i){
		m = i + 1;
		if (arr[i + 1][2] > arr[i][2]){
			m++;
		}
		if (a[i] != 0){
			continue;
		}
		if (arr[i + 1][2] <= arr[i][2]){
			ree = sqrt(pow((arr[i][0] - arr[m][0]), 2) + pow((arr[i][1] - arr[m][1]), 2) + pow((arr[i][2] - arr[m][2]), 2));

			if (ree <= k){
				sum += ree;
				a[i]++;
			}
		}
	}
	printf("%.2f", sum);
	return 0;
}
#endif

#if 0

#include <iostream>
using namespace std;
void func(char **m){
	++m;
	cout << *m << endl;//afternoon
}
int main(){
	static char *a[] = { "morning", "afternoon", "evening" };
	char **p;
	p = a;
	func(p);
	return 0;
}
#endif

#if 0
//找最近的祖先
#include<vector>
class LCA {
public:
	int Func(vector<int> v, int max)
	{
		for (int i = 0; i<v.size(); i++)
		{
			if (max == v[i])
				return v[i];
		}
		return 0;
	}
public:
	int getLCA(int a, int b) {
		//先遍历出最小节点数的所有祖先节点
		//遍历较大数的节点祖先数与其进行比较
		int min = a;
		int max = b;
		vector<int> v;
		if (a>b) swap(min, max);
		int res = min;
		while (min)
		{
			v.push_back(min);
			min /= 2;
		}
		while (max)
		{
			if (Func(v, max))
			{
				return max;
			}
			max /= 2;
		}

	}
};
#endif

#if 0
#include<iostream>
using namespace std;
///找出二进数的中最大的连续1的个数
int main()
{
	int num;
	while (cin >> num)
	{
		int res = 0;
		int count = 0;
		for (; num; num >>= 1)
		{
			while (num && (num & 1 == 1))
			{
				count++;
				num >>= 1;
			}
			if (res<count)
				res = count;
			count = 0;
		}
		cout << res << endl;
	}

	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
//判断是不是素数
bool Fun(int n)
{
	for (int i = 2; i<n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int num;
	while (cin >> num)
	{
		int res = num;
		int dif = num;
		int a1 = 0;
		int b1 = 0;
		int a, b;
		for (int i = 1; i<num / 2; i++)
		{
			a = i;
			b = num - i;
			if (Fun(a) && Fun(b))
			{
				dif = b - a;
				if (dif < res)
				{
					res = dif;
					a1 = a;
					b1 = b;
				}
			}
		}
		cout << a1 << endl;
		cout << b1 << endl;
	
	}

	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<string>
#include<vector>
//1.找出每个单词长度
//2.输出

int main()
{
	string str;
	string resstr;
	vector<string> v;
	int count = 0;
	while (getline(cin, str))
	{
		for (size_t i = 0; i<str.size(); i++)
		{
			size_t j = i;
			if (str[j] != '"')
			{
				while (str[j] && str[j] != ' ')
					j++;
			}
			else
			{
				j = j + 1;
				while (str[j] && str[j] != '"')
					j++;
				j = j + 1;
			}
			resstr = str.substr(i, j - i);
			v.push_back(resstr);
			i = j;
		}

		cout << v.size()<<endl;
		for (auto& str : v)
			cout << str << endl;
	}
	return 0;
}
#endif


//#include<string>
//#include<vector>
/////跳石板
////列出当前数的约束  
////从最大开始加
//void Func(vector<int>& v, int n)
//{
//	//v.resize(n);
//	for (size_t i = 2; i<sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//			v.push_back(n / i);
//		}
//	}
//}
//int main()
//{
//	int n, m, count = 0;
//		cin >> n >> m;
//
//	while (n != m)
//	{
//		vector<int> v;
//		Func(v, n);
//		while (n + v[0] < m)
//		{
//			count++;
//			n = n + v[0];
//			v.resize(n, 0);
//			Func(v, n);
//		}
//		
//	}
//	cout << count << endl;
//
//	return 0;
//}

#if 0
//////计算天数
#include<iostream>
using namespace std;
#include<vector>
//判断是闰年的函数
bool Func(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}
int getOutDay(int year, int month, int day)
{
	vector<int> v{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int res=0;
	if ((year <= 0 && year>12) || (month <= 0 && month>12))
	{
		return -1;
	}
	if (Func(year))
		v[2]++;

	if (day>v[month]) return -1;

	for (int i = 1; i<month; i++)
	{
		res += v[i];
	}
	res += day;
	return res;
}
int main()
{
	int year, month, day, res = 0;;
	while (cin >> year >> month >> day)
	{
		cout << getOutDay(year, month, day) << endl;

	}


	return 0;
}
#endif
#if 0
//#include<iostream>
//using namespace std;
//#include<vector>
////1.所有数相加
////2.所有数相乘
//int Add(vector<int> v)
//{
//	int add = 0;
//	for (int i = 0; i<v.size(); i++)
//	{
//		add += v[i];
//	}
//	return add;
//}
//int Mul(vector<int> v)
//{
//
//	int mul = 1;
//	for (int i = 0; i<v.size(); i++)
//	{
//		mul *= v[i];
//	}
//	return mul;
//}
//int main()
//{
//	int n, count;
//	vector<int> v;
//	cin >> n;
//	v.resize(n);
//	for (auto& it : v)
//		cin >> it;
//	//移除0个 1个 ..n-1个
//	//删除下标【1-n-1】
//
//
//
//
//	return 0;
//}
#endif

//#include<algorithm>

//typedef unsigned long long ull;
//int n = 0;
//int a[1024] = { 0 };
//int startIndex[1024] = { 0 };
//int endIndex[1024] = { 0 };
//ull ans = 0;
//
//void dfs(ull sum, ull product, int index)
//{
//	int i = index;
//	while (i < n)
//	{
//
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a, a + n);
//
//	startIndex[a[0]] = 0;
//	endIndex[a[n - 1]] = n - 1;
//
//	for (int i = 1; i < n; i++)
//	{
//		if (a[i] == a[i - 1])
//			continue;
//		else
//		{
//			startIndex[a[i]] = i;
//			endIndex[a[i - 1]] = i - 1;
//		}
//	}
//	dfs(1, 1, 1);
//	cout << ans;
//	return 0;
//}

#if 0
////////////////////////////////////////////////////////////////////////数组的子集
int *x = NULL;
int n;
int count(int pos, int add, long long mul)
{
	int num = 0;
	for (int i = pos; i<n; ++i)
	{
		add += x[i];
		mul *= x[i];

		if (add>mul)
			num += 1 + count(i + 1, add, mul);
		else if (x[i] == 1)
			num += count(i + 1, add, mul);
		else
			break;

		add -= x[i];
		mul /= x[i];

		while (x[i + 1] == x[i] && i + 1<n)
		{
			++i;
		}
	}
	return num;
}
int main()
{
	cin >> n;
	x = new int[n];
	int add = 0;//和
	long long mul = 1;//积

	for (int i = 0; i<n; ++i)
	{
		cin >> x[i];
	}
	sort(x, x + n);
	int num = count(0, add, mul);
	cout << num;

	if (x != NULL)
	{
		delete[]x;
		x = NULL;
	}

	return 0;

}
#endif

#if 0
////一个数1的个数
#include<iostream>
using namespace std;
int main()
{
	int num;
	while (cin >> num)
	{
		int count = 0;
		while (num)
		{
			count++;
			num = num&(num - 1);
			
		}
		cout << count << endl;
	}

	return 0;
}
#endif

#if 0
#include<vector>
int findMinimum(int n, vector<int> left, vector<int> right) {
	//1.一个数组中至少拿一个，另一个数组至少每种都拿到
	int i = 0, sum = 0;
	int lmin = left[0];
	int rmax = right[0];
	for (int i = 0; i<n; i++)
	{
		if (left[i] == 0)
		{
			sum += right[i];
		}
		else if (left[i] != 0)
		{
			if (lmin == 0)
			{
				lmin = left[i];
			}
			else if (lmin > left[i])
			{
				lmin = left[i];
			}
			
		}
	}
	sum += lmin;
	
	for (int i = 0; i<n; i++)
	{
		if (right[i] == 0)
			sum += left[i];
		else if (right[i] != 0 && left[i] != 0)
		{
			sum += right[i];
		}
		if (right[i]>rmax&&left[i] != 0)
			rmax = right[i];
	}

	sum -= rmax;
	sum--;

	return sum;
}
int main()
{
	vector<int> left{ 0, 7, 1, 6 };
	vector<int> right{ 1, 5, 0, 6 };
	cout<<findMinimum(4, left, right);
	return 0;
}
#endif

#if 0
#include<vector>

class Gloves {
public:
	int min(int num1, int num2)
	{
		if (num1<num2)
			return num1;
		else return num2;
	}
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		//1.一个数组中至少拿一个，另一个数组至少每种都拿到
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;
		for (int i = 0; i<n; i++)
		{
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
				//对于左右手都有的颜色，执行累加-最小值+1
			}
			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};
#endif

#if 0
//计算n以内完全数的个数
#include<iostream>
using namespace std;
bool Fun(int n)
{
	int sum = 0;
	int a = n;
	while (a)
	{
		if (n%a == 0)
		{
			sum += a;
		}
		a--;
	}
	if (sum - n == n)
	{
		return true;
	}
	else return false;
}
int count(int n)
{
	int i, num = 0;
	for (i = 1; i <= n; i++)
	{
		if (Fun(i))
		{
			num++;
		}
	}
	if (num)  return num;
	else return -1;
}
int main()
{
	int n, i;
	int num = 0;
	while (cin >> n)
	{
		cout << count(n) << endl;
	}
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#define joker j
#define JOKER J
//个子，对子，三个--比较牌面大小
//顺子（连续五张）--比较最小牌大小
//三个，炸弹，对王

//对王的函数
string King(string str1, string str2)
{
	if (str1.find("J"))
	{
		return str1;
	}
	else if (str2.find("J"))
	{
		return str2;
	}
	else if (str1.find("j"))
	{
		return str2;
	}
	else if ( str2.find("j"))
	{
		return str1;
	}
	return "";
}
//炸弹
int count(string str,char ch)//数目
{
	int count=0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ch)
		{
			count++;
		}
	}
	return count;
}
void Bomb(string str1, string str2,int size1,int size2)
{
	if (str1.size() < 4 || str2.size() < 4)
		return;

	vector<char> v1;
	vector<char> v2;//分别记录str1和str2中是炸弹字符

	//计数器
	for (size_t i = 0; i < str1.size(); i++)
	{
		if (count(str1,str1[i]) == 4)
		{
			v1.push_back(str1[i]);//就是把四个相同得元素全存在了v中
		}
	}
	
	for (size_t i = 0; i < str2.size(); i++)
	{
		if (count(str2, str2[i]) == 4)
		{
			v2.push_back(str2[i]);//就是把四个相同得元素全存在了v中
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	



	
}
int main()
{
	string str;
	string str1, str2;
	int size1, size2;

	while (getline(cin, str))
	{
		size_t pos = str.find('-');
		str1 = str.substr(0, pos);
		str2 = str.substr(pos + 1, str.size() - 1);
		size1 = str1.size();
		size2 = str2.size();
		if (King(str1, str2) != "")
		{
			cout << King(str1, str2) << endl;
		}
		else if ()
		{

		}


	}
	return 0;
}

#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>
vector<int>& Fun(vector<vector<int>>& v, int line)
{
	size_t i, j;
	for (i = 0; i<line; i++)
	{
		v[i][0] = 1;
		v[i][1] = i;
	}

	for (i = 1, j = 2; i<line; i++,j++)
	{
		for (j = 2; j < v[i].size(); j++)
		{
			v[i][j] = v[i - 1][j - 2] + v[i - 1][j - 1] + v[i - 1][j];
		}
	}

	return v[line - 1];

}
int main()
{
	int line,i;
	cin >> line;
	vector<vector<int>> v;
	v.resize(line);

	for (i = 0; i < v.size(); i++)
	{
		v[i].resize(2 * line - 1, 0);
	}
	

	vector<int> res = Fun(v, line);

	for (i = 0; i<res.size(); i++)
	{
		if (res[i] % 2 == 0)
		{
			cout << i+1 << endl;
			break;
		}
	}

	if (i == res.size())
		cout << "-1" << endl;

	return 0;
}

#endif

#if 0
//两个字符串相加
#include<iostream>
#include <algorithm> 
using namespace std;
#include<string>
string AddLongInteger(string s1, string s2)
{
	int size1 = s1.size() - 1;
	int size2 = s2.size() - 1;
	string res = "";

	int carry = 0;//进位
	while (size1 >= 0 || size2 >= 0)
	{
		if (size1 >= 0 && size2<0)
		{
			int sum = s1[size1] - '0' + carry;
			carry = 0;
			carry = sum / 10;
			res += (char)(sum % 10+'0');
			size1--;
		}
		else if (size2 >= 0 && size1<0)
		{
			int sum = s2[size2] - '0' + carry;
			carry = 0;
			carry = sum / 10;
			res += (char)(sum % 10 + '0');
			size2--;
		}
		else
		{
			int sum = s1[size1] + s2[size2] - '0' - '0' + carry;
			carry = 0;
			carry = sum / 10;
			res += (char)(sum % 10 + '0');
			size1--;
			size2--;
		}
		
	}
	if (carry == 1)
	{
		res += '1';
	}
	reverse(res.begin(), res.end());
	return res;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		AddLongInteger(s1, s2);
		cout << AddLongInteger(s1, s2) << endl;
	}

	return 0;
}
#endif


