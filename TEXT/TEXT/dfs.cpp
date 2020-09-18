////0-1背包问题
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//bool fun(vector<vector<int>> v, int path_length, int total, vector<vector<bool>> visited, int i, int j, int idx)
//{
//	if (path_length == total)
//		return true;
//
//	bool hasPath = false;
//	int result = 0;
//	if (i < 0 || j < 0 || i == v.size() || j == v[0].size(
//		|| visited[i][j]))
//		return false;
//
//	result = fun(board,word,b1)
//}
//int main()
//{
//	vector<vector<int>> v;
//	int m, n, x1, y1, x2, y2;
//	while (cin >> m >> n >> x1 >> y1 >> x2 >> y2)
//	{
//		if (m < 0 || n < 0)
//			cout << 0 << endl;
//
//		int total = m*n;
//		vector<vector<int>> ret(m,vector<bool> (n,1));
//		//vector<vector<int>> v(m, vector<bool>(n, 1));
//		for (int i = x1; i < m; i++)
//		{
//			for (int j = y2; j < n; ++j)
//			{
//				ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
//			}
//		}
//
//
//
//		return ret[x2][y2];
//
//	}
//
//	
//	return 0;
//}

#if 0
//小鼠寻路
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int L, M;
	while (cin >> L >> M)
	{
		vector<int> v;
		v.resize(M);
		for (int i = 0; i<v.size(); i++)
		{
			cin >> v[i];
		}

		int max = v[0], index = 0;
		for (int i = 1; i<v.size(); i++)
		{
			if (v[i]>max)
			{
				index = i;
			}
		}
		int sum = max*M*L;
		int tmp = 0;
		for (int i = 0; i<L; i++)
		{
			tmp = v[i] * M;
		}
			
		int res = sum - tmp;
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v;
		vector<vector<string>> tmp;
		v.resize(n);
		tmp.resize(n);
		string str = "";
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				getchar();
			}

			getline(cin, v[i]);

		}

		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				if (v[i][j] == ' ')
				{
					tmp[i].push_back(str);
					str = "";
				}
				str.push_back(v[i][j]);
			}
			tmp[i].push_back(str);
			str = "";
		}

		string res = "";
		for (int i = 0; i < tmp.size(); i++)
		{
			for (int j = 0; j < tmp[i].size(); j++)
			{
				res += tmp[i][j];
				res += '-';
			}
		}

	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//vector<vector<int>> subsets(vector<int> & S, int idx,int n)
//{
//	vector<vector<int>> result;
//	if (idx == n)
//	{
//		vector<int> tmp;
//		result.push_back(tmp);
//	}
//	else
//	{
//		vector<vector<int>>vec = subsets(S, idx + 1, n);
//		int a = S[idx];
//		for (int i = 0; i < vec.size(); i++)
//		{
//			vector<int> v = vec[i];
//			result.push_back(v);
//			v.push_back(a);
//			sort(v.begin(), v.end());
//			result.push_back(v);
//		}
//	}
//	return result;
//}
//vector<vector<int>> subsets(vector<int> & S, vector<int> & temp, int level, vector<vector<int>> result)
//{
//	if (level == S.size())
//	{
//		result.push_back(temp);
//		return;
//	}
//	subsets(S, temp, level+1, result);
//	temp.push_back(S[level]);
//	subsets(S, temp, level+1, result);
//
//}
void fun(vector<int>& arr, int len,int loc,vector<vector<int>>& res,vector<int> v)
{
	if (loc == len)
	{
		res.push_back(v);
		return;
	}
	fun(arr, len, loc + 1, res, v);
	v.push_back(arr[loc]);
	fun(arr, len, loc + 1, res, v);
}
int main()
{
	vector<int> arr;
	int val = 0;
	while (1)
	{
		vector<vector<int>> res;
		while (cin >> val)
		{
			if (getchar() == '\n')
			{
				break;
			}
			arr.push_back(val);
			val = 0;
		}
		arr.push_back(val);
		
		for (int i = 0; i <arr.size(); i++)
		{
			vector<int> v;
			v.push_back(arr[i]);
			fun(arr, arr.size(), i + 1, res, v);
		}

		int max = 0;
		int all = 0;
		for (int i = 0; i < res.size(); i++)
		{
			all = 0;
			for (int j = 0; j < res[i].size(); j++)
			{
				all += res[i][j];
			}
			if (all % 7 == 0)
			{
				if (all > max)
				{
					max = all;
				}
			}
		}
		if (max == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << max << endl;
		}

	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool fun(vector<int> a, vector<int> b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}
int same(vector<vector<int>> a,int index,int& res)
{
	res = index;
	for (int i = 0,j=index/2; i < index / 2; i++,j++)
	{
		if (!fun(a[i], a[j]))
		{
			return res;
		}
	}
	same(a, index / 2,res);
	return res;
	
	
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int pos = 0;
		vector<vector<int>> v;
		v.resize(m);
		for (int i = 0; i < m; i++)
		{
			v[i].resize(n);
			for (int j = 0; j < n; j++)
			{
				cin >> v[i][j];
			}		
		}
		pos=same(v, v.size(),pos);
		pos = pos / 2;
		for (int i = 0; i < pos; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << v[i][j] << ' ';
			}
			cout << endl;
		}
	

	}
	return 0;
}
#endif

