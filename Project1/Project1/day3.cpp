#if 0
/*��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����1��
��1����*/
//��������
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		int first = 1;
		int second = 1;
		int third = 1;
		while (n > 2){
			third = first + second;
			first = second;
			second = third;
			n--;
		}
		return third;
	}
};
//�ݹ鷽��
//ֱ������򵥵ķ�ʽ��Ϊ����ռ临�Ӷȹ��ߣ�������OJ���������ǿ��Բ���map���С���֦��
class Solution {
private:
	unordered_map<int, int> filter;
public:
	int Fibonacci(int n) {
		if (n == 0 || n == 1){
			return n;
		}
		int pre = 0;
		if (filter.find(n - 1) == filter.end()){
			pre = Fibonacci(n - 1);
			filter.insert({ n - 1, pre });
		}
		else{
			pre = filter[n - 1];
		}
		int ppre = 0;
		if (filter.find(n - 2) == filter.end()){
			ppre = Fibonacci(n - 2);
			filter.insert({ n - 2, ppre });
		}
		else{
			ppre = filter[n - 2];
		}
		return pre + ppre;
	}
};
#endif



#if 0
/*һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ��
��ͬ�Ľ����*/

//����һ���򵥶��鷽ʽ-Ŀǰ�˽�
//״̬���壺f(i): ����į�׵�������
//״̬���ƣ�f(i) = f(i-1)+f(i-2)
//��ʼ״̬: f(0) = 1��0̨�ף�������㣬����0̨�׵ķ�����һ�֣����ǲ���[��������е���֣��������룬�������
//����Ϊ0����˵�������ܿ�ʼ...]��, f(1) = 1;
class Solution {
public:
	int jumpFloor(int number) {
		//dp[n] = dp[n-1]+dp[n-2];
		int *dp = new int[number + 1];
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= number; i++){
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		int num = dp[number]; //��number�±꣬���ǵ�number��̨��
		delete dp;
		return num;
	}
};
//��������
//����ϸ����������룬�ѵ����������쳲�����������
class Solution {
public:
	// ״̬��f(n): ����n��̨�׵���������������n��ֻ���Ǵ�n-1 or n-2��������
	// ���ƹ�ʽ������f(n) = f(n-1) + f(n-2)
	// ��ʼֵ��f(1) = 1, f(2) = 2�� ���Կ��ɣ���ƽ��(0)��ʼ����1̨�ף�����1�֡���������2̨�ף������ַ�ʽ
	int jumpFloor(int n) {
		int first = 1; //��һ��̨��
		int second = 2;//�ڶ���̨��
		int third = n; //����nֱ�ӾͿ�����f(1) = 1 && f(2) = 2�����
		while (n > 2){
			third = first + second;
			first = second;
			second = third;
			--n;
		}
		return third;
	}
};
#endif

#if 0
//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ
class Solution {
public:
	int NumberOf1(int n) {
		int count = 0;
		while (n){
			n &= (n - 1); //���Ա�����Ч���
			count++;
		}
		return count;
	}
};
#endif

#if 0
/*����ǰ��ָ���ʹ�ã��߽��������
����һ����������������е�����k�����
���Զ�������ָ�룬һ��ָ������k����������һ��ָ����ں��棬ʹ�á�ǰ��ָ�롱�ķ�ʽ����ǰ���ָ�뵽���β����
���ָ�룬Ҳ���ǵ�����k���ڵ�*/

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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr){
			return nullptr;
		}
		//���ǿ���Լ���׸��ڵ��ǵ�1���ڵ�
		ListNode *front = pListHead;//ǰ��Ľڵ�
		ListNode *rear = pListHead;//����Ľڵ�
		while (k > 0 && front){
			k--;
			front = front->next;
		}
		while (front){
			front = front->next;
			rear = rear->next;
		}
		return k > 0 ? nullptr : rear; //�ߵ����frontһ����nullptr
	}
};
#endif

#if 0
/*�����е�·��
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ�
�����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
*/
class Solution {
public:
	bool hasPathCore(const char*matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool*visited)
	{
		if (str[pathLength] == '\0')
			return true;//�ַ��������ɹ�

		bool hasPath = false;
		if (row >= 0 && row<rows&&col >= 0 && col<cols&&matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col])
		{
			++pathLength;
			visited[row*cols + col] = true;
			hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)//��
				|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)//��
				|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)//��
				|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);//��

			if (!hasPath)
			{
				--pathLength;//�ص�ǰһ���ַ����¶�λ
				visited[row*cols + col] = false;
			}
		}
		return hasPath;
	}
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || rows<1 || cols<1 || str == nullptr)
			return false;

		bool* visited = new bool[rows*cols];//������ַ������Сһ���Ĳ���ֵ����������ʶ·���Ƿ��Ѿ�����ÿ������
		memset(visited, 0, rows*cols);

		int pathLength = 0;//�ַ������±�
		for (int row = 0; row<rows; ++row)
		{
			for (int col = 0; col<cols; ++col)
			{
				if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
				{
					return true;
				}
			}
		}

		delete[] visited;
		return false;
	}
};
#endif

#if 0
/*������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�*/

class Solution {
public:
	int getDigitSum(int number)
	{
		int sum = 0;
		while (number>0)
		{
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}
	bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
	{
		if (row >= 0 && row<rows&&col >= 0 && col<cols&&getDigitSum(row) + getDigitSum(col) <= threshold&&!visited[row*cols + col])
		{
			return true;
		}
		return false;
	}
	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
	{
		int count = 0;
		if (check(threshold, rows, cols, row, col, visited))
		{
			visited[row*cols + col] = true;
			count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
				+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
		}
		return count;
	}

	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold<0 || rows<1 || cols<1)
			return 0;

		bool *visited = new bool[rows*cols];
		for (int i = 0; i<rows*cols; ++i)
			visited[i] = false;

		int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
		delete[] visited;

		return count;
	}
};
#endif
