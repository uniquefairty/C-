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
//一定要匹配使用
//1.new和delete不是函数，C++提供的一种操作符
//2.new/new[]只需在其后根空间类型，不需要传递字节数
//3.new后跟的空间的类型，因此不需要强转
//4。new/new[]可以进行初始化
//5.new的结果不需要判空
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
//如果没有匹配成功
//如果申请的时内置类型的空间，不会产生任何后果
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
//自定义
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
//对于自定义类型，只要涉及到[],必然会崩溃
//new 会调用构造函数
//free不会调析构函数-对象中的资源不会被销毁
void Test2()
{
	//Test *p1 = (Test *)malloc(sizeof(Test));
	//Test *p2 = (Test *)malloc(sizeof(Test));
	//delete p1;
	//delete[] p2;
	//malloc申请空间时不会调用构造函数--申请的时与对象大小相同的一块内存空间
	//不能将该块内存看成一个对象
	//Test *p3 = new Test;
	//Test *p4 = new Test;
	//free(p3);
	//delete[] p4;//程序崩溃
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
	//pt现在指向的只不过是与Test对象相同大小的一段空间，还不算是一个对象，因为构造函数没有执行
	Test* pt = (Test*)malloc(sizeof(Test));
	new(pt) Test;
	//如果Test类的构造函数有参数时，需要传参
	delete pt;
	return 0;
}
//int main()
//{
//	Test* pt = new Test[10];
//	delete[] pt;
//	return 0;
//}
#endif

#if 0
//*******************************************************************
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
#endif

#if 0
struct ListNode
{
	ListNode *_next;
	ListNode *_prev;
	int _data;

	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocate" << endl;
		return p;
	}
		void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};
class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next =_head;
		_head->_prev = _head;
	}
	~List()
	{
		ListNode *cur = _head->_next;
		while (cur != _head)
		{
			ListNode * next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode *_head;
};
void TestList()
{
	List l;
}
int main()
{
	TestList();
	return 0;
}
#endif

#if 0
//设计一个类，该类只能在堆上创建对象
class Object
{
public:
	static Object* GetObject(int data)
	{
		return new Object(data);
	}
	~Object()
	{}
	//C++98
//private:
//	Object(const Object& o);
	//C++11
	//1.释放new的空间
	//2.在默认成员函数后跟上=delete,删除默认的拷贝构造函数
	Object(const Object& o) = delete;
private:
	Object(int data)
	{}
};
int main()
{
	Object *p = Object::GetObject(10);
	delete p;
	return 0;
}
#endif

#if 0
//只能在栈上创建对象
//只要将new功能屏蔽掉即可。即屏蔽掉operator new和定位new表达式。
//注意：屏蔽了operator new，实际也将定位new屏蔽掉
class Object
{
public:
	Object() {}
private:
	void* operator new(size_t size);
	void operator delete(void *p);
};
#endif

//只能在x64位的进程下运行
#if 0
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif