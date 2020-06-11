
#if 0
//星际密码4.13
#include <iostream>
#include <vector>
using namespace std;
vector<int> a = { 1, 1 };
void data_init()
{
	int i;
	for (i = 2; i<10005; i++)
	{
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
}

int main()
{
	int n, t;
	data_init();
	while (cin >> n)
	{
		while (n--)
		{
			cin >> t;
			printf("%04d", a[t]);
		}
		printf("\n");
	}
	return 0;
}

#endif

#if 0
//树根  --错
#include <iostream>
using namespace std;
int Fun(int num)
{
	int res=0;
	while(num)
	{
		res+=num%10;
		num/=10;
	}
	while(res>9)
		res=Fun(res);

	return res;

}
int main()
{
	int num;
	while(cin>>num)
	{
		cout<<Fun(num);
	}
	return 0;
}
#endif

#if 0
//树根的正确解法
#include <iostream>
using namespace std;
#include <string>
int Fun(int num)
{
	int res = 0;
	while (num>0)
	{
		res += num % 10;
		num /= 10;
	}
	while (res>9)
		res = Fun(res);

	return res;

}
int main()
{
	string str;
	while (cin >> str)
	{
		//cout<<Fun(num);
		//cout<<(num-1)%9+1;
		int sum = 0;
		for (int i = 0; i<str.size(); i++)
		{
			sum += str[i] - '0';
		}
		cout << Fun(sum) << endl;
	}
	return 0;
}
#endif

#if 0
//变态跳台阶4.14
class Solution {
public:
	int jumpFloorII(int number) {
		if (number<0)
			return 0;
		if (number == 1)
			return 1;
		return 2 << (number - 2);
		// int res=pow(2,(number-1));

	}
};
#endif

#if 0
#include <iostream>
using namespace std;

int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		double sum = 2 * r*3.14;
		if (sum >= n)
		{
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}
#endif

#if 0
class Solution {
public:
	int Add(int num1, int num2)
	{
		//return num1+num2;
		while(num1!=0)
		{
			int same=(num1&num2)<<1;
			int diff=num1^num2;
			num2=diff;
			num1=same;
		}
		return num2;
	}
};

//错误代码
//#include <iostream>
//using namespace std;
//int Add(int num1, int num2)
//{
//	//return num1+num2;
//	int same = num1&num2;
//	int diff = num1 ^ num2;
//
//	while (same)
//	{
//		same <<= 1;
//		same = same&diff;
//		diff = same^diff;
//	}
//	return  diff;
//}
//int main()
//{
//	cout<<Add(9,4);
//	return 0;
//}

#endif


#if 0
//注意输入得取值范围
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if ((a + b)>c && (a + c)>b && (b + c)>a&&abs(a - b)<c&&abs(a - c)<b&&abs(c - b)<a)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
#endif

#if 0
4_16 day 28 1
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

/**
*  奇数位上都是奇数或者偶数位上都是偶数
*  输入：数组arr，长度大于2
*  len：arr的长度
*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
*/
void oddInOddEvenInEven(vector<int>& arr, int len) {
	int start = -1;
	int end = -1;
	for (int i = 0; i<len; i++)
	{
		if (i % 2 == 0 && arr[i] % 2 != 0)//下标是偶数但是是奇数
		{
			start = i;
		}
		else if (i % 2 != 0 && arr[i] % 2 == 0)//下标是奇数但是是偶数
		{
			//下标是奇数
			end = i;
		}

		if (start >= 0 && end >= 0)
		{
			int tmp = arr[start];
			arr[start] = arr[end];
			arr[end] = tmp;
			
		}
	}

}
int main()
{
	vector<int> v{ 2, 2, 3, 4 };
	oddInOddEvenInEven(v, 4);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}
#endif

#if 0
//4_16 day 28 2
//猴子分桃
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int main()
{
	int n;
	int total = 0;
	int min = 0, move = 0;
	int flag = 0;//判断是否余数为1；
	int count = 0;
	while (cin >> n)
	{
		if (n>0)
		{
			for (total = 1; total % 5 == 1; total++)
			{
				flag = total;
				count = n;
				while (count&&total % 5 == 1)
				{
					move = total / 5;
					total--;
					total -= move;
					count--;
				}
				if (count == 0)
				{
					min = total + n;
					break;
				}
			}

			cout << flag << " " << min << endl;
		}
	}
	return 0;
}
#endif

#if 0
class Solution {
public:
	/**
	*	正数数组中的最小不可组成和
	*	输入：正数数组arr
	*	返回：正数数组中的最小不可组成和
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) {
		sort(arr.begin(), arr.end());
		int min = arr[0];
		int max = min;
		for (int i = 0; i<len; i++)
			max += len;

		for (int num = min; num<max; num++)
		{
		}
	}
};
#endif

#if 0
//有假币
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int count = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		count = 0;
		while (n >= 2)
		{
			if (n % 3)
				n = n / 3 + 1;
			else
				n /= 3;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
#endif

#if 0
//4_18  day30 1
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		string res;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= 'F'&&str[i] <= 'Z')
			{
				res += (str[i] - 5);
			}
			else if (str[i] == ' ')
			{
				res += ' ';
			}
			else
			{
				int n =str[i]-'A';
				res += ('Z' - 4+ n);
			}
		}
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
//因子个数
//4_18  day30 2
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		int count = 0;
		for (int i = 2; i<sqrt(num); i++)
		{
			if (num%i == 0)
			{
				num /= i;
				count++;
			}
			while (num%i == 0)
			{
				num /= i;
			}
		}

		if (num != 1)//num为质数
		{
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
#endif


////day31 4.20/1美国节日
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int year;
//	vector<int> v{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//	while (cin >> year)
//	{
//		if ((year / 4 == 0 && year / 100 != 0) || year % 400 == 0)
//		{
//			v[2] == 29;
//		}
//		else
//		{
//			v[2] = 28;
//		}
//
//		cout << year << "-" << "01-01" << endl;
//
//	}
//	return 0;
//}

#if 0
//day31 4.20  2.分解因数
#include <iostream>
#include <vector>
using namespace std;

void Print(int NUM, vector<int> v)
{
	cout << NUM << " " << "=";
	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
		{
			cout << " " << v[i] << endl;
			break;
		}
		cout << " " << v[i] << " " << "*";
	}
}
int main()
{
	int num;
	while (cin >> num)
	{
		int NUM = num;
		vector<int> v;
		int ret = 2;

		while (num > 1)
		{
			if (num%ret == 0)
			{
				num /= ret;
				v.push_back(ret);
				continue;
			}
			ret++;
		}

		Print(NUM, v);
	}
	return 0;
}
#endif

#if 0
//day32 4.21  1.淘宝网店
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool IsPrime(int num)
{
	if (num == 1)
		return false;
	if (num == 2)
		return true;
	for(int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool IsLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	int year1, month1, day1, year2, month2, day2;
	vector<int> v{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<int> a{ 0, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62};

	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		int res = 0;
		if (year1 == year2)//年份一样
		{
			if (IsLeap(year1))//是闰年
			{
				v[2] = 29;
			}

			if (month1 == month2)//月份一样
			{
				if (IsPrime(month1))
				{
					res = day2 - day1 + 1;
				}
				else
				{
					res = (day2 - day1 + 1) * 2;
				}
			}
			else//月份不一样
			{
				if (IsPrime(month1))
				{
					res += v[month1] - day1 + 1;
				}
				else
				{
					res += (v[month1] - day1 + 1) * 2;
				}
				//中间月份
				for (int i = month1+1; i < month2; i++)
				{
					if (IsPrime(i))
					{
						res += v[i] ;
					}
					else
					{
						res += v[i] * 2;
					}
				}

				if (IsPrime(month2))
				{
					res += day2;
				}
				else
				{
					res += day2 * 2;
				}

			}
		}
		else//年份不一样
		{
			if (IsLeap(year1))
			{
				v[2] = 29;
			}

			if (IsPrime(month1))
			{
				res += v[month1] - day1+1;
			}
			else
			{
				res += (v[month1] - day1+1) * 2;
			}
			for (int i = month1+1; i <= 12; i++)
			{
				if (IsPrime(i))
				{
					res += v[i];
				}
				else
				{
					res += v[i] * 2;
				}
			}


			for (int i = year1+1; i < year2; i++)
			{
				if (IsLeap(i))
				{
					a[2] = 29;
				}
				else
				{
					a[2] = 28;
				}

				for (int j = 1; j < a.size(); j++)
				{
					res += a[j];
				}
			}

			if (IsLeap(year2))
			{
				v[2] = 29;
			}
			else
			{
				v[2] = 28;
			}

			for (int i = 1; i < month2; i++)
			{
				if (IsPrime(i))
				{
					res += v[i];
				}
				else
				{
					res += v[i] * 2;
				}
			}

			if (IsPrime(month2))
			{
				res += day2;
			}
			else
			{
				res += day2 * 2;
			}
		}

		cout << res<<endl;
	}
	return 0;
}
#endif

//day32 4.21  2.斐波那契凤尾
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//int main()
//{
//	long n;
//	while (cin >> n)
//	{
//		if (n == 1)
//		{
//			cout << "1"<<endl;
//			continue;
//		}
//		if (n == 2)
//		{
//			cout << "2"<<endl;
//			continue;
//		}
//
//		long a = 1;
//		long b = 2;
//		long c;
//		for (int i = 3; i <= n;i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//			//cout << c << " ";
//
//		}
//	 cout << c % 1000000<<endl;
//	}
//	return 0;
//}

#if 0
#include <iostream>
using namespace std;
int main()
{
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;

	for (int i = 2; i <= 100000; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000;
	}

	int n;
	while (cin >> n)
	{
		if (n <= 25)
		{
			cout << fib[n] << endl;
		}
		else
		{
			printf("%06d\n", fib[n]);
		}
	}
	return 0;
}
#endif

#if 0
//day33 4.22  1.剪花布条
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int count = 0;
		size_t found = 0;
		
		while (1)
		{
			size_t found = s1.find(s2);
			if (found != string::npos)
			{
				count++;
			}
			else
			{
				break;
			}
			s1.erase(found, s2.size());
		}
		
		cout << count << endl;
	}
	return 0;
}
#endif

#if 0
//day33 4.22  2.客似云来
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a, b;
	vector<long long> v;
	v.resize(81);
	v[0] = 0;
	v[1] = 1;
	v[2] = 1;
	for (int i = 3; i < v.size(); i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}

	while (cin >> a >> b)
	{
		long long res = 0;
		for (int i = a; i <= b; i++)
		{
			res += v[i];
		}
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
//day34 4.23  1.收件人列表
#include <iostream>
using namespace std;
#include <string>
#include <vector>

bool Fun(string str)
{
	size_t found = str.find(',');
	size_t tmp = str.find(' ');
	if (found != string::npos || tmp != string::npos)
		return true;

	return false;
}
int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		vector<string> v;
		v.resize(n);
		for (int i = 0; i<n; i++)
		{
			string str;
			//v[i] = getline(cin, str);//错误代码
			getline(cin, str);
			v[i] = str;
		}
		for (int i = 0; i<n; i++)
		{
			string str = v[i];
			if (Fun(str))//有空格或逗号
			{
				cout << "\"" << str << "\"";
			}
			else
			{
				cout << str;
			}
			if (i != n - 1)
			{
				cout << "," << " ";
			}
			else{
				cout << endl;
			}

		}
	}
	return 0;
}
#endif

#if 0
//day34 4.23  2.养兔子
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
	long long num[91] = { 1, 2 };
	for (int i = 2; i<91; i++)
		{
			num[i] = num[i - 1] + num[i - 2];
		}

	int d;
		while (cin >> d)
		{
			cout << num[d - 1] << endl:
		}
	return 0;
}

#endif

#if 0
//day35 4.24  1.年会抽奖
#include <iostream>
using namespace std;

int main()
{
	int n;
	long long a[21] = { 0, 0, 1 }, b[21] = { 1, 1, 2 };

	while (cin >> n)
	{
		for (int i = 3; i<=n; i++)
		{
			b[i] = i*b[i - 1];
			a[i] = (i - 1)*(a[i - 1] + a[i - 2]);
		}
		printf("%.2f%c\n", 1.0*a[n]/b[n]*100,'%');
	
	}

	return 0;
}
#endif

#if 0
//day35 4.24  1.年会抽奖
#include <iostream>
using namespace std;
#include <string>
#include <vector>

int main()
{
	string str1, str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		size_t found=str1.find(str2);
		if (found != string::npos)
		{
			if (found == 0 )
			{
				if (str1[str2.size()] == ',')
				{
					cout << "Ignore" << endl;
				}
			}
			else//不是第一个
			{
				if ((str1[found-1]==','&&str1[found+str2.size()]==',')||
					(str1[found - 1] == '"'&&str1[found + str2.size()] == '"'))
					cout << "Ignore" << endl;
				else 
					cout << "Important!" << endl;
			}
			
		}
		else
		{
			cout << "Important!" << endl;
		}
	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

bool IsZi(string s1, string s2)
{
	if (s1[1] == s2[1])
	{
		s2 = s2.substr(0, s1.size());
		if (s1 == s2)
			return true;
	}
	return false;
}
void Mkdir(vector<string> v)
{
	string mk = "mkdir -p ";
	int i = 0;
	while (i < v.size() - 1)
	{
		//前一个字符串是后一个的字串，且后一个字串的下一个位置是/
		if (IsZi(v[i], v[i + 1]) && v[i + 1][v[i].size()] == '/')
		{
			v.erase(v.begin() + i);
		}
		else
			i++;
	}

	for (auto &e : v)
		cout << mk << e << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			string s1;
			cin >> s1;
			v.push_back(s1);
		}

		sort(v.begin(), v.end());
		Mkdir(v);
		cout << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int con = 0;
		queue<char> q;
		for (int i = 0; i<n; i++)
		{
			char ID;
			cin >> ID;
			string OP;
			cin >> OP;
			if (OP == "connect")
				q.push(ID);
			else
			{
				con = q.size()>con ? q.size() : con;
				q.pop();
			}
		}
		cout << con << endl;
	}
	return 0;
}
#endif

#if 0
//day38 4.28  1.红与黑
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int dest[4][2] = { 1, 0, 0, 1, 0, -1, -1, 0 };
struct node{
	int x;
	int y;
};
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<vector<char>> room(m, vector<char>(n));
		int a, b;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> room[i][j];
				if (room[i][j] == '@')
				{
					a = i;
					b = j;
				}

			}
		}
		queue<node> p;
		int result = 1;
		node cur;
		cur.x = a;
		cur.y = b;
		p.push(cur);
		while (!p.empty())
		{
			node tmp = p.front();
			p.pop();
			for (int i = 0; i < 4; i++)
			{
				node next;
				next.x = tmp.x + dest[i][0];
				next.y = tmp.y + dest[i][1];
				if (next.x < m && next.x >= 0 && next.y < n && next.y >= 0 && room[next.x][next.y] == '.')
				{
					result++;
					p.push(next);
					room[next.x][next.y] = '@';
				}
			}

		}
		cout << result << endl;
	}
	return 0;
}
#endif

#if 0
//day38 4.29  1.字符串计数
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s1, s2;
	int len1, len2;
	while (cin >> s1 >> s2 >> len1 >> len2) {
		// 只包含小写字母的字符串可以看成26进制的数制
		// 将s1和s2补长到len2长度
		s1.append(len2 - s1.size(), 'a');
		s2.append(len2 - s2.size(), (char)('z' + 1));

		// 确认s1和s2的两个字符串每个位置上的差值
		vector<int> arr;
		for (int i = 0; i < len2; ++i)
			arr.push_back(s2[i] - s1[i]);
		// 确认len1和len2之间可组成的不同字符串的个数
		int result = 0;
		for (int i = len1; i <= len2; ++i)
			for (int k = 0; k < i; ++k)
				result += arr[k] * pow(26, i - 1 - k);
		// 所有字符串最后都不包含是s2自身，所有最后要减1
		cout << result - 1 << endl;
	}
	return 0;
}
#endif

#if 0
//day38 4.29  2.字符串计数最长公共字串
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		int s1Length = s1.length();
		int s2Length = s2.length();
		// 用来保存状态转移方程中间结果的矩阵
		vector<vector<int>> dp(s1Length, vector<int>(s2Length, 0));
		// 初始化dp矩阵边界：边界要么在，要么不在
		dp[0][0] = (s1[0] == s2[0]) ? 1 : 0;
		for (int i = 1; i < s1Length; ++i) {
			dp[i][0] = (s1[i] == s2[0]) ? 1 : 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int j = 1; j < s2Length; ++j) {
			dp[0][j] = (s1[0] == s2[j]) ? 1 : 0;
			dp[0][j] = max(dp[0][j - 1], dp[0][j]);
		}

		// 根据状态转移方程进行计算
		for (int i = 1; i < s1Length; ++i) {
			for (int j = 1; j < s2Length; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (s1[i] == s2[j])
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
		cout << dp[s1Length - 1][s2Length - 1] << endl;
	}
	return 0;
}
#endif

#if 0
//day40 4.30  1.发邮件
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		long long arr[21] = { 0, 0, 1 };
		for (int i = 3; i <= n; i++)
			arr[i] = (i - 1)*(arr[i - 1] + arr[i - 2]);
		cout << arr[n] << endl;
	}
	return 0;
}
#endif

////最长上升子序列
//#include <iostream>
//using namespace std;
//
//void solve()
//{
//	int i, j, n, top, temp;
//	int arr[1010];//用数组代替栈
//	cin >> n;
//	top = 0;
//	arr[0] = -1;
//	for (i = 0; i < n; i++)
//	{
//		cin >> temp;
//		if (temp > arr[top])
//		{
//			arr[++top] = temp;
//		}
//		else//二分查找
//		{
//			int low = 1, high = top;
//			int mid;
//			while (low <= high)
//			{
//				mid = (low + high) / 2;
//				if (temp > arr[mid])
//				{
//					low = mid + 1;
//				}
//				else
//				{
//					high = mid - 1;
//				}
//			}
//			arr[low] = temp;
//		}
//	}
//	cout << top << endl;
//}

#if 0
//day41 _5.8 1.五子棋
#include <iostream>
using namespace std;
#include <vector>

bool Fun(vector<vector<char>> v,int i, int j)
{
	//横
	if (j+4<20 && v[i][j + 1] == v[i][j] && v[i][j + 2] == v[i][j]
		&& v[i][j + 3] == v[i][j]&& v[i][j + 4] == v[i][j] )
	{
		return true;
	}
	//竖
	if (i + 4 < 20 && v[i + 1][j] == v[i][j] && v[i + 2][j] == v[i][j]
		&& v[i + 3][j] == v[i][j] && v[i + 4][j] == v[i][j])
	{
		return true;
	}
	//左斜
	if (i+4<20&&j-4>=0&&v[i + 1][j - 1] == v[i][j] && v[i + 2][j - 2] == v[i][j]
		&& v[i + 3][j - 3] == v[i][j] && v[i + 4][j - 4] == v[i][j])
	{
		return true;
	}
	//右斜
	if (i+4<20&&j+4<20&&v[i + 1][j + 1] == v[i][j] && v[i + 2][j + 2] == v[i][j]
		&& v[i + 3][j + 3] == v[i][j] && v[i + 4][j + 4] == v[i][j])
	{
		return true;
	}
	return false;
}
int main()
{

	vector<vector<char>> v;
	v. resize(20);
	for (int i = 0; i < 20; ++i)
	{
		v[i].resize(20);
		for (int j = 0; j < 20; ++j)
		{
			char a;
			cin >> a;
			v[i][j] = a;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (v[i][j] == '*' || v[i][j] == '+')
			{
				if (Fun(v, i, j))
				{
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;
	return 0;
}
#endif

#if 0
//day41 _5.8 2.计算器
#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <sstream>
int f(string x)
{
	stringstream ss;
	ss << x;
	int num;
	ss >> num;
	return num;
}
int main()
{
	int n;
	while (cin >> n)
	{
		stack<int> s;
		for (int i = 0; i < n; i++)
		{
			string x;
			cin >> x;
			if (x == "+")
			{
				int a, b;
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				a += b;
				s.push(a);
			}
			else if (x == "-")
			{
				int a, b;
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				a = b-a;
				s.push(a);
			}
			else if (x == "*")
			{
				int a, b;
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				a *= b;
				s.push(a);
			}
			else if (x == "/")
			{
				int a, b;
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				a = b / a;
				s.push(a);
			}
			else
			{
				int a = f(x);
				s.push(a);
			}
		}
		cout << s.top()<<endl;
	}
	return 0;
}
#endif

#if 0
//day42 5.9 1解读密码
#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s;
	while (getline(cin, s))
	{
		string res;
		for (size_t i = 0; i<s.size(); i++)
		{
			if (s[i] >= '0'&&s[i] <= '9')
				res += s[i];
		}
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
//day43 5.11 1电话号码
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

string Fun(string s)
{
	string res;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0'&&s[i] <= '9')
		{
			res += s[i];
		}
		else if (s[i] >= 'A'&&s[i] <= 'C')
		{
			res += '2';
		}
		else if (s[i] >= 'D'&&s[i] <= 'F')
		{
			res += '3';
		}
		else if (s[i] >= 'G'&&s[i] <= 'I')
		{
			res += '4';
		}
		else if (s[i] >= 'J'&&s[i] <= 'L')
		{
			res += '5';
		}
		else if (s[i] >= 'M'&&s[i] <= 'O')
		{
			res += '6';
		}
		else if (s[i] >= 'P'&&s[i] <= 'S')
		{
			res += '7';
		}
		else if (s[i] >= 'T'&&s[i] <= 'V')
		{
			res += '8';
		}
		else if (s[i] >= 'W'&&s[i] <= 'Z')
		{
			res += '9';
		}
		else if (s[i] =='-')
		{
			continue;
		}

		if (res.size() == 3)
			res += '-';
	}
	return res;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v,res;
		v.resize(n);
		res.resize(n);
		string s;
		for (size_t i = 0; i<n; i++)
		{
			cin >> s;
			v[i] = s;
		}

		for (size_t i = 0; i < n; i++)
		{
			res[i]=Fun(v[i]);
		}
		
		sort(res.begin(), res.end());

		for (size_t i = 0; i < n - 1; i++)
		{
			if (res[i] == res[i + 1])
			{
				res[i] = '0';
			}
		}

		for (size_t i = 0; i < n; i++)
		{
			if (res[i] != "0")
			{
				cout << res[i] << endl;
			}
		}
		cout << endl;

	}
	return 0;
}
#endif

#if 0
//day43 5.11 2.求和
//不全对
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n && i <= m/2 ; i++)
		{
			int tmp = m - i;
			if (tmp <= n)
			{
				cout << i << ' ' << tmp << endl;
			}
		}
		if (n >= m)
		{
			cout << m << endl;
		}
	}
	return 0;
}
#endif

#if 0
//day44 5.12 1.骆驼命名法
#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s;
	while (cin >> s)
	{
		string res;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] == '_')
			{
				res += (s[++i] - 'a' + 'A');
			}
			else
			{
				res += s[i];
			}

		}
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
//day44 5.12 2.单词到排
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
string Reverse(string s, int start, int end)
{
	string res;
	for (int i = start; i <= end; i++)
	{
		res += s[i];
	}

	reverse(res.begin(), res.end());
	return res;
}
int main()
{
	string s;
	while (getline(cin, s))
	{
		string res;
		reverse(s.begin(), s.end());

		for (int i = 0, j = 0; i <= s.size(); i++)
		{
			if (s[j] == ' ' || s[j] == '\0' || ((s[j]<'a'&&s[j]>'z') && (s[j]<'A'&&s[j]>'Z')))
			{
				j++;
				continue;
			}
			if (s[i] == ' ' || s[i] == '\0' || ((s[i]<'a'&&s[i]>'z') && (s[i]<'A'&&s[i]>'Z')))
			{
					
				res += Reverse(s, j, i - 1);
				if (s[i] != '\0')
					res += ' ';
				/*while (s[i] == ' '&& s[++i] == ' ')
				{
					i++;
				}*/

				j = i+1;
				
			}
		}
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
//day45 5.13 1.乒乓球筐
//#include <iostream>
//using namespace std;
//#include <string>

