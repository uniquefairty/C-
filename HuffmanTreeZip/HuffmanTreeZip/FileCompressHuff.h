#pragma once
#include <string>
#include <vector>
#include "HuffmanTree.hpp"

struct charInfo
{
	char _ch;  //具体的字符
	size_t _count;  //字符出现的次数
	std::string _strCode; //字符的编码

	charInfo(size_t count=0)
		:_count(count)
	{}

	charInfo operator+(const charInfo& c)
	{
		return charInfo(_count + c._count);
	}

	bool operator>(const charInfo& c)const
	{
		return _count > c._count;
	}

	bool operator==(const charInfo& c)const
	{
		return _count == c._count;
	}
};

class FileCompressHuff
{
public:
	FileCompressHuff();
	void CompressFile(const std::string& path);
	void UNCompressFile(const std::string& path);


private:
	void GenerateHuffManCode(HuffManTreeNode<charInfo> *pRoot);
	void WriteHead(FILE* fOut, const string& filePostFix);//增加文件信息
	string GetFilePostFix(const string& fileName);//获取文件后缀
	void ReadLine(FILE* fIn, string &strInfo);
private:
	std::vector<charInfo> _fileInfo;
};