#pragma once
#include <string>
#include <vector>
#include "HuffmanTree.hpp"

struct charInfo
{
	char _ch;  //������ַ�
	size_t _count;  //�ַ����ֵĴ���
	std::string _strCode; //�ַ��ı���

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
	void WriteHead(FILE* fOut, const string& filePostFix);//�����ļ���Ϣ
	string GetFilePostFix(const string& fileName);//��ȡ�ļ���׺
	void ReadLine(FILE* fIn, string &strInfo);
private:
	std::vector<charInfo> _fileInfo;
};