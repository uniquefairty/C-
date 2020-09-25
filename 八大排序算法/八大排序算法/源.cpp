#if 0
//直接插入排序
#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertSort(vector<int> list)
{
	vector<int> result;
	if (list.empty())
	{
		return result;
	}
	result = list;
	//第一个数肯定是有序的，从第二个数开始遍历，依次插入有序序列
	for (int i = 1; i < result.size(); ++i)
	{
		//取出第i个数，和前i-1个数进行比较，插入合适位置
		int tmp = result[i];
		//因为前i-1个数都是从小到大的有序排列，所以只要比较当前的数（list[j])比tmp大，就把数往后移一位
		int j = i - 1;
		for (; j >=0&&result[j]>tmp; --j)
		{
			result[j + 1] = result[j];
		}
		result[j + 1] = tmp;
	}
	return result;
}
void main()
{
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result;
	result = InsertSort(test);

	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");

}
#endif

# if 0
//直接插入排序-(利用二分查找下标）
#include <iostream>
#include <vector>
using namespace std;

//给定一个有序数组，查找一个大于等于val的下标，不存在返回-1
int BinarySearch(vector<int> list, int n, int val)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);

		if (list[mid] > val)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return (left < n) ? left : -1;
}
vector<int> BinaryInsertSort(vector<int> list)
{
	vector<int> result = list;
	for (int i = 1; i < result.size(); i++)
	{
		int insert_index = BinarySearch(result, i, result[i]);
		if (insert_index != -1)
		{
			int tmp = result[i];
			int j = i - 1;
			while (j >= insert_index)
			{
				result[j + 1] = result[j];
				j--;
			}
			result[j + 1] = tmp;
		}

	}
	return result;
}
void main()
{
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result;
	result = BinaryInsertSort(test);

	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");

}
#endif


#if 0
//归并排序
#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> &input, int left, int mid, int right, vector<int> temp){
	int i = left;                // i是第一段序列的下标
	int j = mid + 1;            // j是第二段序列的下标
	int k = 0;                    // k是临时存放合并序列的下标

	// 扫描第一段和第二段序列，直到有一个扫描结束
	while (i <= mid && j <= right){
		// 判断第一段和第二段取出的数哪个更小，将其存入合并序列，并继续向下扫描
		if (input[i] <= input[j]){
			temp[k++] = input[i++];
		}
		else{
			temp[k++] = input[j++];
		}
	}
	// 若第一段序列还没扫描完，将其全部复制到合并序列
	while (i <= mid){
		temp[k++] = input[i++];
	}

	// 若第二段序列还没扫描完，将其全部复制到合并序列
	while (j <= right){
		temp[k++] = input[j++];
	}

	k = 0;
	// 将合并序列复制到原始序列中
	while (left <= right){
		input[left++] = temp[k++];
	}
}

void MergeSort(vector<int> &input, int left, int right, vector<int> temp){
	if (left < right){
		int mid = (right + left) >> 1;
		MergeSort(input, left, mid, temp);
		MergeSort(input, mid + 1, right, temp);
		Merge(input, left, mid, right, temp);
	}
}

void mergesort(vector<int> &input){
	// 在排序前，先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
	vector<int> temp(input.size());
	MergeSort(input, 0, input.size() - 1, temp);
}

void main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前:";
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result = test;
	mergesort(result);
	cout << "排序后:";
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}
#endif

#if 0
#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}

	result = list;
	int temp;
	// 要遍历的次数
	for (int i = 0; i < result.size() - 1; ++i){
		cout << "第" << i + 1 << "趟排序:" << endl;;
		// 从后向前依次的比较相邻两个数的大小
		for (int j = 0; j < result.size() - 1; j++){
			// 如果后面的元素小，则交换它们的位置
			if (result[j + 1] < result[j]){
				temp = result[j + 1];
				result[j + 1] = result[j];
				result[j] = temp;
			}
			cout << "排序中:";
			for (int s = 0; s < result.size(); s++){
				cout << result[s] << " ";
			}
			cout << endl;
		}
		cout << "排序结果:";
		for (int s = 0; s < result.size(); s++){
			cout << result[s] << " ";
		}
		cout << endl;
	}
	return result;
}

void main(){
	int arr[] = { 6, 4, 8, 1, 2, 3, 9 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = bubbleSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}
#endif

