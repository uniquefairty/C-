#include<iostream>
using namespace std;
#include<vector>


#if 0
void f(int n)
{
	if (n == 1)
		cout << "1";
	else
	{
		int a[100000], tail = 0, head = 0, p = 0;
		a[0] = 1;
		for (int i = 2; i <= n; i++){
			for (int j = head; j <= tail; j++)
			{
				p = a[j] * i + p;
				a[j] = p % 10;
				p = p / 10;
			}
			while (p != 0)
			{
				tail++;
				a[tail] = p % 10;
				p = p / 10;
			}
		}
		for (int i = tail; i >= 0; i--)
			cout << a[i];
	}
}
int main()
{
	int n;
	cin >> n;
	f(n);
	return 0;
}
#endif

#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(1000000, 0);
		int a = 2;
		int d = 0;
		int i = 0;
		v[0] = 1;
		int tail = 0;//记录最后一位数字的下标

		while (a <= n)
		{
			for (i = 0; i<=tail; i++)
			{
				d = v[i] * a + d;
				v[i] = d % 10;
				d = d / 10;
			}
			while (d != 0)
			{
				tail++;
				v[tail] = d % 10;
				d = d / 10;
			}
			a++;
		}

		for (int i = tail; i >= 0; i--)
			cout << v[i];

		//数组逆向输出
	}

	return 0;
}
#endif

#if 0
//错误  两个数相加应该从最低位开始相加 在这里最低为是从两个字符串的
//右边开始相加
#include<string>

void add(string s1, string s2)
{
	int res = 0,i=0,tail=0;
	string c;
	for (i = 0; i < s1.size() || i < s2.size(); i++)
	{
		res = s1[i] + s2[i] - 2 * '0' + res;
		c += res / 10 + '0';
		res = res % 10;
	}
	tail = i-1;
	if (i<s1.size())
	{
		for (; i < s1.size(); i++)
		{
			res = s1[i] -  '0' + res;
			c += res / 10 + '0';
			res = res % 10;
		}
	}
	else
	{
		for (; i < s2.size(); i++)
		{
			res = s2[i] - '0' + res;
			c += res / 10 + '0';
			res = res % 10;
		}
			
	}

	if (res != 0)
	{
		c += res + '0';
	}

	for (int j =c.size()-1; j >=0; j--)
	{
		cout << c[i] - '0';
	}


}
#endif

#if 0
//输入两个整数a和b，输出这两个整数的和。a和b都不超过100位。
#include<iostream>
using namespace std;
#include<string>
void add(string a, string b)
{
	int c[102], tail = 0, p = 0;
	int i = a.length() - 1;
	int j = b.length() - 1;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0 && j >= 0)
		{
			p = (int)a[i] + (int)b[j] + p - '0' - '0';
		}
		else if (i >= 0 && j < 0)
		{
			p = (int)a[i] + p - '0';
		}
		else if (i < 0 && j >= 0)
		{
			p = (int)b[j] + p - '0';
		}
		c[tail++] = p % 10;
		p = p / 10;
		i--; j--;	
	}
	if (p != 0)
	{
		c[tail++] = p;
	}

	for (int i = tail-1; i >= 0; i--)
	{
		cout << c[i];
	}
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		add(s1, s2);
	}
	return 0;
}
#endif

#if 0
//龟兔赛跑结果预测
#include<iostream>
using namespace std;
int main()
{
	int v1, v2, t, s, l;
	int d=0,s1=0,s2=0;//两者相差的距离
	while (cin >> v1 >> v2 >> t >> s >> l)
	{
		int t1 = l / v2;//乌龟全程需要的时间
		for (int i = 1; i <= t1; i++)//每次增加一秒的时间
		{
			s1 += v1;//兔子走的路程
			s2 += v2;//乌龟走的路程
			if (s1!=l&&(s1 - s2) >= t)
			{
				s2 = v2*s + s2;
				i += s;
			}
			if (s1 >= l&&s2<l)
			{
				cout << "R" << endl;
				cout << i << endl;
				break;
			}
			else if(s1 >= l&&s2 >= l)
			{
				cout << "D" << endl;
				cout << t1 << endl;
			}
			else if (s2>=l)
			{
				cout << "T" << endl;
				cout << t1 << endl;
			}
		}
		
	}
	return 0;
}
#endif

