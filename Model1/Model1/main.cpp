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

#include<assert.h>
//typedef int DateType;

//��̬����˳���
template<class T>
class SeqList
{
public:
	SeqList(size_t capacity=10)
		:_array(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	~SeqList()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	void PushBack(const T& data);//β��
	void PopBack()
	{
		_size--;
	}
	//����λ�ò����ɾ��
	void Insert(size_t pos, const T& data)
	{
		_CheckCapacity();
		for (size_t i = _size-1; i >=pos; i--)
		{
			_array[i + 1] = _array[i];
		}
		_array[pos] = data;
		_size++;
	}
	void Erase(size_t pos)
	{
		for (size_t i = pos; i < _size; i++)
		{
			_array[i] = _array[i + 1];
		}
		_size--;
	}

	//��const���ͳ�Ա�����в����޸ĳ�Ա����
	//����thisָ��
	size_t size() const
	{
		return _size;
	}
	size_t Capacity()const
	{
		return _capacity;
	}
	bool Empty()const
	{
		return 0 == _size;
	}

	T& operator[](size_t index)
	{
		assert(index < _size);
		return _array[index];
	}

	const T&operator[](size_t index)const
	{
		assert(index < _size);
		return _array[index];
	}

private:
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			//�����¿ռ�
			T* array = new T[2 * _capacity];
			//����Ԫ��
			//memcpy(array, _array, _size*sizeof(T));
			for (size_t i = 0; i < _size; ++i)
			{
				array[i] = _array[i];
			}
			//�ͷžɿռ�
			delete[] _array;
			_array = array;
			_capacity *= 2;
		}
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

//ע�⣺��ģ���еĺ�������������ж���ʱ����Ҫ��ģ������б�
template<class T>
void SeqList<T>::PushBack(const T& data)
{
	_CheckCapacity();
	_array[_size++] = data;
}

void TestSeqList()
{
	SeqList<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	cout << s1.size() << endl;
	cout << s1.Capacity() << endl;
	s1.Insert(2, 8);
	cout << s1[2] << endl;
	s1[2] = 10;

	const SeqList<double> s2;
	//s2[0];

}

int main()
{
	TestSeqList();
	return 0;
}