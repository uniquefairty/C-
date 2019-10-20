#include<iostream>
using namespace std;
#include<vector>
#if 0
void TestVector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(v2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));

	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	for (auto e : v3)
		cout << e << " ";
	cout << endl;

	//vector<int>::iterator it = v4.begin();
	auto it1 = v4.begin();

	while (it1 != v4.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	auto it2 = v5.rbegin();
	while (it2 != v5.rend())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}

void TestVector2()
{
	vector<int> v5{ 1, 2, 3, 4, 5, 6, 7};
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);
	cout << v5.size() << endl;
	cout << v5.capacity() << endl;
	cout << v5.front() << endl;
	cout << v5.back() << endl;

	v5.erase(v5.begin());
	v5.erase(v5.end()-1);

	auto pos = find(v5.begin(), v5.end(), 5);
	if (pos != v5.end())
		v5.erase(pos);

	v5.clear();

}
//resize设置元素的有效个数
void TestVector3()
{
	vector<vector<int>> vv;
	vv.resize(10);//设置总的行数

	//给每行设置元素
	for (size_t i = 0; i < 10; i++)
	{
		vv[i].resize(10, 6);
	}
}

int main()
{
	TestVector1();
	//TestVector2();
	//TestVector3();
	return 0;
}
#endif

#if 0
int main()
{
	size_t sz;
	std::vector<int> foo;
	//foo.reserve(100);//可以提前增加容量
	//foo[0] = 10;//访问错误，无有效元素
	sz = foo.capacity();
	std::cout << "making foo grow:\n";

	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);//SeqList扩容方式：开辟新空间，拷贝元素 释放旧空间
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed:" << sz << '\n';
		}

	}
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//v.reserve(100);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//迭代器：类似是指针的一种类型，可以将迭代器定义的对象当成是指针的方式进行应用
	//作用：帮助用户透明的（用户不用知道该容器的底层数据结构）遍历容器中的元素

	//vector<int>::iterator it= v.begin();
	auto it = v.begin();
	v.push_back(1);//可能会导致迭代器it失效
	//解决方式：给it迭代器重新赋值
	it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	//v.resize(0);
	//v.clear();
	v.erase(v.begin(), v.end());
	cout << v.size() << endl;

	auto it = v.begin();
	while (it != v.end())
	{
		it = v.erase(it);//返回新元素的迭代器，指向被删除元素的下一个元素
		//++it;
		cout << v.size() << endl;
	}

	return 0;
}
#endif

#if 0
	//引用会不会失效  //会

	int main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		int& ra = v[0];
		ra = 10;
		cout << ra << endl;
		v.push_back(1);

		//ra = 100;
		return 0;
	}
#endif

#if 0
	int main()
	{
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		
		//为向量分配新的内容，替换当前内容并相应的修改大小
		v.assign(4, 100);

		cout << v.size() << endl;
		cout << v[1] << endl;

		return 0;
	}
#endif

#if 0
	///////////杨辉三角
	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {

			vector<vector<int>> vv;

			vv.reserve(numRows);

			for (int i = 1; i <= numRows; ++i)
			{
				vv[i].resize(i, 0);
				vv[i - 1][0] = 1;
				vv[i - 1][i - 1] = 1;

			}

			for (size_t i = 0; i<vv.size(); ++i)
			{
				for (size_t j = 0; j<vv[i].size(); j++)
				{
					if (vv[i][j] == 0)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}

				}

			}
			return vv;

		}
	};
	int main()
	{
		return 0;
	}

#endif

#if 0
	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> ans(numRows);
			if (numRows == 0)    return ans; //若numRows为空，返回空数组
			for (int i = 0; i < numRows; ++i) //给数组一个个赋值
			{
				for (int j = 0; j <= i; ++j)
				{
					if (j == 0 || j == i) //若是左右两边的边界，赋值为1
						ans[i].push_back(1);
					else
						ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]); //否则赋值为该位置左上与右上的和
				}
			}
			return ans;
		}
	};
#endif
#if 0

