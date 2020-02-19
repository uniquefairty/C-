/* ��ɢ��ʵ��*/
#pragma once
#include "Common.h"
#include<vector>
using namespace std;

template<class T>
struct HashBucketNode
{
	//T():Ts���������� 0  �Զ������� T():���ù��캯��
	HashBucketNode(const T& data=T())
		:_pNext(nullptr)
		, _data(data)
	{}

	HashBucketNode<T>* _pNext;
	T _data;
};

//��ϣͰ��������Ψһ��

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

	//�ڲ���ʱ����ϣ���е�Ԫ����Ψһ��
	bool insertunique(const T& data)
	{
		//1.ͨ����ϣ����������Ͱ��
		size_t bucketNo = HashFunc(data);
		//2.���ֵΪdata��Ԫ���ڹ�ϣͰ���Ƿ����
		Node* pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return false;

			pCur = pCur->_pNext;
		}

		//3.�����½ڵ�--ͷ��
		pCur = new Node(data);
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		++_size;
		return true;
	}

	//����п��Բ�����ͬ��Ԫ��
	bool insertEqual(const T& data);

	bool eraseunique(const T& data)
	{
		//1.ͨ����ϣ������������ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);

		//2.��bucketNo����Ӧ����������ֵΪdata�Ľڵ�
		Node* pCur = _ht[bucketNo];
		Node *pPre = nullptr;
		while (pCur)
		{
			if (pCur->_data == data)
			{
				//ɾ��pCur�ڵ�ɾ��
				if (nullptr == pPre)
				{
					//ɾ����һ���ڵ�
					_ht[bucketNo] = pCur->_pNext;
				}
				else
				{
					//ɾ���ڶ����ڵ�
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
		//1.����data���ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);

		//2.��bucketNo����Ӧ����������ֵΪdata�Ľڵ�
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
