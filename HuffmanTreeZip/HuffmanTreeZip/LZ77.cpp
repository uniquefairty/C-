#include "LZ77.h"
#include <iostream>
using namespace std;

#include <assert.h>


const USH MIN_LOOKAHEAD = MAX_MATCH + MIN_MATCH + 1;
const USH MAX_DIST = WSIZE - MIN_LOOKAHEAD;

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
		cout << "���ļ�ʧ��" << endl;
		return;
	}

	//��ȡ�ļ���С
	fseek(fIn,0 , SEEK_END);
	ULL fileSize=ftell(fIn);

	//1.���Դ�ļ��Ĵ�СС��MIN_MATCH���򲻽��д���
	if (fileSize < MIN_MATCH)
	{
		cout << "�ļ�̫С����ѹ��" << endl;
		return;
	}

	//��ѹ���ļ��ж�ȡһ�������������ݵ�������
	fseek(fIn, 0, SEEK_SET);
	size_t lookAhead=fread(_pWin, 1, 2 * WSIZE, fIn);
	USH start = 0;
	USH hashAddr = 0;

	//abcdef..�Ȱ�ǰ�����ַ�����������
	for (USH i = 0; i < MIN_MATCH - 1; ++i)
		_ht.HashFunc(hashAddr,_pWin[i]);

	//ѹ��
	FILE* fOUT = fopen("11.lzp", "wb");
	assert(fOUT);


	//������ƥ����صı���
	USH matchHead = 0;
	USH curMatchLength = 0;//�����Ա���258
	USH curMatchDist = 0;

	//��д�����صı���
	UCH chFlage = 0;
	UCH bitCount = 0;
	bool isLen = false;

	//д��ǵ��ļ�
	FILE* fOutF = fopen("12.txt", "wb");
	assert(fOutF);

	//��ǰ��������ʣ���ֽڵĸ���
	while (lookAhead)
	{
		//1.����ǰ�����ַ�(start,start+1,start+2)���뵽��ϣ���У�����ȡƥ������ͷ
		_ht.Insert(matchHead, _pWin[start + 2],start,hashAddr);

		curMatchLength = 0;
		curMatchDist = 0;
		//2.��֤�ڲ��һ��������Ƿ��ҵ�ƥ�䣬�����ƥ�䣬���ƥ��
		if (matchHead)
		{
			//˳��ƥ�������ƥ��,���մ���<���ȣ�����>��
			curMatchLength = LongestMatch(matchHead, curMatchDist,start);
		}

		//3.��֤�Ƿ��ҵ�ƥ��
		if (curMatchLength < MIN_MATCH)
		{
			//�ڲ��һ�������δ�ҵ��ظ����ַ���
			//��startλ�õ��ַ�д�뵽ѹ���ļ���
			fputc(_pWin[start], fOUT);

			//д��ǰԴ�ַ���Ӧ�ı��
			WriteFlage(fOutF, chFlage, bitCount, false);
			++start;
			lookAhead--;
		}
		else
		{
			//�ҵ�ƥ��
			//��<����,����>��д�뵽ѹ���ļ���
			//д����
			UCH chLen = curMatchLength - 3;
			fputc(curMatchLength-3, fOUT);
			//д����
			fwrite(&curMatchDist, sizeof(curMatchDist), 1, fOUT);

			//д��ǰԴ�ַ���Ӧ�ı��
			WriteFlage(fOutF, chFlage, bitCount, true);

			//�������л�����ʣ����ֽ���
			lookAhead-=curMatchLength;

			//���Ѿ�ƥ����ַ�����������һ����뵽��ϣ����
			--curMatchLength;//��ǰ�ַ����Ѿ�����
			while (curMatchLength)
			{
				start++;
				_ht.Insert(matchHead, _pWin[start+2], start, hashAddr);
				curMatchLength--;
			}
			start++;//��start��ѭ���ټ�һ��
		}

		//������л�������ʣ��ĸ���
		if (lookAhead <= MIN_LOOKAHEAD)
		{
			FillWindow(fIn,lookAhead,start);
		}
	}

	//���λ���������8������λ��110 00000
	if (bitCount > 0 && bitCount < 8)
	{
		chFlage <<= (8 - bitCount);
		fputc(chFlage, fOutF);
	}
	
	fclose(fOutF);

	//��ѹ���ļ��ͱ����Ϣ�ļ��ϲ�;�ȹر��ļ�ָ��fOutF����Ϊû��ˢ�µ��������У��޷���������
	MerageFile(fOUT, fileSize);

	fclose(fIn);
	fclose(fOUT);

	//��������������Ϣ����ʱ�ļ�ɾ��
}

