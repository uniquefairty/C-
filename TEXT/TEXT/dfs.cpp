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

#if 1
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

