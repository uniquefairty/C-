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

# if 0
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
#endif


#if 0
//�鲢����
#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> &input, int left, int mid, int right, vector<int> temp){
	int i = left;                // i�ǵ�һ�����е��±�
	int j = mid + 1;            // j�ǵڶ������е��±�
	int k = 0;                    // k����ʱ��źϲ����е��±�

	// ɨ���һ�κ͵ڶ������У�ֱ����һ��ɨ�����
	while (i <= mid && j <= right){
		// �жϵ�һ�κ͵ڶ���ȡ�������ĸ���С���������ϲ����У�����������ɨ��
		if (input[i] <= input[j]){
			temp[k++] = input[i++];
		}
		else{
			temp[k++] = input[j++];
		}
	}
	// ����һ�����л�ûɨ���꣬����ȫ�����Ƶ��ϲ�����
	while (i <= mid){
		temp[k++] = input[i++];
	}

	// ���ڶ������л�ûɨ���꣬����ȫ�����Ƶ��ϲ�����
	while (j <= right){
		temp[k++] = input[j++];
	}

	k = 0;
	// ���ϲ����и��Ƶ�ԭʼ������
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
	// ������ǰ���Ƚ���һ�����ȵ���ԭ���鳤�ȵ���ʱ���飬����ݹ���Ƶ�����ٿռ�
	vector<int> temp(input.size());
	MergeSort(input, 0, input.size() - 1, temp);
}

void main(){
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ:";
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result = test;
	mergesort(result);
	cout << "�����:";
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
	// Ҫ�����Ĵ���
	for (int i = 0; i < result.size() - 1; ++i){
		cout << "��" << i + 1 << "������:" << endl;;
		// �Ӻ���ǰ���εıȽ������������Ĵ�С
		for (int j = 0; j < result.size() - 1; j++){
			// ��������Ԫ��С���򽻻����ǵ�λ��
			if (result[j + 1] < result[j]){
				temp = result[j + 1];
				result[j + 1] = result[j];
				result[j] = temp;
			}
			cout << "������:";
			for (int s = 0; s < result.size(); s++){
				cout << result[s] << " ";
			}
			cout << endl;
		}
		cout << "������:";
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
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++){
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = bubbleSort(test);
	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
}
#endif

