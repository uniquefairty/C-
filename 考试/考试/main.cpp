#include<iostream>
using namespace std;

#if 0
//////�����ַ������ظ����ַ�
#include<string>
int main()
{
	string s;
	while(cin >> s)
	{
		int a[256] = { 0 };//��256��������б��
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
//�����г��ִ�������һ�������
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
//�������������һ�����
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
//��ת�ַ���
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
	//qsort(v.begin(), v.end());//����

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

////////c����
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
//��ת�ַ����еĵ���
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
//���ǹ�
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
		//�����鲻ͬ�����ݼ����bֵҪ��ͬ��
		//�����Ⱦ�˵��������Ч�����������ȣ���˵������������������ģ�����������
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
//ͳ�ƻ���
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
//��������
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
//�ַ���ת����
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
////�ֵ���
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

//��32λcpu��ѡ��ȱʡ���������£������½ṹ�嶨�壺
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
//��sizeof��struct A����ֵΪ����
#endif

#if 0
//쳲����������о����������С��ֵ
#include<iostream>
using namespace std;
#include<vector>
//1.���г���jv  2.������  3.�Ҳ�ֵ
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
//쳲����������о����������С��ֵ
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
			//�ҵ���N�����
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
///////ƥ������
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
//ƥ������
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
//��С������
#include<iostream>
using namespace std;
//��������˳��������Ĺ�����
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
	//�������Լ��

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
}*///շת�����
//��ת������������Լ������⣺��a��b��
//���Լ������ת��Ϊa��b֮�������Ϊ����֮����С����֮��Ĺ�Լ�������Զ������������
//�������������ֱ࣬������Ϊ0������ķ�ĸ��Ϊ�����
#endif

#if 0
//�ֵ���������
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
	//��i-1��ʼ������ǰ��Ƚϣ��Ƚϳ���
	for (size_t i = 0; i<v.size(); i++)
	{
		if (v[i - 1].size() >= v[i].size())
		{
			lenSym = false;
			break;
		}
	}
	//�Ƚ�ASCII��
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
	//�ֱ���򣺱��� 
	//�����㣺��������
	int res;
	int a = A&B;//��ͬ�Ĳ���
	int b = A^B;//��ͬ�Ĳ���
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
//ֻ�������º�������
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
//����
//class Board {
//	//���� ���� �����Խ���
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
///���뱣������
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
//��ˮ������
#include<iostream>
using namespace std;
#include<vector>

//����
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

	//��������

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
	//������֮��ľ���>d;

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
//�����������
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
		//�ȱ�������С�ڵ������������Ƚڵ�
		//�����ϴ����Ľڵ�������������бȽ�
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
///�ҳ�������������������1�ĸ���
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
//�ж��ǲ�������
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
//1.�ҳ�ÿ�����ʳ���
//2.���

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


#include<string>
#include<vector>
///��ʯ��
//�г���ǰ����Լ��  
//�����ʼ��
void Func(vector<int>& v, int n)
{
	//v.resize(n);
	for (size_t i = 2; i<sqrt(n); i++)
	{
		if (n%i == 0)
		{
			v.push_back(n / i);
		}
	}
}
int main()
{
	int n, m, count = 0;
		cin >> n >> m;

	while (n != m)
	{
		vector<int> v;
		Func(v, n);
		while (n + v[0] < m)
		{
			count++;
			n = n + v[0];
			v.resize(n, 0);
			Func(v, n);
		}
		
	}
	cout << count << endl;

	return 0;
}