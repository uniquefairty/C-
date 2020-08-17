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