//#include<vector>
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<vector<int>> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			v[i].resize(n);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			
//		}
//	}
//}

#if 0
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n ;
	while (cin >> n)
	{
		vector<char> v;
		vector<char> v0{ 'A', 'B', 'C', 'D', 'E', 'F' };
		if (n < 10)
		{
			cout << n << endl;
			n = 0;
		}
		for (n; n > 0; n /= 16)
		{
			int tmp = n % 16;
			if (tmp < 10)
			{
				v.push_back(tmp+'0');
			}
			else
			{
				v.push_back(v0[tmp % 10]);
			}
		}
		reverse(v.begin(), v.end());

		for (auto &it : v)
		{
			if (it < 10)
				cout << it - '0';
			else
			{
				cout << it;

			}
		}
	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main()
{
	int x, y, i;
	int d, n = 1;
	char h[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	while (cin >> x)
	{
		y = x;
		while (x >= 10)
		{
			x /= 10;
			++n;
		}
		int *r = new int[n];
		for (i = 0; y >= 16; ++i)
		{
			r[i] = y % 16;
			y /= 16;
		}
		r[i++] = y;

		for (i = (n - 1); i >= 0; --i)
		{
			cout << h[r[i]];
		}
	}
	return 0;
}
#endif


#if 0
//算法训练1
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v;
	v.resize(M);
	for (int i = 0; i < v.size(); i++)
	{
		v[i].resize(N);
		for (int j = 0; j < v[i].size(); j++)
		{
			cin >> v[i][j];
		}
	}

	int max = v[0][2];
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i][2]>max)
			max = v[i][2];
	}
	cout << max << endl;
	return 0;
}
#endif

#if 0
//huffmans树
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#include <queue>
class Less
{
public:
	bool operator()(const int left, const int right)
	{
		return left > right;
	}
};
int main()
{
	int num;
	cin >> num;
	vector<int> v;
	v.resize(num);
	int sum = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	priority_queue<int,vector<int>,Less> q;
	for (auto e : v)
	{
		q.push(e);
	}

	while (q.size()>1)
	{
		int tmp = q.top();
		q.pop();
		tmp += q.top();
		q.pop();
		sum += tmp;
		q.push(tmp);
		/*sort(v.begin(), v.end());
		int tmp = v[0] + v[1];
		sum += tmp;
		v.erase(v.begin(),v.begin()+1);
		v.push_back(tmp);*/
	}
	
	cout << sum;
	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <algorithm>
#define maxx 100
using namespace std;
int main()
{
	int a[maxx];
	int i, n;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);//从小到大排序
	int sum = 0;
	while (n>1)
	{
		i = 0;
		a[i] = a[i] + a[i + 1];
		sum += a[i];
		a[i + 1] = -1;//将这个数去除
		sort(a, a + n);
		for (i = 0; i<n - 1; i++)
			a[i] = a[i + 1];
		n--;
	}
	printf("%d\n", sum);
	return 0;
}
#endif

#if 0
//Huffman树
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	cin >> num;
	vector<int> v;
	v.resize(num);
	int sum = 0;
	int i = 0;
	int n = v.size();
	for (size_t i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	while (n>1)
	{
		i = 0;
		v[i] = v[i] + v[i+1];
		sum += v[i];
		v[i+1] = -1;//将这个数去除
		sort(v.begin(), v.begin()+n);//排序

		for (; i < v.size()-1; i++)
		{
			v[i] = v[i + 1];
		}
		n--;
	}

	cout << sum;
	return 0;
}
#endif


#if 0
scanf("%f",&fahr);

celsius

printf("fahr=%.1f,celsius=%.1f",fahr, celsius);

#endif

#if 0
//数组逆序排列
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void Swap(vector<int>& v,int start, int end)
{
	int tmp = v[start];
	v[start] = v[end];
	v[end] = tmp;
}

