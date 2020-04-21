#if 0
#include <iostream>
using namespace std;

bool Fun1(int n)
{
	for (int i = 2; i<n; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int flag = 0;
		if (n<11)
		{
			cout << "-1";
			continue;
		}
		for (int i = 11; i <=n; i += 10)
		{
			if (Fun1(i))
			{
				flag = 1;
				cout << i << " ";
			}
		}
		if (flag == 0)
			cout << "-1";
	}
	return 0;
}
#endif


#if 0
class Solution {
public:
	/**
	*
	* @param number string×Ö·û´®
	* @return string×Ö·û´®
	*/
	string change(string number) {

		int i = 0;
		int j = number.size() - 1;
		for (; i<j; i++, j--)
		{
			while (i<j&&number[i] % 2 != 0)
				i++;
			while (i<j&&number[j] % 2 != 0)
				j--;
			char tmp = number[i];
			number[i] = number[j];
			number[j] = tmp;
		}
		return number;

	}
};
#endif
