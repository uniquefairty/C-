#include<iostream>
using namespace std;

#if 0
int main()
{
	int *p = (int *)malloc(sizeof(int) * 10);
	free(p);
	return 0;
}
#endif

#if 0
//new/delete new[]/delete[]
//malloc/free
//һ��Ҫƥ��ʹ��
//1.new��delete���Ǻ�����C++�ṩ��һ�ֲ�����
//2.new/new[]ֻ���������ռ����ͣ�����Ҫ�����ֽ���
//3.new����Ŀռ�����ͣ���˲���Ҫǿת
//4��new/new[]���Խ��г�ʼ��
//5.new�Ľ������Ҫ�п�
int main()
{
	int *p1 = new int;
	int *p2 = new int(10);
	int *p3 = new int[10];
	int *p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;

	return 0;
}
#endif

#if 0
//���û��ƥ��ɹ�
//��������ʱ�������͵Ŀռ䣬��������κκ��
void Test1()
{
	int *p1 = (int *)malloc(sizeof(int));
	int *p2 = (int *)malloc(sizeof(int));
	delete p1;
	delete[] p2;

	int *p3 = new int;
	int *p4 = new int;
	free(p3);
	delete[] p4;

	int *p5 = new int[10];
	int *p6 = new int[10];
	free(p5);
	delete p6;
}
//�Զ���
class Test
{
public:
	Test()
	{
		_data = 10;
		_p = new int;
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		delete _p;
		cout << "~Test()" << this << endl;
	}
private:
	int _data;
	int *_p;
};
//�����Զ������ͣ�ֻҪ�漰��[],��Ȼ�����
//new ����ù��캯��
//free�������������-�����е���Դ���ᱻ����
void Test2()
{
	//Test *p1 = (Test *)malloc(sizeof(Test));
	//Test *p2 = (Test *)malloc(sizeof(Test));
	//delete p1;
	//delete[] p2;
	//malloc����ռ�ʱ������ù��캯��--�����ʱ������С��ͬ��һ���ڴ�ռ�
	//���ܽ��ÿ��ڴ濴��һ������
	//Test *p3 = new Test;
	//Test *p4 = new Test;
	//free(p3);
	//delete[] p4;//�������
	//Test *p5 = new Test[10];
	//Test *p6 = new Test[10];
	//free(p5);
	//delete p6;
}
int main()
{
	//Test1();
	Test2();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif 

#if 0
class Test
{
public:
	Test()
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int _data;
};
int main()
{
	Test* pt = new Test[10];
	delete[] pt;
	return 0;
}
#endif

void * operator new(size_t size,const char* filename,const char * funName,size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << size << endl;
	return malloc(size);
}
void operator delete(void *p, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << endl;
	free(p);

}
//#define new new(_FILE_,_FUNCDNAME_,_LINE_)
int main()
{
	int *p = new(_FILE_, _FUNCDNAME_, _LINE_) int;
	delete p;
	return 0;
}
