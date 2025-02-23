//#include<iostream>
#include<algorithm>
//using namespace std;

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

#if 0
int main()
{
	int n;
	while(cin>>n)
	{
		int f1=1,f2=1,fn=0;
		while((n-2)>0)
		{
			fn=f1+f2;
			f1=f2;
			f2=fn;
			n--;
		}
		cout<<fn<<endl;
	}
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<string>

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		size_t i = 0, j = 0;
		for (; i<str1.size() && j<str2.size(); i++, j++)
		{
			if (str1[i] != '?' && str1[i] != '*')
			{
				if (str1[i] != str2[j])
				{
					cout << "false" << endl;
					break;
				}
			}
			else if (str1[i] == '*')
			{
				i++;
				while ((str2[j] >= 'a' || str2[j] <= 'z'
					|| str2[j] >= 'A' || str2[j] <= 'Z'
					|| str2[j] >= '0' || str2[j] <= '9') && (str1[i] != str2[j]))
				{
					j++;
				}
				if (str1[i] == str2[j])
				{
					continue;
				}
				else
				{
					cout << "false" << endl;
					break;
				}
			}
		}

		if (i == str1.size())
			cout << "true" << endl;
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
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		size_t i = 0, j = 0;
		for (; i < str1.size() && j < str2.size(); i++, j++)
		{
			if (str1[i] != '?' && str1[i] != '*')
			{
				if (str1[i] != str2[j])
				{
					cout << "false" << endl;
					break;
				}
			}
			else if (str1[i] == '*'&&i != str1.size() - 1)
			{
				i++;
				while ((str2[j] >= 'a' || str2[j] <= 'z'
					|| str2[j] >= 'A' || str2[j] <= 'Z'
					|| str2[j] >= '0' || str2[j] <= '9') && (str1[i] != str2[j]))
				{
					j++;
				}
				if (str1[i] == str2[j])
				{
					continue;
				}
				else
				{
					cout << "false" << endl;
					break;
				}
			}
			else if (str1[i] == '*'&&i == str1.size() - 1)
			{
				while ((str2[j] >= 'a' || str2[j] <= 'z'
					|| str2[j] >= 'A' || str2[j] <= 'Z'
					|| str2[j] >= '0' || str2[j] <= '9') && (j != str2.size()))
				{
					j++;
				}
				if (j != str2.size())
				{
					cout << "false" << endl;
					break;
				}
			}

			if (i == str1.size() && j == str2.size())
				cout << "true" << endl;
		}
	}
	return 0;
	}

#endif

#if 0
#include<iostream>
	using namespace std;
#include<string>

	bool match(const char* pattern, const char* str)
	{
		if (*pattern == '\0' || *str == '\0')
			return true;

		if (*pattern == '\0' || *str == '\0')
			return false;

		if (*pattern == '?')
			return match(pattern + 1, str + 1);
		else if (*pattern == '*')
			return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
		else if (*pattern == *str)
			return match(pattern + 1, str + 1);

			return false;
	}

	int main()
	{
		string pattern, str;
		while (cin >> pattern >> str)
		{
			bool ret = match(pattern.c_str(), str.c_str());
			if (ret)
				cout << "true" << endl;
			else
				cout << "false" << endl;
		}
		return 0;
	}
#endif

#if 0
	///三个换一个瓶子
#include<iostream>
	using namespace std;
	int main()
	{
		int num;
		while (cin >> num)
		{
			int total = num;//总共剩余的瓶数
			int exchage = 0;//换汽水的瓶数
			while (total >= 3)
			{
				exchage += total / 3;
				total = total % 3 + total / 3;
			}
			if (total == 2)
				exchage++;
			cout << exchage << endl;

		}
		return 0;
	}
#endif

#if 0
#include<iostream>
	using namespace std;
