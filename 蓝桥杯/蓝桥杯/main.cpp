#include<iostream>
using namespace std;
#include<vector>


#if 0
void f(int n)
{
	if (n == 1)
		cout << "1";
	else
	{
		int a[100000], tail = 0, head = 0, p = 0;
		a[0] = 1;
		for (int i = 2; i <= n; i++){
			for (int j = head; j <= tail; j++)
			{
				p = a[j] * i + p;
				a[j] = p % 10;
				p = p / 10;
			}
			while (p != 0)
			{
				tail++;
				a[tail] = p % 10;
				p = p / 10;
			}
		}
		for (int i = tail; i >= 0; i--)
			cout << a[i];
	}
}
int main()
{
	int n;
	cin >> n;
	f(n);
	return 0;
}
#endif

#if 0
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(1000000, 0);
		int a = 2;
		int d = 0;
		int i = 0;
		v[0] = 1;
		int tail = 0;//��¼���һλ���ֵ��±�

		while (a <= n)
		{
			for (i = 0; i<=tail; i++)
			{
				d = v[i] * a + d;
				v[i] = d % 10;
				d = d / 10;
			}
			while (d != 0)
			{
				tail++;
				v[tail] = d % 10;
				d = d / 10;
			}
			a++;
		}

		for (int i = tail; i >= 0; i--)
			cout << v[i];

		//�����������
	}

	return 0;
}
#endif

#if 0
//����  ���������Ӧ�ô����λ��ʼ��� ���������Ϊ�Ǵ������ַ�����
//�ұ߿�ʼ���
#include<string>

void add(string s1, string s2)
{
	int res = 0,i=0,tail=0;
	string c;
	for (i = 0; i < s1.size() || i < s2.size(); i++)
	{
		res = s1[i] + s2[i] - 2 * '0' + res;
		c += res / 10 + '0';
		res = res % 10;
	}
	tail = i-1;
	if (i<s1.size())
	{
		for (; i < s1.size(); i++)
		{
			res = s1[i] -  '0' + res;
			c += res / 10 + '0';
			res = res % 10;
		}
	}
	else
	{
		for (; i < s2.size(); i++)
		{
			res = s2[i] - '0' + res;
			c += res / 10 + '0';
			res = res % 10;
		}
			
	}

	if (res != 0)
	{
		c += res + '0';
	}

	for (int j =c.size()-1; j >=0; j--)
	{
		cout << c[i] - '0';
	}


}
#endif

#if 0
//������������a��b����������������ĺ͡�a��b��������100λ��
#include<iostream>
using namespace std;
#include<string>
void add(string a, string b)
{
	int c[102], tail = 0, p = 0;
	int i = a.length() - 1;
	int j = b.length() - 1;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0 && j >= 0)
		{
			p = (int)a[i] + (int)b[j] + p - '0' - '0';
		}
		else if (i >= 0 && j < 0)
		{
			p = (int)a[i] + p - '0';
		}
		else if (i < 0 && j >= 0)
		{
			p = (int)b[j] + p - '0';
		}
		c[tail++] = p % 10;
		p = p / 10;
		i--; j--;	
	}
	if (p != 0)
	{
		c[tail++] = p;
	}

	for (int i = tail-1; i >= 0; i--)
	{
		cout << c[i];
	}
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		add(s1, s2);
	}
	return 0;
}
#endif

#if 0
//�������ܽ��Ԥ��
#include<iostream>
using namespace std;
int main()
{
	int v1, v2, t, s, l;
	int d=0,s1=0,s2=0;//�������ľ���
	while (cin >> v1 >> v2 >> t >> s >> l)
	{
		int t1 = l / v2;//�ڹ�ȫ����Ҫ��ʱ��
		for (int i = 1; i <= t1; i++)//ÿ������һ���ʱ��
		{
			s1 += v1;//�����ߵ�·��
			s2 += v2;//�ڹ��ߵ�·��
			if (s1!=l&&(s1 - s2) >= t)
			{
				s2 = v2*s + s2;
				i += s;
			}
			if (s1 >= l&&s2<l)
			{
				cout << "R" << endl;
				cout << i << endl;
				break;
			}
			else if(s1 >= l&&s2 >= l)
			{
				cout << "D" << endl;
				cout << t1 << endl;
			}
			else if (s2>=l)
			{
				cout << "T" << endl;
				cout << t1 << endl;
			}
		}
		
	}
	return 0;
}
#endif