//void Swap(vector<int>& v, int n)
//{
//	int end = n-1;
//	for (size_t i = 0; i < n/ 2; i++)//注意条件
//	{
//		int tmp = v[i];
//		v[i] = v[end];
//		v[end] = v[i];
//		end--;
//	}
//}
int main()
{
	vector<int> v;
	int num;
	
	while (cin >> num)
	{
		if (num == 0)
			break;
		v.push_back(num);
	}
	int start = 0, end = v.size() - 1;
	while (start < end)
	{
	    Swap(v,start, end);
		start++;
		end--;
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	return 0;
}

#endif

#if 0
#include<stdio.h>
void swap(int a[], int n)
{
	int i, j, t;
	for (i = 0; i<n / 2; i++)
	{
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
}
int main()
{
	int a[100], i = 0, j;
	for (i = 0; i<100; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 0)
			break;
	}
	swap(a, i);
	for (j = 0; j<i; j++)
	{
		printf("%d ", a[j]);
	}
	return 0;
}
#endif

#if 0
/*
问题描述
　　给定两个仅由大写字母或小写字母组成的字符串(长度介于1到10之间)，它们之间的关系是以下4中情况之一：
  　　1：两个字符串长度不等。比如 Beijing 和 Hebei
	　　2：两个字符串不仅长度相等，而且相应位置上的字符完全一致(区分大小写)，比如 Beijing 和 Beijing
	  　　3：两个字符串长度相等，相应位置上的字符仅在不区分大小写的前提下才能达到完全一致（也就是说，它并不满足情况2）。比如 beijing 和 BEIjing
		　　4：两个字符串长度相等，但是即使是不区分大小写也不能使这两个字符串一致。比如 Beijing 和 Nanjing
		  　　编程判断输入的两个字符串之间的关系属于这四类中的哪一类，给出所属的类的编号。
*/
#include <iostream>
using namespace std;
#include<string>

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int flag = 0;
	if (s1.size() == s2.size())
	{
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] != s2[i])//相同位置上的字符不相等
			{
				if (s1[i] - s2[i] == 32 || s2[i] - s1[i] == 32)//可以大小写相互替换
				{
					flag = 1;
				}
				else
				{
					cout << "4" << endl;
					return 0;
				}
				
				
			}
		}
		if (flag == 1)
		{
			cout << "3" << endl;
		}
		else
		{
			cout << "2" << endl;
		}
	}
	else
	{
		//字符串长度不相等
		cout << "1" << endl;
	}
	return 0;
}
#endif


#if 0
//字符串拼接
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	string s3 = s1 + s2;
	cout << s3 << endl;
	return 0;
}

#endif

#if 0
//回形取数
#include<iostream>
#include<string.h>
#define N 205

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	int res[N][N];
	int a[N][N];

	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			cin >> a[i][j];

	memset(res, 1, sizeof(res));

	//方法，首先第一个为0，代表走过的，判断下一次要走的方向的格子是否为1，
	//如果为1，就将下一个格子置为1，对于蛇形来说+1 -1 代表着方向，但是只改变当前的状态，
	//就会导致存在某一个点最后永远无法到达，因为到了那个点，但是他的下一个位置却是走过的 
	int i = 0, j = 0, ct = 0;
	res[0][0] = 0;
	cout << a[0][0] << " ";

	while (ct<n*m - 1){
		while (i<n - 1 && res[i + 1][j] != 0) {

			i++;
			cout << a[i][j] << " ";
			res[i][j] = 0;
			ct++;
		}
		while (j<m - 1 && res[i][j + 1] != 0){
			j++;
			cout << a[i][j] << " ";
			res[i][j] = 0;
			ct++;
		}
		while (i>-1 && res[i - 1][j] != 0 && i - 1 >= 0) {
			i--;
			cout << a[i][j] << " ";
			res[i][j] = 0;
			ct++;
		}
		while (j>-1 && res[i][j - 1] != 0 && j - 1 >= 0){
			j--;
			res[i][j] = 0;
			cout << a[i][j] << " ";
			ct++;
		}
	}

	return 0;
}

#endif