#if 0

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool fun(vector<int> v, int m, int k, int index)
{
	while (m)
	{
		if (v[index] < k)
		{
			return false;
			break;
		}
		index++;
		m--;
	}
	return true;
}
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<int> v;
		v.resize(n);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i < n; i++)
		{
			int count = m;
			int j = i;
			int flag = 1;
			while (j < n && count)
			{
				if (v[j] < k)
				{
					flag = 0;
					break;
					
				}
				j++;
				count--;
				
			}
			if (!count&&flag == 1)
			{
				res += 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int find_max(vector<int> v, vector<bool>& visit)
{
	int pos = 0;
	int max = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > max && visit[i])
		{
			max = v[i];
			pos = i;
		}
	}
	visit[pos] = false;
	return pos;
}
int find_second(vector<int>v, vector<bool> visit)
{
	find_max( v, visit);
	return find_max(v, visit);
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> v;
		v.resize(2);
		for (int i = 0; i < 2; i++)
		{
			v[i].resize(n);
			for (int j = 0; j < n; j++)
			{
				cin >> v[i][j];
			}
		}

		vector<bool> visit(n, true);
		//排序
		while (n)
		{
			int index = find_max(v[1], visit);
			int pos = find_second(v[1], visit);
			cout << index + 1 << ' ';
			n--;

		}
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;
string fun(string str, int i, int n)
{
	string res = "";
	int j = i+n;
	while (n)
	{
		res += str[j-1];
		j--;
		n--;
	}
	return res;
}
int main()
{
	int n;
	string str;
	while (cin >> n)
	{
		getchar();
		getline(cin, str);
		string res = "";
		int i = 0;
		for (; i < str.size();)
		{
			if ((i + n) < str.size())
			{
				res+=fun(str, i, n);
				i = i + n;
			}
			else
			{
				break;
			}
		}
		if (i != str.size())
		{
			for (int j = str.size() - 1; j >= i; j--)
			{
				res += str[j];
			}
		}
		
		cout << res << endl;
	
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int> > RotateMatrix(vector<vector<int> >& matrix) {
	// write code here
	vector<vector<int> > result;
	result.resize(matrix[0].size());
	int ii = 0, jj = 0;
	for (int j = matrix[0].size() - 1; j >= 0; j--)
	{
		result[ii].resize(matrix.size());
		for (int i = 0, jj = 0; i<matrix.size(); i++)
		{
			result[ii][jj] = matrix[i][j];
			jj++;
		}
		ii++;
	}
	return result;
}
int main()
{

	vector<vector<int> > matrix = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	RotateMatrix(matrix);
	return 0;
}
#endif


//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//int main()
//{
//	string str1,str2;
//	str1 = "abccade";
//	str2 = "dgcadde";
//	int length = 0;
//	string res = "";
//	for (int i = 0; i < str1.size(); i++)
//	{
//		int pos = str2.find(str1[i]);
//		int j = i;
//		if (pos != string::npos)
//		{
//			while (pos < str2.size() && j < str1.size())
//			{
//				string tmp = "";
//				while (str2[pos] == str1[j])
//				{				
//					tmp += str1[j];
//					pos++;
//					j++;
//				}
//				if (tmp.size() > res.size())
//				{
//					res = tmp;
//				}
//
//			}
//		}
//
//	}
//	cout << res << endl;
//	return 0;
//}


#if 0
string GetCommon(string str1, string str2) {
	// write code here
	vector<vector<int>> record(str1.size(), vector<int>(str2.length()));
	int maxlen = 0, maxend = 0;
	for (int i = 0; i<str1.size(); i++)
	{
		for (int j = 0; j<str2.size(); j++)
		{
			if (str1[i] == str2[j])
			{
				if (i == 0 || j == 0)
				{
					record[i][j] = 1;
				}
				else
				{
					record[i][j] = record[i - 1][j - 1] + 1;
				}
			}
			else{
				record[i][j] = 0;
			}

			if (record[i][j]>maxlen)
			{
				maxlen = record[i][j];
				maxend = i;
			}
		}
		return str1.substr(maxend - maxlen + 1, maxlen);
	}
}
#endif

# if 0
#include <iostream>
#include <string>
#include <vector>

using namespace std;
string GetCommon(string str1, string str2) {
	// write code here
	vector<vector<int>> record(str1.size(), vector<int>(str2.length()));
	int maxlen = 0; maxend = 0;
	for (int i = 0; i<str1.size(); i++)
	{
		for (int j = 0; j<str2.size(); j++)
		{
			if (str1[i] == str2[j])
			{
				if (i == 0 || j == 0)
				{
					record[i][j] = 1;
				}
				else
				{
					record[i][j] = record[i - 1][j - 1] + 1;
				}
			}
			else{
				record[i][j] = 0;
			}

			if (record[i][j]>maxlen)
			{
				maxlen = record[i][j];
				maxend = i;
			}
		}
		return str1.substr(maxend - maxlen + 1, maxlen);
	}
}
#endif

#if 0
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#pragma pack(2)
int main()
{
	struct u
	{
		int mid;
		char gender;
		int c[4];
	};
	cout << sizeof(u) << endl;
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		string res = "";
		int count = 0;
		for (int i = 0; i<str.size();)
		{
			res += str[i];
			res += '_';
			i++;
			count = 1;
			if (str[i] != str[i - 1])
			{
				res += count+'0';
				res += '_';
				//i++;
				continue;
				
			}

			while (i<str.size() && str[i] == str[i - 1])
			{
				count++;
				i++;
			}
			res += count+'0';
			if (i != str.size())
			{
				res += '_';
			}
			
		}

		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr)
	{}
};

ListNode* fun(ListNode* pHead1, ListNode * pHead2)
{
	if (pHead1 == nullptr)
	{
		return pHead2;
	}
	if (pHead2 == nullptr)
	{
		return pHead1;
	}

	if (pHead1->val <= pHead2->val)
	{
		pHead1->next = fun(pHead1->next, pHead2);
			return pHead1;
	}
	else
	{
		pHead2->next = fun(pHead1, pHead2->next);
		return pHead2;
	}
}
int main()
{
	int n,m;
	while (cin >> n)
	{
		ListNode *pHead1 = new ListNode(0);
		ListNode *p1 = pHead1;
		while (n--)
		{
			int tmp;
			cin >> tmp;
			ListNode *Node = new ListNode(tmp);
			p1->next = Node;
			p1 = Node;
		}

		cin >> m;
		ListNode *pHead2 = new ListNode(0);
		ListNode *p2 = pHead2;
		while (m--)
		{
			int tmp;
			cin >> tmp;
			ListNode *Node = new ListNode(tmp);
			p2->next = Node;
			p2 = Node;
		}

		ListNode* head=fun(pHead1->next, pHead2->next);
		while (head)
		{
			cout << head->val ;
			if (head->next != nullptr)
			{
				cout << ' ';
			}
			head = head->next;
		}

	}


	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		if (str.size() == 0)
		{
			cout << "true" << endl;
			continue;
		}

		if (str.size() % 2 != 0)
		{
			cout << "false" << endl;
			continue;
		}
		stack<int> s;
		int flag = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				s.push(str[i]);
			}
			else
			{
				char c = s.top();
				char m;
				if (c == '(')
					m = ')';
				if (c == '[')
					m = ']';
				if (c == '{')
					m = '}';

				if (str[i] != m)
				{
					cout << false << endl;
					flag = 1;
					break;
				}
				else
				{
					s.pop();
				}
			}	
		}
		if (flag)
		{
			cout << "false" << endl;
		}
		else
		{
			cout << "true" << endl;
		}

	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main()
{
	string str;
	while (getline(cin,str))
	{
		int visit[256] = { 0 };
		string res = "";
		for (int i = 0; i < str.size(); i++)
		{
			if (visit[str[i]] == 0)
			{
				res += str[i];
				visit[str[i]] =1;
			}
		}
		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		if (str.size() == 0)
		{
			cout << "true" << endl;
			continue;
		}

		if (str.size() % 2 != 0)
		{
			cout << "false" << endl;
			continue;
		}
		stack<char> s;
		int flag = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				s.push(str[i]);
			}
			else
			{
				char c = s.top();
				char m;
				if (c == '(')
					m = ')';
				if (c == '[')
					m = ']';
				if (c == '{')
					m = '}';

				if (str[i] != m)
				{
					cout << false << endl;
					flag = 1;
					break;
				}
				else
				{
					s.pop();
				}
			}
		}
		if (!s.empty())
		{
			flag = 1;
		}
		if (flag)
		{
			cout << "false" << endl;
		}
		else
		{
			cout << "true" << endl;
		}

	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main()
{
	string str;
	stack<char> s;
	while (cin>>str)
	{
		
		while (!s.empty())
		{
			s.pop();
		}
		if (str.empty())
		{
			cout << "true" << endl;
			continue;

		}
		
		int flag = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				s.push(str[i]);
			}
			else
			{
				if (s.empty())
				{
					flag = 0;
					break;
				}
				char c = s.top();
				s.pop();
				if (str[i] == ')' && (c == '[' || c == '{'))
				{
					flag = 1;
					break;
				}
				else if (str[i] == ']' && (c == ')' || c == '}'))
				{
					flag = 1;
					break;
				}
				else if (str[i] == '}' && (c == ')' || c == ']'))
				{
					flag = 1;
					break;
				}
			}
		}
		if (!s.empty())
			flag = 1;
		if (flag)
		{
			cout << "false" << endl;
		}
		else
		{
			cout << "true" << endl;
		}

	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
#define DECLARE(name,type)type name##_##type##_type

int main()
{
	cout << DECLARE(val, int) << endl;
	return 0;
}
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool fun(vector<vector<int>> pv, vector<int> line)
{
	int posi = 0, posj = 0;
	for (int i = 0; i < pv.size(); i++)
	{
		if (pv[i][0] == line[0] && pv[i][1] == line[1])
		{
			return true;
		}
	}

	return false;

}
bool self(vector<vector<int>> v, int line,vector<vector<int>> pv)
{
	int data = v[line][0];
	int tmp = v[line][1];
	int same1,same2;
	int i = 0,j=0;

	for (i = 0; i < v.size() && i != line; i++)
	{
		if (v[i][0] == data)
		{
			same1 = v[i][1];
			break;
		}
		
	}

	if (i == v.size())
		return false;

	for (j = 0; j < v.size() && j != line; j++)
	{
		if (v[j][1] == tmp)
		{
			same2 = v[j][0];
			break;
		}
	}

	if (same1 == same2&&fun(pv, v[i]) && fun(pv,v[j]))
		return true;
	else
	{
		return false;
	}


}
int main()
{
	int n, m, q;
	while (cin >> n >> m >> q)
	{
		vector<vector<int>>  pv;
		pv.resize(m);
		for (int i = 0; i<m; i++)
		{
			pv[i].resize(2);
			for (int j = 0; j<2; j++)
			{
				cin >> pv[i][j];
			}
			sort(pv[i].begin(), pv[i].end());
		}
		vector<vector<int>>  v;
		v.resize(q);
		for (int i = 0; i<q; i++)
		{
			v[i].resize(2);
			for (int j = 0; j<2; j++)
			{
				cin >> v[i][j];
			}
			sort(v[i].begin(),v[i].end());
		}

		for (int i = 0; i < v.size(); i++)
		{
			if (fun(pv, v[i]))
			{
				cout << "YES" << endl;
			}
			else
			{
				if (self(v, i,pv))
				{
					cout << "YES" << endl;
				}
				else
				{
					cout << "NO" << endl;
				}
			}
			
		}


	}
	return 0;
}