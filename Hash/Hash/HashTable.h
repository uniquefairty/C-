#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "Common.h"

enum State{EMPTY,EXIST,DELETE};
template<class T>
struct Elem
{
	//pair<K, V> _val;
	Elem(const T& data = T())
		:_data(data)
		, _state(EMPTY)
	{}

	T _data;
	State _state;
};


//�����ϣ����Ԫ��Ψһ
//T:��ʾԪ������
//DF����ʾT���͵Ķ���ת��Ϊ�������ݵķ���
//isLine��ѡ��������̽�⻹�Ƕ���̽���������ϣ��ͻ

template<class T,class DF = DefHashF<T>, bool isLine = true>
class HashTable
{
public:
	HashTable(size_t capacity = 10)
		:_size(0)
	{
		_ht.resize(10);
	}

	bool Insert(const T& data)
	{
		//����ϣ��ײ�ռ��Ƿ����
		//1.ͨ����ϣ�����������ϣ��ַ
		size_t hashAddr = HashFunc(data);

		size_t i = 0;

		//2.�Һ��ʵ�λ��
		while (_ht[hashAddr]._state != EMPTY)
		{
			//Ԫ���Ѿ�����
			if (_ht[hashAddr]._state == EXIST&&_ht[hashAddr]._data == data)
				return false;

			//λ��״̬��DELETE 
			//EXIST��������ϣ��ͻ

			if (isLine)
			{
				//����̽��
				hashAddr++;
				if (hashAddr == _ht.capacity())
					hashAddr = 0;
			}
			else
			{
				//����̽��
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= _ht.capacity();
			}
	
		}
		//�ҵ�һ����λ��,����Ԫ��
		_ht[hashAddr]._data = data;
		_ht[hashAddr]._state = EXIST;
		++_size;
		return true;
	}

	size_t Find(const T& data)
	{
		//ͨ����ϣ�������������е�λ��
		size_t hashAddr = HashFunc(data);
		size_t i = 0;
		//����
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST&&_ht[hashAddr]._data == data)
				return hashAddr;

			if (isLine)
			{
				//����̽��
				hashAddr++;
				if (hashAddr == _ht.capacity())
					hashAddr = 0;
			}
			else
			{
				//����̽��
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= _ht.capacity();
			}

		}
		return -1;
	}

	bool Erase(const T& data)
	{
		int index = Find(data);
		if (-1 != index)
		{
			_ht[index]._state = DELETE;
			_size--;
			return true;
		}
			return false;
	}

	size_t Size()const
	{
		return _size;
	}

	void Swap(HashTable<T, DF, isLine>& ht)
	{
		_ht.swap(ht._ht);
		swap(_size, ht._size);
	}

private:
	void CheckCapacity()
	{
		if (_size *10/ _ht.capacity() >= 7)
		{
			//1.�´���һ����ϣ��
			HashTable<T, DF, isLine> newHT(GetNextPrime(_ht.capacity()));

			//2.����ϣ����״̬���ڵ�Ԫ�����ϣ���в���
			for (auto e : _ht)
			{
				if (e._state == EXIST)
				{
					newHT.insert(e);
				}
			}
			Swap(newHT);
		}
	}
	size_t HashFunc(const T& data)
	{
		//DF df;
		//return df(data) % 10;

		return DF()(data) % _ht.capacity();
	}

private:
	std::vector<Elem<T>> _ht;
	size_t _size;//��ϣ���е���Ч����
};

void TestHashTable()
{
	int array[] = { 21, 67, 112,99,5,13,44 };
	HashTable<int, DefHashF<int>> ht;
	for (auto e : array)

		ht.Insert(e);

	cout << ht.Size() << endl;
	ht.Insert(87);
	ht.Insert(77);
	cout << ht.Size() << endl;

	if (ht.Find(87 != -1))
	{
		cout << "87 is in hashtable" << endl;
	}
	else
	{
		cout << "87 is not in hashtable" << endl;
	}

	ht.Erase(67);
	cout << ht.Size() << endl;
	if (ht.Find(67 != -1))
	{
		cout << "67 is in hashtable" << endl;
	}
	else
	{
		cout << "67 is not in hashtable" << endl;
	}

	if (ht.Find(87 != -1))
	{
		cout << "87 is in hashtable" << endl;
	}
	else
	{
		cout << "87 is not in hashtable" << endl;
	}
}

void TestHashTable2()
{

	HashTable<string, StrInt> ht;
	ht.Insert("1111");
	ht.Insert("2222");
	ht.Insert("3333");
	ht.Insert("4444");
}