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
			pParent->_Right = pCur;
		else
			pParent->_left = pCur;
		return true;
	}

	bool Delete(const T& data)
	{
		if (nullptr == _pRoot)
			return false;
		//�ҵ���ɾ���ڵ��λ��
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

		//data���ڶ������У��޷�ɾ��
		if (nullptr == pCur)
			return false;

		Node* pDelNode = pCur;

		if (nullptr == pCur->_pLeft)//ֻ���Һ���||��Ҷ�ӽڵ�
		{
			if (nullptr == pParent)
			{
				//pCur�Ǹ��ڵ�
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
		else//���Һ��Ӷ���
		{

		}


	}
private:
	Node * _pRoot;

};