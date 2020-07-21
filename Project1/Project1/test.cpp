#if 0
//������⣬���ֲ��ң��ٽ�����
//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
//��������{ 3, 4, 5, 1, 2 }Ϊ{ 1, 2, 3, 4, 5 }��һ����ת�����������СֵΪ1��
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

//OJ���ӣ�https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?
tpId=13&tqId=11159&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-
interviews/question-ranking
//��Ŀ����
//�������⣬������ʵ��һ������Сֵ����
//����һ�������ϣ�����һ�μ��ɣ��������ǿ��Ը�������ʹ����΢��Ч�Ҹ���һ�������
//����Ҫ��Ҫô��һ���ǵݼ���������飨��Сֵ���ʼ����Ҫô��һ����ת(��Сֵ���м�ĳ���ط�)
//���ң���ת֮���и������������ڱ�����ʱ��ԭʼ�����Ƿǵݼ��ģ���ת֮�󣬾��п��ܳ��ֵݼ�������
�ݼ������֣�������Сֵ
//�����������ö��ֲ��ҵķ�ʽ�����ж�λ
//������β�±꣬��Ϊ�Ƿǵݼ�������ת��������ת�����Կ����������֣�ǰ�벿������ǵݼ�����벿��
����ǵݼ���ǰ�벿��������ں�벿�֡�
//���ԣ����Ǽ������¶��壬leftָ������࣬rightָ�����Ҳ࣬midΪ����֮����м�λ�á�
//��a[mid] > a[left],˵��midλ����ԭ����ǰ�벿�֣���һ��˵����Ŀ����Сֵ����mid���Ҳ࣬��
left=mid
//a[mid] < a[left], ˵��midλ����ԭ�����벿�֣���һ��˵����Ŀ����Сֵ����mid����࣬��
right=mid
//������̣�����[left, right]������С
//��������У�left��Զ��ԭ����ǰ�벿�֣�right��Զ��ԭ����ĺ�벿�֣�����Χ��һֱ��С
//��left��right����ʱ��rightָ���λ�ã�������СԪ�ص�λ��
//���ǣ���Ϊ��Ŀ˵���Ƿǵݼ���Ҳ����ζ�����������ظ�����Ϊ���ظ������Ϳ��ܻ���a[left] ==a[mid] == a[right]�������
���Ǿ��޷��ж�������mid��໹���Ҳࡣ��ע�⣬ֻҪ�����߲���ȣ����Ǿ����ж�Ӧ�������С��Χ��

//����һ
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
//������
class Solution {
public:
	
		int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty()){
			return 0;
		}

		int left = 0;
		int right = rotateArray.size() - 1;
		int mid = 0;
		//Ҫһֱ�������������֤����ת����
		while (rotateArray[left] >= rotateArray[right]){
			if (right - left == 1){
				//�����±��Ѿ�������
				mid = right;
				break;
			}
			mid = left + ((right - left) >> 1); //ע����������ȼ�
			if (rotateArray[mid] == rotateArray[left] && rotateArray[left] ==
				rotateArray[right]){
				//�޷��ж�Ŀ��������mid��࣬�����Ҳ����ǲ������Ա�����ʽ
				int result = rotateArray[left];
				for (int i = left + 1; i < right; i++){
					if (result > rotateArray[i]){
						result = rotateArray[i];
					}
				}
				return result;
			}
			if (rotateArray[mid] >= rotateArray[left]){ //����������ȣ� ��������
				rotateArray[left] >= rotateArray[right]
					//˵��mid��ǰ�벿��
					left = mid;
			}
			else{
				//˵��mid�ں�벿��
				right = mid;
			}
		}
		return rotateArray[mid];
	}
};
#endif

