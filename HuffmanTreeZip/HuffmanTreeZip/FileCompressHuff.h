#pragma once
#include <string>
#include <vector>

struct charInfo
{
	char _ch;  //具体的字符
	size_t _count;  //字符出现的次数
	std::string _strCode; //字符的编码

	charInfo(size_t count=0)
		:_count(count)
	{}

	charInfo operator+(const charInfo& c)
	{
		return charInfo(_count + c._count);
	}

	bool operator>(const charInfo& c)
	{
		return _count > c._count;
	}
};

class FileCompressHuff
{
public:
	FileCompressHuff();
	void CompressFile(const std::string& path);
	void UNCompressFile(const std::string& path);

private:
	std::vector<charInfo> _fileInfo;
};