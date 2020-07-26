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

#if 0

/*����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c
�������г����������ַ��� abc,acb,bac,bca,cab �� cba ��*/
//����˼·��
//ȫ�������⣬���Կ������¶������̬
//��������԰�Ŀ�괮���������֣���һ���֣����ĸ��ַ���ͷ���ڶ����֣�ʣ�µ���������
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
			//start �� i �Ĺ�ϵ�ǣ���ʾ��˭��ʼ
			swap(str, start, i);
			//��ȷ�����ĸ��ַ���Ϊ��ʼ����Ҫ�ھ�����һ���ֵ������������
			//����һ��Ҫ�����⣬i�����Ǿ�����˭��Ϊ���еĿ�ʼ��������sub�ַ���ÿ�ο�ʼ����
			//Ҫ��start + 1��ʼ
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
/*����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������
1,2,3,4,��*/
//����˼·��
//˼·һ��ֱ����������ȡǰn�������������������
//˼·�������Բ�����С�ѣ���������ʹ��C+++ priority_queue or java PriorityQueue���ȼ���
//�н��д����ײ�ԭ�����ƶѣ�.�������˼·����ʵ��topk������ʹ���ֳɵĽ�������������Ҫ�˽��ʵ
//�֣����������˽�һ��
struct comp{
	bool operator()(const int &a, const int &b){
		return a < b; //������Ҫ���ѣ��������ǲ��ý�������
	}
};
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> list;
		if (input.size() == 0 || k <= 0 || k > input.size()){
			return list;
		}

		priority_queue<int> queue; //����ָ������ʵ������
		for (int i = 0; i < input.size(); i++){
			if (i < k){
				//ǰk��Ԫ�أ�ֱ�ӷ��룬priority_queue�ڲ��ή������
				queue.push(input[i]);
			}
			else{
				if (input[i] < queue.top()){
					//����µ����ݣ�С��queue�ײ�Ԫ�أ����ֵ�������и���
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
