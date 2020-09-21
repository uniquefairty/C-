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
