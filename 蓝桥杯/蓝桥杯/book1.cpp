#if 0
//二维数中查找
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = 0;
		int col = array[0].size() - 1;
		if (array.empty())
			return false;
		while (row<array.size() && col >= 0)
		{
			if (target == array[row][col])
				return true;
			else if (target<array[row][col])
			{
				col--;
			}
			else if (target>array[row][col])
			{
				row++;
			}
		}
		return false;
		return 0;
	}
};
#endif

#if 0
void replaceSpace(char *str, int length) {
	//从后往前遍历，字符之移动一边
	//定义两个指针
	if (str == nullptr || length <= 0)
		return;
	int oldlength = 0;
	int numberOfBlack = 0;
	while (*str != '\0')
	{
		oldlength++;//原始字符串的长度
		if (*str == ' ')
			++numberOfBlack;
		str++;
	}
	int newlength = oldlength + numberOfBlack * 2;//新字符串的长度
	if (newlength>length)
		return;
	while (oldlength >= 0 && newlength >= 0)
	{
		if (str[oldlength--] == ' ')
		{
			str[newlength--] = '0';
			str[newlength--] = '2';
			str[newlength--] = '%';
		}
		else
		{
			str[oldlength] = str[newlength];
			oldlength--;
			newlength--;
		}
	}
}
#endif

#if 0
//替换空格
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int i = length - 1, j, count = 0;
		while (i >= 0){							//从后往前扫描字符串
			if (str[i] == ' '){						//如果扫描到字符是空格
				for (j = length; j >= i; j--){			//将字符串从空格到最后的'\0'都往后移动两个位置，因为要塞 %20
					str[j + 2] = str[j];
				}
				str[i] = '%';			//i就是空格的位置，放%
				str[i + 1] = '2';		  //i+1放2
				str[i + 2] = '0';			// i+2放0
				length += 2;			//长度要加二
			}
			i--;
		}
	}
};
#endif

#if 0
//从尾到头打印链表
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		while (head != NULL)
		{
			//v.push_back(head->val);
			v.insert(v.begin(), head->val);
			head = head->next;
		}
		//reverse(v.begin(), v.end());
		return v;
	}
};
#endif

#if 0
//重建二叉树
#include<vector>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	int find_int(vector<int> v, int x)//返回中序遍历中根节点的下标
	{
		for (size_t i = 0; i<v.size(); i++)
		{
			if (v[i] == x)
				return i;
		}
		return -1;
	}
	vector<int> Newarr(vector<int> origin, int start, int end)//子序列的数组
	{
		vector<int> tmp;
		int now = start;
		for (; now <= end; now++)
		{
			tmp.push_back(origin[now]);
		}
		return tmp;
	}
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty())
			return nullptr;
		int div;
		TreeNode* root = new struct TreeNode(0);//给根节点先初始化
		root->val = pre[0];
		root->left = root->right = nullptr;//构建根节点

		div = find_int(vin, pre[0]);//中序中根节点的下标
		root->left = reConstructBinaryTree(Newarr(pre, 1, div), Newarr(vin, 0, div - 1));
		root->right = reConstructBinaryTree(Newarr(pre, div + 1, pre.size() - 1), Newarr(vin, div + 1, vin.size() - 1));
		return root;
	}
};
#endif

#if 0
//给定一个二叉树的前序遍历和中序遍历的序列，输出对应这个二叉树的后续遍历序列。
#include<iostream>
using namespace std;
#include<string>
//构建二叉树
//后序遍历二叉树
struct BTreeNode
{
	BTreeNode *left;
	BTreeNode *right;
	char val;
	BTreeNode(int x) :val(x), left(nullptr), right(nullptr)
	{}
};
BTreeNode *CreatTree(string pre, string vin)
{
	char val = pre[0];
	BTreeNode *root = new BTreeNode(pre[0]);
	root->val = val;
	root->left = root->right = nullptr;
	int div = vin.find(val);//存放中序中根的下标
	if (div == string::npos)
		return nullptr;
	int preleftlength = div;
	root->left = CreatTree(pre.substr(1, div), vin.substr(0, div));
	root->right = CreatTree(pre.substr(div + 1, pre.size() - div - 1),
		vin.substr(div + 1, vin.size() - div - 1));
	return root;
}

void PastOrder(BTreeNode* p)
{
	if (p == nullptr)
		return;
	PastOrder(p->left);
	PastOrder(p->right);
	cout << p->val;
}
int main()
{
	string pre, vin;
	while (cin >> pre >> vin)
	{
		BTreeNode * res=CreatTree(pre, vin);
		PastOrder(res);
	}
	return 0;
}
#endif

#if 0
//给定一个二叉树的前序遍历和中序遍历的序列，输出对应这个二叉树的后续遍历序列。
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//构建二叉树结点
struct BTreeNode
{
	char data;
	BTreeNode* left;
	BTreeNode* right;
	BTreeNode(char x) :data(x), left(NULL), right(NULL){}
};

//根据父节点将二叉树分为左右子树
vector<char> m_copy(vector<char> &v, int l, int r)
{
	return vector<char>(v.begin() + l, v.begin() + r);
}

