#include "LZHashTable.h"
#include <string.h>


const USH HASH_BITS = 15;
const USH HASH_SIZE = (1 << HASH_BITS);
const USH HASH_MASK = HASH_SIZE - 1;

LZHashTable::LZHashTable(USH size)
	:_prev(new USH[size * 2])
	, _head(_prev + size)
{
	memset(_prev, 0, size * 2 * sizeof(USH));
}

LZHashTable::~LZHashTable()
{
	delete[] _prev;
	_prev = nullptr;
}
void LZHashTable::Insert(USH& matchHead, UCH ch, USH pos, USH& hashAddr)
{
	HashFunc(hashAddr, ch);
	
	//找当前三个字符在查找缓冲区中找到的最近的一个，即:匹配链的头
	matchHead = _head[hashAddr];

	//pos可能会超过32k，&MASK的目的就是为了不越界
	_prev[pos&HASH_MASK] = _head[hashAddr];
	_head[hashAddr] = pos;

}


//abcdfg
//hashAddr:前一次计算出的哈希地址abc
//本次需要计算bcd哈希地址
//ch：本次匹配三个字符中的最后一个d
//本次的哈希地址是在上一次哈希地址上计算出来的
void LZHashTable::HashFunc(USH& hashAddr, UCH ch)
{
	hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}
USH LZHashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}