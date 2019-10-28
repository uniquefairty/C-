#include<iostream>
using namespace std;
//list :��ͷ���˫��ѭ������
//1.��
//2.�˽�ײ�ʵ��
//3.ģ��ʵ��

#include<list>
#include<vector>
void TestList1()
{
	list<int> L1;
	list<int> L2(10, 5);
	vector<int> v{ 1, 2, 3, 4, 5, 6,7, 8, 9, 0 };
	list<int> L3(v.begin(), v.end());
	list<int> L4(L3);
	cout << L1.size() << endl;
	//���õ������ķ�ʽ
	//list<int>::iterator it = L2.begin();
	auto it = L2.begin();

	while (it != L2.end())
	{
		cout << *it << " ";
	}

	cout << endl;

	for (auto e : L3)
		cout << e << " ";
	cout << endl;

	cout << L3.front() << endl;
	cout << L3.back() << endl;

	auto rit = L4.rbegin();
	while (rit != L4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

