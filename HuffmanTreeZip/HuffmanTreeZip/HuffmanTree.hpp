#pragma once
using namespace std;
//#include <iostream>
#include "FileCompressHuff.h"
#include <queue>
#include <vector>

template<class W>
struct HuffManTreeNode
{
	HuffManTreeNode(const W& weight = W())//�������ͣ�0 �Զ������ͣ��޲ι��캯�� ȫȱʡ���캯��
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		,_weight(weight)
	{}

	HuffManTreeNode<W>*_pLeft;
	HuffManTreeNode<W>* _pRight;
	HuffManTreeNode<W>* _pParent;

	W _weight;//�ڵ��Ȩֵ
};

template<class W>
class Less
{
	typedef HuffManTreeNode<W> Node;
public:
	bool operator()(const Node* pLeft, const Node* pRight)
	{
		return pLeft->_weight > pRight->_weight;
	}
};


template<class W>
class HuffManTree
{
	typedef  HuffManTreeNode<W> Node;
public:
	HuffManTree()
		:_pRoot(nullptr)
	{}
	
	HuffManTree(const vector<W>& vWeight,const W& invalid)//��Ч��Ȩֵ����Ч(�ַ�����0��)��Ȩֵ
	{
		CreateHuffManTree(vWeight,invalid);
	}

	~HuffManTree()
	{
		_DestroyTree(_pRoot);
	}

	Node* GetRoot()
	{
		return _pRoot;
	}

	void CreateHuffManTree(const vector<W>& vWeight, const W& invalid)
	{
		//1.����ɭ��
		std::priority_queue<Node*,vector<Node *>,Less<W>> q;
		for (auto e : vWeight)
		{
			if (e == invalid)
				continue;

			q.push(new Node(e));
		}

		//2.
		while (q.size() > 1)
		{
			Node* pLeft = q.top();
			q.pop();

			Node* pRight = q.top();
			q.pop();

			Node* pParent = new Node(pLeft->_weight + pRight->_weight);
			pParent->_pLeft = pLeft;
			pParent->_pRight = pRight;

			pLeft->_pParent = pParent;
			pRight->_pParent = pParent;
			q.push(pParent);
		}
		_pRoot = q.top();
	}


private:
	void _DestroyTree(Node*& pRoot)
	{
		if (pRoot)
		{
			_DestroyTree(pRoot->_pLeft);
			_DestroyTree(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	Node* _pRoot;
};

//void TestHuffManTree()
//{
//	vector<int> v{ 3, 1, 7, 5 };
//	HuffManTree<int> t(v);
//
//}