//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		size_t i = 0;
//		for (; i<s2.size(); i++)
//		{
//			size_t pos = s1.find(s2[i]);
//			if (pos != string::npos)
//				s1[i] -= 32;
//			else{
//				cout << "No" << endl;
//				break;
//			}
//		}
//		if (i == s2.size())
//			cout << "Yes" << endl;
//	}
//	return 0;
//}

#include <iostream>
using namespace std;
#include <string>
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int arr[256] = { 0 };
		int flag = 1;
		for (size_t i = 0; i < s1.size(); i++)
		{
			arr[s1[i]]++;
		}
		
		for (size_t i = 0; i < s2.size(); i++)
		{
			arr[s2[i]]--;
		}

		for (size_t i = 0; i < 256; i++)
		{
			if (arr[i] < 0)
			{
				cout << "No" << endl;
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "Yes" << endl;
	}
	return 0;
}

#endif

#if 0
//day46 5.14 数组中出现次数超过一半的数字
#include <iostream>
using namespace std;
#include <vector>
//int MoreThanHalfNum_Solution(vector<int> numbers) {
//	int tmp = 0;
//	int res = numbers[0];
//	sort(numbers.begin(), numbers.end());
//	int count = 1;
//	for (int i = 0; i<numbers.size() - 1; i++)
//	{
//		if (numbers[i] == numbers[i + 1])
//			count++;
//		else
//			count = 1;
//		
//		if (count > tmp)
//		{
//			tmp = count;
//			res = numbers[i];
//		}
//			
//	}
//
//	if (tmp>numbers.size() / 2)
//		return res;
//	else
//		return 0;
//}//////没过

