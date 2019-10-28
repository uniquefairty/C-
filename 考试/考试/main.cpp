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