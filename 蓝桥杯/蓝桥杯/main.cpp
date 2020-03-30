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
