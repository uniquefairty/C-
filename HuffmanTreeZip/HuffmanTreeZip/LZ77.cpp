#include "LZ77.h"
#include <iostream>
using namespace std;

#include <assert.h>

LZ77::LZ77()
	:_pWin(new UCH[WSIZE* 2])
	, _ht(WSIZE)
{}

LZ77::~LZ77()
{
	delete[] _pWin;
	_pWin = nullptr;
}

void LZ77::CompressFile(const std::string& strFilePath)
{

	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		cout << "打开文件失败" << endl;
		return;
	}

	//获取文件大小
	fseek(fIn,0 , SEEK_END);
	ULL fileSize=ftell(fIn);

	//1.如果源文件的大小小于MIN_MATCH，则不进行处理
	if (fileSize < MIN_MATCH)
	{
		cout << "文件太小，不压缩" << endl;
		return;
	}

	//从压缩文件中读取一个缓冲区的数据到窗口中
	fseek(fIn, 0, SEEK_SET);
	USH lookAhead=fread(_pWin, 1, 2 * WSIZE, fIn);
	USH start = 0;
	USH hashAddr = 0;

	//abcdef..先把前两个字符读到缓冲区
	for (USH i = 0; i < MIN_MATCH - 1; ++i)
		_ht.HashFunc(hashAddr,_pWin[i]);

	//压缩
	FILE* fOUT = fopen("2.lzp", "wb");
	assert(fOUT);

//	USH start = 0;
	USH matchHead = 0;
	UCH curMatchLength = 0;
	USH curMatchDist = 0;

	//当前缓冲区中剩余字节的个数
	while (lookAhead)
	{
		//1.将当前三个字符插入到哈希表中，并获取匹配链的头
		_ht.Insert(matchHead, _pWin[start + 2],start,hashAddr);

		//2.验证在查找缓冲区中是否找到匹配，如果有匹配，找最长匹配
		if (matchHead)
		{
			//顺着匹配链找最长匹配,最终带出<长度，距离>对
			curMatchLength = LongestMatch(matchHead, curMatchDist);
		}

		//3.验证是否找到匹配
		if (curMatchLength < MIN_MATCH)
		{
			//在查找缓冲区中未找到重复的字符串
			//将start位置的字符写入到压缩文件中
			++start;
			lookAhead--;
		}
		else
		{
			//找到匹配
			//将<长度,距离>对写入到压缩文件中
			//写长度
			fputc(curMatchLength, fOUT);
			//写距离
			fwrite(&curMatchDist, sizeof(curMatchDist), 1, fOUT);

			//更新先行缓冲区剩余的字节数
			lookAhead-=curMatchLength;

			//将已经匹配的字符串按照三个一组插入到哈希表中
			--curMatchLength;//当前字符串已经插入
			while (curMatchLength)
			{
				start++;
				_ht.Insert(matchHead, _pWin[start], start, hashAddr);
				curMatchLength--;
			}
		}
	}
}

UCH LZ77::LongestMatch(USH matchHead, USH& curMatchDist)
{
	return 0;
}
