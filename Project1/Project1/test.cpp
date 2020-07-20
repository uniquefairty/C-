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

