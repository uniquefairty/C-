#if 0
/*输入一个非空整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输
出No。假设输入的数组的任意两个数字都互不相同。*/
//解题思路：
//看清楚，是二叉搜索树 后序遍历
//二叉搜索树:它或者是一棵空树，或者是具有下列性质的二叉树： 若它的左子树不空，则左子树上所有结点
//的值均小于它的根结点的值； 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
//后序遍历：先左后右再根
//BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是root节点），如果去掉最后一
//个元素的序列为T，那么T满足：T可以分成两段，前一段（左子树）小于x，后一段（右子树）大于x，且这两
//段（子树）都是合法的后序序列
//验证思路就是：当前序列，及其子序列必须都满足上述定义

class Solution {
public:
	bool VerifySquenceOfBSTCore(vector<int> &sequence, int start, int end){
		if (start >= end){
			//在不断查找过程中，区域不断缩小，为空时，证明之前的所有范围都满足检测条件
			//也就是是一个BST
			return true;
		}
		//拿到root节点的值
		int root = sequence[end];
		//先遍历左半部分，也就是整体都要比root小，拿到左子树序列
		int i = 0;
		while (i < end && sequence[i] < root){
			i++;
		}
		//在检测右子树是否符合大于root的条件，要从i开始，也就是右半部分的开始
		for (int j = i; j < end; j++){
			if (sequence[j] < root){
				//在合法位置处，当前值小于root，不满足BST定义
				return false;
			}
		}
		//走到这里，就说明，当前序列满足需求。但并不代表题目被解决了，还要在检测left和right各自是否也满足
			return VerifySquenceOfBSTCore(sequence, 0, i - 1) &&
			VerifySquenceOfBSTCore(sequence, i, end - 1);
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()){
			return false;
		}

		return VerifySquenceOfBSTCore(sequence, 0, sequence.size() - 1);
	}
};
#endif

#if 0
/*简单回溯法的使用
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为
从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。*/
//解题思路：
//这是一个典型的DFS回溯的算法
//回溯法本质是一个基于DFS的穷举的过程
//1. 先添加值
//2. 在判定现有结果是否满足条件
//3. DFS
//4. 回退
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
	void FindPathDFS(TreeNode* root, int expectNumber, vector<vector<int> >
		&result, vector<int> &list){
		if (root == nullptr){
			return;
		}
		//先添加值
		list.push_back(root->val);
		expectNumber -= root->val;
		//检测条件是否满足题面需求
		if (root->left == nullptr && root->right == nullptr && expectNumber == 0)
		{
			result.push_back(list);
		}
		//dfs进去
		FindPathDFS(root->left, expectNumber, result, list);
		FindPathDFS(root->right, expectNumber, result, list);

		list.pop_back(); //回退
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int> > result;
		vector<int> list;
		FindPathDFS(root, expectNumber, result, list);
		return result;
	}
};
#endif

#if 0

/*输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c
所能排列出来的所有字符串 abc,acb,bac,bca,cab 和 cba 。*/
//解题思路：
//全排列问题，可以看做如下多叉树形态
//该问题可以把目标串理解成两部分：第一部分：以哪个字符开头，第二部分：剩下的是子问题
class Solution {
public:
	void swap(string &str, int i, int j){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	bool IsExist(vector<string>& result, string &str){
		auto it = result.begin();
		for (; it != result.end(); ++it){
			if (*it == str){
				return true;
			}
		}
		return false;
	}
	void PermutationHelper(string &str, int start, vector<string>& result){
		if (start == str.length() - 1){
			if (!IsExist(result, str)){
				result.push_back(str);
			}
			return;
		}
		for (int i = start; i < (int)str.size(); i++){
			//start 和 i 的关系是：表示以谁开始
			swap(str, start, i);
			//当确定以哪个字符作为开始，就要在决定另一部分的排列组合种类
			//这里一定要深刻理解，i仅仅是决定以谁作为排列的开始，但是求sub字符串每次开始，都
			//要从start + 1开始
				PermutationHelper(str, start + 1, result);
			swap(str, start, i);
		}
	}
	vector<string> Permutation(string str) {
		vector<string> result;
		if (str.length() > 0){
			PermutationHelper(str, 0, result);
			sort(result.begin(), result.end());
		}
		return result;
	}
};
#endif

#if 0
/*输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是
1,2,3,4,。*/
//解题思路：
//思路一：直接升序排序，取前n个，这个方法不考虑了
//思路二：可以采用最小堆，我们这里使用C+++ priority_queue or java PriorityQueue优先级队
//列进行处理（底层原理类似堆）.这里核心思路在于实现topk，我们使用现成的解决方案。如果需要了解堆实
//现，可以自行了解一下
struct comp{
	bool operator()(const int &a, const int &b){
		return a < b; //我们需要最大堆，所以我们采用降序排序
	}
};
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> list;
		if (input.size() == 0 || k <= 0 || k > input.size()){
			return list;
		}

		priority_queue<int> queue; //采用指定容器实现最大堆
		for (int i = 0; i < input.size(); i++){
			if (i < k){
				//前k个元素，直接放入，priority_queue内部会降序排序
				queue.push(input[i]);
			}
			else{
				if (input[i] < queue.top()){
					//如果新的数据，小于queue首部元素（最大值），进行更新
					queue.pop();
					queue.push(input[i]);
				}
			}
		}
		for (int i = 0; i < k; i++){
			list.push_back(queue.top());
			queue.pop();
		}
		return list;
	}
};

#endif