//#include<vector>
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<vector<int>> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			v[i].resize(n);
//		}
//		for (int i = 0; i < n; i++)
//		{
//			
//		}
//	}
//}

#if 0
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n ;
	while (cin >> n)
	{
		vector<char> v;
		vector<char> v0{ 'A', 'B', 'C', 'D', 'E', 'F' };
		if (n < 10)
		{
			cout << n << endl;
			n = 0;
		}
		for (n; n > 0; n /= 16)
		{
			int tmp = n % 16;
			if (tmp < 10)
			{
				v.push_back(tmp+'0');
			}
			else
			{
				v.push_back(v0[tmp % 10]);
			}
		}
		reverse(v.begin(), v.end());

		for (auto &it : v)
		{
			if (it < 10)
				cout << it - '0';
			else
			{
				cout << it;

			}
		}
	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
int main()
{
	int x, y, i;
	int d, n = 1;
	char h[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	while (cin >> x)
	{
		y = x;
		while (x >= 10)
		{
			x /= 10;
			++n;
		}
		int *r = new int[n];
		for (i = 0; y >= 16; ++i)
		{
			r[i] = y % 16;
			y /= 16;
		}
		r[i++] = y;

		for (i = (n - 1); i >= 0; --i)
		{
			cout << h[r[i]];
		}
	}
	return 0;
}
#endif


#if 0
//�㷨ѵ��1
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v;
	v.resize(M);
	for (int i = 0; i < v.size(); i++)
	{
		v[i].resize(N);
		for (int j = 0; j < v[i].size(); j++)
		{
			cin >> v[i][j];
		}
	}

	int max = v[0][2];
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i][2]>max)
			max = v[i][2];
	}
	cout << max << endl;
	return 0;
}
#endif

#if 0
//huffmans��
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#include <queue>
class Less
{
public:
	bool operator()(const int left, const int right)
	{
		return left > right;
	}
};
int main()
{
	int num;
	cin >> num;
	vector<int> v;
	v.resize(num);
	int sum = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	priority_queue<int,vector<int>,Less> q;
	for (auto e : v)
	{
		q.push(e);
	}

	while (q.size()>1)
	{
		int tmp = q.top();
		q.pop();
		tmp += q.top();
		q.pop();
		sum += tmp;
		q.push(tmp);
		/*sort(v.begin(), v.end());
		int tmp = v[0] + v[1];
		sum += tmp;
		v.erase(v.begin(),v.begin()+1);
		v.push_back(tmp);*/
	}
	
	cout << sum;
	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <algorithm>
#define maxx 100
using namespace std;
int main()
{
	int a[maxx];
	int i, n;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);//��С��������
	int sum = 0;
	while (n>1)
	{
		i = 0;
		a[i] = a[i] + a[i + 1];
		sum += a[i];
		a[i + 1] = -1;//�������ȥ��
		sort(a, a + n);
		for (i = 0; i<n - 1; i++)
			a[i] = a[i + 1];
		n--;
	}
	printf("%d\n", sum);
	return 0;
}
#endif

#if 0
//Huffman��
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	cin >> num;
	vector<int> v;
	v.resize(num);
	int sum = 0;
	int i = 0;
	int n = v.size();
	for (size_t i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	while (n>1)
	{
		i = 0;
		v[i] = v[i] + v[i+1];
		sum += v[i];
		v[i+1] = -1;//�������ȥ��
		sort(v.begin(), v.begin()+n);//����

		for (; i < v.size()-1; i++)
		{
			v[i] = v[i + 1];
		}
		n--;
	}

	cout << sum;
	return 0;
}
#endif


#if 0
scanf("%f",&fahr);

celsius

printf("fahr=%.1f,celsius=%.1f",fahr, celsius);

#endif

#if 0
//������������
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void Swap(vector<int>& v,int start, int end)
{
	int tmp = v[start];
	v[start] = v[end];
	v[end] = tmp;
}

