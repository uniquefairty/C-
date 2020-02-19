/* 开散列实现*/
#pragma once
#include "Common.h"
#include<vector>
using namespace std;

template<class T>
struct HashBucketNode
{
	//T():Ts是内置类型 0  自定义类型 T():调用构造函数
	HashBucketNode(const T& data=T())
		:_pNext(nullptr)
		, _data(data)
	{}

	HashBucketNode<T>* _pNext;
	T _data;
};

//哈希桶的数据是唯一的

template<class T,class DF=DFDef<T>>
class HashBucket
{
	typedef HashBucketNode<T> Node;
	typedef Node* PNode;
public:
	HashBucket(size_t capacity = 10)
		:_size(0)
	{
		_ht.resize(GetNextPrime(10));
	}

	//在插入时，哈希表中的元素是唯一的
	bool insertunique(const T& data)
	{
		//1.通过哈希函数，计算桶号
		size_t bucketNo = HashFunc(data);
		//2.检测值为data的元素在哈希桶中是否存在
		Node* pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return false;

			pCur = pCur->_pNext;
		}

		//3.插入新节点--头插
		pCur = new Node(data);
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		++_size;
		return true;
	}

	//表格中可以插入相同的元素
	bool insertEqual(const T& data);

	bool eraseunique(const T& data)
	{
		//1.通过哈希函数计算打他在的桶号
		size_t bucketNo = HashFunc(data);

		//2.在bucketNo所对应的链表中找值为data的节点
		Node* pCur = _ht[bucketNo];
		Node *pPre = nullptr;
		while (pCur)
		{
			if (pCur->_data == data)
			{
				//删除pCur节点删除
				if (nullptr == pPre)
				{
					//删除第一个节点
					_ht[bucketNo] = pCur->_pNext;
				}
				else
				{
					//删除第二个节点
					pPre->_pNext = pCur->_pNext;
				}

				delete pCur;
				--_size;
				return true;

			}
			else
			{
				pPre = pCur;
				pCur = pCur->_pNext;
			}
		}

		return false;
	}

	Node* find(const T& data)const
	{
		//1.计算data所在的桶号
		size_t bucketNo = HashFunc(data);

		//2.在bucketNo所对应的链表中找值为data的节点
		Node* pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;
			pCur = pCur->_pNext;
		}
		return nullptr;
	}

	size_t size()const
	{
		return _size;
	}

	bool empty()const
	{
		return _size;
	}
private:
	size_t HashFunc(const T& data) const
	{
		return DF()data%_ht.capacity;
	}

private:
	vector<Node*> _ht;
	size_t _size;
};
