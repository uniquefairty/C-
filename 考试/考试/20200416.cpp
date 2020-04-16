#if 0
#include <iostream>
#include <vector>
using namespace std;
void FunEnd(vector<int>& v, int index)//将index的元素放到最后
{
	int tmp = v[index];
	for (int i = 1; i < v.size()-1; i++)
	{
		v[i] = v[i + 1];
	}
	v[v.size() - 1] = v[index];
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v;
	v.resize(n);
	for (size_t i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	int res = 0;//比赛次数
	int flag = 0;

	while (res != m)
	{
		if (v[0] > v[1])
		{
			res++;
			if (res == m)
				break;
			FunEnd(v, 1);
		}
		else
		{
			FunEnd(v, 0);
			res = 0;
		}
	}

	cout << res;
	return 0;
}

#endif

//随机减法
//给定一个数a0，定义如下随机序列a1, a2, ...an。
//
//1、从闭区间[0, a0]中等概率随机选出一个整数k0，令a1 = a0 - k0。
//
//2、得到随机数a1之后，再从闭区间[0, a1]中等概率随机选出一个整数k1，再令 a2 = a1 - k1。
//
//3、一般地，得到随机数ai之后，再从闭区间[0, ai]中等概率随机选出一个整数ki，令ai + 1 = ai - ki。
//
//问an = 0的概率是多少 ?
//#include <iostream>
//#include <vector>
//#include <time.h>
//using namespace std;
//int main()
//{
//	int n, val;
//	cin >> n >> val;
//	int res = val;
//	int count = 0;
//	int total = n;
//	srand((unsigned int)time(NULL));
//
//	while (n--)
//	{
//		int k=rand() % val;
//		cout << k << " " << val << endl;
//		res = val - k;
//		if (res == 0)
//			count++;
//		val = res;
//	}
//
//	double r = count / total;
//	printf("%0.5f", r);
//	return 0;
//}

#if 0
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int main()
{
	int n, val;
	cin >> n >> val;
	int res = val;
	int count = 0;
	int total = n;
	double r = 1;
	srand((unsigned int)time(NULL));

	while (n--)
	{
		r *= (1.0 / val);
		int k = rand() % val;
		cout << k << " " << val << endl;
		res = val - k;
		if (res == 0)
			count++;
		val = res;
	}

	printf("%0.5f", r);
	return 0;
}
#endif
