#if 0
//查找第k个小数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, k;
	while (cin >> n)
	{
		int t = 0;
		vector<int> v;
		v.resize(n);
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}
		cin >> k;
		int res = v[0];
		sort(v.begin(), v.end());

		for (int i = 0; i<n-1; i++)
		{
			if (v[i + 1] != v[i])
			{
				res = v[i];
				t++;
			}

			if (k == t)
				break;
		}
		cout << res << endl;
	}
	return 0;
}
#endif
