#if 0
/*定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为
O（1））。
注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。*/

//解题思路：
//很容易想到，在栈内部保存min变量，每次更新的时候，都对min变量进行更新。
//但是，面试官很容易就会问到：如果想拿出第二小，第三小的值怎么拿？
//用上面的办法就不行了
//为了满足通用，我们使用一个辅助栈，内部保存元素的个数和数据栈完全一样，不过，辅助栈内部永远保存
//本次入栈的数为所有数据的最小值（注意：辅助栈内部元素可能会出现“必要性”重复）
//我们这里是为了实现算法， 所以就不从0开始实现stack了
//题面说了，保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法，所以，后面的代
//码对空的检验可有可无
class Solution {
private:
	stack<int> data_stack; //数据栈
	stack<int> min_stack;  //辅助栈
public:
	void push(int value) {
		data_stack.push(value);
		if (min_stack.size() == 0 || value < min_stack.top()){
			Java代码
				18. 核心考点：栈的理解
				min_stack.push(value);
		}
		else{ //min_stack.size() != 0 && value >= min_stack.top()
			min_stack.push(min_stack.top());
		}
	}
	void pop() {
		if (data_stack.size() == 0 || min_stack.size() == 0){
			return;
		}
		data_stack.pop();
		min_stack.pop();
	}
	int top() {
		return data_stack.top();
	}
	int min() {
		return min_stack.top();
	}
};
#endif


#if 0
/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假
设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应
的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等
的）*/
//解题思路：
//要判定第二个序列是否可能是该栈的弹出序列，就要使用指定的入栈顺序
//模拟出来对应的弹栈序列，我们设入栈顺序序列式pushV， 可能出栈序列popV
//popv的第一个元素，一定是最后入栈，最先弹栈的,而我们的入栈顺序是一定的
//也就决定了，我们必须一直入栈，直到碰到popv的第一个元素，然后开始弹栈
//最后在循环这个过程，如果符合要求，最后栈结构一定是空的
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0 || popV.size() == 0 || pushV.size() != popV.size())
		{
			return false;
		}
		stack<int> st; //辅助栈，帮我们进行入栈出栈模拟
		int i = 0;
		int j = 0;
		for (; i < pushV.size(); i++){ //遍历入栈序列，开始入栈
			st.push(pushV[i]);
			//如果该条件不满足，就要一直入栈
			//如果该条件满足，就要一直出栈
			//pushV代表对应的入栈逻辑，popV代表对应的出栈逻辑
			//两个元素相等，代表入栈逻辑结束，出栈逻辑开始，想想为什么？
			while (!st.empty() && st.top() == popV[j]){
				st.pop(); //去掉栈顶，在比较下一个
				j++;
			}
		}
		return st.empty();
	}
};
#endif

#if 0
/*从上往下打印出二叉树的每个节点，同层节点从左至右打印*/
//本质是层序遍历二叉树，借助queue即可完成
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
	vector<int> PrintFromTopToBottom(TreeNode* root) 
	{
		if (root == nullptr)
		{
			return vector<int>();
		}
		vector<int> v;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			TreeNode *father = q.front();
			q.pop();
			v.push_back(father->val);
			if (father->left)
			{
				//左子树不为空
				q.push(father->left);
			}
			if (father->right)
			{

				//右子树不为空
				q.push(father->right);
			}
		}

		return v;
	}
};
#endif