#include<string>
	//在s长的str中一直查找短的str每个元素
	//查找每个字符并往后遍历，返回相同字串
	string Fun(string str_min, string str_max, int i, int pos)
	{
		string res;
		while (i < str_min.size() && pos < str_max.size())
		{
			if (str_min[i] == str_max[pos])
			{
				res += str_min[i];
			}
			else
			{
				break;
			}
		}
		return res;
	}

	int main()
	{
		string s1, s2;
		while (cin >> s1 >> s2)
		{
			string res,tmp;
			string str_min, str_max;
			str_min = s1; str_max = s2;
			if (s1.size()>s2.size())  swap(str_min, str_max);

			for (size_t i = 0; i<str_min.size(); i++)
			{
				size_t pos = str_max.find(str_min[i]);
				if (pos != string::npos)
				{
					tmp = Fun(str_min, str_max, i, pos);
					if (tmp.size() > res.size())
						res = tmp;
				}
			}

			cout << res << endl;

		}
		return 0;
	}
#endif

#if 0
#include<vector>
#include<string>
	void find(string s1, string s2)//s1是较短的子串 s2是较长的子串
	{
		int l1 = s1.size(), l2 = s2.size(), max = 0, start = 0;
		vector<vector<int>> lcs(l1 + 1, vector<int>(l2 + 1, 0));

		for (int i = 1; i <= l1; i++)
		{
			for (int j = 1; j <= l2; j++)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				}
				if (lcs[i][j] > max)
				{
					max = lcs[i][j];
					start = i - max;
				}
			}
		}
		cout << s1.substr(start, max) << endl;
	}

	int main()
	{
		string s1, s2;
		while (getline(cin, s1) && getline(cin, s2))
		{
			if (s1.size() < s2.size())
				find(s1, s2);
			else
				find(s2, s1);
		}
		return 0;
	}

#endif

#if 0
//字符串反转
#include<iostream>
#include <algorithm>
using namespace std;
#include<string>
	int main()
	{
		string str;
		while (cin >> str)
		{
			//string res = 
			reverse(str.begin(), str.end());
			cout <<str << endl;
		}
		return 0;
	}
#endif

#if 0
	//求两个字符串子串的最长长度
#include<string>
#include<vector>
	int conSubStr(string s1, string s2)//s2较短 s1较长
	{
		int len1 = s1.size();
		int len2 = s2.size();

		//储存子串长度的数组
		vector<int> count(len2 + 1, 0);
		//记录目前为止最长字串的长度和s2中的位置
		int maxlen = 0;
		int endpos = 0;

		for (int i = 0; i < len1; i++)
		{
			for (int j = len2; j > 0; j--)
			{
				if (s2[j - 1] == s1[i])
				{
					count[j] = count[j - 1] + 1;
					if (count[j] > maxlen)
					{
						maxlen = count[j];
						endpos = j;
					}
				}
				else
				{
					count[j] = 0;
				}

			}
		}
		/*if (0 == maxlen)
		{
			return 0;
		}*/

		return maxlen;
		/*substr.resize(maxlen);
		for (int i = endpos - maxlen; i < endpos; i++)
		{
			substr[i - endpos + maxlen] = s2[i];
		}*/

	}
	int main()
	{
		string s1, s2;
		while (cin >> s1 >> s2)
		{
			cout << conSubStr(s1,s2)<<endl;
		}
		return 0;
	}
#endif
#if 0
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
	using namespace std;

	int main()
	{
		string str1,str2;
		while(cin>>str1>>str2)
		{
			if(str1.size()>str2.size())
				swap(str1,str2);

			int len1=str1.size(),len2=str2.size();
			int i,j,start=0,max=0;

			vector<vector<int>> Mcs(len1+1,vector<int>(len2+1,0));
			for(i=1;i<=len1;i++)
			{
				for(j=1;j<=len2;j++)
				{
					if(str1[i-1]==str2[i-1])
						Mcs[i][j]=Mcs[i-1][j-1]+1;
					//如果有更长得子串，更新长度

					if(Mcs[i][j]>max)
					{
						max=Mcs[i][j];
						//以i结尾得最大长度为max，则子串得起始位置为i-max
						start=i-max;
					}
				}
			}
			cout<<str1.substr(start,max)<<endl;

		}
		return 0;
	}
