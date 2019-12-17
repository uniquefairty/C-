#include<iostream>
using namespace std;

//binary search tree
template<class T>
struct BSTNode
{
	BSTreeNode(const T& data = T())
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
			pParent->_Right = pCur;
		else
			pParent->_left = pCur;
		return true;
	}

	bool Delete(const T& data)
	{
		if (nullptr == _pRoot)
			return false;
		//找到待删除节点的位置
		Node *pCur = _pRoot;
		Node *pParent = _nullptr;
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

		Node* pDelNode = pCur;

		if (nullptr == pCur->_pLeft)//只有右孩子||是叶子节点
		{
			if (nullptr == pParent)
			{
				//pCur是根节点
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
				_pRoot = pCur->_pLeft;
			}
			else
			{
				if (pCur == pParent->_pLeft)
					pParent->_pLeft = pCur->_pLeft;
				else
				    pParent->_pRight = pCur > _pLeft;			
			}
		}
		else//左右孩子都有
		{

		}


	}
private:
	Node * _pRoot;

};