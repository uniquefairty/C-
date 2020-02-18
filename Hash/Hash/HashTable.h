#pragma once
#include <vector>
#include <iostream>
using namespace std;

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
template<class T��class DF = DefHashF<T>, bool isLine = true>
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
				hassAddr %= _ht.capacity();
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
		//����
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST&&_ht[hashAddr]._data == data)
				return hashAddr;

			//����̽��
			hashAddr++;
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
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

private:
	size_t HashFunc(const T& data)
	{
		return data % 10;
	}

private:
	std::vector<Elem<T>> _ht;
	size_t _size;//��ϣ���е���Ч����
};

void TestHashTable()
{
	int array[] = { 21, 67, 112,99,5,13,44 };
	HashTable<int> ht;
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