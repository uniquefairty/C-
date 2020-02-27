//#include "HuffmanTree.hpp"
#include "FileCompressHuff.h"

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