int MoreThanHalfNum_Solution(vector<int> numbers) {

	sort(numbers.begin(), numbers.end());
	int res = numbers[numbers.size()/2];
	int count = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == res)
			count++;

	}
	if (count > numbers.size()/2)
		return res;
	else
		return 0;
}
int main()
{
	//vector<int> v{ 1, 2, 2, 2, 2, 2,2,3, 4,5 };
	vector<int> v{ 1, 2, 2, 2, 2, 2, 2, 3, 4, 5 ,8,8,8,8,8,8,8,8,8,8,8};
	cout<<MoreThanHalfNum_Solution(v)<<endl;
	return 0;
}
#endif

#if 0
//day47 5.15 1.合唱团  20%
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Fun(vector<int> v, int start, int end, int sub)
{
	int res = 1;
	int flag = 1;
	for (int i = start; i<end; i++)
	{
		if (abs(v[i] - v[i + 1]) <= sub)
		{
			res *= v[i];
		}
		else
		{
			flag = 0;
		}
	}

	if (flag)
	{
		res *= v[end];
		return res;
	}
	else
	{
		return 0;
	}

}

int main()
{
	int n, k, d;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(n);
		int res = 0, tmp = 0;
		for (size_t i = 0; i<n; i++)
		{
			int a;
			cin >> a;
			v[i] = a;
		}
		cin >> k >> d;

		for (size_t i = 0; i <= n - k; i++)
		{
			tmp = Fun(v, i, i + k - 1, d);
			if (tmp>res)
				res = tmp;
		}
		cout << res << endl;
	}
	return 0;
}