//根据前序序列和中序序列重建二叉树
BTreeNode* reConstructBTree(vector<char> pre, vector<char> vin)
{
	if (pre.size() == 0 || vin.size() == 0)
		return NULL;

	BTreeNode* node = new BTreeNode(pre[0]);

	for (unsigned long i = 0; i < vin.size(); ++i)
	{
		if (pre[0] == vin[i])
		{
			node->left = reConstructBTree(m_copy(pre, 1, i + 1), m_copy(vin, 0, i));
			node->right = reConstructBTree(m_copy(pre, i + 1, pre.size()), m_copy(vin, i + 1, vin.size()));
		}
	}
	return node;
}

//后序遍历二叉树
void PastOrder(BTreeNode* p)
{
	if (p == NULL)
		return;

	PastOrder(p->left);
	PastOrder(p->right);
	cout << p->data;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.size() != s2.size())
	{
		return -1;
	}
	int length = s1.size();
	vector<char> pre, vin;
	for (int i = 0; i<length; i++)
	{
		pre.push_back(s1[i]);
		vin.push_back(s2[i]);
	}
	BTreeNode* res = reConstructBTree(pre, vin);
	PastOrder(res);
	return 0;
}
#endif

#if 0
#include<stack>
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int tmp;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				tmp = stack1.top();
				stack2.push(tmp);
				stack1.pop();
			}
		}
		tmp = stack2.top();
		stack2.pop();
		return tmp;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>
int minNumberInRotateArray(vector<int> rotateArray) 
{
	if (rotateArray.size() == 0)
		return 0;
	int start = 0, end = rotateArray.size() - 1;
	int mid = 0;
	while (rotateArray[start] >= rotateArray[end])
	{
		if (end - start == 1)
		{
			return rotateArray[end];
		}

		//mid = (start + end) / 2;//可能会出现数组溢出
		mid = start + (end - start) / 2;

		if (rotateArray[start] == rotateArray[end] &&
			rotateArray[mid] == rotateArray[start])
		{
			int res = rotateArray[0];
			for (int i = 1; i < rotateArray.size() - 1; i++)
			{
				if (rotateArray[i] < res)
				{
					res = rotateArray[i];
				}
			}
			return res;
		}

		if (rotateArray[start] > rotateArray[mid])
			end = mid;
		else if (rotateArray[start] < rotateArray[mid])
			start = mid;
	}
}

int main()
{
	vector<int> v{ 3, 5, 4, 1, 2 };
	cout<<minNumberInRotateArray(v);
	return 0;
}
#endif

#if 0
#include<vector>
int minNumberInRotateArray(vector<int> rotateArray) 
{
	if (rotateArray.size() == 0)
		return 0;
	int start = 0, end = rotateArray.size() - 1;
	int mid = 0;

	while (start < end){
		int mid = start + (end - start) / 2;
		if (array[mid] > array[end]){
			start = mid + 1;
		}
		else if (array[mid] == array[end])
		{
			end = end - 1;
		}
		else
		{
			end = mid;
		}
	}
	return rotateArray[start];

}
#endif

#if 0
//斐波那契数
class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 1)
			return n;

		int first = 0;
		int second = 1;
		int third = 0;
		for (int i = 2; i <= n; i++)
		{
			third = first + second;
			first = second;
			second = third;
		}
		return third;
	}
};
#endif

#if 0
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
class Solution {
public:
	int jumpFloor(int number) {
		if (number == 1)
			return 1;
		else if (number == 2)
			return 2;
		else
			return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
};
#endif 

#if 0
#include<math.h>
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
class Solution {
public:
	int jumpFloorII(int number) {
		if (number<0)
			return 0;
		return pow((float)2, number - 1);
	}
};
#endif

#if 0
//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
class Solution {
public:
	int rectCover(int number) {
		if (number<1)
			return 0;
		else if (number <= 2)
			return number;
		else return rectCover(number - 2) + rectCover(number - 1);

	}
};
#endif

#if 0
//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		for (int i = 0; i <= 32; i++)
		{
			if ((n & 0x1) == 1)
			{
				count++;
			}
			n = (unsigned)n >> 1;
		}
		return count;
	}
};
#endif

#if 0
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//保证base和exponent不同时为0
//x^11=x^8*x^2*x^1=x^2^3*x^2^1*x^2^0=(1*x^2^3)*(0*x^2^2)*(1*x^2^1)*(1*x^2^0)
//11-->1011
//所以，我们可以这样实现这个快速幂运算。
//
//step1：首先需要知道在每次循环里通过自乘计算base的2的指数次方。循环的次数就是所求指数exponent的二进制位数
//
//step2: 其次就是对于每个base的2的指数次方，乘以其相对应的二进制位上的数。
//
//step3: 循环里不断的累成step2里计算的结果。
class Solution {
public:
	double Power(double base, int exponent) {
		int num = abs(exponent);//整数可能是负数
		double res = 1.0;
		while (num)
		{
			if ((num & 1) == 1)
			{
				res *= base;
			}
			base *= base;
			num >>= 1;
		}
		if (exponent<0)//如果整数是负数
			res = 1.0 / res;
		return res;

	}
};
#endif