void LZ77::FillWindow(FILE* fIn, size_t& lookAhead, USH& start)
{
	//ѹ���Ѿ����е��Ҵ������л�����ʣ������ݲ���MIN_LOOKAHEAD
	if (start >= WSIZE)
	{
		//1.���Ҵ������ݰ��Ƶ���
		memcpy(_pWin, _pWin + WSIZE, WSIZE);
//		memcpy(_pWin + WSIZE, 0, WSIZE);
		start -= WSIZE;
		//2.���¹�ϣ��
		_ht.Updata();

		//3.���Ҵ��в���WSIZE���Ĵ�ѹ������
		if (!feof(fIn))
			lookAhead = fread(_pWin + WSIZE, 1, WSIZE, fIn);
	}

}


//��ѹ���ļ��ͱ����Ϣ�ļ��ϲ�
void  LZ77::MerageFile(FILE* fOUT,  ULL fileSize)
{
	//1.��ȡ�����Ϣ�ļ������ݣ�Ȼ�󽫽��д�뵽ѹ���ļ���
	FILE* fInF = fopen("12.txt", "rb");
	size_t flagSize = 0;
	UCH* pReadbuff = new UCH[1024];
	while (true)
	{
		size_t rdSize = fread(pReadbuff, 1, 1024, fInF);
		if (0 == rdSize)
			break;

		fwrite(pReadbuff, 1, rdSize, fOUT);
		flagSize += rdSize;
	}
	//2.��������Ϣ���ֽ���  && �����ļ��Ĵ�С
	fwrite(&flagSize, sizeof(flagSize), 1, fOUT);
	fwrite(&fileSize, sizeof(fileSize), 1, fOUT);
	
	delete[] pReadbuff;
	fclose(fInF);
}



//chFlage:���ֽ��е�ÿ������λ�������ֵ�ǰ�ֽ���Դ�ַ����ǳ��ȣ�
//0--��Դ�ַ�  1--������
//bitCount:���ֽ��ж��ٸ�����λ�Ѿ�������
//isCharOrLen��������ֽ���Դ�ַ����ǳ���
void LZ77::WriteFlage(FILE* fOutF, UCH& chFlage, UCH& bitCount, bool isLen)
{
	chFlage <<= 1;
	if (isLen)
		chFlage |= 1;

	bitCount++;
	if (bitCount == 8)
	{
		//���ñ��д�뵽ѹ���ļ���
		fputc(chFlage, fOutF);
		chFlage = 0;
		bitCount = 0;
	}
}

//ƥ�䣺���ڲ��һ������н��еģ����һ������п��ܻ��ҵ����ƥ��
//�������Ҫ���ƥ��
//ע�⣺����������״��--�������������ƥ�����
//      ƥ������MAX_DIST��Χ�ڽ���ƥ�䣬̫Զ�ľ����򲻽���ƥ��

