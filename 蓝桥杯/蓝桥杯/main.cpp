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

#if 1
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

int main()
{
	return 0;
}

