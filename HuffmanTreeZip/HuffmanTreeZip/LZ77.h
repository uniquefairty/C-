#pragma once
#include <string>
#include "LZHashTable.h"

class LZ77
{
public:
	LZ77();
	~LZ77();
	void CompressFile(const std::string& strFilePath);
	void UNCompressFile(const std::string& strFilePath);
private:
	USH LZ77::LongestMatch(USH matchHead, USH& curMatchDist,USH start);
	void WriteFlage(FILE* fOut,UCH& chFlage,UCH& bitCount,bool isCharOrLen );

private:
	UCH* _pWin;  //用来保存待压缩数据的缓冲区
	LZHashTable _ht;
};