#if 0
//��ά���в���
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
	//�Ӻ���ǰ�������ַ�֮�ƶ�һ��
	//��������ָ��
	if (str == nullptr || length <= 0)
		return;
	int oldlength = 0;
	int numberOfBlack = 0;
	while (*str != '\0')
	{
		oldlength++;//ԭʼ�ַ����ĳ���
		if (*str == ' ')
			++numberOfBlack;
		str++;
	}
	int newlength = oldlength + numberOfBlack * 2;//���ַ����ĳ���
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
//�滻�ո�
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int i = length - 1, j, count = 0;
		while (i >= 0){							//�Ӻ���ǰɨ���ַ���
			if (str[i] == ' '){						//���ɨ�赽�ַ��ǿո�
				for (j = length; j >= i; j--){			//���ַ����ӿո�����'\0'�������ƶ�����λ�ã���ΪҪ�� %20
					str[j + 2] = str[j];
				}
				str[i] = '%';			//i���ǿո��λ�ã���%
				str[i + 1] = '2';		  //i+1��2
				str[i + 2] = '0';			// i+2��0
				length += 2;			//����Ҫ�Ӷ�
			}
			i--;
		}
	}
};
#endif

#if 0
//��β��ͷ��ӡ����
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
//�ؽ�������
#include<vector>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	int find_int(vector<int> v, int x)//������������и��ڵ���±�
	{
		for (size_t i = 0; i<v.size(); i++)
		{
			if (v[i] == x)
				return i;
		}
		return -1;
	}
	vector<int> Newarr(vector<int> origin, int start, int end)//�����е�����
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
		TreeNode* root = new struct TreeNode(0);//�����ڵ��ȳ�ʼ��
		root->val = pre[0];
		root->left = root->right = nullptr;//�������ڵ�

		div = find_int(vin, pre[0]);//�����и��ڵ���±�
		root->left = reConstructBinaryTree(Newarr(pre, 1, div), Newarr(vin, 0, div - 1));
		root->right = reConstructBinaryTree(Newarr(pre, div + 1, pre.size() - 1), Newarr(vin, div + 1, vin.size() - 1));
		return root;
	}
};
#endif

#if 0
//����һ����������ǰ�������������������У������Ӧ����������ĺ����������С�
#include<iostream>
using namespace std;
#include<string>
//����������
//�������������
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
	int div = vin.find(val);//��������и����±�
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
//����һ����������ǰ�������������������У������Ӧ����������ĺ����������С�
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//�������������
struct BTreeNode
{
	char data;
	BTreeNode* left;
	BTreeNode* right;
	BTreeNode(char x) :data(x), left(NULL), right(NULL){}
};

//���ݸ��ڵ㽫��������Ϊ��������
vector<char> m_copy(vector<char> &v, int l, int r)
{
	return vector<char>(v.begin() + l, v.begin() + r);
}

//����ǰ�����к����������ؽ�������
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

//�������������
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
//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
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

		//mid = (start + end) / 2;//���ܻ�����������
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
//쳲�������
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
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
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
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
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
//���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
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