#endif


#if 0
	//求两个字符串的最长子串并输出
#include<string>
#include<vector>
	string conSubStr(string s1, string s2)//s2较短 s1较长
	{
		int len1 = s1.size();
		int len2 = s2.size();
		//储存子串长度的数组
		vector<int> count(len2 + 1, 0);
		//记录目前为止最长字串的长度和s2中的位置
		int maxlen = 0;
		int endpos = 0;
		for (int i = 0; i < len1; i++)
		{
			for (int j = len2; j > 0; j--)
			{
				if (s2[j - 1] == s1[i])
				{
					count[j] = count[j - 1] + 1;
					if (count[j] > maxlen)
					{
						maxlen = count[j];
						endpos = j;
					}
				}
				else
				{
					count[j] = 0;
				}

			}
		}
		string substr;
		substr.resize(maxlen);
		for (int i = endpos - maxlen; i < endpos; i++)
		{
		substr[i - endpos + maxlen] = s2[i];
		}
		return substr;
	}
	int main()
	{
		string s1, s2;
		while (cin >> s1 >> s2)
		{
			cout << conSubStr(s1, s2) << endl;
		}
		return 0;
	}
#endif

#if 0
#include<iostream>
	using namespace std;
#include<vector>
#include <algorithm>

	//反转后的序列
	void sort(vector<int>& v)
	{
		int size = v.size();
		vector<int> tmp;
		int mid = size / 2;
		int i = 0;
		while (i<size / 2)
		{
			tmp.push_back(v[i]);
			tmp.push_back(v[mid]);
			i++;
			mid++;
		}
		v = tmp;
	}
	int main()
	{
		int T, n, k;
		cin >> T;
		while (T)
		{
			cin >> n >> k;
			vector<int> v(2 * n);
			for (size_t i = 0; i<2 * n; i++)
			{
				cin >> v[i];
			}
			while (k)
			{
				sort(v);
				k--;
			}

			for (int i = 0; i<v.size(); i++)
			{
				cout << v[i] << " ";

				*if(i!=v.size()-1)
				{
					cout<<v[i]<<" ";
				}
				else 
				{
					cout<<v[i];
				}*/
			}

		}
		return 0;
	}
#endif

#if 0
#include<iostream>
	using namespace std;
#include<vector>
#include<String>
#include <algorithm>
	//输出列表[start,end][i,+4]
	void Print(vector<int> v, int start, int end)
	{
		for (int i = start; i<end; i++)
		{
			cout << v[i] << " ";
		}
	}
	void Fun1(vector<int> v, string s)
	{
		int i, j;
		int res = v[0];
		for (i = 0, j = 0;; i<s.size(); i++)
		{
			if (s[i] = 'U')
			{
				if (j == 0)
				{
					j = v.size() - 1;
				}
				else
					j--;
			}
			else if (s[i] = 'D')
			{
				if (j == v.size() - 1)
					j = 0;
				else j++;
			}
			res = v[j];
		}
		//输出列表
	}
	int main()
	{
		int tatal;
		string s;
		while (cin >> tatal >> s)
		{
			vetctor<int> v(tatal);
			for (int i = 0; i<tatal; i++)
				v[i] = i + 1;//数组里存放的歌曲数目

			if (tatal <= 4)
			{
				Fun1(v, s);
			}
			for (int i = 0; i<s.size(); i++)
			{

			}
		}

		return 0;
	}
#endif