#if 0
////回形取数
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n, m;
	cin >> n >> m;
	int i, j;
	vector<vector<int>> v;
	v.resize(n);
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i].resize(n);
		for (size_t j = 0; j < v[i].size(); j++)
		{
			cin >> v[i][j];
		}
	}

	for (i = 0; i < (n + 1) / 2 && i < (m + 1) / 2; i++)//这里的i代表全书，循环的次数i小于行数的一半且小于列数的一半
	{
		for (j = i; j < n - i; j++)//向下输出
		{
			if (i == 0 && j == 0)
			{
				cout << v[j][i];
			}
			else
			{
				cout << " " << v[j][i];
			}
			
		}

		for (j = i + 1; j < m - i; j++)//向右输出
		{
			cout << " " << v[n - i - 1][j];
		}

		/*当m为奇数时最后一次循环只有左一列的数据。
		每进一次循环都读了对称的两列数据，前面i-1次循环读了2i个数据（i从0开始）在这次判断之前又读了一列数据
		所以判断有没有对称的右列数据只要判断m-2*i-1是否大于0（等价于m - i - 1 > i） ,下同 */
		if (m - i - 1 > i)
		{
			for (j = n - i - 2; j >= i; j--)//向上输出
				cout << " " << v[j][m - i - 1];
		}

		if (n - i - 1 > i)
		{
			for (j = m - i - 2; j > i; j--)//向右输出
				cout << " " << v[i][j];
		}
	}

	return 0;
}

#endif

#if 0
//1221是一个非常特殊的数，它从左边读和从右边读是一样的，编程求所有这样的四位十进制数。
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					if (i == l && j == k) {
						cout << i << j << k << l << endl;
						/*System.out.println("" + i + j + k + l);*/
					}
				}
			}
		}
	}
	return 0;
}
#endif

#if 0

//　求出区间[a,b]中所有整数的质因数分解。
#include <iostream>
#include <vector>
using namespace std;

//判断是否是质数
bool IsPrime(int n)
{
	int i;
	for (i = 2; i <= n / 2; i++)
	{
		if (n%i == 0)
			return false;
	}

	if (i > n / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	vector<int> v;//存储这个区间的所有质数
	int a, b;
	cin >> a;
	cin >> b;
	for (int i = 2; i <= b; i++)
	{
		if (IsPrime(i))
		{
			v.push_back(i);
		}
	}

	for (int i=a; i <= b; ++i)
	{
		if (IsPrime(i))//是质数的话，直接输出
		{
			cout << i << "=" << i;
		}
		else
		{
			cout << i << "=";
			int tmp = i;
			int index = 0;//存储质数的数组下标
			while (tmp != 1)//当前数字没有被除尽时继续
			{
				if (tmp%v[index] == 0)//从第一个质数开始除
				{
					cout << v[index];
					tmp /= v[index];

					index = 0;//还原数组下标从一个数组中的值
					if (tmp != 1)
						cout << "*";
				}
				else//不能整除的话尝试下一个质数
				{
					index++;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

#endif


#if 0
//n皇后问题
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[8][8];//记录不同位置的权值：是否可以放皇后
int location[8];//记录每行放皇后的位置标记（每行的哪一列）
int maxn = -1;//多少种方法

//rows:总共放了多少行
//colimns:这一行放皇后的列下标
int valid(int rows, int columns)//剪枝函数
{
	for (int i = 0; i < rows; i++)
	{
		//判断是否在同一列或是对角线
		if (columns == location[i] || abs(rows - i) == abs(columns - location[i]))
			return 0;
	}
	return 1;
}
void Queue(int row)//回溯函数
{
	if (row == 8)
	{
		int current_max = 0;
		for (int i = 0; i < 8; i++)
		{
			current_max += num[i][location[i]];
		}
		maxn = max(current_max, maxn);
	}
	else
	{
		for (int n = 0; n < 8; n++)//当前行放皇后的列下标
		{
			if (valid(row, n))
			{
				location[row] = n;
				Queue(row + 1);
			}
		}
	}
}
int main()
{
	int k;
	cin >> k;
	//while (k--)
	//{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> num[i][j];
			}
		}
		Queue(0);
		cout << maxn << endl;
	//}
		return 0;
}
#endif

#if 0
//2n皇后问题
#include <iostream>
#include <cmath>
using namespace std;
int board[8][8];
int all = 0;
int black_location[8];//记录每行放皇后的列下标
int white_location[8];

//rows:总共放了多少行
//colimns:当前行放皇后的列下标
int w_valid(int rows, int columns)//剪枝函数
{
	for (int i = 0; i < rows; i++)
	{
		//判断当前行是否和前面的皇后在一列 或者 是对角线
		if (columns == white_location[i] || abs(rows - i) == abs(columns - white_location[i]))
		{
			return 0;
		}
	}
	return 1;
}

int b_valid(int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		if (columns == black_location[i] || abs(rows - i) == abs(columns - black_location[i]))
		{
			return 0;
		}
	}
	return 1;
}

//cur :当前行 n:总共的行数
void Queen_b(int cur, int n)
{
	if (cur == n)
		all++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			//这个位置有了白皇后并且可以不能放皇后
			if (i == white_location[cur] || board[cur][i] == 0)
				continue;
			else
			{
				if (b_valid(cur, i))
				{
					black_location[cur] = i;
					Queen_b(cur + 1, n);//计算下一行
				}
			}
		}
	}
}

void Queen_w(int cur, int n)
{
	if (cur == n)
	{
		Queen_b(0, n);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (board[cur][i] == 0)//当前位置不能插入
				continue;
			if (w_valid(cur, i))
			{
				white_location[cur] = i;//记录当前行可以放皇后的列下标
				Queen_w(cur + 1, n);//计算下一行
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int h = 0; h < n; h++)
		{
			cin >> board[i][h];
		}
		
	}
	Queen_w(0, n);
	cout << all;
	return 0;
}

#endif

#if 0
//报时助手
#include <iostream>
#include <string>
using namespace std;

string n[100] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
"twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
"thirty", "forty", "fifty" };