#endif

//2.马戏团


#if 0
//day48 5.16 1.左右最值最大差
class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		// write code here
		int max = A[0];
		int pos = 0;
		for (size_t i = 0; i<A.size(); i++)
		{
			if (A[i]>max)
			{
				max = A[i];
				pos = i;
			}

		}

		if (pos == 0)
			return A[pos] - A[n - 1];
		else if (pos == n - 1)
			return A[pos] - A[0];
		else
		{
			int left = A[pos] - A[0];
			int right = A[pos] - A[n - 1];
			return left>right ? left : right;
		}
	}
};
#endif

#if 0
//day48 5.16 2.顺时针打印矩阵
class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		vector<int> ret;
		int x1 = 0, y1 = 0;
		int x2 = n - 1, y2 = m - 1;
		while (x1 <= x2&&y1 <= y2)
		{
			for (int j = y1; j <= y2; ++j)
				ret.push_back(mat[x1][j]);
			for (int i = x1 + 1; i<x2; ++i)
				ret.push_back(mat[i][y2]);
			for (int j = y2; x1<x2&&j >= y1; --j)
				ret.push_back(mat[x2][j]);
			for (int i = x2 - 1; y1<y2&&i>x1; --i)
				ret.push_back(mat[i][y1]);
			x1++; y1++;
			x2--; y2--;
		}
		return ret;
	}
};
#endif

