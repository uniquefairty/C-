//#include "HuffmanTree.hpp"
#include "FileCompressHuff.h"

#include "LZ77.h"

#if 0
int main()
{
	//TestHuffManTree();
	FileCompressHuff fc;

	//压缩文本文件
	fc.CompressFile("1.txt");
	fc.UNCompressFile("2.txt");

	//压缩照片
	//fc.CompressFile("1.png");
	//fc.UNCompressFile("2.png");
	return 0;
}

#endif 

#if 1
//LZ77算法的检测
//源文件：10.txt  压缩文件：11.lzp  标记文件：12.txt  解压缩文件：13.txt
#include <windows.h>
#include <iostream>
int main()
{
	LZ77 lz;
	long t1 = GetTickCount();
	//lz.CompressFile("10.txt");
	//lz.CompressFile("C语言关键字.jpg");
	//lz.CompressFile("二叉树.jpg");
	//lz.CompressFile("LZ77.txt");
	//lz.CompressFile("Allen老师叫早2.mp3");
	//lz.CompressFile("天亮以前说再见_20160105691321.mp3");

	lz.CompressFile("LZ77.bin");


	lz.UNCompressFile("11.lzp");
	long t2 = GetTickCount();
	cout << "运行时间" << (t2 - t1) << endl;
	
	return 0;
}
#endif

