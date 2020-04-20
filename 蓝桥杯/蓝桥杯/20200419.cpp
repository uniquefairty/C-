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
	// nΪ������m����
	// rΪ������У�cΪ�������
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	int store[1005][1005];
	// ������Ϊ0
	memset(store, 0, sizeof(store));
	// ����
	int sum = n * m;
	int row = 0, col = 0, cnt = 1;
	store[row][col] = 1;
	while (cnt < sum)
	{
		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
		while (col + 1 < m && !store[row][col + 1])
			store[row][++col] = ++cnt;
		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
		while (row + 1 < n && !store[row + 1][col])
			store[++row][col] = ++cnt;
		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
		while (col - 1 >= 0 && !store[row][col - 1])
			store[row][--col] = ++cnt;
		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
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
//	// nΪ������m����
//	// rΪ������У�cΪ�������
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
//		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
//		while (col + 1 < m && !store[row][col + 1])
//			store[row][++col] = ++cnt;
//		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
//		while (row + 1 < n && !store[row + 1][col])
//			store[++row][col] = ++cnt;
//		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
//		while (col - 1 >= 0 && !store[row][col - 1])
//			store[row][--col] = ++cnt;
//		// �����ߣ�ֱ���ߵ�ͷ������һ���Ѿ��߹�
//		while (row - 1 >= 0 && !store[row - 1][col])
//			store[--row][col] = ++cnt;
//	}
//	cout << store[r - 1][c - 1];
//	return 0;
//}

#if 0
//�����������
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> ans;
		if (matrix.size() == 0)
		{
			return ans;
		}

		int cir = 0;//��¼�ڼ�Ȧ
		int row = matrix.size();
		int col = matrix[0].size();
		//����Ȧ��
		int max_cir = int(min(matrix.size(), matrix[0].size()) + 1) / 2;

		for (; cir<max_cir; cir++)
		{
			for (int i = cir; i<col - cir; i++)//��
			{
				ans.push_back(matrix[cir][i]);
			}

			for (int i = cir + 1; i<row - cir; i++)//��
			{
				ans.push_back(matrix[i][col - 1 - cir]);
			}

			for (int i = col - 2 - cir; i >= cir && (row - 1 - cir != cir); i--)//��
			{
				ans.push_back(matrix[row - cir - 1][i]);
			}

			for (int i = row - 2 - cir; i>cir && (col - 1 - cir != cir); i--)
			{
				ans.push_back(matrix[i][cir]);
			}

		}
		return ans;
	}
};
#endif