#if 0
//歌曲翻页
#include<string>
using namespace std;
int main()
{
	int n; 
	string order;
	while (cin >> n >> order)
	{
		int num = 1;
		int first = 1;//将n首歌曲编号1：n，
		//num位光标当前所在歌曲的编号，first为当前屏幕显示页的第一首歌曲的编号
		if (n <= 4)//歌曲总数不超过4时，所有歌曲一页即可显示完，不需要翻页，first始终不变
		{
			for (int i = 0; i < order.size(); i++)
			{
				if (num == 1 && order[i] == 'U')
					num = n;
				else if (num == n&&order[i] == 'D')
					num = 1;
				else if (order[i] == 'U')
					num--;
				else
					num++;
			}
			for (int i = 1; i <= n - 1; i++)
				cout << i << ' ';
			cout << n << endl;
			cout << num << endl;
		}
		else//歌曲总数大于4时，显示完全所有歌曲需翻页，屏幕总是显示4首歌
		{
			for (int i = 0; i < order.size(); i++)
			{
				if (num == 1 && order[i] == 'U')//特殊翻页
				{
					first -= 3;
					num = n;
				}
				else if (num == n&&order[i] == 'D')//特殊翻页
				{
					first = 1;
					num = 1;
				}
				else if (first != 1 && num == first&&order[i] == 'U')//一般翻页
				{
					first--;
					num--;
				}
				else if (first != n - 3 && num == first + 3 && order[i] == 'D')//一般翻页
				{
					first++;
					num++;
				}
				else if (order[i] == 'U')//其他情况
					num--;
				else
					num++;//其他情况
			}
			for (int i = first; i < first + 3; i++)
				cout << i << ' ';
			cout << first + 3 << endl;
			cout << num << endl;
		}
	}
	return 0;
}
#endif

#if 0
//第一次出现的字符
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int arr[256] = { 0 };
		int i = 0;
		for (i = 0; i<s.size(); i++)
		{
			arr[s[i]]++;
		}
		for (i = 0; i<s.size(); i++)
		{
			if (arr[s[i]] == 1)
			{
				cout << s[i] << endl;
				break;
			}
		}
		if (i == s.size())
			cout << "-1" << endl;
	}
	return 0;
}
#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;
//最大公约数--》辗转相除
int Fun(int pow, int num)
{
	while (pow*num != 0)
	{
		if (pow>num)
		{
			pow %= num;
		}
		else if (pow<num)
		{
			num %= pow;
		}
		else
		{
			return num;
		}
	}

	return num == 0 ? pow : num;
}
int main()
{
	int count, pow;
	vector<int> v;
	while (cin >> count >> pow)
	{
		v.resize(count);
		for (int i = 0; i<count; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i<count; i++)
		{
			if (pow >= v[i])
			{
				pow = pow + v[i];
			}
			else
			{
				pow += Fun(pow, v[i]);
			}
		}
		cout << pow << endl;
	}
	return 0;
}
#endif

#if 0
//找数组中个数超过数组一半的
//找红包
#include<vector>
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		int count = 1, res = gifts[0];
		sort(gifts.begin(), gifts.end());
		for (int i = 1; i<n; i++)
		{
			if (gifts[i] == gifts[i - 1])
			{
				count++;
			}
			else if (gifts[i] != gifts[i - 1])
			{
				if (count>n / 2)
					return gifts[i-1];
				count = 1;
			}
		}
		return 0;
	}
};

int main()
{
	vector<int> v{ 1, 2, 3, 2, 2 };
	int n = 5;
	Gift g;
	cout<<g.getValue(v, n);
	return 0;
}
#endif

#if 0
//编译距离  错误

#include<iostream>
#include<string>
using namespace std;

