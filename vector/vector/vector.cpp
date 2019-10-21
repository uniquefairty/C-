#include<iostream>
using namespace std;
//#include<vector>
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
//resize����Ԫ�ص���Ч����
void TestVector3()
{
	vector<vector<int>> vv;
	vv.resize(10);//�����ܵ�����

	//��ÿ������Ԫ��
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
	//foo.reserve(100);//������ǰ��������
	//foo[0] = 10;//���ʴ�������ЧԪ��
	sz = foo.capacity();
	std::cout << "making foo grow:\n";

	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);//SeqList���ݷ�ʽ�������¿ռ䣬����Ԫ�� �ͷžɿռ�
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

	//��������������ָ���һ�����ͣ����Խ�����������Ķ��󵱳���ָ��ķ�ʽ����Ӧ��
	//���ã������û�͸���ģ��û�����֪���������ĵײ����ݽṹ�����������е�Ԫ��

	//vector<int>::iterator it= v.begin();
	auto it = v.begin();
	v.push_back(1);//���ܻᵼ�µ�����itʧЧ
	//�����ʽ����it���������¸�ֵ
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
		it = v.erase(it);//������Ԫ�صĵ�������ָ��ɾ��Ԫ�ص���һ��Ԫ��
		//++it;
		cout << v.size() << endl;
	}

	return 0;
}
#endif

#if 0
	//���û᲻��ʧЧ  //��

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
		
		//Ϊ���������µ����ݣ��滻��ǰ���ݲ���Ӧ���޸Ĵ�С
		v.assign(4, 100);

		cout << v.size() << endl;
		cout << v[1] << endl;

		return 0;
	}
#endif

#if 0
	///////////�������
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
			if (numRows == 0)    return ans; //��numRowsΪ�գ����ؿ�����
			for (int i = 0; i < numRows; ++i) //������һ������ֵ
			{
				for (int j = 0; j <= i; ++j)
				{
					if (j == 0 || j == i) //�����������ߵı߽磬��ֵΪ1
						ans[i].push_back(1);
					else
						ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]); //����ֵΪ��λ�����������ϵĺ�
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
			//vector�ĵ�������һ��ԭ��ָ��
			typedef T* iterator;
			//typedef const T* const_iterator;
			/////////////////////////////////
			//����������
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
				//����[first,last)����Ԫ�صĸ���
				size_t n = 0;
				auto it = first;
				while (it != last)
				{
					++it;
					++n;
				}
				_start = new T[n];
				//��[first,last)�����е�Ԫ�ط��õ�_start�Ŀռ���
				for (size_t = 0; i < n; i++)
				{
					_start[i] = *first++;
				}
				_finish = _start + n;
				_endofstorage = _start + n;
			}
			vector(const vector<T>& v)
			{
				//Ϊ����Ķ�������ռ�
				T* _start = new T[v.Capacity()];
				//�������ݣ�����ʹ��memcpy������������ͷŵ��������
				for (int i = 0; i < v.Size(); i++)
				{
					_start[i] = v[i];
					//��ɿ�������
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
			//������
			iterator begin()
			{
				return _start;
			}
			iterator end()
			{
				return _finish;
			}
			//��������
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
			//���T�����������ͣ�T()--->0
			//���T�����Զ������ͣ�T()--->���ø�����޲ι��캯��
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

			//��������
		private:
			iterator _start;
			iterator _finish;
			iterator _endofstorage;
		};
	}
#endif

#if 0
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

		//vector<int>::iterator it=v.begin();
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

		pos = find(v.begin(), v.end(), 30);
		v.erase(pos);

		for (auto e : v)
		{
			cout << e << " ";
		}


		return 0;
	}
#endif

#if 0
	int main()
	{
		int a[] = { 1, 2, 3, 4 };
		vector<int> v(a, a + sizeof(a) / sizeof(int));

		vector<int>::iterator pos = find(v.begin(), v.end(),3);
		/*v.erase(pos);
		cout << *pos << endl;*/

		//��pos������ݣ�����pos������ʧЧ
		//insert�ᵼ�µ�����ʧЧ������Ϊinsert���ܻᵼ�����ݣ����ݺ�pos��ָ��ԭ���Ŀռ�
		//��ԭ���Ŀռ��ѽ��ͷ�
		v.insert(pos, 30);
		cout << *pos << endl;
		/*v.insert(pos, 30);
		cout << *pos << endl;*/


		return 0;
	}
#endif

#if 0
	int main()
	{
		int a[] = { 1,2,3,4 };
		vector<int> v(a, a + sizeof(a) / sizeof(int));
		//erase�᷵��ɾ��λ�õ���һ��λ��                                  

		/*auto it = v.begin();
		while (it != v.end())
		{
		if (*it % 2 == 0)
		v.erase(it);

		++it;
		}*/
		//�������

		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}

		return 0;

	}
#endif

