//#include <iostream>
//using namespace std;
//#include <vector>
////记录每张牌的个数
////尽量是顺子或数字连续的三队
//bool Double(vector<int>& v,int i)//数字i相同的牌
//{
//	if (v[i] >= 2)
//	{
//		v[1] -= 2;
//		return true;
//	}
//	return false;
//}
//
//bool Fun1(vector<int>& v,int i)//顺子
//{
//	int count = 5;
//	while (count)
//	{
//		if (v[i]>0)
//		{
//			count--;
//			i++;
//		}
//		else return false;
//	}
//	return true;
//}
//bool Fun2(vector<int>& v,int i)//连对
//{
//	int count = 3;
//	while (count)
//	{
//		if (v[i]>1)
//		{
//			count--;
//			i++;
//		}
//		else return false;
//	}
//	return true;
//}
//int main()
//{
//	vector<int> v;
//	v.resize(10);
//	int count = 0;
//	for (int i = 0; i<v.size(); i++)
//	{
//		cin >> v[i];
//	}
//
//	for (int i = 0; i<v.size(); i++)
//	{
//		if (Fun1(v,i))//顺子
//		{
//			int t = 5;
//			while (t--)
//			{
//				v[i]--;
//			}
//			count++;
//		}
//	}
//	return 0;
//}



#if 0
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
int main()
{
	int num;
	cin >> num;
	vector<string> v;
	v.resize(num);
	string maxstr;
	for (int i = 0; num; i++, num--)
	{
		string str;
		cin >> str;
		v[i] += str;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i<v.size(); i++)
	{
		maxstr += v[i];
		for (int j = 1; j<v.size(); j++)
		{

		}
	}

	return 0;
}

#endif

#if 0
int strcmp(char *source, char *dest)//比较
{
	int i = 0;
	while (1)
	{
		if (*source == *dest)
		{
			source++;
			dest++;
		}
		else return -1;
	}
	return 0;
	
}

#endif


//CComplex& operator=(const CComplex& c)
//{
//	m_real = c.mreal;
//	m_image = c.m_image;
//}

//#include<stdio.h>
//#include <iostream>
//using namespace std;
//int main()
//{
//	unsigned  char  a = 2, b = 4, c = 5, d;
//	d = a | b;  d &= c;  
//	cout << d;
//	//printf("%d\n", d);
//}
//
//
//void sort(int& array[])
//{
//	int i = 0, j = 0;
//	for (i = 0; i < array.size() - 1; i++)
//	{
//		for (j = 0; j < array.size() - 1 - i; j++)
//		{
//			if (array[j] > array[j + i])
//			{
//				int tmp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = tmp;
//			}
//		}
//	}
//}

#if 0
//二分查找
int bin_search(int *array, int array_size, int key)
{
	int start = 0;
	int end = array_size - 1;
	while (start < end)
	{
		int mid = (start+end) / 2;
		if (array[mid] < key)
		{
			start = mid + 1;
		}
		else if (array[mid] == key)
		{
			return mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	
}

#endif

#if 0
class Card
{
public:
	Card(string name,string id,string money)
		:_name(name)
		, _id(id)
		, _money(money)
	{}
	~Card
	{ }

private:
	string _name;
	string _id;
	string _money;
};
#endif

#if 0
//删除链表重复节点
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
//重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
ListNode* deleteDuplication(ListNode* pHead){
	if (pHead == NULL || pHead->next == NULL) return pHead;
	else
	{
		//新建一个节点，防止头结点要被删除
		ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
		newHead->next = pHead;
		ListNode* pre = newHead;
		ListNode* p = pHead;
		ListNode* next = NULL;
		while (p != NULL && p->next != NULL)
		{
			next = p->next;
			if (p->val == next->val)//如果当前节点的值和下一个节点的值相等
			{
				while (next != NULL && next->val == p->val)//向后重复查找
					next = next->next;
				pre->next = next;//指针赋值，就相当于删除
				p = next;
			}
			else//如果当前节点和下一个节点值不等，则向后移动一位
			{
				pre = p;
				p = p->next;
			}
		}
		return newHead->next;//返回头结点的下一个节点
	}
}

//创建节点
ListNode* CreateListNode(int val) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = val;
	node->next = NULL;
	return node;
}
//打印节点
void Print(ListNode* head) {
	ListNode* cur = head;
	while (cur->next != NULL) {
		printf("%p(%d) --> ", cur, cur->val);
		cur = cur->next;
	}
	printf("%p(%d) --> NULL", cur, cur->val);
	printf("\n");
}

int main(){
	ListNode* node1 = CreateListNode(1);
	ListNode* node2 = CreateListNode(2);
	ListNode* node3 = CreateListNode(3);
	ListNode* node4 = CreateListNode(3);
	ListNode* node5 = CreateListNode(4);
	ListNode* node6 = CreateListNode(4);
	ListNode* node7 = CreateListNode(5);
	node1->next = node2; node2->next = node3;
	node3->next = node4; node4->next = node5;
	node5->next = node6; node6->next = node7;
	Print(node1);
	deleteDuplication(node1);
	Print(node1);
	system("pause");
	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;
#include <string>
int firstUniqChar(string s) {
	// 统计每个字符出现的次数
	int count[256] = { 0 };
	int size = s.size();
	for (int i = 0; i < size; ++i)
		count[s[i]] += 1;
	// 按照字符次序从前往后找只出现一次的字符
	for (int i = 0; i < size; ++i)
		if (1 == count[s[i]])
			return i;
	return -1;
}

int main()
{
	string s;
	cin >> s;
	cout << firstUniqChar(s) << endl;
	return 0;
}

#endif

#if 0
//返回值为函数指针
#include<iostream>
using namespace std;

int Max(int i, int j) {
	return i >= j ? i : j;
}
typedef int(*PFun)(int, int);

PFun fun(int a) {
	cout << a << endl;
	return Max;
}
int main() {
	PFun pf;
	pf = fun(100);
	int max = pf(5, 8);
	cout << "max : " << max << endl;
	return 0;
}
#endif


