int calStringDistance(string s1, string s2)
{
	int count = 0;
	int Size1 = s1.size(), Size2 = s2.size();

	//判断他俩不同得字符都有哪些
	for (int i = 0; i<s1.size(); i++)
	{
		if (s2.find(s1[i]) != string::npos&&s2.size())
		{
			s2.erase(s2.find(s1[i]), 1);
			count++;//删除得个数是相等的个数
		}
	}
	return  Size1 - count>Size2 - count ? Size1 - count : Size2 - count;

	//return s2.size() + s1.size() - count;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << calStringDistance(s1, s2) << endl;
	}
	return 0;
}
#endif
#if 0
/////要交的版本
#include<iostream>
#include<string>
using namespace std;

int calStringDistance(string s1, string s2)
{
	//if(s1.empty()&&s2.empty())
	//return 0;
	int count = 0;
	int Size1 = s1.size(), Size2 = s2.size();
	//判断他俩不同得字符都有哪些
	for (size_t i = 0; i<s1.size(); i++)
	{
		if (s2.find(s1[i]) != string::npos&&s2.size())
		{
			s2.erase(s2.find(s1[i]), 1);
			count++;//删除得个数是相等的个数
		}
	}
	return  Size1 - count>Size2 - count ? Size1 - count : Size2 - count;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << calStringDistance(s1, s2) << endl;
	}
	return 0;
}
#endif

#if 0
//编辑距离
#include<string>
int min(int a, int b)
{
	return a < b ? a : b;
}
int edit(string str1, string str2)
{
	int max1 = str1.size();
	int max2 = str2.size();

	int **ptr = new int*[max1 + 1];

	for (int i = 0; i < max1 + 1; i++)
	{
		ptr[i] = new int[max2 + 1];
	}

	for (int i = 0; i < max1 + 1; i++)
	{
		ptr[i][0] = i;
	}
	for (int i = 0; i < max2 + 1; i++)
	{
		ptr[0][i] = i;
	}

	for (int i = 1; i < max1 + 1; i++)
	{
		for (int j = 1; j < max2 + 1; j++)
		{
			int d;
			int temp = min(ptr[i - 1][j] + 1, ptr[i][j - 1] + 1);
			if (str1[i - 1] == str2[j - 1])
			{
				d = 0;
			}
			else
			{
				d = 1;
			}
			ptr[i][j] = min(temp, ptr[i - 1][j - 1] + d);
		}
	}
	//cout << "********" << endl;
	//for (int i = 0; i < max1 + 1; i++)
	//{
	//	for (int j = 0; j < max2 + 1; j++)
	//	{
	//		cout << ptr[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//		cout << "********" << endl;
			int dis = ptr[max1][max2];

			for (int i = 0; i < max1 + 1; i++)
			{
				delete[] ptr[i];
				ptr[i] = NULL;
			}

			delete[] ptr;
			ptr = NULL;

			return dis;
}
int main()
{
	string str1 = "sailn";
	string str2 = "failing";

	int r = edit(str1, str2);
	cout << "the dis is: " << r << endl;
	return 0;
}
#endif

#if 0
//礼物的最大值
#include <vector>
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		int rows = board.size();
		int cols = board[0].size();
		vector<int> v(cols, 0);
		for (int i = 0; i<rows; i++)
		{
			for (int j = 0; j<cols; j++)
			{
				int left = 0;
				int up = 0;

				if (i>0)
					up = v[j];
				if (j>0)
					left = v[j - 1];

				v[j] = std::max(left, up) + board[i][j];
			}
		}

		int res = v[cols - 1];
		return res;

	}
};
#endif