//void Swap(vector<int>& v, int n)
//{
//	int end = n-1;
//	for (size_t i = 0; i < n/ 2; i++)//ע������
//	{
//		int tmp = v[i];
//		v[i] = v[end];
//		v[end] = v[i];
//		end--;
//	}
//}
int main()
{
	vector<int> v;
	int num;
	
	while (cin >> num)
	{
		if (num == 0)
			break;
		v.push_back(num);
	}
	int start = 0, end = v.size() - 1;
	while (start < end)
	{
	    Swap(v,start, end);
		start++;
		end--;
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	return 0;
}

#endif

#if 0
#include<stdio.h>
void swap(int a[], int n)
{
	int i, j, t;
	for (i = 0; i<n / 2; i++)
	{
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
}
int main()
{
	int a[100], i = 0, j;
	for (i = 0; i<100; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 0)
			break;
	}
	swap(a, i);
	for (j = 0; j<i; j++)
	{
		printf("%d ", a[j]);
	}
	return 0;
}
#endif

#if 0
/*
��������
���������������ɴ�д��ĸ��Сд��ĸ��ɵ��ַ���(���Ƚ���1��10֮��)������֮��Ĺ�ϵ������4�����֮һ��
  ����1�������ַ������Ȳ��ȡ����� Beijing �� Hebei
	����2�������ַ�������������ȣ�������Ӧλ���ϵ��ַ���ȫһ��(���ִ�Сд)������ Beijing �� Beijing
	  ����3�������ַ���������ȣ���Ӧλ���ϵ��ַ����ڲ����ִ�Сд��ǰ���²��ܴﵽ��ȫһ�£�Ҳ����˵���������������2�������� beijing �� BEIjing
		����4�������ַ���������ȣ����Ǽ�ʹ�ǲ����ִ�СдҲ����ʹ�������ַ���һ�¡����� Beijing �� Nanjing
		  ��������ж�����������ַ���֮��Ĺ�ϵ�����������е���һ�࣬������������ı�š�
*/
#include <iostream>
using namespace std;
#include<string>

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int flag = 0;
	if (s1.size() == s2.size())
	{
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] != s2[i])//��ͬλ���ϵ��ַ������
			{
				if (s1[i] - s2[i] == 32 || s2[i] - s1[i] == 32)//���Դ�Сд�໥�滻
				{
					flag = 1;
				}
				else
				{
					cout << "4" << endl;
					return 0;
				}
				
				
			}
		}
		if (flag == 1)
		{
			cout << "3" << endl;
		}
		else
		{
			cout << "2" << endl;
		}
	}
	else
	{
		//�ַ������Ȳ����
		cout << "1" << endl;
	}
	return 0;
}
#endif


#if 0
//�ַ���ƴ��
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	string s3 = s1 + s2;
	cout << s3 << endl;
	return 0;
}

#endif

#if 0
//����ȡ��
#include<iostream>
#include<string.h>
#define N 205

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	int res[N][N];
	int a[N][N];

	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			cin >> a[i][j];

	memset(res, 1, sizeof(res));

	//���������ȵ�һ��Ϊ0�������߹��ģ��ж���һ��Ҫ�ߵķ���ĸ����Ƿ�Ϊ1��
	//���Ϊ1���ͽ���һ��������Ϊ1������������˵+1 -1 �����ŷ��򣬵���ֻ�ı䵱ǰ��״̬��
	//�ͻᵼ�´���ĳһ���������Զ�޷������Ϊ�����Ǹ��㣬����������һ��λ��ȴ���߹��� 
	int i = 0, j = 0, ct = 0;
	res[0][0] = 0;
	cout << a[0][0] << " ";

	while (ct<n*m - 1){
		while (i<n - 1 && res[i + 1][j] != 0) {

			i++;
			cout << a[i][j] << " ";
			res[i][j] = 0;
			ct++;
		}
		while (j<m - 1 && res[i][j + 1] != 0){
			j++;
			cout << a[i][j] << " ";
			res[i][j] = 0;
			ct++;
		}
		while (i>-1 && res[i - 1][j] != 0 && i - 1 >= 0) {
			i--;
			cout << a[i][j] << " ";
			res[i][j] = 0;
			ct++;
		}
		while (j>-1 && res[i][j - 1] != 0 && j - 1 >= 0){
			j--;
			res[i][j] = 0;
			cout << a[i][j] << " ";
			ct++;
		}
	}

	return 0;
}