//���ҵĹ����У���Ҫ��ÿ���ҵ���ƥ�������бȽϣ��ҵ��ƥ��
USH LZ77::LongestMatch(USH matchHead, USH& MatchDist,USH start)
{
	USH curMatchLen = 0;  //һ��ƥ��ĳ���
	USH maxMatchLen = 0;  //����ƥ�䳤��
	UCH maxMatchCount = 255; //����ƥ������������״��
	USH curMatchStart = 0;  //��ǰƥ���ڲ��һ���������ʼλ��

	//�����л������в��һ�����ʱ������̫Զ���ܳ���MAX_DIST
	USH limit = start > MAX_DIST ? start - MAX_DIST : 0;

	do
	{
		//ƥ�䷶Χ
		//���л���������ʼλ�úͽ�βλ��
		UCH* pstart = _pWin + start;
		UCH* pend = pstart + MAX_MATCH;

		//���һ�����ƥ�䴮����ʼ
		UCH* pMatchStart = _pWin + matchHead;
		curMatchLen = 0;

		//���Խ��б���ƥ��
		while (pstart < pend && *pstart == *pMatchStart)
		{
			curMatchLen++;
			pstart++;
			pMatchStart++;
		}

		//һ��ƥ�����
		if (curMatchLen > maxMatchLen)
		{
			maxMatchLen = curMatchLen;
			curMatchStart = matchHead;
		}
	} while ((matchHead=_ht.GetNext(matchHead))>limit && maxMatchCount--);//��ֹ��ѭ��maxMatchCount--

	MatchDist = start - curMatchStart;
	return maxMatchLen;
}

void LZ77::UNCompressFile(const std::string& strFilePath)
{
	//��ѹ���ļ�
	FILE* fInD = fopen(strFilePath.c_str(), "rb");//ָ��ѹ�����ݵ�ָ��
	if (nullptr == fInD)
	{
		cout << "ѹ���ļ�ʧ��" << endl;
		return;
	}

	//����������ݵ��ļ�ָ��
	FILE* fInF = fopen(strFilePath.c_str(), "rb");//ָ������Ϣ��ָ��
	if (nullptr == fInF)
	{
		fclose(fInD);
		cout << "ѹ���ļ�ʧ��" << endl;
		return;
	}
	//��ȡԴ�ļ��Ĵ�С
	ULL fileSize = 0;
	fseek(fInF, 0 - sizeof(fileSize), SEEK_END);
	fread(&fileSize, sizeof(fileSize), 1, fInF);

	//��ȡ�����Ϣ�Ĵ�С
	size_t flagSize = 0;
	fseek(fInF, 0-sizeof(fileSize)-sizeof(flagSize), SEEK_END);
	fread(&flagSize, sizeof(flagSize), 1, fInF);

	//����ȡ�����Ϣ�ļ���ָ���ƶ������������ݵ���ʼλ��
	fseek(fInF, 0 - sizeof(flagSize) -sizeof(fileSize)- flagSize, SEEK_END);


	//д��ѹ��������
	FILE* fOut = fopen("14.txt", "wb");
	assert(fOut);

	FILE* fR = fopen("14.txt", "rb");//��λǰ����ƥ����ļ�ָ��
	assert(fR);
	UCH bitCount = 0;
	UCH chFlage = 0;
	ULL encodeCount = 0;

	while (encodeCount<fileSize)
	{
		//��ȡ���
		if (0 == bitCount)
		{
			chFlage=fgetc(fInF);//��ָ������Ϣ�ļ�ָ���ж�ȡ8������λ�ı����Ϣ
			bitCount = 8;
		}

		if (chFlage & 0x80)
		{
			//���볤�ȶ�
			USH matchLen = fgetc(fInD)+3;
			USH matchDist = 0;
			fread(&matchDist, sizeof(matchDist), 1, fInD);//fInDָ��ѹ�����ݵ�ָ��

			//��ջ�������ϵͳ�Ὣ���������д�뵽�ļ���
			fflush(fOut);

			//���½�����ֽ�����С
			encodeCount += matchLen;

			//��λǰ����ƥ����ļ�ָ��
			//fR:��ȡǰ��ƥ�䴮�е�����
			UCH ch;
			fseek(fR, 0-matchDist, SEEK_END);
			while (matchLen)
			{
				ch = fgetc(fR);
				fputc(ch, fOut);
				matchLen--;

				//�ڻ�ԭ���Ⱦ����ʱ��һ��Ҫ��ջ�����������ỹԭ����
				fflush(fOut);

			}
		}
		else
		{
			//Դ�ַ�
			UCH ch = fgetc(fInD);
			fputc(ch, fOut);
			encodeCount += 1;
		}
		chFlage <<= 1;
		bitCount--;
	}
	
	fclose(fInD);
	fclose(fInF);
	fclose(fOut);
	fclose(fR);
}