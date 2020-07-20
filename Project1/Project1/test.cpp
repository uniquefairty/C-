#if 0
//数组理解，二分查找，临界条件
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{ 3, 4, 5, 1, 2 }为{ 1, 2, 3, 4, 5 }的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

//OJ链接：https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?
tpId=13&tqId=11159&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-
interviews/question-ranking
//题目解析
//数组问题，本质其实是一个求最小值问题
//方法一：理论上，遍历一次即可，但是我们可以根据题面使用稍微高效且更简单一点的做法
//按照要求，要么是一个非递减排序的数组（最小值在最开始），要么是一个旋转(最小值在中间某个地方)
//而且，旋转之后有个特征，就是在遍历的时候，原始数组是非递减的，旋转之后，就有可能出现递减，引起
递减的数字，就是最小值
//方法二：采用二分查找的方式，进行定位
//定义首尾下标，因为是非递减数组旋转，所以旋转最后可以看做成两部分，前半部分整体非递减，后半部分
整体非递减，前半部分整体大于后半部分。
//所以，我们假设如下定义，left指向最左侧，right指向最右侧，mid为二分之后的中间位置。
//则，a[mid] > a[left],说明mid位置在原数组前半部分，进一步说明，目标最小值，在mid的右侧，让
left=mid
//a[mid] < a[left], 说明mid位置在原数组后半部分，进一步说明，目标最小值，在mid的左侧，让
right=mid
//这个过程，会让[left, right]区间缩小
//这个过程中，left永远在原数组前半部分，right永远在原数组的后半部分，而范围会一直缩小
//当left和right相邻时，right指向的位置，就是最小元素的位置
//但是，因为题目说的是非递减，也就意味着数据允许重复，因为有重复发，就可能会有a[left] ==a[mid] == a[right]的情况，
我们就无法判定数据在mid左侧还是右侧。（注意，只要有两者不相等，我们就能判定应该如何缩小范围）

//方法一
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty()){
			return 0;
		}
		for (int i = 0; i < rotateArray.size() - 1; i++){
			if (rotateArray[i] > rotateArray[i + 1]){
				return rotateArray[i + 1];
			}
		}
		return rotateArray[0];
	}
};
//方法二
class Solution {
public:
	
		int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty()){
			return 0;
		}

		int left = 0;
		int right = rotateArray.size() - 1;
		int mid = 0;
		//要一直满足该条件，以证明旋转特性
		while (rotateArray[left] >= rotateArray[right]){
			if (right - left == 1){
				//两个下标已经相邻了
				mid = right;
				break;
			}
			mid = left + ((right - left) >> 1); //注意操作符优先级
			if (rotateArray[mid] == rotateArray[left] && rotateArray[left] ==
				rotateArray[right]){
				//无法判定目标数据在mid左侧，还是右侧我们采用线性遍历方式
				int result = rotateArray[left];
				for (int i = left + 1; i < right; i++){
					if (result > rotateArray[i]){
						result = rotateArray[i];
					}
				}
				return result;
			}
			if (rotateArray[mid] >= rotateArray[left]){ //试想两者相等， 隐含条件
				rotateArray[left] >= rotateArray[right]
					//说明mid在前半部分
					left = mid;
			}
			else{
				//说明mid在后半部分
				right = mid;
			}
		}
		return rotateArray[mid];
	}
};
#endif

#if 0
核心考点：链表，前后指针的使用，边界条件检测
解析：输入一个链表，输出该链表中倒数第k个结点。
//OJ链接：https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?
//解题思路：
//这道题原题是不需要保证奇偶位置不变的。
//现在新增了需求，解决方法也比较多，我们用较优方式解决一下，借鉴一下插入排序的思想
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int k = 0;
		for (int i = 0; i < array.size(); ++i){
			if (array[i] & 1){ //从左向右，每次遇到的，都是最前面的奇数，一定将来要被放在k
				下标处
					int temp = array[i]; //现将当前奇数保存起来
				int j = i;
				while (j > k){ //将该奇数之前的内容(偶数序列)，整体后移一个位置
					array[j] = array[j - 1];
					j--;
				}
				array[k++] = temp; //将奇数保存在它将来改在的位置，因为我们是从左往右放
				//的，没有跨越奇数，所以一定是相对位置不变的
			}
		}
	}
};
#endif

#if 0
链接：https://www.nowcoder.com/questionTerminal/57d85990ba5b440ab888fc72b0751bf8?answerType=1&f=discussion

给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1，m <= n），每段绳子的长度记为k[1], ..., k[m]。请问k[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
链接：https ://www.nowcoder.com/questionTerminal/57d85990ba5b440ab888fc72b0751bf8?answerType=1&f=discussion
来源：牛客网

class Solution {
public:
	int cutRope(int number) {
		if (number == 2) {
			return 1;
		}
		else if (number == 3) {
			return 2;
		}

		vector<int> f(number + 1, -1);
		for (int i = 1; i <= 4; ++i) {
			f[i] = i;
		}
		for (int i = 5; i <= number; ++i) {
			for (int j = 1; j < i; ++j) {
				f[i] = max(f[i], j * f[i - j]);
			}
		}
		return f[number];
	}
};
#endif