#endif

#if 0
////����ȡ��
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	int n, m;
	cin >> n >> m;
	int i, j;
	vector<vector<int>> v;
	v.resize(n);
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i].resize(n);
		for (size_t j = 0; j < v[i].size(); j++)
		{
			cin >> v[i][j];
		}
	}

	for (i = 0; i < (n + 1) / 2 && i < (m + 1) / 2; i++)//�����i����ȫ�飬ѭ���Ĵ���iС��������һ����С��������һ��
	{
		for (j = i; j < n - i; j++)//�������
		{
			if (i == 0 && j == 0)
			{
				cout << v[j][i];
			}
			else
			{
				cout << " " << v[j][i];
			}
			
		}

		for (j = i + 1; j < m - i; j++)//�������
		{
			cout << " " << v[n - i - 1][j];
		}

		/*��mΪ����ʱ���һ��ѭ��ֻ����һ�е����ݡ�
		ÿ��һ��ѭ�������˶ԳƵ��������ݣ�ǰ��i-1��ѭ������2i�����ݣ�i��0��ʼ��������ж�֮ǰ�ֶ���һ������
		�����ж���û�жԳƵ���������ֻҪ�ж�m-2*i-1�Ƿ����0���ȼ���m - i - 1 > i�� ,��ͬ */
		if (m - i - 1 > i)
		{
			for (j = n - i - 2; j >= i; j--)//�������
				cout << " " << v[j][m - i - 1];
		}

		if (n - i - 1 > i)
		{
			for (j = m - i - 2; j > i; j--)//�������
				cout << " " << v[i][j];
		}
	}

	return 0;
}

#endif

#if 0
//1221��һ���ǳ����������������߶��ʹ��ұ߶���һ���ģ������������������λʮ��������
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					if (i == l && j == k) {
						cout << i << j << k << l << endl;
						/*System.out.println("" + i + j + k + l);*/
					}
				}
			}
		}
	}
	return 0;
}
#endif

#if 0

//���������[a,b]�������������������ֽ⡣
#include <iostream>
#include <vector>
using namespace std;

