#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>


string Fun(string str)
{
	string countstr;
	int count = 0;
	int i = 0;
	int j = str.size() - 1;
	while (str[i] != '[')
	{
		i++;
	}
	int pos = i;
	while (str[j] != ']')
	{
		j--;
	}
	i++;
	while (str[i] != '|')
	{
		countstr += str[i];
		i++;
	}
	str.erase(pos, i - pos + 1);
	count = atoi(countstr);
	string res = str.substr(i + 1, j - i - 1);
	str.insert(pos, res, res.size())
		return res;

}
int main()
{
	string str;
	cin >> str;



}