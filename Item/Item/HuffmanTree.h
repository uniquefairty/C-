#pragma once

template<class W>
struct HuffManTreeNode
{
	HuffManTreeNode(const W& weight = W())
		:_pLeft(nullptr)
		,_pRight(nullptr)
		, _weight(weight)
	{}

	HuffManTreeNode<W>* _pLeft;
	HuffManTreeNode<W>* _pRight;
	W _weight;//�ڵ��Ȩֵ
};

template<class W>
class HuffManTree
{
	typedef HuffManTreeNode<W> Node;
public:
	HuffManTree()
		:_pRoot(nullptr)
	{}

	void CreatHuffManTree(const vector<W> weight)
	{
		//1.����ɭ��
		for (auto e : vWeight)
		{
			new Node(e);
		}
	}
private:
	Node* _pRoot;
};