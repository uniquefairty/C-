#include<iostream>
using namespace std;

#if 0
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Swap(double& left, double& right)
{
	double temp = left;
	left = right;
	right = temp;
}
void Swap(char& left, char& right)
{
	char temp = left;
	left = right;
	right = temp;
}
#endif 

#if 0
//�������޹�
//Add����ģ��
template<class T>//ģ������б�
T Add(T left, T right)//�����б�
{
	cout << typeid(T).name() << endl;
	return left + right;
}

//template<class T1, class T2>
//T1 Add(T1 left,T2 right)
//{
//	cout << typeid(T1).name() << " " << typeid(T2).name() << endl;
//	return left + right;
//}
int main()
{
	//�Ժ���ģ�����ʵ����
	//�ڱ���׶Σ������������⵽��ĳ������ģ�������ʵ����
	//��ʵ�ε����ͽ������ݣ��������ݽ����ȷ��ģ������б�T��ʵ������
	//��Ϻ���ģ�����ɾ������͵ĺ���
	Add(1, 2);
	Add(1.0, 2.0);
	Add('1', '2');
	//ģ�����һ�㲻��������ת��
	Add(1,(int) 1.0);//��ʽʵ����

	Add<int>(1, 2.0);//�����������ܽ�����ʽ����ת��
	return 0;
}
#endif

#if 0
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	int a1 = 10, a2 = 20;
	double b1 = 2.0, b2 = 9.0;

	Add(a1, a2);
	Add(b1, b2);
	//��ʽʵ����
	Add<int>(a1, b1);
	return 0;
}
#endif

#if 0
//һ����ģ�庯�����Ժ�һ��ͬ����ģ�庯��ͬʱ���ڣ�
//���Ҹú���ģ�廹���Ա�ʵ����Ϊ�����ģ�庯��
int Add(int left, int right)
{
	return left + right;
}

template<class T>
T Add(T left, T right)
{
	return left + right;
}

void Test()
{
	Add(1, 2);//���ģ�庯��ƥ�䣬����������Ҫת��
	Add<int>(1, 2);//���ñ������ض���Add�İ汾
}

int main()
{
	Test();
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T1,class T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2);//��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
	Add(1, 2.0);//ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����

	return 0;
}
#endif