#if 0
���Ŀ��㣺����ǰ��ָ���ʹ�ã��߽��������
����������һ����������������е�����k����㡣
//OJ���ӣ�https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?
//����˼·��
//�����ԭ���ǲ���Ҫ��֤��żλ�ò���ġ�
//�������������󣬽������Ҳ�Ƚ϶࣬�����ý��ŷ�ʽ���һ�£����һ�²��������˼��
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int k = 0;
		for (int i = 0; i < array.size(); ++i){
			if (array[i] & 1){ //�������ң�ÿ�������ģ�������ǰ���������һ������Ҫ������k
				�±괦
					int temp = array[i]; //�ֽ���ǰ������������
				int j = i;
				while (j > k){ //��������֮ǰ������(ż������)���������һ��λ��
					array[j] = array[j - 1];
					j--;
				}
				array[k++] = temp; //���������������������ڵ�λ�ã���Ϊ�����Ǵ������ҷ�
				//�ģ�û�п�Խ����������һ�������λ�ò����
			}
		}
	}
};
#endif

#if 0
���ӣ�https://www.nowcoder.com/questionTerminal/57d85990ba5b440ab888fc72b0751bf8?answerType=1&f=discussion

����һ������Ϊn�����ӣ�������Ӽ�����������m�Σ�m��n����������n>1����m>1��m <= n����ÿ�����ӵĳ��ȼ�Ϊk[1], ..., k[m]������k[1]x...xk[m]���ܵ����˻��Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
���ӣ�https ://www.nowcoder.com/questionTerminal/57d85990ba5b440ab888fc72b0751bf8?answerType=1&f=discussion
��Դ��ţ����

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

#if 0
����ʹ�ã����㷨����� ��day1��
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������
{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
������
//OJ���ӣ�https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId = 13 & tqId = 11181 & rp = 1 & ru = / ta / coding - interviews&qru = / ta / coding - interviews / question - ranking
//����˼·��
//���������˼·�Ƚ���ȷ
//˼·һ������map��ʹ��<���֣�����>��ӳ���ϵ�����ͳ��ÿ���ַ����ֵĴ���
//˼·�������򣬳��ִ����������֣�һ�����м�λ�á�Ȼ�����м���ֵ����ֳ��ֵĴ����Ƿ����Ҫ��
//˼·����Ŀ��������Ŀ�����ݳ������鳤�ȵ�һ�룬��ô�����飬����ͬʱȥ��������ͬ�����֣������ʣ�µ�һ��������
�����֡����ʣ����������ô������Ҳ��һ���ģ����ǽ��������������ϰ����ʣ�µ�һ�����ֻ��������ص�ԭ�������У�
���������һ��ͳ��һ�����ֳ��ִ������������жϡ�
//˼·һ
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		unordered_map<int, int> map;
		int half = numbers.size() / 2;
		for (int i = 0; i < numbers.size(); i++){
			auto it = map.find(numbers[i]);
			//����Ѿ���map�У�����������������ڣ����룬�״γ���
			if (it != map.end()){
				map[numbers[i]]++;
			}
			else{
				map.insert(make_pair(numbers[i], 1));
			}
			//�������߲���һ����ֱ�ӽ����ж���ע�⣬����Ҫ���ǲ�������Ϊ{1}�����
			//�ߵ������Ӧ��key valһ������
			if (map[numbers[i]] > half){
				return numbers[i];
			}
		}
		//�ߵ����˵��û���ҵ�
		return 0;
	}
};
//˼·��
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int target = numbers[numbers.size() / 2];
		int count = 0;
		for (int i = 0; i < numbers.size(); i++){
			if (target == numbers[i]){
				count++;
			}
		}
		if (count > numbers.size() / 2){
			return target;
		}
		return 0;
	}
};
//˼·��
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0){
			return 0;
		}
		//�ص�дһ��
		//���Բ�ȡ��ͬ���������е�����˼·
		int number = numbers[0];
		int times = 1;
		for (int i = 1; i < numbers.size(); i++){
			if (times == 0){ //�����ǰtimes��0��˵��֮ǰ�Ĳ�ͬ��������
				number = numbers[i];
				times = 1;
			}
			else if (numbers[i] == number){
				times++;
			}
			else{
				times--;
			}
		}
		//������뱾��������������timesһ��>0, ����number����ľ���׼Ŀ�꣬���ǻ���Ҫȷ��
		int count = 0;
		for (int i = 0; i < numbers.size(); i++){
			if (numbers[i] == number){
				count++;
			}
		}
		return count > numbers.size() / 2 ? number : 0;
	}
};
#endif
