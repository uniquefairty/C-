//#include "HuffmanTree.hpp"
#include "FileCompressHuff.h"

#include "LZ77.h"

#if 0
int main()
{
	//TestHuffManTree();
	FileCompressHuff fc;

	//ѹ���ı��ļ�
	fc.CompressFile("1.txt");
	fc.UNCompressFile("2.txt");

	//ѹ����Ƭ
	//fc.CompressFile("1.png");
	//fc.UNCompressFile("2.png");
	return 0;
}

#endif 

#if 1
//LZ77�㷨�ļ��
//Դ�ļ���10.txt  ѹ���ļ���11.lzp  ����ļ���12.txt  ��ѹ���ļ���13.txt
#include <windows.h>
#include <iostream>
int main()
{
	LZ77 lz;
	long t1 = GetTickCount();
	lz.CompressFile("10.txt");
	lz.UNCompressFile("11.lzp");
	long t2 = GetTickCount();
	cout << "����ʱ��" << (t2 - t1) << endl;
	
	return 0;
}
#endif