//�ж��Ƿ�������
bool IsPrime(int n)
{
	int i;
	for (i = 2; i <= n / 2; i++)
	{
		if (n%i == 0)
			return false;
	}

	if (i > n / 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	vector<int> v;//�洢����������������
	int a, b;
	cin >> a;
	cin >> b;
	for (int i = 2; i <= b; i++)
	{
		if (IsPrime(i))
		{
			v.push_back(i);
		}
	}

	for (int i=a; i <= b; ++i)
	{
		if (IsPrime(i))//�������Ļ���ֱ�����
		{
			cout << i << "=" << i;
		}
		else
		{
			cout << i << "=";
			int tmp = i;
			int index = 0;//�洢�����������±�
			while (tmp != 1)//��ǰ����û�б�����ʱ����
			{
				if (tmp%v[index] == 0)//�ӵ�һ��������ʼ��
				{
					cout << v[index];
					tmp /= v[index];

					index = 0;//��ԭ�����±��һ�������е�ֵ
					if (tmp != 1)
						cout << "*";
				}
				else//���������Ļ�������һ������
				{
					index++;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

#endif


#if 0
//n�ʺ�����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[8][8];//��¼��ͬλ�õ�Ȩֵ���Ƿ���ԷŻʺ�
int location[8];//��¼ÿ�зŻʺ��λ�ñ�ǣ�ÿ�е���һ�У�
int maxn = -1;//�����ַ���

//rows:�ܹ����˶�����
//colimns:��һ�зŻʺ�����±�
int valid(int rows, int columns)//��֦����
{
	for (int i = 0; i < rows; i++)
	{
		//�ж��Ƿ���ͬһ�л��ǶԽ���
		if (columns == location[i] || abs(rows - i) == abs(columns - location[i]))
			return 0;
	}
	return 1;
}
void Queue(int row)//���ݺ���
{
	if (row == 8)
	{
		int current_max = 0;
		for (int i = 0; i < 8; i++)
		{
			current_max += num[i][location[i]];
		}
		maxn = max(current_max, maxn);
	}
	else
	{
		for (int n = 0; n < 8; n++)//��ǰ�зŻʺ�����±�
		{
			if (valid(row, n))
			{
				location[row] = n;
				Queue(row + 1);
			}
		}
	}
}
int main()
{
	int k;
	cin >> k;
	//while (k--)
	//{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> num[i][j];
			}
		}
		Queue(0);
		cout << maxn << endl;
	//}
		return 0;
}
#endif

#if 0
//2n�ʺ�����
#include <iostream>
#include <cmath>
using namespace std;
int board[8][8];
int all = 0;
int black_location[8];//��¼ÿ�зŻʺ�����±�
int white_location[8];

//rows:�ܹ����˶�����
//colimns:��ǰ�зŻʺ�����±�
int w_valid(int rows, int columns)//��֦����
{
	for (int i = 0; i < rows; i++)
	{
		//�жϵ�ǰ���Ƿ��ǰ��Ļʺ���һ�� ���� �ǶԽ���
		if (columns == white_location[i] || abs(rows - i) == abs(columns - white_location[i]))
		{
			return 0;
		}
	}
	return 1;
}

int b_valid(int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		if (columns == black_location[i] || abs(rows - i) == abs(columns - black_location[i]))
		{
			return 0;
		}
	}
	return 1;
}

//cur :��ǰ�� n:�ܹ�������
void Queen_b(int cur, int n)
{
	if (cur == n)
		all++;
	else
	{
		for (int i = 0; i < n; i++)
		{
			//���λ�����˰׻ʺ��ҿ��Բ��ܷŻʺ�
			if (i == white_location[cur] || board[cur][i] == 0)
				continue;
			else
			{
				if (b_valid(cur, i))
				{
					black_location[cur] = i;
					Queen_b(cur + 1, n);//������һ��
				}
			}
		}
	}
}

void Queen_w(int cur, int n)
{
	if (cur == n)
	{
		Queen_b(0, n);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (board[cur][i] == 0)//��ǰλ�ò��ܲ���
				continue;
			if (w_valid(cur, i))
			{
				white_location[cur] = i;//��¼��ǰ�п��ԷŻʺ�����±�
				Queen_w(cur + 1, n);//������һ��
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int h = 0; h < n; h++)
		{
			cin >> board[i][h];
		}
		
	}
	Queen_w(0, n);
	cout << all;
	return 0;
}

#endif

#if 0
//��ʱ����
#include <iostream>
#include <string>
using namespace std;

string n[100] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
"twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
"thirty", "forty", "fifty" };

void ass(int num)
{
	int a = num / 10;
	int b = num % 10;

	if (num <= 20)
	{
		cout << n[num];
	}
	else
	{
		cout << n[a + 18];
		if (b != 0)
		{
			cout << " " << n[b];
		}
	}
}
void time_ass(int hour, int minu)
{
	if (minu == 0)
	{
		ass(hour);
		cout << "o'clock" << endl;
	}
	else
	{
		ass(hour);
		cout << " ";
		ass(minu);
		cout << endl;
	}
}
int main()
{
	int h, m;
	cin >> h >> m;
	time_ass(h, m);
	return 0;
}
#endif

#if 0
//�ж�����
#include <iostream>
using namespace std;
int main()
{
	int year;
	cin >> year;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
	return 0;
}
#endif

#if 0
//���������
#include <iostream>
using namespace std;
int main()
{
	long i;
	int n;
	int a, b, c, d, e, f;
	cin >> n;
	for (i = 10000; i < 10000; i++)
	{
			a = i % 10;//��
			b = i / 10 % 10;//ʮ
			c = i / 100 % 10;//��
			d = i % 1000 % 10;//ǧ
			e = i / 10000 ;//��

			if (a == e&&b == d&&a + b + c + d + e == n)
				cout << i << endl;
	 }
	for (i = 100000; i < 1000000; i++)
	{
		a = i / 100000 % 10;
		b = i / 10000 % 10;
		c = i / 1000 % 10;
		d = i / 100 % 10;
		e = i / 10 % 10;
		f = i % 10;

		if (a == f&&b == e&&c == d&&a + b + c + d + e + f == n)
			cout << i << endl;
	}
		
	return 0;
}
#endif

#if 0
//ʱ��ת��
#include <iostream>
using namespace std;
int main()
{
	int t, h, m, s;
	cin >> t;
	h = t / 3600;
	t %= 3600;
	m = t / 60;
	t %= 60;
	s = t;
	cout << h << ":" << m << ":" << s;
	return 0;
}
#endif

#if 0
//�㷨ѵ�� ��������
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
	int n,res=0;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++)
	{
		if ((v[i + 1] - v[i]) == 1)
			res++;
	}
	cout << res;
	return 0;
}
#endif

