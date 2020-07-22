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

