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
			while (++j&&j < v.size() - 1)
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

#include <iostream>
#include <vector>
#include <stack>
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

	stack<int> st;
	for (int i = 1; i <= n; i++)
	{
		result[i] += st.size();
		while (!st.empty() && v[i] >= st.top())
		{
			st.pop();
		}
		st.push(v[i]);
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
			while (++j&&j < v.size() - 1)
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
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	vector<int> v1, v2;

	while (cin >> n)
	{
		v1.resize(n);
		for (int i = 0; i<v1.size(); i++)
		{
			cin >> v1[i];
		}
		cin >> m;
		v2.resize(m);
		for (int i = 0; i<v2.size(); i++)
		{
			cin >> v2[i];
		}

		int *pre = &v1[0];
		int *last = &v2[0];
		while (pre&&last)
		{
			if (*pre == *last)
				cout << *pre << ' ';
			pre++;
			last++;
		}

	}
	return 0;
}
#endif


//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct Node
//{
//	int val;
//	Node* next;
//
//};
//
//int main()
//{
//	int n, m;
//	Node* pre = new Node();
//	Node *last = new Node();
//	Node *head1 = pre;
//	Node *head2 = last;
//
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			int data = 0;
//			cin >> data;
//			Node* new_node = new Node();
//			new_node->val = data;
//			pre->next = new_node;
//			pre = new_node;
//		}
//
//		cin >> m;
//		for (int i = 0; i < m; i++)
//		{
//			int data = 0;
//			cin >> data;
//			Node* new_node = new Node();
//			new_node->val = data;
//			last->next = new_node;
//			last = new_node;
//		}
//
//		head1 = head1->next;
//		head2 = head2->next;
//
//		while (head1&&head2)
//		{
//			if (head1->val == head2->val)
//			{
//				cout << head1->val << ' ';
//				head1 = head1->next;
//				head2 = head2->next;
//			}
//			else if (head1->val > head2->val)
//			{
//				head1 = head1->next;
//			}
//			else
//			{
//				head2 = head2->next;
//			}
//		}
//
//	}
//
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//int main()
//{
//	int n, k;
//	map<string, int> map;
//	vector<string> v;
//	vector<vector<string>> res;
//	while (cin >> n)
//	{
//		v.resize(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//
//		}
//		sort(v.begin(), v.end());
//		for (int i = 0; i < v.size(); i++)
//		{
//			int count = 0;
//			
//		}
//
//	}
//
//
//
//
//
//	return 0;
//}


#if 0
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	vector<int> res;
	//vector<int> tmp;
	while (cin >> n)
	{
		int pos = (n-1) / 2;
		v.resize(n);
		res.resize(n);
		for (int m = 0; m < n; m++)
		{
			for (int i = 0; i < n; i++)
			{
				cin >> v[i];
			}

			res = v;

			for (auto i = 0;i<=v.size();i++)
			{
				v = res;
				v.erase(v.begin()+i);
				sort(v.begin(), v.end());
				cout << v[pos] << endl;
			}
			

		}
		


	}
	return 0;
}
#endif

