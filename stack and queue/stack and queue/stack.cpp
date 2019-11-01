#include<iostream>
using namespace std;
#include<stack>

class MinStack
{
public:
	void push(int x)
	{
		_elem.push(x);//ֻҪ��ѹջ���Ƚ�Ԫ�ر��浽_elem��
		//���xС��_min��ջ��Ԫ�أ���x��ѹ��_min��
		if (_min.empty() || x <= _min.top())
			_min.push(x);
	}
	void pop()
	{
		//���_minջ����Ԫ�ص��ڳ�ջ��Ԫ�أ�_min����Ԫ��Ҫ�Ƴ�

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
	stack<int> _elem;//����ջ������
	stack<int> _min;//����ջ����Сֵ
};