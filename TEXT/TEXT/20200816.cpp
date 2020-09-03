#if 0
//字符串--移除k个数，使剩下的数字是所有可能中最大的
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

//看高楼层数--错误
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
		//判断前部分
		if (i != 0)
		{
			//result[i]++;
			int j = i;
			//int pre = v[j - 1];//保存前面的值
			//int maxpre = pre;//前面的最大值
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
		//判断后部分
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