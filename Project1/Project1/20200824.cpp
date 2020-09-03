//#include <iostream>
//using namespace std;
//#include <string>
//#include <cstdlib>
//
//
//string Fun(string str)
//{
//	string countstr;
//	int count = 0;
//	int i = 0;
//	int j = str.size() - 1;
//	while (str[i] != '[')
//	{
//		i++;
//	}
//	int pos = i;
//	while (str[j] != ']')
//	{
//		j--;
//	}
//	i++;
//	while (str[i] != '|')
//	{
//		countstr += str[i];
//		i++;
//	}
//	str.erase(pos, i - pos + 1);
//	count = atoi(countstr);
//	string res = str.substr(i + 1, j - i - 1);
//	str.insert(pos, res, res.size())
//		return res;
//
//}
//int main()
//{
//	string str;
//	cin >> str;
//
//
//
//}

//#if 0
//#include <iostream>
//using namespace std;
//#include <vector>;
//
//int FindStart(vector<vector<int>> v, int start, int X)
//{
//	if (start == X)
//		return 0;
//
//	int end = 0;
//	int result = 0;
//	int min = 0;
//	for (int i = 0; i<v.size(); i++)
//	{
//		result = 0;
//		if (v[i][0] == start)
//		{
//			end = v[i][1];
//			result += v[i][2];
//			FindStart(v, end, X);
//		}
//		if (result<min)
//			result = min;
//
//	}
//	return min;
//}

//void a()
//{
//
//}
//int main()
//{
//	a();
//	int N, P;
//	cin >> N >> P;
//	vector<vector<int>> v;
//	v.resize(P);
//	for (int i = 0; i<v.size(); i++)
//	{
//		v[i].resize(3);
//		for (int j = 0; j<3; j++)
//		{
//			int val = 0;
//			cin >> val;
//			v[i][j] = val;
//		}
//	}
//	int X;
//	cin >> X;
//
//	int result=FindStart(v, 0, X);
//	cout<<FindStart(v, 0, X);
//	return 0;
//
//}
//#endif


#include <iostream>
using namespace std;
#include <string>

int main()
{
	string str;
	int K;
	cin >> str;
	cin >> K;
	for (int i = 1; i<str.size(); i++)
	{
		if (str[i]<str[i - 1] || (str[i + 1]>str[i] && str[i]>str[i - 1]))
		{
			str.erase(str[i - 1]);
			K--;
			if (K == 0)
				//return str;
		}


	}
	return 0;
}