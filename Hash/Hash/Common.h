#pragma once
#include<string>
using namespace std;

size_t GetNextPrime(size_t capacity);

//�������ݲ���Ҫת��
template<class T>
class DefHashF
{
public:
	T operator()(const T& data)
	{
		return data;
	}
};

//�ַ���ת��Ϊ����
class StrInt
{
public:
	size_t operator()(const std::string& s)
	{
		return BKDRHash(s.c_str());
	}
private:
	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;  
		}
		return hash;
	}
};