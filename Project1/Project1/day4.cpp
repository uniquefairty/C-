#if 0
/*����һ��������ת��������������ı�ͷ*/

//1. ��������ָ�룬�������ƣ����ƶ����߷�ת����֤���������
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr)
		{
			return pHead;
		}
		//����ͷ��㣬������2���ڵ�
		ListNode *first = pHead; //ָ���һ���ڵ�
		ListNode *second = first->next; //ָ��ڶ����ڵ�
		ListNode *third = second->next; //ָ��������ڵ㣬����Ϊnullptr
		while (third)
		{ //��Ϊthird����ǰ�棬������һ���ȵ�nullptr��ֻҪ������Ƿ�Ϸ�����
			//��ת
			second->next = first;
			//ָ���������
			first = second;
			second = third;
			third = third->next;
		}
		second->next = first; //�����������ֻ�������ڵ� or ������ת����ʱ�����һ���ڵ㲢δ��ת
		pHead->next = nullptr; //�����ĵ�һ���ڵ㣬next������nullptr������һ��
		pHead = second; //ͷָ��ָ�����һ���ڵ�
		return pHead;
	}
};
//2. ���Բ���ͷ��˼����з�ת
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		//ͷ�巨
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;

		ListNode* new_head = nullptr;//����һ���µ�ͷ�ڵ�
		while (pHead)
		{
			ListNode* p = pHead;
			pHead = pHead->next;
			p->next = new_head;
			new_head = p;

		}
		return new_head;
	}
};

#endif


#if 0
/*���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������*/
//����һ���ȽϺ�����
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		//������ͷ���(��ʵ������ͷ���򵥣����ǰ����ѵ���)
		//�ϲ�ǰ�����ж�
		if (nullptr == pHead1){
			return pHead2;
		}
		if (nullptr == pHead2){
			return pHead1;
		}
		//�ϲ���,�޷��ǱȽϸ����׽ڵ�˭С���ͰѸýڵ��ԭ������ɾ������β�嵽�½ڵ㴦���Ƚ��У����������κ�һ
		��������Ϊ��
			ListNode *new_head = nullptr;
		ListNode *new_tail = nullptr;
		while (pHead1 && pHead2){
			//���ж����Ǹ��ڵ�
			ListNode *p = pHead1->val < pHead2->val ? pHead1 : pHead2;
			//����ָ�������У�ɾ��Ŀ��ڵ�
			if (p == pHead1){
				pHead1 = pHead1->next;
			}
			else{
				pHead2 = pHead2->next;
			}
			//β�嵽������,����Ҫ���ǵ�һ�β�������
			if (nullptr == new_head){
				new_head = p;
				new_tail = p;
			}
			else{
				new_tail->next = p;
				new_tail = p;
			}
		}
		//�ϲ��󣬿��ܻ��У�1. pHead1Ϊ�� 2. pHead2Ϊ�� 3. ��Ϊ��(�ϲ����)
		if (nullptr == pHead1){
			new_tail->next = pHead2;
		}
		else if (nullptr == pHead2){
			new_tail->next = pHead1;
		}
		����ְ����
		else{
			//do nothing
		}
		return new_head;
	}
};
//����������һ������Javaд�����ַ���������������һ��C++��
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		//������ͷ���(��ʵ������ͷ���򵥣����ǰ����ѵ���)
		//�ϲ�ǰ�����ж�
		if (nullptr == pHead1){
			return pHead2;
		}
		if (nullptr == pHead2){
			return pHead1;
		}
		//�ϲ��У��ҵ���һ���ڵ�
		ListNode *new_head = nullptr;
		if (pHead1->val < pHead2->val){
			new_head = pHead1;
			pHead1 = pHead1->next;
		}
		else{
			new_head = pHead2;
			pHead2 = pHead2->next;
		}
		//�ϲ�ʣ�µĽڵ�
		new_head->next = Merge(pHead1, pHead2);
		return new_head;
	}
};

#endif