//#include <iostream>
//using namespace std;
//#include <vector>
//#include <algorithm>
//int main()
//{
//	long n, m;
//	cin >> n >> m;
//
//	long res = pow(n, n + 1) - (n - 1)*m;
//	cout << res;
//	return 0;
//}

#if 0
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(void)
{
	int m, n;
	cin >> n >> m;
	for (int i = 0;; i++)
	{
		bool flag = true;
		long long x = i;
		for (int j = 1; j <= n; j++)
		{
			x = x * n + m;
			if (x % (n - 1) != 0)
			{
				flag = false;
				break;
			}
			x = x / (n - 1);
		}
		if (flag == false) continue;
		if (flag == true)
		{
			x = x * n + m;
			printf("%lld", x);
			return 0;
		}
	}
	return 0;
}

#endif 

#if 0
//ˮ�ɻ���
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a = n % 100;//��λ
	int b = n / 10 % 10;//ʮλ
	int c = n / 100;//��λ
	if ((a*a*a + b*b*b + c*c*c) == n)
		cout << "YES" << endl;
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
#endif

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int x,y,z,x1, y1, z1, p;
//	cin >> x >> y >> z >> x1 >> y1 >> z1 >> p;
//
//	double res = x1 / x + y1 / y + z1 / z;
//
//	printf("%.2f", res);
//	return 0;
//}

#if 0
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int x, y, z, x1, y1, z1, p;
	cin >> x >> y >> z >> x1 >> y1 >> z1 >> p;
	long long  m = x1*y*z + y1*x*z + z1*x*y;//�������ڿ��ǵ�0<x1,y1,z1<=1000000,����0<x,y,z<100,���鿴�����͵�ȡֵ��Χ��long int���޷������ˣ�����long long���ʺϡ�
	int n = x*y*z;
	int s = m / n;
	cout << s << ".";
	for (int i = 0; i<p - 1; i++)//��p-1λ��С���������
	{
		m = m%n * 10;
		s = m / n;
		cout << s;
	}
	//����pλС���Ƿ�+1,s1ΪpΪС��ֵ��s2Ϊp+1λС��ֵ
	m = m%n * 10;
	int s1 = m / n;
	m = m%n * 10;
	int s2 = m / n;
	if (s2 >= 5)
		cout << s1 + 1;
	else
		cout << s1;
	return 0;

}
#endif

#if 0
//����˷�
#include<iostream>
#include<stdio.h>
using namespace std;
#include <vector>

int main()
{
	int n,m;
	cin >> n>>m;
	vector<vector<int>> v,k;
	v.resize(n);
	k.resize(n);
	for (int i = 0; i < n; i++)
	{
		v[i].resize(n);
		k[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			v[i][j] = num;
			k[i][j] = num;
		}
	}

	vector<vector<int>> ans;
	ans.resize(n);
	for (int i = 0; i < n; i++)
	{
		ans[i].resize(n);
	}

	if (m == 0)//�����0�����ǵ�λ����
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					ans[i][j] = 1;
				else
					ans[i][j] = 0;
			}
		}
	}


	if (m > 1)
	{
		m--;
		while (m)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int m = 0; m < n; m++)
					{
						ans[i][j] += v[i][m] * k[m][j];
					}
				}
			}

			//k=ans
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					k[i][j] = ans[i][j];
				}
			}
			m--;
		}
	}
	
	
	//��ӡ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j]<<" ";
		}
		cout << endl;
	}

	return 0;

}
#endif

#if 0
#include<stdio.h>
void f(int a)
{
	if (a == 1)printf("A");//��ʼ��������д���˵�����
	else
	{
		f(a - 1);
		printf("%c", a + 64);
		f(a - 1);
	}
}