void ass(int num)
{
	int a = num / 10;
	int b = num % 10;

	if (num <= 20)
	{
		cout << n[num];
	}
	else
	{
		cout << n[a + 18];
		if (b != 0)
		{
			cout << " " << n[b];
		}
	}
}
void time_ass(int hour, int minu)
{
	if (minu == 0)
	{
		ass(hour);
		cout << "o'clock" << endl;
	}
	else
	{
		ass(hour);
		cout << " ";
		ass(minu);
		cout << endl;
	}
}
int main()
{
	int h, m;
	cin >> h >> m;
	time_ass(h, m);
	return 0;
}
#endif

#if 0
//判断闰年
#include <iostream>
using namespace std;
int main()
{
	int year;
	cin >> year;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
	return 0;
}
#endif

#if 0
//特殊回文数
#include <iostream>
using namespace std;
int main()
{
	long i;
	int n;
	int a, b, c, d, e, f;
	cin >> n;
	for (i = 10000; i < 10000; i++)
	{
			a = i % 10;//个
			b = i / 10 % 10;//十
			c = i / 100 % 10;//百
			d = i % 1000 % 10;//千
			e = i / 10000 ;//万

			if (a == e&&b == d&&a + b + c + d + e == n)
				cout << i << endl;
	 }
	for (i = 100000; i < 1000000; i++)
	{
		a = i / 100000 % 10;
		b = i / 10000 % 10;
		c = i / 1000 % 10;
		d = i / 100 % 10;
		e = i / 10 % 10;
		f = i % 10;

		if (a == f&&b == e&&c == d&&a + b + c + d + e + f == n)
			cout << i << endl;
	}
		
	return 0;
}
#endif

#if 0
//时间转换
#include <iostream>
using namespace std;
int main()
{
	int t, h, m, s;
	cin >> t;
	h = t / 3600;
	t %= 3600;
	m = t / 60;
	t %= 60;
	s = t;
	cout << h << ":" << m << ":" << s;
	return 0;
}
#endif

#if 0
//算法训练 相邻数对
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	int n,res=0;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++)
	{
		if ((v[i + 1] - v[i]) == 1)
			res++;
	}
	cout << res;
	return 0;
}
#endif