#include <iostream>
#include <vector>

	int main ()
	{
		std::vector<int> myvector (100);
		std::cout << "1. capacity of myvector: " << myvector.capacity() << '\n';

		myvector.resize(10);
		std::cout << "2. capacity of myvector: " << myvector.capacity() << '\n';

		myvector.shrink_to_fit();
		std::cout << "3. capacity of myvector: " << myvector.capacity() << '\n';

		return 0;
	}
#endif

#if 0
	int main()
	{
		int a[] = { 1, 2, 3, 4 };
		vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

		v[0] = 10;
		cout << v[0] << endl;

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		vector<int> swapv;
		swapv.swap(v);

		cout << "v data:";
		cout << v.size() << endl;
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		cout << "swapv data:";
		for (size_t i = 0; i < swapv.size(); i++)
		{
			cout << swapv[i] << " ";
		}
		cout << endl;

		for (auto x : v)
		{
			cout << x << " ";
		}
		cout << endl;

		return 0;

	}
#endif

	
#if 0
	namespace bite
	{
		template<class T>
		class
		{
		public:
			//vector的迭代器是一个原生指针
			typedef T* iterator;
			//typedef const T* const_iterator;
			/////////////////////////////////
			//构造与销毁
			vector()
				:_start(nullptr)
				, _finish(nullptr)
				, _endofstorage(nullptr)
			{}
			vector(int n, const T& data)
				:_start(new T[n])
			{
				for (size_t i = 0; i < n; i++)
				{
					_start[i] = data;
				}
				_finish = _start + n;
				_endofstorage = _finish;
			}
			//[first,last)
			template<class Iterator>
			vector(Iterator first, Iterator last)
			{
				//计算[first,last)区间元素的个数
				size_t n = 0;
				auto it = first;
				while (it != last)
				{
					++it;
					++n;
				}
				_start = new T[n];
				//将[first,last)区间中的元素放置到_start的空间中
				for (size_t = 0; i < n; i++)
				{
					_start[i] = *first++;
				}
				_finish = _start + n;
				_endofstorage = _start + n;
			}
			vector(const vector<T>& v)
			{
				//为构造的对象申请空间
				T* _start = new T[v.Capacity()];
				//拷贝内容，不能使用memcpy（）避免二次释放的情况发生
				for (int i = 0; i < v.Size(); i++)
				{
					_start[i] = v[i];
					//完成拷贝内容
				}
				_finish = _start + v.Size();
				_endofstorage = _start + v.Capacity();
			}
			vector<T>& operator=(const vector<T>& v)
			{
				Swap(v);
				teturn *this;
			}

			~vector()
			{
				if (_start)
				{
					delete[] _start;
					_start = _finish = _endofstorage=nullptr;
				}
			}
			//////////////////////////////
			//迭代器
			iterator begin()
			{
				return _start;
			}
			iterator end()
			{
				return _finish;
			}
			//容量操作
			size_t size() const
			{
				return _finish - _start;
			}
			size_t capacity() const
			{
				return _endofstorage - _start;
			}
			bool empty()const
			{
				return _start == _finish;
			}
			
			//T():
			//如果T代表内置类型，T()--->0
			//如果T代表自定义类型，T()--->调用该类的无参构造函数
			void resize(size_t newsize, const T& data = T())
			{
				size_t oldsize = size();
				if (newsize > oldsize)
				{
					size_t cap = capacity();
					if (newsize > cap)
					{
						reserve(newsize);
					}
					for (; oldsize < newsize; ++oldsize)
					{
						_start[oldsize] = data;
					}
				}
			}

			//析构函数
		private:
			iterator _start;
			iterator _finish;
			iterator _endofstorage;
		};
	}
#endif

	int main()
	{
		int a[] = { 1, 2, 3, 4 };
		vector<int> v(a, a + sizeof(a) / sizeof(a[0]));

		vector<int>::iterator pos = find(v.begin(), v.end(), 3);

		v.insert(pos, 30);

		for (size_t i=0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << '\n';

		auto it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << '\n';
		for (auto e : v)
		{
			cout << e << " ";
		}

		return 0;
	}