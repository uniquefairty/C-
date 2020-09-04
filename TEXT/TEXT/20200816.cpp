#if 0
//字符串--移除k个数，使剩下的数字是所有可能中最大的
#include <iostream>
using namespace std;
#include <string>

int main()
{
	string str;
	int k;
	cin >> str>>k;

	if (k == str.length())
	{
		cout << "0" << endl;
	}
	else
	{
		while (k--)
		{
			int index = 0;
			for (; index < str.length() && str[index] < str[index + 1]; index++)
				;
			str.erase(index, 1);
		}
		
	}
	cout << str << endl;
	return 0;
}
#endif

#if 0
//看高楼层数--错误
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	vector<int> result;
	v.resize(n);
	result.resize(n, 1);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < v.size(); i++)
	{
		//判断前部分
		if (i != 0)
		{
			//result[i]++;
			int j = i;
			//int pre = v[j - 1];//保存前面的值
			//int maxpre = pre;//前面的最大值
			int maxpre = v[j];
			while (--j)
			{		
				if (v[j - 1] > maxpre)
				{
					result[i]++;
					maxpre = v[j - 1];
				}
			}

		}
		//判断后部分
		if (i != v.size())
		{
			result[i]++;
			int j = i;
			int maxafter = v[j];
			while (++j&&j < v.size()-1)
			{
				if (v[j + 1]>maxafter)
				{
					result[i]++;
					maxafter = v[j + 1];
				}
			}
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}
	return 0;
}

#endif

#if 0
1.压缩算法
//小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，
//于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，
//对于字符串中连续的m个相同字符串S将会压缩为m | S，
//例如字符串ABCABCABC将会被压缩为[3 | ABC]，现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	stack<char> st;
	string s;
	cin >> s;
	int n = s.length();

	for (int i = 0; i < n; ++i)
	{
		if (s[i] != ']')
		{
			st.push(s[i]);
		}
		else
		{
			string tmp = "";
			while (st.top() != '|')
			{
				tmp += st.top();
				st.pop();
			}
			reverse(tmp.begin(), tmp.end());//tmp重复的字符串

			string num = "";
			st.pop();
			while (st.top() != '[')
			{
				num += st.top();
				st.pop();
			}
			st.pop();
			reverse(num.begin(), num.end());
			int x = stoi(num);

			string t = "";
			while (x--)
			{
				for (char c : tmp)
					st.push(c);
			}

		}
	}
	string ans;
	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;

}
#endif