int main()
{
	int a;
	scanf("%d", &a);
	f(a);
	return 0;
}
#endif

#if 0
//��������
#include<iostream>
#include<stdio.h>
using namespace std;

struct Complex
{
	double a, b;
};

Complex add(Complex c1, Complex c2)
{
	Complex result;
	result.a = c1.a + c2.a;
	result.b = c1.b + c2.b;
	return result;
}

Complex minu(Complex c1, Complex c2)
{
	Complex result;
	result.a = c1.a - c2.a;
	result.b = c1.b - c2.b;
	return result;
}

Complex multi(Complex c1, Complex c2)
{
	Complex result;
	result.a = c1.a * c2.a - c1.b * c2.b;
	result.b = c1.a * c2.b + c1.b * c2.a;
	return result;
}

Complex divide(Complex c1, Complex c2)
{
	Complex result;
	result.a = (c1.a*c2.a + c1.b*c2.b) / (c2.a*c2.a + c2.b*c2.b);
	result.b = (c1.b*c2.a - c1.a*c2.b) / (c2.a*c2.a + c2.b*c2.b);
	return result;
}

int main()
{
	char op;
	double a, b, c, d;

	while (cin >> op >> a >> b >> c >> d)
	{
		Complex x, y, ans;
		x.a = a; x.b = b;
		y.a = c; y.b = d;

		if (op == '+') ans = add(x, y);
		else if (op == '-') ans = minu(x, y);
		else if (op == '*') ans = multi(x, y);
		else if (op == '/') ans = divide(x, y);

		printf("%.2f+%.2fi\n", ans.a, ans.b);
	}
	return 0;
}
#endif

#if 0
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, m, k, x;
	ll a = 10, ans = 1;
	cin >> n >> m >> k >> x;
	while (k) {
		if (k & 1) {
			ans = ans * a % n;
		}
		a = a * a % n;
		k >>= 1;
	}
	ans %= n;
	ans = (x + ans * m) % n;
	cout << ans << endl;
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	double x[4], y[4];
	double s = 0;
	scanf("%lf %lf %lf %lf", &x[0], &y[0], &x[1], &y[1]);
	scanf("%lf %lf %lf %lf", &x[2], &y[2], &x[3], &y[3]);
	if (max(x[0], x[1]) <= min(x[2], x[3]) || max(x[2], x[3]) <= min(x[0], x[1]) || max(y[0], y[1]) <= min(y[2], y[3]) || max(y[2], y[3]) <= min(y[0], y[1]))
		printf("0.00\n");
	else
	{
		sort(x, x + 4);//����
		sort(y, y + 4);
		s = (x[2] - x[1])*(y[2] - y[1]);
		printf("%.2lf", s);
	}

#endif

#if 0
	//�����޷������λ����
#include <iostream>
using namespace std;
int main(void)
{
	int i, res = 0;
	unsigned int x, y;
	cin >> x >> y;
	for (i = 0; i<32; i++)//32λ����Ϊ����������ݣ���С�ɸ���ʵ���޸� 
	{
		if ((y & 1) == 1)//y�����λ�Ƿ�Ϊ1 
		{
			res += x;//������˵Ľ�� 
		}
		x <<= 1;
		y >>= 1;
	}
	cout << res << endl;
	return 0;
}
#endif

#if 0
//��һ�����������������������
#include <iostream>
using namespace std;
#include <algorithm>
#include <math.h>
//�ж��Ƿ�������
int zhi(int n)
{
	int i;
	if (n<2) return 0;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0) 
			return 0;
	}
	return 1;
}

//��һ��������������� 
int zhiyin(int n){
	int i;
	int max = 1;
	for (i = 2; n != 1;)
	{
		if (zhi(i))
		{
			if (n%i == 0)
			{//������ 
				max = i;
				n = n / i;
			}
			else i++;
		}
		else
			i++;
	}
	return max;
}
int main()
{
	int n, i;
	cin >> n;
	int a[2502], b[2502], c[2502];
	for (i = 0; i<n; i++)
	{
		cin>>a[i];
	}

	for (i = 0; i<n; i++)
	{
		c[i] = a[i];
		b[i] = zhiyin(a[i]);
	}
	int bm = b[0];
	for (i = 0; i<n-1 ; i++)
	{//�ҵ����������� 
		if (bm <= b[i])
			bm = b[i];
	}
	for (i = 0; i<n; i++)
	{
		if (bm == b[i])
		{
			break;
		}
	}
	cout << c[i];
	return 0;
}
#endif

