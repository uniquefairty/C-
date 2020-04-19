#if 0
//1
#include<iostream>
using namespace std;
#include <vector>

int main()
{
	int n;
	int a, b, c;
	cin >> n;
	cin >> a >> b >> c;
	int count = 0;
	for (int num = 1; num <= n; num++)
	{
		if (num%a != 0 && num%b != 0 && num%c != 0)
		{
			count++;
		}
	}

	cout << count << endl;
		return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
#include <string>
int main()
{
	string str;
	cin >> str;
	string res;
	for (int i = 0; i<str.size(); i++)
	{
		res += (str[i] + 3);
	}
	cout << res;
	return 0;
}

#endif
#if 0
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	// n为行数，m列数
	// r为输出的行，c为输出的列
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	int store[1005][1005];
	// 所有置为0
	memset(store, 0, sizeof(store));
	// 总数
	int sum = n * m;
	int row = 0, col = 0, cnt = 1;
	store[row][col] = 1;
	while (cnt < sum)
	{
		// 向右走，直到走到头或者下一个已经走过
		while (col + 1 < m && !store[row][col + 1])
			store[row][++col] = ++cnt;
		// 向下走，直到走到头或者下一个已经走过
		while (row + 1 < n && !store[row + 1][col])
			store[++row][col] = ++cnt;
		// 向左走，直到走到头或者下一个已经走过
		while (col - 1 >= 0 && !store[row][col - 1])
			store[row][--col] = ++cnt;
		// 向上走，直到走到头或者下一个已经走过
		while (row - 1 >= 0 && !store[row - 1][col])
			store[--row][col] = ++cnt;
	}
	cout << store[r - 1][c - 1];
	return 0;
}
#endif

//#include <iostream>
//#include <cstring>
//#include <vector>
//using namespace std;
//int main() {
//	// n为行数，m列数
//	// r为输出的行，c为输出的列
//	int n, m, r, c;
//	cin >> n >> m >> r >> c;
//	vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//		v[i].resize(m);
//	int sum = n * m;
//	int row = 0, col = 0, cnt = 1;
//	store[row][col] = 1;
//	while (cnt < sum)
//	{
//		// 向右走，直到走到头或者下一个已经走过
//		while (col + 1 < m && !store[row][col + 1])
//			store[row][++col] = ++cnt;
//		// 向下走，直到走到头或者下一个已经走过
//		while (row + 1 < n && !store[row + 1][col])
//			store[++row][col] = ++cnt;
//		// 向左走，直到走到头或者下一个已经走过
//		while (col - 1 >= 0 && !store[row][col - 1])
//			store[row][--col] = ++cnt;
//		// 向上走，直到走到头或者下一个已经走过
//		while (row - 1 >= 0 && !store[row - 1][col])
//			store[--row][col] = ++cnt;
//	}
//	cout << store[r - 1][c - 1];
//	return 0;
//}
