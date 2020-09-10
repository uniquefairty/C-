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

