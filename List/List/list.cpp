#include<iostream>
using namespace std;
//list :带头结点双向循环链表
//1.用
//2.了解底层实现
//3.模拟实现

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
	//采用迭代器的方式
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
	//L.remove(2);//删除所有的2
	//remove_if:删除所有满足条件的结点
	//条件：就是该函数的参数
	//该函数实现的原理：对每个节点中的值域用参数条件进行验证，如果满足则删除，如果不满足什么都不做。
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
    //获取第二个结点
	auto pos = ++L.begin();
	cout << *pos << endl;

	L.insert(pos, 4);//在pos前加入值为4的结点 //1 4 2 3

	//在pos前插入[v.begin(),v.end()]区间中的元素
	vector<int> v{ 7, 8, 9 };
	L.insert(pos, v.begin(), v.end());//1 4 7 8 9 2 3

	//删除pos位置上的元素
	L.erase(pos);//1 4 7 8 9 3
	//删除list中[begin,end]区间中的元素
	L.erase(L.begin(), L.end());

}
void TestList6()
{
	int array[] = { 1, 2, 3 };
	list<int> L1(array, array + sizeof(array) / sizeof(array[0]));
	list<int> L2;

	L1.swap(L2);//交换L1和L2中的元素
	L2.clear();
	cout << L1.size() << endl;
	cout << L2.size ()<< endl;

}

//list中迭代器失效--迭代器指向的节点不存在
void TestListIterator()
{
	list<int> L{ 1, 2, 3, 4 };
	auto it = L.begin();
	L.erase(it);
	//erase之后，it所指向的节点已经被删除掉了
	//it迭代器失效
	//解决方法：给迭代器重新赋值
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
	//list:带头结点双向循环列表
	//list的节点类
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
	//List迭代器：将节点类型的指针重新封装
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> Self;
	};

}