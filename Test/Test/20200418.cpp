#if 0
#include <iostream>
using namespace std;
#include <string>
int main()
{
	string str;
	cin >> str;
	string res,h;
	//reverse(str.begin(),str.end());
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i]>127)
		{
			h = str[i];
			h += str[i - 1];
			i -= 2;
			res += h;
		}
		else
		{
			res += str[i];
		}
	}
	cout << res;
	cout << str;
	return 0;
}
#endif

#if 0

#include<iostream>
#include<Windows.h>

//实现字符串的逆转(汉字,字母,数字)

using namespace std;

#define MAX 1000

void res(char *s) //逆序(带中文)字符串
{
	if (!*s) { return; }//判断指针是否为空;
	int len = strlen(s);//字符串长度;
	char *p = new char[len + 1];//申请堆空间存放字符串
	for (int i = 0, t = len - 1; s[i];)
	{
		if (s[i] > 0) {//非汉字一个一个字符逆转;
			p[t--] = s[i++];
		}
		else{//汉字两个两个字符逆转;
			p[t - 1] = s[i];
			p[t] = s[i + 1];
			t -= 2;
			i += 2;
		}
	}
	memcpy_s(s, len, p, len);//把p里面的数据拷贝到s里面去,len是字符串的长度;
	delete[]p; //释放堆空间
}
int main()
{
	char a[MAX] = { 0 };
	cout << "输入一个字符串:";
	cin >> a;
	res(a);
	cout << "逆转后:" << a << endl;
	system("pause");
}
#endif

