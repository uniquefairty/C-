#include "FileCompressHuff.h"
#include "HuffmanTree.hpp"
#include <assert.h>


FileCompressHuff::FileCompressHuff()//构造函数--完成初始化
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
	FILE* fIn = fopen(path.c_str(), "rb");
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
			_fileInfo[(unsigned char)pReadBuff[i]]._count++;
		}
	}
	

	//2.以字符出现的次数为权值，创建HuffManTree
	HuffManTree<charInfo> t(_fileInfo,charInfo(0));

	//3.获取每个字符的编码
	GenerateHuffManCode(t.GetRoot());

	//4.用获取的字符编码重新改写编码
	FILE* fOut = fopen("2.txt", "wb");

	if (nullptr == fOut)
	{
		assert(false);
		return;
	}

	WriteHead(fOut, path);//解压缩的信息
	                      //+解压缩数据
	fseek(fIn,0,SEEK_SET);//修改文件指针指向起始位置
	char ch = 0;
	size_t bitcount = 0;//统计读到的比特位个数
	while (true)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;
		//根据字节的编码对读取到的内容进行重写
		for (int i = 0; i < rdSize; i++)
		{
			string strCode=_fileInfo[(unsigned char)pReadBuff[i]]._strCode;
			//A:"110"  B:"101" 
			for (size_t j = 0; j< strCode.size(); j++)
			{
				ch <<= 1;
				if ('1' == strCode[j])
	
				ch |= 1;
				bitcount++;
				if (8 == bitcount)
				{
					fputc(ch, fOut);//读取一个字节(8个比特位)
					bitcount = 0;
					ch = 0;
				}
			}
		}
		
	}
	//最后一个可能不够8个比特位
	if (bitcount < 8)
	{
		ch <<= (8 - bitcount);//剩下的比特位数值移到高位
		fputc(ch, fOut);
	}

	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

void FileCompressHuff::UNCompressFile(const std::string& path)
{
	FILE* fIn = fopen(path.c_str(), "rb");
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

		//如果读取到的是\n
		if (strchCount.empty())
		{
			strchCount += '\n';
			ReadLine(fIn, strchCount);
		}

		//A:1
		_fileInfo[(unsigned char)strchCount[0]]._count = atoi(strchCount.c_str() + 2);
		
	}

	//还原哈夫曼树
	HuffManTree<charInfo> t;
	t.CreateHuffManTree(_fileInfo, charInfo(0));

	FILE* fOut = fopen("3.txt","wb");
	assert(fOut);
	//解压缩
	unsigned char* pReadBuff = new unsigned char[1024];
	HuffManTreeNode<charInfo>* pCur = t.GetRoot();
	size_t fileSize = pCur->_weight._count;//文件组的大小就是字节组中字符的个数
	size_t unCount = 0;//解压缩的个数
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
				if (ch & 0x80)//检测高位
					pCur = pCur->_pRight;
				else
					pCur = pCur->_pLeft;

				ch <<= 1;
				if (nullptr == pCur->_pLeft&&nullptr == pCur->_pRight)
				{
					fputc(pCur->_weight._ch, fOut);
					unCount++;
					if (unCount == fileSize)
						break;
					pCur = t.GetRoot();//每次写一个字符，然后指向根节点
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
void FileCompressHuff::WriteHead(FILE* fOut, const string& fileName)//文件压缩信息
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
		if (_fileInfo[i]._count)//出现字符的次数不为0
		{
			lineCount++;
			strChCount += _fileInfo[i]._ch;
			strChCount += ':';
			//char *  itoa ( int value, char * str, int base );
			_itoa(charInfo._count, szValue, 10);//字符转整形
			strChCount += szValue;
			strChCount += '\n';
		}
	}

	_itoa(lineCount, szValue, 10);
	strHead += szValue;//+行数
	strHead += '\n';
	//写字符信息
	strHead += strChCount;//+每个字符的信息

	fwrite(strHead.c_str(),1,strHead.size(),fOut);

}

//2.txt  F:\123\2.txt
string FileCompressHuff::GetFilePostFix(const string& fileName)
{
	return fileName.substr(fileName.rfind('.'));
}

//获取每个字符的编码
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
