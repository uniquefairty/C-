#if 0
/*输入一个链表，反转链表后，输出新链表的表头*/

//1. 定义三个指针，整体右移，边移动，边翻转，保证不会断链。
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
		//不带头结点，至少有2个节点
		ListNode *first = pHead; //指向第一个节点
		ListNode *second = first->next; //指向第二个节点
		ListNode *third = second->next; //指向第三个节点，可能为nullptr
		while (third)
		{ //因为third在最前面，所以他一定先到nullptr，只要检测它是否合法即可
			//翻转
			second->next = first;
			//指针整体后移
			first = second;
			second = third;
			third = third->next;
		}
		second->next = first; //当传入的链表只有两个节点 or 上述翻转结束时，最后一个节点并未翻转
		pHead->next = nullptr; //曾经的第一个节点，next并不是nullptr，设置一下
		pHead = second; //头指针指向最后一个节点
		return pHead;
	}
};
//2. 可以采用头插思想进行翻转
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		//头插法
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;

		ListNode* new_head = nullptr;//定义一个新的头节点
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
/*输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。*/
//方法一，比较好理解的
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
		//不考虑头结点(其实，考虑头结点简单，我们按照难的来)
		//合并前，先判定
		if (nullptr == pHead1){
			return pHead2;
		}
		if (nullptr == pHead2){
			return pHead1;
		}
		//合并中,无非是比较各自首节点谁小，就把该节点从原链表中删除，在尾插到新节点处，比较中，两个链表任何一
		个都不能为空
			ListNode *new_head = nullptr;
		ListNode *new_tail = nullptr;
		while (pHead1 && pHead2){
			//先判定拿那个节点
			ListNode *p = pHead1->val < pHead2->val ? pHead1 : pHead2;
			//再在指定链表中，删除目标节点
			if (p == pHead1){
				pHead1 = pHead1->next;
			}
			else{
				pHead2 = pHead2->next;
			}
			//尾插到新链表,这里要考虑第一次插入的情况
			if (nullptr == new_head){
				new_head = p;
				new_tail = p;
			}
			else{
				new_tail->next = p;
				new_tail = p;
			}
		}
		//合并后，可能会有：1. pHead1为空 2. pHead2为空 3. 都为空(合并完成)
		if (nullptr == pHead1){
			new_tail->next = pHead2;
		}
		else if (nullptr == pHead2){
			new_tail->next = pHead1;
		}
		比特职读会
		else{
			//do nothing
		}
		return new_head;
	}
};
//方法二，上一道题是Java写的两种方法，我们这里来一个C++的
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
		//不考虑头结点(其实，考虑头结点简单，我们按照难的来)
		//合并前，先判定
		if (nullptr == pHead1){
			return pHead2;
		}
		if (nullptr == pHead2){
			return pHead1;
		}
		//合并中，找到第一个节点
		ListNode *new_head = nullptr;
		if (pHead1->val < pHead2->val){
			new_head = pHead1;
			pHead1 = pHead1->next;
		}
		else{
			new_head = pHead2;
			pHead2 = pHead2->next;
		}
		//合并剩下的节点
		new_head->next = Merge(pHead1, pHead2);
		return new_head;
	}
};

#endif

#if 0
/*在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例
如，链表1->2->3->3->4->4->5 处理后为 1->2->5*/
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
		//考虑到与可能全部相同，带个头结点更简单
		ListNode *head = new ListNode(0);
		head->next = pHead;
		//prev 永远 在 last的前面
		ListNode *prev = head;
		ListNode *last = prev->next;
		while (last != nullptr){
			//1. 如果last和last->next不相等，就一直让prev和last往后走，先找到重复的开始
			while (last->next != nullptr && last->val != last->next->val){
				prev = prev->next;
				last = last->next;
			}
			//2. 如果如果last和last->next相等，就让last一直往后走，在找到重复的范围
			while (last->next != nullptr && last->val == last->next->val){
				last = last->next;
			}
			//走到这里结果一共有三种,注意：prev永远指向的是前驱有效节点：
			//1. last->next != nullptr 并且 (prev, last] 限定了一段重复范围，此时进行去重
			//2. last->next == nullptr && (prev, last] 限定了一段重复范围，此时进行去重，最后相当于prev->next = nullptr
			//3. last->next == nullptr && prev->next == last,这说明，从本次循环开始，大家都不相同，就不需要进行去重，这个是特殊情况
				
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
/*输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）*/
//解题思路：
//二叉树都是递归定义的，所以递归操作是比较常见的做法
//首先明白：子结构怎么理解，可以理解成子结构是原树的子树(或者一部分)
//也就是说，B要是A的子结构，B的根节点+左子树+右子树，都在A中存在且构成树形结构
//比较的过程要分为两步
//1. 先确定起始位置
//2. 在确定从该位置开始，后续的左右子树的内容是否一致
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
		//和下面的寻找代码不同的是，现在要执行的是第二步
		if (nullptr == beginSub){ //beginSub为nullptr，说明已经比较完了
			return true;
		}
		if (nullptr == begin){ //begin为空，说明beginSub不是你的子树
			return false;
		}
		if (begin->val != beginSub->val){
			return false; //说明，整树中，有不相等的节点
		}
		//在比较左右子树是否相等
		//这里大家深度想想递归是怎么返回的【整个递归的结果，由最深层调用的结果决定】
		return IsSameFromBegin(begin->left, beginSub->left) && IsSameFromBegin(begin->right,
			beginSub->right);
	}
	//比较的过程要分为两步
	//1. 先确定起始位置
	//2. 在确定从该位置开始，后续的左右子树的内容是否一致
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		//下面逻辑整体执行的是第一步
		//先判定两棵树有没有为空的情况
		if (pRoot1 == nullptr || pRoot2 == nullptr){
			return false;
		}
			bool result = false;
		//找到了起始位置
		if (pRoot1->val == pRoot2->val){
			//从该起始位置开始，查找是否一致
			result = IsSameFromBegin(pRoot1, pRoot2);
		}
		//如果pRoot1->val ！= pRoot2->val or 从起始位置开始，不一致
		if (!result){
			//在A树的左子树使用相同的方式找找
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		//左子树没有，再在右子树找找
		if (!result){
			result = HasSubtree(pRoot1->right, pRoot2);
		}
		return result;
	}
};
#endif

#if 0
/*操作给定的二叉树，将其变换为源二叉树的镜像*/
//所谓的二叉树镜像本质是自顶向下(or自底向上)进行左右子树交换的过程
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

