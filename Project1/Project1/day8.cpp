#if 0
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

bool Fun(string str1, string str2, int i)
{
	for (int j = 1; j<str2.size(); j++)
	{
		if (str1[i + 1] == str2[j])
		{
			i++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string str1, str2;
	int count;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		if (str1 == str2)
			return 0;
		count = 0;
		for (int i = 0; i<str1.size(); i++)
		{
			if (str1[i] == str2[0])
			{
				if (Fun(str1, str2, i))
				{
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}
#endif



#if 0
//·ÖÆ»¹û
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	vector<int> v;
	int n;
	while (cin >> n)
	{
		v.resize(n);
		int sum = 0;
		int result = 0;
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
			sum += v[i];
		}
		int avg = sum / n;

		for (int i = 0; i<n; i++)
		{
			if (v[i]>avg)
			{
				int t = v[i] - avg;
				result += (t + 1) / 2;
			}
		}
		cout << result << endl;
	}
	return 0;
}
#endif

