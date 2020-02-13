#include "FileCompressHuff.h"
#include "HuffmanTree.hpp"
#include <assert.h>


FileCompressHuff::FileCompressHuff()
{
	_fileInfo.resize(256);
	for (int i = 0; i < 256; i++)
	{
		_fileInfo[i]._ch = i;
		_fileInfo[i]._count = 0;
	}
}
void FileCompressHuff::CompressFile(const std::string& path)
{
	//1.ͳ��Դ�ļ���ÿ���ַ����ֵĴ���
	FILE* fIn = fopen(path.c_str(), "r");
	if (nullptr == fIn)
	{
	//	assert(false);
		return;
	}

	char* pReadBuff = new char[1024];
	int rdSize = 0;
	while (true)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;
	}

	for (int i = 0; i < rdSize; i++)
	{
		_fileInfo[pReadBuff[i]]._count++;
	}
	

	//2.���ַ����ֵĴ���ΪȨֵ������HUffManTree
	HuffManTree<charInfo> t(_fileInfo);


	//3.��ȡÿ���ַ��ı���

	//4.�û�ȡ���ַ��������¸�д����

	delete[] pReadBuff;
	fclose(fIn);
}
