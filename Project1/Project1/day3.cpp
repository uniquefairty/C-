#if 0
/*大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项
是1）。*/
//迭代方案
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
//递归方案
//直接用最简单的方式因为代码空间复杂度过高，过不了OJ，所以我们可以采用map进行“剪枝”
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
/*一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算
不同的结果）*/

//方法一：简单动归方式-目前了解
//状态定义：f(i): 跳到i台阶的总跳法
//状态递推：f(i) = f(i-1)+f(i-2)
//初始状态: f(0) = 1（0台阶，就是起点，到达0台阶的方法有一种，就是不跳[这里可能有点奇怪，但是想想，如果方法
//次数为0，就说明不可能开始...]）, f(1) = 1;
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
		int num = dp[number]; //第number下标，就是第number阶台阶
		delete dp;
		return num;
	}
};
//方法二：
//在仔细看看这个代码，难道不像上题的斐波那契数列吗？
class Solution {
public:
	// 状态：f(n): 到第n阶台阶的总跳法，而到了n，只能是从n-1 or n-2跳过来的
	// 递推公式：所以f(n) = f(n-1) + f(n-2)
	// 初始值：f(1) = 1, f(2) = 2， 可以看成，从平地(0)开始跳到1台阶，方法1种。或者跳到2台阶，有两种方式
	int jumpFloor(int n) {
		int first = 1; //第一个台阶
		int second = 2;//第二个台阶
		int third = n; //等于n直接就考虑了f(1) = 1 && f(2) = 2的情况
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
//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
class Solution {
public:
	int NumberOf1(int n) {
		int count = 0;
		while (n){
			n &= (n - 1); //可以避免无效检测
			count++;
		}
		return count;
	}
};
#endif

#if 0
/*链表，前后指针的使用，边界条件检测
输入一个链表，输出该链表中倒数第k个结点
可以定义两个指针，一个指针先走k步，再让另一个指针跟在后面，使用“前后指针”的方式，当前面的指针到达结尾，后
面的指针，也就是倒数第k个节点*/

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
		//我们可以约定首个节点是第1个节点
		ListNode *front = pListHead;//前面的节点
		ListNode *rear = pListHead;//后面的节点
		while (k > 0 && front){
			k--;
			front = front->next;
		}
		while (front){
			front = front->next;
			rear = rear->next;
		}
		return k > 0 ? nullptr : rear; //走到这里，front一定是nullptr
	}
};
#endif

#if 0
/*矩阵中的路径
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/
class Solution {
public:
	bool hasPathCore(const char*matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool*visited)
	{
		if (str[pathLength] == '\0')
			return true;//字符串遍历成功

		bool hasPath = false;
		if (row >= 0 && row<rows&&col >= 0 && col<cols&&matrix[row*cols + col] == str[pathLength] && !visited[row*cols + col])
		{
			++pathLength;
			visited[row*cols + col] = true;
			hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)//左
				|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)//上
				|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)//右
				|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);//下

			if (!hasPath)
			{
				--pathLength;//回到前一个字符重新定位
				visited[row*cols + col] = false;
			}
		}
		return hasPath;
	}
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || rows<1 || cols<1 || str == nullptr)
			return false;

		bool* visited = new bool[rows*cols];//定义和字符矩阵大小一样的布尔值矩阵，用来标识路径是否已经进入每个格子
		memset(visited, 0, rows*cols);

		int pathLength = 0;//字符串的下标
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
/*地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？*/

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
