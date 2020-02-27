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
	
	//�ҵ�ǰ�����ַ��ڲ��һ��������ҵ��������һ������:ƥ������ͷ
	matchHead = _head[hashAddr];

	//pos���ܻᳬ��32k��&MASK��Ŀ�ľ���Ϊ�˲�Խ��
	_prev[pos&HASH_MASK] = _head[hashAddr];
	_head[hashAddr] = pos;

}


//abcdfg
//hashAddr:ǰһ�μ�����Ĺ�ϣ��ַabc
//������Ҫ����bcd��ϣ��ַ
//ch������ƥ�������ַ��е����һ��d
//���εĹ�ϣ��ַ������һ�ι�ϣ��ַ�ϼ��������
void LZHashTable::HashFunc(USH& hashAddr, UCH ch)
{
	hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}
USH LZHashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}