#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double Fun(int x1, int y1, int x2, int y2)
{
	double res = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	res = sqrt(res);
	return res;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> v;
		v.resize(2 * n);
		for (int i = 0; i<v.size(); i++)
		{
			v[i].resize(2);
			int a, b;
			cin >> a >> b;
			v[i][0] = a;
			v[i][1] = b;
		}

		int x1, y1, x2, y2;
		double res = 0;
		for (int i = 0; i<n; i++)
		{
			for (int j = n; j<2 * n; j++)
			{
				x1 = v[i][0];
				y1 = v[i][1];
				x2 = v[j][0];
				y2 = v[j][1];
				double ans = Fun(x1, y1, x2, y2);
				if (i == 0 && j == n)
					res = ans;
				else if (res>ans)
				{
					res = ans;
				}
				
			}
		}
		printf("%.3f\n", res);

	}
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double Fun(int x1, int y1, int x2, int y2)
{
	double res = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	res = sqrt(res);
	return res;
}
int main()
{
	int count;
	while (cin >> count)
	{
		while (count)
		{
			int n;
			while (cin >> n)
			{
				vector<vector<int>> v;
				v.resize(2 * n);
				for (int i = 0; i<v.size(); i++)
				{
					v[i].resize(2);
					int a, b;
					cin >> a >> b;
					v[i][0] = a;
					v[i][1] = b;
				}

				int x1, y1, x2, y2;
				double res = 0;
				for (int i = 0; i<n; i++)
				{
					for (int j = n; j<2 * n; j++)
					{
						x1 = v[i][0];
						y1 = v[i][1];
						x2 = v[j][0];
						y2 = v[j][1];
						double ans = Fun(x1, y1, x2, y2);
						if (i == 0 && j == n)
							res = ans;
						else if (res>ans)
						{
							res = ans;
						}

					}
				}
				printf("%.3f\n", res);
			}
			count--;
		}
		break;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;
#include <queue>


int main()
{
	int count = 0;
	cin >> count;
	while (count)
	{
		int n;
		while (cin >> n)
		{
			getchar();
			vector<string> v;
			queue<int> q;
			v.resize(n);
			for (int i = 0; i<n; i++)
			{
				string s;
				getline(cin,s);
				v[i] = s;
			}
			for (int i = 0; i<v.size(); i++)
			{
				string s = v[i];
				if (s[0] == 'P'&&s[1] == 'U')
				{
					q.push(s[5] - '0');
				}
				else if (s[0] == 'P'&&s[1] == 'O')
				{
					if (q.empty())
					{
						cout << "-1" << endl;
					}
					else
					{
						q.pop();
					}
				}
				else if (s[0] == 'T')
				{
					if (q.empty())
					{
						cout << "-1" << endl;
					}
					else
					{
						cout << q.front() << endl;
					}

				}
				else if (s[0] == 'S')
				{
					cout << q.size() << endl;
				}
			}

		}
		count--;
	}

	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <stack>

int main()
{
	int n;
	while(cin >> n)
	{
		getchar();
		vector<string> v;
		stack<int> q,m;

		v.resize(n);
		for (int i = 0; i<n; i++)
		{
			string s;
			getline(cin, s);
			v[i] = s;
		}
		for (int i = 0; i<v.size(); i++)
		{
			string s = v[i];
			if (s[0] == 'a')
			{
				q.push(s[4] - '0');
			}
			else if (s[0] == 'p'&&s[1] == 'e')
			{
				//当前头部的元素
				while (!q.empty())
				{
					m.push(q.top());
					q.pop();
				}
				cout << m.top() << endl;
				while (!m.empty())
				{
					q.push(m.top());
					m.pop();
				}
			}
			else if (s[0] == 'p'&&s[1] == 'o')
			{
				//弹出队列头部元素
				while (!q.empty())
				{
					m.push(q.top());
					q.pop();
				}
				m.pop();
				while (!m.empty())
				{
					q.push(m.top());
					m.pop();
				}
			}
		}
	}
	return 0;
}

#endif


