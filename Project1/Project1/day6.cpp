#if 0
/*����һ���ǿ��������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,������
��No���������������������������ֶ�������ͬ��*/
//����˼·��
//��������Ƕ��������� �������
//����������:��������һ�ÿ����������Ǿ����������ʵĶ������� ���������������գ��������������н��
//��ֵ��С�����ĸ�����ֵ�� ���������������գ��������������н���ֵ���������ĸ�����ֵ��
//�����������������ٸ�
//BST�ĺ������еĺϷ������ǣ�����һ������S�����һ��Ԫ����x ��Ҳ����root�ڵ㣩�����ȥ�����һ
//��Ԫ�ص�����ΪT����ôT���㣺T���Էֳ����Σ�ǰһ�Σ���������С��x����һ�Σ�������������x��������
//�Σ����������ǺϷ��ĺ�������
//��֤˼·���ǣ���ǰ���У����������б��붼������������

class Solution {
public:
	bool VerifySquenceOfBSTCore(vector<int> &sequence, int start, int end){
		if (start >= end){
			//�ڲ��ϲ��ҹ����У����򲻶���С��Ϊ��ʱ��֤��֮ǰ�����з�Χ������������
			//Ҳ������һ��BST
			return true;
		}
		//�õ�root�ڵ��ֵ
		int root = sequence[end];
		//�ȱ�����벿�֣�Ҳ�������嶼Ҫ��rootС���õ�����������
		int i = 0;
		while (i < end && sequence[i] < root){
			i++;
		}
		//�ڼ���������Ƿ���ϴ���root��������Ҫ��i��ʼ��Ҳ�����Ұ벿�ֵĿ�ʼ
		for (int j = i; j < end; j++){
			if (sequence[j] < root){
				//�ںϷ�λ�ô�����ǰֵС��root��������BST����
				return false;
			}
		}
		//�ߵ������˵������ǰ�����������󡣵�����������Ŀ������ˣ���Ҫ�ڼ��left��right�����Ƿ�Ҳ����
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
/*�򵥻��ݷ���ʹ��
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ
�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����*/
//����˼·��
//����һ�����͵�DFS���ݵ��㷨
//���ݷ�������һ������DFS����ٵĹ���
//1. �����ֵ
//2. ���ж����н���Ƿ���������
//3. DFS
//4. ����
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
		//�����ֵ
		list.push_back(root->val);
		expectNumber -= root->val;
		//��������Ƿ�������������
		if (root->left == nullptr && root->right == nullptr && expectNumber == 0)
		{
			result.push_back(list);
		}
		//dfs��ȥ
		FindPathDFS(root->left, expectNumber, result, list);
		FindPathDFS(root->right, expectNumber, result, list);

		list.pop_back(); //����
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int> > result;
		vector<int> list;
		FindPathDFS(root, expectNumber, result, list);
		return result;
	}
};
#endif

