#if 0
//�ַ���--�Ƴ�k������ʹʣ�µ����������п���������
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

//����¥����--����
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
		//�ж�ǰ����
		if (i != 0)
		{
			//result[i]++;
			int j = i;
			//int pre = v[j - 1];//����ǰ���ֵ
			//int maxpre = pre;//ǰ������ֵ
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
		//�жϺ󲿷�
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