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

//ʵ���ַ�������ת(����,��ĸ,����)

using namespace std;

#define MAX 1000

void res(char *s) //����(������)�ַ���
{
	if (!*s) { return; }//�ж�ָ���Ƿ�Ϊ��;
	int len = strlen(s);//�ַ�������;
	char *p = new char[len + 1];//����ѿռ����ַ���
	for (int i = 0, t = len - 1; s[i];)
	{
		if (s[i] > 0) {//�Ǻ���һ��һ���ַ���ת;
			p[t--] = s[i++];
		}
		else{//�������������ַ���ת;
			p[t - 1] = s[i];
			p[t] = s[i + 1];
			t -= 2;
			i += 2;
		}
	}
	memcpy_s(s, len, p, len);//��p��������ݿ�����s����ȥ,len���ַ����ĳ���;
	delete[]p; //�ͷŶѿռ�
}
int main()
{
	char a[MAX] = { 0 };
	cout << "����һ���ַ���:";
	cin >> a;
	res(a);
	cout << "��ת��:" << a << endl;
	system("pause");
}
#endif

