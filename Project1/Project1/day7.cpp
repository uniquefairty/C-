#if 0
/*�ڹ��ϵ�һ
άģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý��������,�������
�а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},��������
��������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����һ�����飬��������������������еĺͣ���᲻�ᱻ
������ס��(�������ĳ���������1��*/
//����˼·��
//����һ�����ǿ���ʹ��dp���
//����״̬# f(i): ��i�±��β��������������еĺ�
//״̬���ƣ�f(i) = max(f(i-1)+array[i], array[i]) ������һ��Ҫע�������ؼ��֡�
//״̬��ʼ����f(0) = array[0], max = array[0]
//�����������Խ���һ���̶��Ż�������д������汾���ڿ���

//����һ
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		//�����Ҹ�Ƶdp����
		//����״̬# f(i): ��i�±��β��������������еĺ�
		//״̬���ƣ�f(i) = max(f(i-1)+array[i], array[i]) ������һ��Ҫע�������ؼ��֡�
		//״̬��ʼ����f(0) = array[0], max = array[0]
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
//������
//�����ԣ�����Ĵ��룬ֻ��ʹ��dp[i] �� dp[i-1]�����������Ż��Ŀ��ܵ�
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
			//�����Ҹ�Ƶdp����
			//����״̬# f(i): ��i�±��β��������������еĺ�
			int max_value = array[0];
		int total = array[0]; //��ǰ�ۼƵĺ�

		//for ѭ�������������i�±��β�����������еĺ�
		for (int i = 1; i < array.size(); i++){
			if (total >= 0){
				//���֮ǰtotal�ۼƵĺ�>=0,˵����ǰ����+total����������������
				total += array[i];
			}
			else{
				//���֮ǰ�ۼƵĺ�<0,˵����ǰ����+total����������������,����֮ǰ������ֵ
				//������һ��������ʵ������֮ǰ���������ݺ���ȷ���ġ�
				//�������ǿ��Դ���ǰ�����ڣ�Ҳ�����Ǵ����ڵ��Ժ�����Ҫ��Ҫ����ǰ���Ϳ���ǰ
				//������������û�й��׶�
					total = array[i];
			}
			//�ߵ��⣬��ʾ��i�±��β��������������еĺ��Ѿ�������������ֵͳ��
			if (max_value < total){
				max_value = total;
			}
		}
		return max_value;
	}
};
#endif

#if 0
/*����һ������Сд��ĸ��ɵ��ַ������������ҳ�һ��λ�ã�ɾ���Ǹ���ĸ֮���ַ�����ɻ��ġ���
�����ܻ���һ���Ϸ��Ľ⡣����������ַ����Ѿ���һ�����Ĵ�����ô���-1*/
//����˼·��
//���Դ��������ͳ�ƣ������ͬ����ɾ������һ�������ж��Ƿ��ǻ��ģ�����ǣ��±����ɾ�����ݵ���
//�꣬������ǣ�������һ��Ԫ�ص��±�
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
			cout << -1 << endl; //�Ѿ��ǻ�����
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