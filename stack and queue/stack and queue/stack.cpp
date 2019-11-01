#include<iostream>
using namespace std;
#include<stack>

class MinStack
{
public:
	void push(int x)
	{
		_elem.push(x);//只要是压栈，先将元素保存到_elem中
		//如果x小于_min中栈顶元素，将x再压入_min中
		if (_min.empty() || x <= _min.top())
			_min.push(x);
	}
	void pop()
	{
		//如果_min栈顶的元素等于出栈的元素，_min顶的元素要移除

		if (_min.top() == _elem.top())
			_min.pop();
		_elem.pop();
	}
	int top()
	{
		return _elem.top();
	}
	int getMin()
	{
		return _min.top();
	}
private:
	stack<int> _elem;//保存栈中数据
	stack<int> _min;//保存栈中最小值
};