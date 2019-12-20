#include<iostream>
using namespace std;

#if 0
//binary search tree
template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		,_data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	T _data;
};
//���裺�����������е�Ԫ��Ψһ������˵�������������е�����һ����Ψһ�ģ������ظ���
template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}

	bool Insert(const T& data)
	{
		//����
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//�ǿ�
		//1.���ն����������ԣ��Ҵ�����ڵ�������λ��
		Node *pCur = _pRoot;
		Node *pParent = nullptr;
		while (pCur)
		{
			pParent = pCur; 
			if (pCur->_data < data)
				pCur = pCur->_pRight;
			else if (pCur->_data>data)
				pCur = pCur->_pLeft;
			else
				return false;//˵������������
		}
		//2.�����½ڵ�
		pCur = new Node(data);
		if (pParent->_data < data)
			pParent->_pRight = pCur;
		else
			pParent->_pLeft = pCur;
		return true;
	}

	bool Delete(const T& data)
	{
		if (nullptr == _pRoot)
			return false;
		//�ҵ���ɾ���ڵ��λ��
		Node *pCur = _pRoot;
		Node *pParent = nullptr;
		while (pCur)
		{
			if (pCur->_data == data)
			{
				break;
			}
			else if (pCur->_data < data)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
		}

		//data���ڶ������У��޷�ɾ��
		if (nullptr == pCur)
			return false;

		Node* pDelNode = pCur;//Ҫɾ���Ľڵ�

		if (nullptr == pCur->_pLeft)//ֻ���Һ���||��Ҷ�ӽڵ�
		{
			if (nullptr == pParent)
			{
				//ɾ����pCur�Ǹ��ڵ�
				_pRoot = pCur->_pRight;
			}
			else
			{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pRight;
				else 
					pParent->_pRight = pCur->_pRight;
			}
		}
		else if (nullptr == pCur->_pRight)//ֻ������
		{
			if (nullptr == pParent)
			{
				//ɾ����pCur�Ǹ��ڵ�
				_pRoot = pCur->_pLeft;
			}
			else
			{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pLeft;
				else
				    pParent->_pRight = pCur-> _pLeft;			
			}
		}
		else//���Һ��Ӷ���
		{
			//��pCur����������һ������ڵ�-��һ�����������е���С�ڵ㣨�����ڵ�)
			Node *pDel = pCur->_pRight;//ָ���������ĵ�һ���ڵ�
			pParent = pCur;
			while (pDel->_pLeft)
			{
				pParent = pDel;
				pDel = pDel->_pLeft;
			}
			pCur->_data = pDel->_data;
			//ɾ������ڵ�pDel,pDel��һ��û�����ӵĽڵ�
			if (pParent->_pLeft == pDel)
			{
				pParent->_pLeft = pDel->_pRight;
			}
			else
			{
				pParent->_pRight = pDel->_pRight;
			}
			pDelNode = pDel;
		}
		delete pDelNode;
		return true;
	}
	Node* Find(const T& data)
	{
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		return nullptr;
	}
	//��֤��
	void InOrder()//�������
	{
		_InOrder(_pRoot);
	}
	Node *LeftMost()//Ѱ����Сֵ
	{
		if (nullptr == _pRoot)
			return nullptr;
		Node *pCur = _pRoot;
		while (pCur->_pLeft)
		{
			pCur = pCur->_pLeft;
		}
		return pCur;
	}
	Node *RightMost()
	{
		if (nullptr == _pRoot)
			return nullptr;
		Node *pCur = _pRoot;
		while (pCur->_pRight)
		{
			pCur = pCur->_pRight;
		}
		return pCur;
	}
private:
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}
private:
	Node * _pRoot;
};

void TestBSTree()
{
	BSTree<int> t;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
		t.Insert(e);
	t.InOrder();
	cout << endl;
	cout << t.LeftMost()->_data << endl;
	cout << t.RightMost()->_data << endl;
	t.Delete(6);
	t.InOrder();
	cout << endl;
	t.Delete(8);
	t.InOrder();
	cout << endl;

}
#endif

//K-V
template<class K,class V>
struct BSTNode
{
	BSTNode(const K& key,const V&value)
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _key(key)
		, _value(value)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pRight;
	K _key;
	V _value;
};
template<class K,class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}
	Node *Find(const K&key)
	{
		Node *pCur = _pRoot;
		while (pCur)
		{
			if (key == pCur->_key)
				return pCur;
			else if (key < pCur->_key)
				pCur = pCur->_pLeft;
			else pCur = pCur->_pRight;
		}
		retunr nullptr;
	}
	bool Insert(const K& key, congst V& value)
	{
		if (nullptr == _pRoot)
		{

		}
	}
};