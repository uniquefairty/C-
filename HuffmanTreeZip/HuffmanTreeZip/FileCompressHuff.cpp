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
	//1.统计源文件中每个字符出现的次数
	FILE* fIn = fopen(path.c_str(), "r");
	if (nullptr == fIn)
	{
		assert(false);
		return;
	}

	char* pReadBuff = new char[1024];
	int rdSize = 0;
	while (true)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;

		for (int i = 0; i < rdSize; i++)
		{
			_fileInfo[pReadBuff[i]]._count++;
		}
	}
	

	//2.以字符出现的次数为权值，创建HuffManTree
	HuffManTree<charInfo> t(_fileInfo,charInfo(0));

	//3.获取每个字符的编码
	GenerateHuffManCode(t.GetRoot());

	//4.用获取的字符编码重新改写编码
	FILE* fOut = fopen("2.txt", "w");
	if (nullptr == fOut)
	{
		assert(false);
		return;
	}

	WriteHead(fOut, path);//解压缩的信息
	fseek(fIn,0,SEEK_SET);//
	char ch = 0;
	size_t bitcount = 0;
	while (true)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;
		//根据字节的编码对读取到的内容进行重写
		for (size_t i = 0; i < rdSize; i++)
		{
			string strCode=_fileInfo[pReadBuff[i]]._strCode;
			//A:"110"  B:"101" 
			for (size_t j = 0; i < strCode.size(); i++)
			{
				ch <<= 1;
				if ('1' == strCode[j])
					ch |= 1;
				bitcount++;
				if (8 == bitcount)
				{
					fputc(ch, fOut);
					bitcount = 0;
					ch = 0;
				}
			}
		}
		
	}
	//最后一个可能不够8个比特位
	if (bitcount < 8)
	{
		ch <<= (8 - bitcount);
		fputc(ch, fOut);
	}

	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

void FileCompressHuff::UNCompressFile(const std::string& path)
{
	FILE* fIn = fopen(path.c_str(), "r");
	if (nullptr == fIn)
	{
		assert(false);
		return;
	}
	//文件后缀
	string strFilePostFix;
	ReadLine(fIn, strFilePostFix);

	//字符信息的总行数
	string strCount;
	ReadLine(fIn, strCount);
	int lineCount = atoi(strCount.c_str());

	//字符信息
	for (int i = 0; i < lineCount; i++)
	{
		string strchCount;
		ReadLine(fIn, strchCount);

		//A:1
		_fileInfo[strchCount[0]]._count = atoi(strchCount.c_str() + 2);//前两个字符是A和：
	}

	//还原哈夫曼树
	HuffManTree<charInfo> t;
	t.CreateHuffManTree(_fileInfo, charInfo(0));

	FILE* fOut = fopen("3.txt","w");
		assert(fOut);
	//解压缩
	char* pReadBuff = new char[1024];
	HuffManTreeNode<charInfo>* pCur = t.GetRoot();
	char ch = 0;
	while (true)
	{
		size_t rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;

		for (size_t i = 0; i < rdSize; i++)
		{
			//只需将一个字节中8个比特位单独处理
			ch = pReadBuff[i];
			for (int pos = 0; pos < 8; pos++)
			{
				if (ch & 0x80)
					pCur = pCur->_pRight;
				else
					pCur = pCur->_pLeft;

				ch <<= 1;
				if (nullptr == pCur->_pLeft&&nullptr == pCur->_pRight)
				{
					fputc(pCur->_weight._ch,fOut);
					pCur = t.GetRoot();
				}
				
			}
		}
	}
	//压缩数据
	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

void FileCompressHuff::ReadLine(FILE* fIn, string &strInfo)
{
	assert(fIn);
	while (!feof(fIn))//没有到文件的末尾
	{
		char ch = fgetc(fIn);
		if (ch == '\n')
			break;
		strInfo += ch;
	}
	
}
void FileCompressHuff::WriteHead(FILE* fOut, const string& fileName)
{
	assert(fOut);

	//写文件后缀
	string strHead;
	strHead += GetFilePostFix(fileName);
	strHead += '\n';

	//写行数
	size_t lineCount = 0;
	string strChCount;//字符的次数
	char szValue[32] = { 0 };
	for (int i = 0; i < 256; i++)
	{
		charInfo& charInfo = _fileInfo[i];
		if (_fileInfo[i]._count)
		{
			lineCount++;
			strChCount += _fileInfo[i]._ch;
			strChCount += ':';
			_itoa(charInfo._count, szValue, 10);
			strChCount += szValue;//字符转整形
			strChCount += '\n';
		}
	}

	_itoa(lineCount, szValue, 10);
	strHead += szValue;
	strHead += '\n';
	//写字符信息

	strHead += strChCount;

	fwrite(strHead.c_str(),1,strHead.size(),fOut);

	//fwrite();
}

//2.txt  F:\123\2.txt
string FileCompressHuff::GetFilePostFix(const string& fileName)
{
	return fileName.substr(fileName.rfind('.'));
}
void FileCompressHuff::GenerateHuffManCode(HuffManTreeNode<charInfo> *pRoot)//根到叶子的路径
{
	if (nullptr == pRoot)
		return;
	
	GenerateHuffManCode(pRoot->_pLeft);
	GenerateHuffManCode(pRoot->_pRight);

	if (nullptr == pRoot->_pLeft&&nullptr == pRoot->_pRight)//递归pRoot就是叶子节点
	{
		string& strCode = _fileInfo[pRoot->_weight._ch]._strCode;
		HuffManTreeNode<charInfo>* pCur = pRoot;
		HuffManTreeNode<charInfo>* pParent = pCur->_pParent;

		while (pParent)
		{
			if (pCur == pParent->_pLeft)//左子树是0 右子树1
			{
				strCode += '0';
			}
			else
			{
				strCode += '1';
			}

			pCur = pParent;
			pParent = pCur->_pParent;
		}
		
		reverse(strCode.begin(), strCode.end());

		//_fileInfo[pRoot->_weight._ch]._strCode= strCode;//_fileInfo里面的每一个元素都是一个结构体
	}

}
