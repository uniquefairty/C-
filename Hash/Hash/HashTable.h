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


//假设哈希表中元素唯一
//T:表示元素类型
//DF：表示T类型的对象转化为整数数据的方法
//isLine：选择用线性探测还是二次探测来解决哈希冲突

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
		//检测哈希表底层空间是否充足
		//1.通过哈希蛤属，计算哈希地址
		size_t hashAddr = HashFunc(data);

		size_t i = 0;

		//2.找合适的位置
		while (_ht[hashAddr]._state != EMPTY)
		{
			//元素已经存在
			if (_ht[hashAddr]._state == EXIST&&_ht[hashAddr]._data == data)
				return false;

			//位置状态：DELETE 
			//EXIST，发生哈希冲突

			if (isLine)
			{
				//线性探测
				hashAddr++;
				if (hashAddr == _ht.capacity())
					hashAddr = 0;
			}
			else
			{
				//二次探测
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= _ht.capacity();
			}
	
		}
		//找到一个空位置,插入元素
		_ht[hashAddr]._data = data;
		_ht[hashAddr]._state = EXIST;
		++_size;
		return true;
	}

	size_t Find(const T& data)
	{
		//通过哈希函数，计算表格中的位置
		size_t hashAddr = HashFunc(data);
		size_t i = 0;
		//查找
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST&&_ht[hashAddr]._data == data)
				return hashAddr;

			if (isLine)
			{
				//线性探测
				hashAddr++;
				if (hashAddr == _ht.capacity())
					hashAddr = 0;
			}
			else
			{
				//二次探测
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
			//1.新创建一个哈希表
			HashTable<T, DF, isLine> newHT(GetNextPrime(_ht.capacity()));

			//2.将哈希表中状态存在的元素向哈希表中插入
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
	size_t _size;//哈希表中的有效个数
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