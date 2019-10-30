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
	//��װ�����������
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> Self;
	public:
		list_iterator(Node* pCur)
			:_pCur(pCur)
		{}
		//��ָ��ķ�ʽ����Ӧ��
		T& operator*()
		{
			return _pCur->_data;
		}
		T* operator->()
		{
			return &(_pCur->data);
		}
		//3.�ƶ�
		Self& operator++()
		{
			_pCur = _pCur->_pNext;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_pCur = _pCur->_pNext;
			return temp;
		}
		Self& operator--()
		{
			_pCur = _pcur->_pPer;
			return *this;
		}
		Self operator--(int)
		{
			Self temp(*this);
			_pCur = _pCur->__pPer;
			return temp;
		}
		//4.�Ƚ�
		bool operator!=(const Self& s)
		{
			return _pCur != s._pCur;
		}
		bool operator==(const Self& s)
		{
			return _pCur == s._pCur;
		}
		Node* _pCur;
	};

	//��װ���������
	template<class Iterator,class T>
	struct list_reverse_iterator
	{
		typedef list_reverse_iterator<Iterator, T> Self;
	public:
		list_reverse_iterator(Iterator it)
		:_it(it)
		{}
		//��ָ��ķ�ʽ����Ӧ��
		T& operator*()
		{
			Iterator temp = _it;
			--temp;
			return *temp;
		}
		T* operator->()
		{
			return &(operator*());
		}
		//3.�ƶ�
		Self& operator++()
		{
			--it;
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			_it--;
			reurn temp;
		}
		Self& operator--()
		{
			++it;
			return(*this);
		}
		Self operator--(int)
		{
			Self temp(*this);
			++it;
			return temp;
		}
		//4.�Ƚ�
		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}
		bool operator==(const Self& s)
		{
			return _it == s._it;
		}
	
		Iterator _it;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef list_iterator<T> iterator;
		typedef list_reverse_iterator<iterator, T> reverse_iterator;
		//list�Ĺ���
		list()
		{
			CreateHead();
		}
		list(int n, const T& data)
		{
			CreateHead();
			for (size_t i = 0; i < n; i++)
				push_back(data);
		}
		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& L)
		{
			CreateHead();
			Node *pCur = L._pHead->_pNext;
			while (pCur != L._pHead)
			{
				push_back(pCur->data);
				pCur = pCur->_pNext;
			}
		}
		//list(const list<T>& L)
		//{
		//	CreateHead();
		//	//��L�е�Ԫ�ع�����ʱ��temp��Ȼ���뵱ǰ���󽻻�
		//	list<T> temp(L.cbegin(), L.cend());
		//	this->swap(temp);
		//}

		list<T>& operator=(const list<T>& L)
		{
			if (this != &L)
			{
				clear();
				Node* pCur = L._pHead->_pNext;
				while (pCur != _pHead)
				{
					push_back(pCur->_data);
					pCur = pCur->_pNext;
				}
			}
			return *this;
		}
		list<T>& operator=(const list<T> L)
		{
			this->swap(L);
			return *this;
		}
		~list()
		{
			clear();
			delete _pHead;
		}
		/////////////////////////////////////
		//������
		iterator begin()
		{
			return iterator(_pHead->_pNext);
		}
		iterator end()
		{
			return iterator(_pHead);
		}
		reverse_iterator rbegin()
		{
			return end();
		}
		reverse_iterator rend()
		{
			return begin();
		}
		/////////////////////////////////////
		//����
		size_t size()const
		{
			size_t count = 0;
			Node* pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				++count;
				pCur = pCur->_pNext;
			}
			return count;
		}
		size_t empty() const
		{
			return _pHead->_pNext == _pHead;
		}
		void resize(size_t newsize, const T&data = T())
		{
			size_t oldsize = size();
			if (newsize > oldsize)
			{
				//�������
				for (size_t i = oldsize; i < newsize; ++i)
					push_back(data);
			}
			else
			{
				//������
				for (size_t i = newsize; i < oldsize; ++i)
					pop_back();
			}
		}
		/////////////////////////////////////
		//Ԫ�ط���
		T& front()
		{
			return _pHead->_pNext->data;
		}
		const T& front()const
		{
			return _pHead->_pNext->data;
		}
		T& back()
		{
			return _pHead->_pPer->_data;
		}
		const T& back()const
		{
			return _pHead->_pPPer->_data;
		}
		///////////////////////////////////
		//�޸�
		void push_back(const T& data)
		{
			insert(end(), data);
		}
		void pop_back()
		{
			erase(--end());
		}
		void push_front(const T& data)
		{
			insert(begin(), data);
		}
		void pop_front()
		{
			erase(begin());
		}
		//��posΪ֮ǰ����ֵΪdata�Ľ��
		iterator insert(iterator pos, const T& data)
		{
			Node* pNewNode = new Node(data);
			Node* pCur = pos._pCur;
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;

			return iterator(pNewNode);
		}
		//ɾ��posλ�õĽ�㣬���ظýڵ����һ��λ��
		iterator erase(iterator pos)
		{
			Node *pDelNode = pos._pCur;
			if (pDelNode == _pHead)
				return end();
			Node* pRet = pDelNode->_pNext;//���淵�ص���һ������λ��
			pDelNode->_pPre->_pNext = pDelNode->_pNext;
			pDelNode->_pNext->_pPre = pDelNode->_pPre;
			delete pDelNode;
			return iterator(pRet);
		}
		void clear()
		{
			Node* pCur = _pHead->_pNext;
			//ͷɾ��
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = pHead->_pNext;
			}
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
		void swap(list<T>& L)
		{
			swap(_pHead, L._pHead);
		}
		private:
			void CreateHead()
			{
				_pHead = new Node;
				_pHead->_pNext = _pHead;
				_pHead->_pPre = _pHead;
			}
		protected:
			Node* _pHead;
	};
}
int main()
{
	return 0;
}