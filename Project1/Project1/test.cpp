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

