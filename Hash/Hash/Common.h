#pragma once
#include<string>
using namespace std;

size_t GetNextPrime(size_t capacity);

//整形数据不需要转化
template<class T>
class DefHashF
{
public:
	T operator()(const T& data)
	{
		return data;
	}
};

//字符串转化为整形
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