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
//与类型无关
//Add函数模板
template<class T>//模板参数列表
T Add(T left, T right)//参数列表
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
	//对函数模板进行实例化
	//在编译阶段，如果编译器检测到对某个函数模板进行了实例化
	//对实参的类型进行推演，根据推演结果，确认模板参数列表T的实际类型
	//结合函数模板生成具体类型的函数
	Add(1, 2);
	Add(1.0, 2.0);
	Add('1', '2');
	//模板参数一般不进行类型转化
	Add(1,(int) 1.0);//显式实例化
	Add<int>(1, 2.0);//编译器：可能进行隐式类型转化
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
	//显式实例化
	Add<int>(a1, b1);
	return 0;
}
#endif

#if 0
//一个非模板函数可以和一个同名的模板函数同时存在，
//而且该函数模板还可以被实例化为这个非模板函数
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
	Add(1, 2);//与非模板函数匹配，编译器不需要转化
	Add<int>(1, 2);//调用编译器特定的Add的版本
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
	Add(1, 2);//与非函数模板类型完全匹配，不需要函数模板实例化
	Add(1, 2.0);//模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数

	return 0;
}
#endif

#include<assert.h>
//typedef int DateType;

//动态类型顺序表
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
	void PushBack(const T& data);//尾插
	void PopBack()
	{
		_size--;
	}
	//任意位置插入和删除
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

	//在const类型成员函数中不能修改成员变量
	//修饰this指针
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
			//开辟新空间
			T* array = new T[2 * _capacity];
			//拷贝元素
			//memcpy(array, _array, _size*sizeof(T));
			for (size_t i = 0; i < _size; ++i)
			{
				array[i] = _array[i];
			}
			//释放旧空间
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

//注意：类模板中的函数放在类外进行定义时，需要加模板参数列表
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