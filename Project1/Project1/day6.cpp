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

