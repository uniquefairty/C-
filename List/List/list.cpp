#include<iostream>
using namespace std;
//list :��ͷ���˫��ѭ������
//1.��
//2.�˽�ײ�ʵ��
//3.ģ��ʵ��

#if 0
#include<list>
#include<vector>
void TestList1()
{
	list<int> L1;
	list<int> L2(10, 5);
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> L3(v.begin(), v.end());
	list<int> L4(L3);
	cout << L1.size() << endl;
	//���õ������ķ�ʽ
	//list<int>::iterator it = L2.begin();
	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
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
void TestList2()
{
	list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);
	cout << L.size() << endl;
	L.push_front(0);
	cout << L.front() << endl;
	L.pop_back();
	cout << L.back() << endl;

	auto it = find(L.begin(), L.end(), 2);
	if (it != L.end())
		L.insert(it, 5);
	L.erase(it);
}

bool IsOdd(int data)
{
	if (0 == data % 2)
		return true;
	return false;
}
void TestList3()
{
	list<int> L{ 9, 1, 2, 2, 3, 4, 2 };
	for (auto e : L)
		cout << e << " ";
	cout << endl;
	//L.remove(2);//ɾ�����е�2
	//remove_if:ɾ���������������Ľ��
	//���������Ǹú����Ĳ���
	//�ú���ʵ�ֵ�ԭ����ÿ���ڵ��е�ֵ���ò�������������֤�����������ɾ�������������ʲô��������
	L.remove_if(IsOdd);
	for (auto e : L)
		cout << e << " ";

}

void TestList4()
{
	list<int> L{ 9, 1, 2, 2, 3, 4, 2 };
	L.sort();
	L.unique();
}

void TestList5()
{
	int array[] = { 1, 2, 3 };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
    //��ȡ�ڶ������
	auto pos = ++L.begin();
	cout << *pos << endl;

	L.insert(pos, 4);//��posǰ����ֵΪ4�Ľ�� //1 4 2 3

	//��posǰ����[v.begin(),v.end()]�����е�Ԫ��
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());//1 4 7 8 9 2 3

	//ɾ��posλ���ϵ�Ԫ��
	L.erase(pos);//1 4 7 8 9 3
	//ɾ��list��[begin,end]�����е�Ԫ��
	L.erase(L.begin(), L.end());

}
void TestList6()
{
	int array[] = { 1, 2, 3 };
	list<int> L1(array, array + sizeof(array) / sizeof(array[0]));
	list<int> L2;

	L1.swap(L2);//����L1��L2�е�Ԫ��
	L2.clear();
	cout << L1.size() << endl;
	cout << L2.size ()<< endl;

}

//list�е�����ʧЧ--������ָ��Ľڵ㲻����
void TestListIterator()
{
	list<int> L{ 1, 2, 3, 4 };
	auto it = L.begin();
	L.erase(it);
	//erase֮��it��ָ��Ľڵ��Ѿ���ɾ������
	//it������ʧЧ
	//��������������������¸�ֵ
	it = L.begin();
	while (it != L.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	//TestList4();
	//TestList5();
	//TestList6();
	TestListIterator();
	return 0;
}
#endif

namespace bit
{
	//list:��ͷ���˫��ѭ���б�
	//list�Ľڵ���
	template<class T>
	struct ListNode
	{
		ListNode(const T&data = T())
			:_pNext(nullptr)
			, _pPer(nullptr)
			, _data(data)
		{}
		ListNode<T> * _pNext;
		ListNode<T>* _pPre;
		T _data;
	};
	//List�����������ڵ����͵�ָ�����·�װ
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> Self;
	};

}