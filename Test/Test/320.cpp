//#include <iostream>
//using namespace std;
//#include <vector>
////��¼ÿ���Ƶĸ���
////������˳�ӻ���������������
//bool Double(vector<int>& v,int i)//����i��ͬ����
//{
//	if (v[i] >= 2)
//	{
//		v[1] -= 2;
//		return true;
//	}
//	return false;
//}
//
//bool Fun1(vector<int>& v,int i)//˳��
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
//bool Fun2(vector<int>& v,int i)//����
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
//		if (Fun1(v,i))//˳��
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
int strcmp(char *source, char *dest)//�Ƚ�
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
//���ֲ���
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
//ɾ�������ظ��ڵ�
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
//�ظ��Ľ�㲻��������������ͷָ�롣
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
ListNode* deleteDuplication(ListNode* pHead){
	if (pHead == NULL || pHead->next == NULL) return pHead;
	else
	{
		//�½�һ���ڵ㣬��ֹͷ���Ҫ��ɾ��
		ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
		newHead->next = pHead;
		ListNode* pre = newHead;
		ListNode* p = pHead;
		ListNode* next = NULL;
		while (p != NULL && p->next != NULL)
		{
			next = p->next;
			if (p->val == next->val)//�����ǰ�ڵ��ֵ����һ���ڵ��ֵ���
			{
				while (next != NULL && next->val == p->val)//����ظ�����
					next = next->next;
				pre->next = next;//ָ�븳ֵ�����൱��ɾ��
				p = next;
			}
			else//�����ǰ�ڵ����һ���ڵ�ֵ���ȣ�������ƶ�һλ
			{
				pre = p;
				p = p->next;
			}
		}
		return newHead->next;//����ͷ������һ���ڵ�
	}
}

//�����ڵ�
ListNode* CreateListNode(int val) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = val;
	node->next = NULL;
	return node;
}
//��ӡ�ڵ�
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
	// ͳ��ÿ���ַ����ֵĴ���
	int count[256] = { 0 };
	int size = s.size();
	for (int i = 0; i < size; ++i)
		count[s[i]] += 1;
	// �����ַ������ǰ������ֻ����һ�ε��ַ�
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
//����ֵΪ����ָ��
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


































