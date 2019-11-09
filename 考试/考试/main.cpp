#include<iostream>
using namespace std;
#include<string>
#if 0
int main()
{
	string s;
	cin >> s;
	int j = 0;;
	int a[256] = { 0 };
	for (size_t i = 0; i < s.size(); i++)
			{
					a[s[i]]++;
					if (a[s[i]] == 1)
					{
						j++;
						cout << s[i];
					}
						
			}
	s[j] = '\0';
	

//	//for (size_t i = 0; i < s.size(); i++)
//	{
//		a[s[i]]++;
//	}
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		while (s[i] && a[s[i]] == 1)
//			cout << s[i];
//	}
//*/
	return 0;
}
#endif

#if 0
int main()
{
	string s;
	cin >> s;

	for (size_t i = 0; i < s.size(); i++)
	{

		for (size_t j = i+1; j < s.size(); j++)
		{
			if (s[j] == s[i])
			{
				s.erase(j);
			}
		}


	}

	cout << s;
	system("pause");
	return 0;
}

#endif

#if 0
#include<iostream>
using namespace std;
#include<string>

int main()
{
	string str("abcd1234ed125ss12345678");
	string str2;
	int count1 = 0, count2 = 0;
	int flag = 1;
	//cin >> str;
	auto it = str.begin();
	auto start1 = str.begin();

	while (it != str.end())
	{
		if ((*it <= '9'&&*it >= '0') && flag)
		{
			while (*it <= '9'&&*it >= '0'&&it!=str.end())
			{
				count1++;
				str2 += *it;
				it++;
			}
			flag = 0;
		}

		if ((*it <= '9'&&*it >= '0') && !flag)
		{
			count2 = 0;
			start1 = it;
			while (it != str.end()&&*it <= '9'&&*it >= '0')
			{
					it++;
					count2++;
			}
		}
		if (count1 < count2)
		{
			str2.erase(str2.begin(), str2.end());
			while (start1!=str.end()&&*start1<='9'&&*start1>='0')
			{
				str2 += *start1;
				start1++;
			}
		}
		if (it == str.end())
			break;
	   it++;
	}
	cout << str2 << endl;
	return 0;
}

#endif
#if 0
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string s1("abcd1234ed125ss12345678");
	string s2;
	for (size_t i = 0; i < s1.size(); i++)
	{
		while (s1[i] <= '9'&&s1[i] >= '0'&&i<s1.size())
		{
			int count1 = 0;
			s2 += s1[i];
			count1++;
			i++;
		}
	}
	
	return 0;
}
#endif

#if 0
#include<vector>
int Func(vector<int> v, int num)
{
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == num)
			count++;
	}
	return count;
}
int main()
{
	vector<int> v{ 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int res = v[0];
	for (int i=0; i < v.size(); i++)
	{
		int count=Func(v, v[i]);
		count >= v.size()/2 ? res = v[i] : res = 0;
	}
	cout << res;

	return 0;
}
#endif

#if 0
//数组中出现次数超过一半的数字
#include<vector>
class Solution {
public:
	size_t Func(vector<int> v, int num)
	{
		size_t count = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i] == num)
				count++;
		}
		return count;
	}
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int res = numbers[0];
		for (size_t i = 0; i < numbers.size(); i++)
		{
			size_t count = Func(numbers, numbers[i]);
			count >= numbers.size() / 2 ? res = numbers[i] : res = 0;
		}
		cout << res << endl;
		return res;

	}
};
#endif

#if 0
//找数组次数超过一半的数
#include<iostream>
using namespace std;
#include<vector>
size_t Func(int* v, int val,int num)
{
	size_t count = 0;
	for (size_t i = 0; i < num; i++)
	{
		if (v[i] == val)
			count++;
	}
	return count;
}
int main()
{
	int num;
	cin >> num;
	int *arr=new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	
	int res = arr[0];
	for (size_t i = 0; i < num; i++)
	{
		size_t count = Func(arr, arr[i],num);
		count >= num/ 2 ? res = arr[i] : res = -1;
	}
	cout << res << endl;
	return 0;
}
#endif

#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int m=7, n=2;
	//cin >> m >> n;
	int count = 1;
	vector<int> v;
	while (m%n)
	{
		v.push_back(m % (n*count));
		count++;
		m = m - m%n;
	}
	return 0;
}