//#if 1
////迷宫问题
//#include<iostream>
//using namespace std;
//#include<vector>
//int moving(int row, int col, int i, int j, vector<vector<int>> b, queue q)
//{
//	if ((i == row - 1) && (j == col - 1) && check(i, j, b))
//	{
//		q.push_back(i);
//		q.push_back(j);
//	}
//	moving(row, col, i - 1, j, b, q);
//
//}
//bool check(int i, int j, vector<vector<int>> b)
//{
//	if (b[i][j] == 1)
//		return false;
//	else return true;
//}
//int main()
//{
//	int row, col;
//	vector<vector<int>> v，b;
//	queue q;
//	while (cin >> row >> col)
//	{
//		int i = 0, j = 0;
//		v.resize(row);
//		for (int i = 0; i<row; i++)
//		{
//			v[i].resize(col);
//			for (int j = 0; j<col; j++)
//				cin >> v[i][j];
//		}
//		b = v;
//
//		for (int i = 0; i<row; i++)
//		{
//			for (int j = 0; j<col; j++)
//			{
//				moving(row, col, i, j, b, q)
//			}
//		}
//	}
//	return 0;
//}
//#endif

#if 0
#include<vector>

int N, M;//分别代表行和列
vector<vector<int>> maze;//迷宫矩阵
vector<vector<int>> path_temp;//存储当前路径，第一维表示位置
vector<vector<int>> path_best;//存储最佳位置

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//表示当前节点已走，不可再走
	path_temp.push_back({ i, j });//将当前节点加入到路径中
	if (i == N - 1 && j == M - 1)//判断是否到达终点
	{
		if (path_best.empty() || path_temp.size() < path_best.size())
		{
			path_best = path_temp;
		}
	}

	if (i - 1 >= 0 && maze[i - 1][j] == 0)//探索向上走是否可行
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//探索向下走是否可行
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j-1] == 0)//探索向左走是否可行
		MazeTrack(i, j-1);
	if (j + 1 <M && maze[i][j+1] == 0)//探索向右走是否可行
		MazeTrack(i, j+1);

	maze[i][j] = 0;
	path_temp.pop_back();
}
int main()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto& i : maze)
		{
			for (auto &j : i)
				cin >> j;
		}
		MazeTrack(0, 0);//回溯寻找迷宫的最短路径

		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//输出通路
	}
	return 0;
}

#endif

#if 0
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		int count = 1;
		for (int i = 1; i<n; i++)
		{
			if (gifts[i - 1] == gifts[i])
			{
				count++;
				if (count >= n / 2)
				{
					return gifts[i];
				}

			}
			else
			{
				count = 1;
			}
		}
		return 0;
	}
};
#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n);
		for (int i = 0; i<n; i++)
			cin >> v[i];
		int sum = v[0];
		int tmp = v[0];
		for (int i = 0; i<n; i++)
		{
			tmp += v[i];
			if (v[i]>tmp)
			{
				tmp = v[i];
			}
			if (tmp>sum)
			{
				sum = tmp;
			}
		}
		cout << sum << endl;
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
	string s1, s2, s3;
	while (1)
	{
		getline(cin , s1);
		cin >> s2;
		int arr[256] = { 0 };
		int i = 0;
		for (; i<s2.size(); i++)
		{
			arr[s2[i]] = 1;
		}

		for (i = 0; i<s1.size(); i++)
		{
			if (arr[s1[i]] == 1)
			{
				continue;
			}
			s3 += s1[i];
		}
		s3 += '\0';
		for (i = 0; i<s3.size(); i++)
		{
			cout << s3[i] << endl;
		}
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
	string s1, s2, s3;
	while (cin >> s1 >> s2)
	{
		int arr[256] = { 0 };
		int i = 0;
		for (; i<s2.size(); i++)
		{
			arr[s2[i]] = 1;
		}

		for (i = 0; i<s1.size(); i++)
		{
			if (arr[s1[i]] == 1)
			{
				s1.erase(i, 1);
				i--;
			}

		}

		cout << s1;
		
	}


	return 0;
}


#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, i;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (i = 0; i<n; i++)
	{
		cin >> v[i];
	}
	int sum = v[0], max = v[0];
	for (i = 1; i<n; i++)
	{
		sum += v[i];
		if (sum<v[i])
		{
			sum = v[i];
		}
		if (sum>max)
		{
			max = sum;
		}
	}
	cout << max;

	return 0;
}
#endif