#if 0
//�׳˵����ұ߷�0����
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	long int temp = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
		temp *= i;
		while (temp % 100 == 0)
		{
			temp /= 100;
		}
		temp %= 100;
	}
	while (temp % 10 == 0)
	{
		temp /= 10;
	}
	printf("%d", temp % 10);

	return 0;

}
#endif

#if 0
//������
#include<iostream> 
using namespace std;
int m, n, A[50005];
int ans[2000000] = { 0 };
int sum = 0;
int main()
{
	cin >> n >> m;//����ѧ�����ͻ��� 
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			int temp;
			cin >> temp;
			A[i] = (A[i] << 1) + temp;//2���Ʊ��� 
		}
		ans[A[i]]++;//���ÿ���𰸵����� 
	}
	int max = (1 << m) - 1;
	for (int i = 0; i<n; i++)
	{
		int temp = A[i] ^ max;//��λȡ�� 
		sum += ans[temp];
	}
	cout << sum / 2 << endl;
	return 0;
}
#endif

#if 0
//��������
#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;
typedef long long ll;
ll value[2005];
ll dp[2005][5];//��ʾ��i��β������ 
ll n;
int main()
{
	memset(dp, 0, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) //��ʼ�� 
	{
		cin >> value[i];
		dp[i][1] = 1;
	}
	ll sum = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int k = 2; k <= 4; k++)
		{
			for (int j = i - 1; j >= 1; j--)
			{
				if (value[i]>value[j])
					dp[i][k] += dp[j][k - 1];

			}
			if (k == 4)
			{
				sum += dp[i][k];
			}
			//printf("%d zai %d de wei zhi you %d\n",value[i],k,dp[i][k]); 
		}
	}
	printf("%lld\n", sum);
}
#endif

#if 0
//������1������
#include <stdio.h>
int sum = 0;
int len;
void fun(int a[1000], int len)
{
	int i = 0;
	for (i = 0; i<len; i++)
	{
		if (a[i] == 1)
			sum++;
	}
}

void change(int n)
{
	int a[1000];
	int i = 0;
	while (n>0)
	{
		a[i] = n % 2;
		n /= 2;
		i++;
	}
	fun(a, i);
}

int main()
{
	int L, R;
	scanf("%d %d", &L, &R);
	int i;
	for (i = L; i <= R; i++)
	{
		change(i);
	}
	printf("%d", sum);
	return 0;
}
#endif

#if 0
//�������������󣬷ֱ���m*s��s*n��С���������������˵Ľ����
#include <iostream>
using namespace std;

int main()
{
	int m, s, n;
	int a[201][201], b[201][201], c[201][201];

	cin >> m >> s >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	//����˷�
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < s; j++)
		{
			for (int k = 0; k < n; k++)
			{
				c[i][k] += a[i][j] * b[j][k];
			}
		}
	}

	//�������
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
#endif

#if 0
//1�ĸ���
#include <stdio.h>
int sum = 0;
void f(int n)
{
	int a;
	while (n>0)
	{
		if (n % 10 == 1)
			sum++;
		n /= 10;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++)
	{
		f(i);
	}
	printf("%d", sum);
	return 0;
}
#endif

#if 0
//����������n����С����ȫƽ������
//��һ�����ܱ�ʾ��ĳ����Ȼ����ƽ������ʽ����������Ϊ��ȫƽ����
//Tips��n��32λ�з�������
#include <stdio.h>
#include <math.h>
int main()
{
	long long n;
	scanf("%lld", &n);
	long long j;
	long long acc;
	if (n >= 0)
	{
		j = (long long)sqrt(n) - 1;
		while (1)
		{
			acc = j*j;
			j++;
			if (acc >= n)
			{
				printf("%lld", acc);
				break;
			}
		}
	}
	else
		printf("0");
	return 0;
}
#endif

