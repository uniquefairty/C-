//#include <iostream>
//using namespace std;
//#include <vector>
////记录每张牌的个数
////尽量是顺子或数字连续的三队
//bool Double(vector<int>& v,int i)//数字i相同的牌
//{
//	if (v[i] >= 2)
//	{
//		v[1] -= 2;
//		return true;
//	}
//	return false;
//}
//
//bool Fun1(vector<int>& v,int i)//顺子
//{
//	int count = 5;
//	while (count)
//	{
//		if (v[i]>0)
//		{
//			count--;
//			i++;
//		}
//		else return false;
//	}
//	return true;
//}
//bool Fun2(vector<int>& v,int i)//连对
//{
//	int count = 3;
//	while (count)
//	{
//		if (v[i]>1)
//		{
//			count--;
//			i++;
//		}
//		else return false;
//	}
//	return true;
//}
//int main()
//{
//	vector<int> v;
//	v.resize(10);
//	int count = 0;
//	for (int i = 0; i<v.size(); i++)
//	{
//		cin >> v[i];
//	}
//
//	for (int i = 0; i<v.size(); i++)
//	{
//		if (Fun1(v,i))//顺子
//		{
//			int t = 5;
//			while (t--)
//			{
//				v[i]--;
//			}
//			count++;
//		}
//	}
//	return 0;
//}



#if 0
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
int main()
{
	int num;
	cin >> num;
	vector<string> v;
	v.resize(num);
	string maxstr;
	for (int i = 0; num; i++, num--)
	{
		string str;
		cin >> str;
		v[i] += str;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i<v.size(); i++)
	{
		maxstr += v[i];
		for (int j = 1; j<v.size(); j++)
		{

		}
	}

	return 0;
}

#endif


//int strcmp(char *source, char *dest)//比较
//{
//	int i = 0;
//	while (1)
//	{
//		if (*source == *dest)
//		{
//			source++;
//			dest++;
//		}
//		else return -1;
//	}
//	return 0;
//	
//}
//
//CComplex& operator=(const CComplex& c)
//{
//	m_real = c.mreal;
//	m_image = c.m_image;
//}

#include<stdio.h>
#include <iostream>
using namespace std;
//int main()
//{
//	unsigned  char  a = 2, b = 4, c = 5, d;
//	d = a | b;  d &= c;  
//	cout << d;
//	//printf("%d\n", d);
//}
//
//
//void sort(int& array[])
//{
//	int i = 0, j = 0;
//	for (i = 0; i < array.size() - 1; i++)
//	{
//		for (j = 0; j < array.size() - 1 - i; j++)
//		{
//			if (array[j] > array[j + i])
//			{
//				int tmp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = tmp;
//			}
//		}
//	}
//}

int bin_search(int *array, int array_size, int key)
{
	int start = 0;
	int end = array_size - 1;
	while (start < end)
	{
		int mid = (start+end) / 2;
		if (array[mid] < key)
		{
			start = mid + 1;
		}
		else if (array[mid] == key)
		{
			return mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	
}

class Card
{
public:
	Card(string name,string id,string money)
		:_name(name)
		, _id(id)
		, _money(money)
	{}
	~Card
	{ }

private:
	string _name;
	string _id;
	string _money;
};