#include<assert.h>
	namespace bit
	{ 
		template<class T>
		class vector
		{
		public:
			//vector��������һ��ԭ��ָ��
			typedef T iterator;
			typedef const T* const_iterator;

			//////����������
			vector()
				:_start(nullptr)
				, _finish(nullptr)
				, _endofStoragr(nullptr)
			{}

			vector(int n, const T&data)
				:_start(new T[n])
			{
				for (size_t i = 0; i < n; ++i)
				{
					_start[i] = data;
				}
				_finish = _start + n;
				_endofStorage = _finish;
			}

			//vector(int n, const T&value = T())
			//	:_start(nullptr)
			//	, _finish(nullptr)
			//	, endofStorage(nullptr)
			//{
			//	reserve(n);
			//	while (n--)
			//	{
			//		push_back(value);
			//	}
			//}

			//���ʹ��iterator�����������ᵼ�³�ʼ���ĵ�����[first��last��ֻ����vector�ĵ�����
			//��������������������������[firsr��last]���������������ĵ�����

			template<class InputIterator>
			vector(InputIterator first, InputIterator last)
			{
				size_t n = 0;//����[first,last)������Ԫ�صĸ���
				auto it = first;
				while (it != last)
				{
					++it;
					++n;
				}

				_start = new T[n];//����ռ�

				for (size_t i = 0; i < n; i++)
				{
					_start[i] = *first++;
				}
				_finish = _start + n;
				_endofStorage = _start + n;
			}
			//vector(IntputIterator first, IntputIterator last)
			//{
			//	reserve(last - first);//����
			//	while (first != last)
			//	{
			//		push_back(*first);
			//		first++;
			//	}
			//}

			vector(const vector<T>& v)//��������
				:_start(nullptr)
				, _finish(nullptr)
				, _endofStorage(nullptr)
			{
				reserve(v.capacity());//������ͬ��������С
				iterator it = begin();//itָ����Ҫ�����Ķ���
				const_iterator vit = v.cbegin();//vitָ�򱻿����Ķ���

				while (vit != v.cend())
				{
					*it++ = *vit++;
				}

				_finish = _start + v.size();
				_endofStorage = _start + v.capacity();
			}

			vector<T>& operator=(vector<T> v)
			{
				swap(v);
				retirn *this;
			}

			~vector()
			{
				if (_start)
				{
					delete[] _start;
					_start = _finish = _endofStorage = nullptr;
				}
			}
			//////������
			iterator begin()
			{
				return _start;
			}
			iterator end()
			{
				return _finish;
			}

			const_iterator cbegin()
			{
				return _start;
			}
			const_iterator cend()
			{
				return _finish;
			}

			//////����
			size_t size()const
			{
				return _finish - start;
			}
			size_t capacity()const
			{
				return _endofStorage - _start;
			}
			bool empty()const
			{
				return _start == _finish;
			}

			void reserve(size_t newcapacity)
			{
				if (newcapacity > capacity())
				{
					
					T* temp = new T[newcapacity];//1.����ռ�
					//2.����Ԫ��
					//memset��temp��_start, size()*sizeof(T));
					size_t oldsize = size();

					if (_start)//���startָ��Ŀռ����
					{
						for (size_t i = 0; i < oldsize; i++)
							tmp[i] = _start[i];
					}

					_start = tmp;
					_finish = _start + oldsize;
					_endofStorage = _start + newcapacity;
				}
			}

			void resize(size_t n, const T& value = T())
			{
				//1.���С�ڵ�ǰ��size�������ݸ�����С
				if (n <= size())
				{
					_finish = _start + n;
					return;
				}

				//2.�ռ䲻��������
				if (n > capacity())
				{
					reserve(n);
				}

				//3.��size����n
				iterator it = _finish;
				iterator _finish = _start + n;
				while (it != _finish)
				{
					*it = value;
					it++;
				}
			}
			//////���ʲ���
			T& operator[](size_t pos)
			{
				assert(pos < size());
				return _start[pos];
			}
			const T& operator[](size_t pos)const
			{
				assert(pos < size());
				return _start[pos];
			}
			T& front()
			{
				return *_start;
			}
			const T& front()const
			{
				return *_start;
			}
			T& back()
			{
				return *(_finish - 1);
			}
			const T&back()const
			{
				return *(finish - 1);
			}
			//////�޸Ĳ���

			void push_back(const T& x)
			{
				insert(end(), x);
			}
			void pop_back()
			{
				erase(--end());
			}
			void swap(vector<T>& v)
			{
				swap(_start, v._start);
				swap(_finish, v._finish);
				swap(_endofStorage, v._endofStorage);
			}

			iterator insert(iterator pos, const T& x)
			{
				assert(pos <= _finish);

				//�ռ䲻����������
				if (_finish == _endofStorage)//����Ƿ���Ҫ����
				{
					//size_t size = size();
					size_t newcapacity = (0 == capacity()) ? 1 : capacity() * 2;
					reserve(newcapacity);

					//����������ݣ���Ҫ����pos????/��?????????????????????????????????????????????????????
					//pos = _start + size;

				}
				iterator end = _finish - 1;
				while (end >= pos)
				{
					*(end + 1) = *end;
					--end;
				}

				//������Ԫ��
				*pos = x;
				++_finish;
				return pos;
			}

			//����ɾ�����ݵ���һ������
			iterator erase(iterator pos)
			{
				auto it = pos + 1;//pos���������Ԫ�ص�λ��
				while (it != _finish)
				{
					*(it - 1) = *it;
					++it;
				}
				--_finish;
				return pos;
			}

		private:
			iterator _start;//ָ�����ݿ�Ŀ�ʼ
			iterator _finish;//ָ����Ч���ݵ�β
			iterator _endofStorage;//ָ��洢������β
		};

	}
	int main()
	{
		return 0;
	}