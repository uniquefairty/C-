#if 0
//�ַ���--�Ƴ�k������ʹʣ�µ����������п���������
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
//����¥����--����
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
		//�ж�ǰ����
		if (i != 0)
		{
			//result[i]++;
			int j = i;
			//int pre = v[j - 1];//����ǰ���ֵ
			//int maxpre = pre;//ǰ������ֵ
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
		//�жϺ󲿷�
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
1.ѹ���㷨
//СQ��Ҫ���������ѷ���һ�������ַ����������������ַ����Ĺ��ڳ��ˣ�
//����СQ������һ��ѹ���㷨���ַ������ظ��Ĳ��ֽ�����ѹ����
//�����ַ�����������m����ͬ�ַ���S����ѹ��Ϊm | S��
//�����ַ���ABCABCABC���ᱻѹ��Ϊ[3 | ABC]������СQ��ͬѧ�յ���СQ���͹������ַ��������ܰ��������н�ѹ��ô��
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
			reverse(tmp.begin(), tmp.end());//tmp�ظ����ַ���

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


