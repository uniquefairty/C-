#if 0
#include <iostream>
#include <vector>
using namespace std;
void FunEnd(vector<int>& v, int index)//��index��Ԫ�طŵ����
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
	int res = 0;//��������
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

//�������
//����һ����a0�����������������a1, a2, ...an��
//
//1���ӱ�����[0, a0]�еȸ������ѡ��һ������k0����a1 = a0 - k0��
//
//2���õ������a1֮���ٴӱ�����[0, a1]�еȸ������ѡ��һ������k1������ a2 = a1 - k1��
//
//3��һ��أ��õ������ai֮���ٴӱ�����[0, ai]�еȸ������ѡ��һ������ki����ai + 1 = ai - ki��
//
//��an = 0�ĸ����Ƕ��� ?
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
