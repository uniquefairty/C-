#if 0
//ֱ�Ӳ�������
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
	//��һ�����϶�������ģ��ӵڶ�������ʼ���������β�����������
	for (int i = 1; i < result.size(); ++i)
	{
		//ȡ����i��������ǰi-1�������бȽϣ��������λ��
		int tmp = result[i];
		//��Ϊǰi-1�������Ǵ�С������������У�����ֻҪ�Ƚϵ�ǰ������list[j])��tmp�󣬾Ͱ���������һλ
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
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result;
	result = InsertSort(test);

	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");

}
#endif

//ֱ�Ӳ�������-(���ö��ֲ����±꣩
#include <iostream>
#include <vector>
using namespace std;

//����һ���������飬����һ�����ڵ���val���±꣬�����ڷ���-1
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
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result;
	result = BinaryInsertSort(test);

	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");

}
