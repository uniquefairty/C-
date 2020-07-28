#if 0
/*在古老的一
维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量
中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向
量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被
他忽悠住？(子向量的长度至少是1）*/
//解题思路：
//方法一：我们可以使用dp完成
//定义状态# f(i): 以i下标结尾的最大连续子序列的和
//状态递推：f(i) = max(f(i-1)+array[i], array[i]) 【这里一定要注意连续关键字】
//状态初始化：f(0) = array[0], max = array[0]
//方法二：可以进行一定程度优化，具体写完基本版本，在考虑

//方法一
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		//经典且高频dp问题
		//定义状态# f(i): 以i下标结尾的最大连续子序列的和
		//状态递推：f(i) = max(f(i-1)+array[i], array[i]) 【这里一定要注意连续关键字】
		//状态初始化：f(0) = array[0], max = array[0]
		int max_value = array[0];
		int *dp = new int[array.size()];
		dp[0] = array[0];

		for (int i = 1; i < array.size(); i++){
			dp[i] = max(dp[i - 1] + array[i], array[i]);
			if (max_value < dp[i]){
				max_value = dp[i];
			}
		}
		delete dp;
		return max_value;
	}
};
//方法二
//很明显，上面的代码，只会使用dp[i] 和 dp[i-1]，所以是有优化的可能的
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
			//经典且高频dp问题
			//定义状态# f(i): 以i下标结尾的最大连续子序列的和
			int max_value = array[0];
		int total = array[0]; //当前累计的和

		//for 循环，用来检测以i下标结尾的连续子序列的和
		for (int i = 1; i < array.size(); i++){
			if (total >= 0){
				//如果之前total累计的和>=0,说明当前数据+total，有利于整体增大
				total += array[i];
			}
			else{
				//如果之前累计的和<0,说明当前数据+total，不利于整体增大,丢弃之前的所有值
				//这里有一个基本事实，就是之前的连续数据和是确定的。
				//连续，是可以从以前到现在，也可以是从现在到以后。至于要不要加以前，就看以前
				//对整体增大又没有贡献度
					total = array[i];
			}
			//走到这，标示以i下标结尾的最大连续子序列的和已经算出，进行最大值统计
			if (max_value < total){
				max_value = total;
			}
		}
		return max_value;
	}
};
#endif

#if 0
/*给定一个仅由小写字母组成的字符串。现在请找出一个位置，删掉那个字母之后，字符串变成回文。请
放心总会有一个合法的解。如果给定的字符串已经是一个回文串，那么输出-1*/
//解题思路：
//可以从两侧进行统计，如果不同，则删除任意一个，在判定是否是回文，如果是，下标就是删除数据的下
//标，如果不是，就是另一个元素的下标
#include <iostream>
#include <string>
using namespace std;
bool IsPalindrome(string &s, int *start, int *end){
	int i = 0;
	int j = s.size() - 1;
	bool result = true;
	while (i <= j){
		if (s[i] != s[j]){
			result = false;
			break;
		}
		i++, j--;
	}
	if (start != nullptr) *start = i;
	if (end != nullptr) *end = j;
	return result;
}
int main()
{
	int num = 0;
	cin >> num;
	while (num){
		string s;
		cin >> s;
		int start = 0;
		int end = s.size() - 1;
		if (IsPalindrome(s, &start, &end)){
			cout << -1 << endl; //已经是回文了
		}
		else{
			s.erase(end, 1);
			if (IsPalindrome(s, nullptr, nullptr)){
				cout << end << endl;
			}
			else{
				cout << start << endl;
			}
		}
		num--;
	}
}
#endif