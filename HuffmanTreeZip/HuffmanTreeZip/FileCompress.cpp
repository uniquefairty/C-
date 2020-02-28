//#include "HuffmanTree.hpp"
#include "FileCompressHuff.h"

#include "LZ77.h"

#if 0
int main()
{
	//TestHuffManTree();
	FileCompressHuff fc;

	//压缩文本文件
	/*fc.CompressFile("1.txt");
	fc.UNCompressFile("2.txt");*/

	fc.CompressFile("1.png");
	fc.UNCompressFile("2.png");
	return 0;
}

#endif 


int main()
{
	LZ77 lz;
	lz.CompressFile("10.txt");
	return 0;
}