#if 0
/*��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ��
�磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5*/
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (nullptr == pHead){
			return pHead;
		}
		//���ǵ������ȫ����ͬ������ͷ������
		ListNode *head = new ListNode(0);
		head->next = pHead;
		//prev ��Զ �� last��ǰ��
		ListNode *prev = head;
		ListNode *last = prev->next;
		while (last != nullptr){
			//1. ���last��last->next����ȣ���һֱ��prev��last�����ߣ����ҵ��ظ��Ŀ�ʼ
			while (last->next != nullptr && last->val != last->next->val){
				prev = prev->next;
				last = last->next;
			}
			//2. ������last��last->next��ȣ�����lastһֱ�����ߣ����ҵ��ظ��ķ�Χ
			while (last->next != nullptr && last->val == last->next->val){
				last = last->next;
			}
			//�ߵ�������һ��������,ע�⣺prev��Զָ�����ǰ����Ч�ڵ㣺
			//1. last->next != nullptr ���� (prev, last] �޶���һ���ظ���Χ����ʱ����ȥ��
			//2. last->next == nullptr && (prev, last] �޶���һ���ظ���Χ����ʱ����ȥ�أ�����൱��prev->next = nullptr
			//3. last->next == nullptr && prev->next == last,��˵�����ӱ���ѭ����ʼ����Ҷ�����ͬ���Ͳ���Ҫ����ȥ�أ�������������
				
			if (prev->next != last)
			{
				prev->next = last->next;
			}
			last = last->next;
		}
		return head->next;
	}
};
#endif


#if 0
/*�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��*/
//����˼·��
//���������ǵݹ鶨��ģ����Եݹ�����ǱȽϳ���������
//�������ף��ӽṹ��ô��⣬���������ӽṹ��ԭ��������(����һ����)
//Ҳ����˵��BҪ��A���ӽṹ��B�ĸ��ڵ�+������+������������A�д����ҹ������νṹ
//�ȽϵĹ���Ҫ��Ϊ����
//1. ��ȷ����ʼλ��
//2. ��ȷ���Ӹ�λ�ÿ�ʼ�����������������������Ƿ�һ��
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	bool IsSameFromBegin(TreeNode* begin, TreeNode* beginSub){
		//�������Ѱ�Ҵ��벻ͬ���ǣ�����Ҫִ�е��ǵڶ���
		if (nullptr == beginSub){ //beginSubΪnullptr��˵���Ѿ��Ƚ�����
			return true;
		}
		if (nullptr == begin){ //beginΪ�գ�˵��beginSub�����������
			return false;
		}
		if (begin->val != beginSub->val){
			return false; //˵���������У��в���ȵĽڵ�
		}
		//�ڱȽ����������Ƿ����
		//�������������ݹ�����ô���صġ������ݹ�Ľ�������������õĽ��������
		return IsSameFromBegin(begin->left, beginSub->left) && IsSameFromBegin(begin->right,
			beginSub->right);
	}
	//�ȽϵĹ���Ҫ��Ϊ����
	//1. ��ȷ����ʼλ��
	//2. ��ȷ���Ӹ�λ�ÿ�ʼ�����������������������Ƿ�һ��
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//�����߼�����ִ�е��ǵ�һ��
		//���ж���������û��Ϊ�յ����
		if (pRoot1 == nullptr || pRoot2 == nullptr){
			return false;
		}
			bool result = false;
		//�ҵ�����ʼλ��
		if (pRoot1->val == pRoot2->val){
			//�Ӹ���ʼλ�ÿ�ʼ�������Ƿ�һ��
			result = IsSameFromBegin(pRoot1, pRoot2);
		}
		//���pRoot1->val ��= pRoot2->val or ����ʼλ�ÿ�ʼ����һ��
		if (!result){
			//��A����������ʹ����ͬ�ķ�ʽ����
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		//������û�У���������������
		if (!result){
			result = HasSubtree(pRoot1->right, pRoot2);
		}
		return result;
	}
};
#endif

#if 0
/*���������Ķ�����������任ΪԴ�������ľ���*/
//��ν�Ķ��������������Զ�����(or�Ե�����)�����������������Ĺ���
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr){
			return;
		}
		TreeNode *temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
		//TreeNode *temp = pRoot->left;
		//pRoot->left = pRoot->right;
		//pRoot->right = temp;
	}
};
#endif

