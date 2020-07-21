#if 0
字符串相关，特性观察，临界条件处理
请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。例如，当字符串为We Are Happy.则经过替换之后的字
符串为We%20Are % 20Happy。
//OJ链接：https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?
tpId = 13 & tqId = 11155 & tPage = 1 & rp = 1 & ru = % 2Fta % 2Fcoding - interviews&qru = % 2Fta % 2Fcoding -
interviews%2Fquestion - ranking
//字符串操作问题
//解决思路：
//虽然是替换问题，但是生成的字符串整体变长了.
//因替换内容比被替换内容长，所以，一定涉及到字符串中字符的移动问题
//移动方向一定是向后移动，所以现在的问题无非是移动多少的问题
//因为是 ' ' -> "%20",是1换3，所以可以先统计原字符串中空格的个数(设为n)，然后可以计算出新字符串的长度
//所以：new_length = old_length + 2*n
//最后，定义新老索引（或者指针），各自指向新老空间的结尾，然后进行old->new的移动
//如果是空格，就连续放入“%20”,其他平移即可。
//当然，C++和Java都有很多容器，也可以从前往后通过开辟空间来进行解决。也就是使用空间来换取时间。
//但是，我们最好不要在当前场景下这么做
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		char *start = str;
		while (*start)
		{
			if (isspace(*start))
			{
				count++;
			}
			start++;
		}

		char *old_end = str + length;
		char *new_end = str + length + 2 * count;
		while (old_end >= str&&new_end >= str)
		{
			if (!isspace(*old_end))
			{
				*new_end = *old_end;
				new_end--;
				old_end--;
			}
			else{
				*new_end-- = '0';
				*new_end-- = '2';
				*new_end-- = '%';
				old_end--;
			}
		}

	}
};
#endif

#if 0
二叉树重建，遍历理解，递归
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重
复的数字。例如输入前序遍历序列{ 1, 2, 4, 7, 3, 5, 6, 8 }和中序遍历序列{ 4, 7, 2, 1, 5, 3, 8, 6 }，则重建二叉树并返回
//OJ链接：https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?
tpId = 13 & tqId = 11157 & tPage = 1 & rp = 1 & ru = % 2Fta % 2Fcoding - interviews&qru = % 2Fta % 2Fcoding -
interviews%2Fquestion - ranking
//经典二叉树问题
//解题思路：
//根据root节点，将中序vector划分成vin_left，vin_right两部分中序子序列
//根据中序子序列长度，将前序vector划分成pre_left, pre_right对应的前序子序列
//root->left递归生成
//root->right递归生成
/**
* Definition for binary tree
* struct TreeNode {
* int val;
* TreeNode *left;
* TreeNode *right;
* TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* reConstructBinaryTreeCore(vector<int> pre, int preStart, int preEnd, vector<int>
		vin, int vinStart, int vinEnd) {
		if (preStart > preEnd || vinStart > vinEnd){
				return nullptr;
		}
		TreeNode *root = new TreeNode(pre[preStart]);
		for (auto i = vinStart; i <= vinEnd; i++){//在中序序列中，找根节点，可以将数组划分为两部分
			if (pre[preStart] == vin[i]){
				//前序的第一个节点，是root，能将中序划分为两部分
				//一棵树，无论前，中，后怎么遍历，元素的个数是不变的
				//在实际遍历的时候，前，中，后序遍历，各种遍历方式左右子树的节点都是在一起的
				//所以这里重点是要想清楚下标问题
				//根据中序，我们能确认左子树的节点个数是：i - vinStart (没有从0开始哦)
				//所以，需要从preStart+1，连续i - vinStart个元素，就是左子树的前序序列
				root->left = reConstructBinaryTreeCore(pre, preStart + 1, i - vinStart + preStart,
					vin, vinStart, i - 1);
				root->right = reConstructBinaryTreeCore(pre, i - vinStart + preStart + 1,
					preEnd, vin, i + 1, vinEnd);
				break;
			}
		}
		return root;
	}
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty()){
			return nullptr;
		}
		return reConstructBinaryTreeCore(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
};
#endif

#if 0
链表相关，多结构混合使用，递归
输入一个链表，按链表从尾到头的顺序返回一个ArrayList
/**
* struct ListNode {
*    int val;
*    struct ListNode *next;
*    ListNode(int x) :
*       val(x), next(NULL) {
*    }
* };
*/
//方法一，stack方式，这种方式会有内存占用过多的问题
class Solution {

public:
	vector<int> printListFromTailToHead(ListNode* head) {
		stack<int> s;
		vector<int> v;
		while (head){
			s.push(head->val);
		}
		while (!s.empty()){
			v.push_back(s.top());
			s.pop();
		}
		return v;
	}
};
//方法二，逆置数组
class Solution {

public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		while (head){
			v.push_back(head->val);
			head = head->next;
		}

		reverse(v.begin(), v.end());
		return v;
	}
};
//方法三，递归方式
class Solution {
public:
	void printListFromTailToHeadCore(ListNode* head, vector<int> &v){
		if (nullptr == head){
			return;
		}
		printListFromTailToHeadCore(head->next, v);
		v.push_back(head->val);
	}
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		printListFromTailToHeadCore(head, v);
		return v;
	}
};
#endif

