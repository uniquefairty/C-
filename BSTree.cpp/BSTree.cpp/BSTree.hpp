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
//假设：二叉搜索树中得元素唯一（不能说明二叉搜索树中得数据一定是唯一的，可以重复）
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
		//空树
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}
		//非空
		//1.按照二叉树的特性，找待插入节点在树得位置
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
				return false;//说明该数据已有
		}
		//2.插入新节点
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
		//找到待删除节点的位置
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

		//data不在二叉树中，无法删除
		if (nullptr == pCur)
			return false;

		Node* pDelNode = pCur;//要删除的节点

		if (nullptr == pCur->_pLeft)//只有右孩子||是叶子节点
		{
			if (nullptr == pParent)
			{
				//删除的pCur是根节点
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
		else if (nullptr == pCur->_pRight)//只有左孩子
		{
			if (nullptr == pParent)
			{
				//删除的pCur是根节点
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
		else//左右孩子都有
		{
			//在pCur的右子树中一个代替节点-》一定是右子树中的最小节点（最左侧节点)
			Node *pDel = pCur->_pRight;//指向右子树的第一个节点
			pParent = pCur;
			while (pDel->_pLeft)
			{
				pParent = pDel;
				pDel = pDel->_pLeft;
			}
			pCur->_data = pDel->_data;
			//删除替代节点pDel,pDel是一个没有左孩子的节点
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
	//验证：
	void InOrder()//中序遍历
	{
		_InOrder(_pRoot);
	}
	Node *LeftMost()//寻找最小值
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