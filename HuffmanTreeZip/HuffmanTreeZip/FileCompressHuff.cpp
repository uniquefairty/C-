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
	

	//2.���ַ����ֵĴ���ΪȨֵ������HuffManTree
	HuffManTree<charInfo> t(_fileInfo,charInfo(0));

	//3.��ȡÿ���ַ��ı���
	GenerateHuffManCode(t.GetRoot());

	//4.�û�ȡ���ַ��������¸�д����
	FILE* fOut = fopen("2.txt", "w");
	if (nullptr == fOut)
	{
		assert(false);
		return;
	}

	WriteHead(fOut, path);//��ѹ������Ϣ
	fseek(fIn,0,SEEK_SET);//
	char ch = 0;
	size_t bitcount = 0;
	while (true)
	{
		rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;
		//�����ֽڵı���Զ�ȡ�������ݽ�����д
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
	//���һ�����ܲ���8������λ
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
	//�ļ���׺
	string strFilePostFix;
	ReadLine(fIn, strFilePostFix);

	//�ַ���Ϣ��������
	string strCount;
	ReadLine(fIn, strCount);
	int lineCount = atoi(strCount.c_str());

	//�ַ���Ϣ
	for (int i = 0; i < lineCount; i++)
	{
		string strchCount;
		ReadLine(fIn, strchCount);

		//A:1
		_fileInfo[strchCount[0]]._count = atoi(strchCount.c_str() + 2);//ǰ�����ַ���A�ͣ�
	}

	//��ԭ��������
	HuffManTree<charInfo> t;
	t.CreateHuffManTree(_fileInfo, charInfo(0));

	FILE* fOut = fopen("3.txt","w");
		assert(fOut);
	//��ѹ��
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
			//ֻ�轫һ���ֽ���8������λ��������
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
	//ѹ������
	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

void FileCompressHuff::ReadLine(FILE* fIn, string &strInfo)
{
	assert(fIn);
	while (!feof(fIn))//û�е��ļ���ĩβ
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

	//д�ļ���׺
	string strHead;
	strHead += GetFilePostFix(fileName);
	strHead += '\n';

	//д����
	size_t lineCount = 0;
	string strChCount;//�ַ��Ĵ���
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
			strChCount += szValue;//�ַ�ת����
			strChCount += '\n';
		}
	}

	_itoa(lineCount, szValue, 10);
	strHead += szValue;
	strHead += '\n';
	//д�ַ���Ϣ

	strHead += strChCount;

	fwrite(strHead.c_str(),1,strHead.size(),fOut);

	//fwrite();
}

//2.txt  F:\123\2.txt
string FileCompressHuff::GetFilePostFix(const string& fileName)
{
	return fileName.substr(fileName.rfind('.'));
}
void FileCompressHuff::GenerateHuffManCode(HuffManTreeNode<charInfo> *pRoot)//����Ҷ�ӵ�·��
{
	if (nullptr == pRoot)
		return;
	
	GenerateHuffManCode(pRoot->_pLeft);
	GenerateHuffManCode(pRoot->_pRight);

	if (nullptr == pRoot->_pLeft&&nullptr == pRoot->_pRight)//�ݹ�pRoot����Ҷ�ӽڵ�
	{
		string& strCode = _fileInfo[pRoot->_weight._ch]._strCode;
		HuffManTreeNode<charInfo>* pCur = pRoot;
		HuffManTreeNode<charInfo>* pParent = pCur->_pParent;

		while (pParent)
		{
			if (pCur == pParent->_pLeft)//��������0 ������1
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

		//_fileInfo[pRoot->_weight._ch]._strCode= strCode;//_fileInfo�����ÿһ��Ԫ�ض���һ���ṹ��
	}

}
