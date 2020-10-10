#if 0
#include <iostream>
struct Vector2
{
	int x;
	int y;
};

class Character
{
	std::string name;
	Vector2 position;

public:
	Character()
	{
		Vector2 v;
		this->position = v;
		//this->position = new Vector2();
		
	}
	Vector2 GetPosition()  
	{
		return this->position;
	}
};

class Player :public Character
{
public:
	void Rename(std::string name)
	{
		this->Rename = name;
	}
};

int main()
{
	Player* player = new Player();
	//player->GetPosition().x = 10;
	Vector2 v;
	player->GetPosition() = v;
	std::cout << player->GetPosition().x;
}
#endif

#if 0
//合并两个有序链表
#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int m) :val(m)
	{}
};

ListNode *Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	if (pHead2 == NULL)
	{
		return pHead1;
	}

	if (pHead1->val <= pHead2->val)
	{
		pHead1->next = Merge(pHead1->next, pHead2);
		return pHead1;
	}
	else
	{
		pHead2->next = Merge(pHead1, pHead2->next);
		return pHead2;
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		ListNode *pHead1 = new ListNode(0);
		ListNode *tmp = pHead1;
		while (n--)
		{
			int m = 0;
			cin >> m;
			ListNode* cur = new ListNode(m);
			tmp->next = cur;
			tmp = cur;
		}

		int p;
		cin >> p;
		ListNode *pHead2 = new ListNode(0);
		tmp = pHead2;
		while (p--)
		{
			int m = 0;
			cin >> m;
			ListNode* cur = new ListNode(m);
			tmp->next = cur;
			tmp = cur;
		}

		ListNode* res = Merge(pHead1->next, pHead2->next);
		while (res)
		{
			cout << res->val << ' ';
			res = res->next;
		}


	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		string res;
		char tmp;
		
		for (int i = 0; i<str.size();)
		{
			res += str[i];
			res += '_';
			int j = i + 1;
			int count = 1;
			while (str[j] == str[i])
			{
				count++;
				j++;
			}
			res += count + '0';
			if (j != str.size())
			{
				res += '_';
			}
			i = j;
		}

		cout << res << endl;
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		string res="";
		char tmp;
		res += str[0];
		int count = 1;
		for (int i = 1; i<str.size();i++)
		{
			if (str[i] != str[i - 1])
			{
				res += "_" + to_string(count) + "_" + str[i];
				count = 1;
			}
			else
			{
				count++;
			}
		}
		res += "_" + to_string(count);
		cout << res << endl;
	}
	return 0;
}

#endif

#if 0
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	int b = 10, a = 3;
	b += b *= b%a++;
	cout << b << endl;//20

	char* str = "\\\"abcde\"\\\n";
	cout << strlen(str) << endl;//10
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
union
{
	int i;
	char x[2];
}a;
int main()
{
	a.x[0] = 10;
	a.x[1] = 1;
	cout << a.i << endl;//266
	return 0;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int fun(char a, vector<vector<char>> arr, int& count,char tmp)
{
	for (int i = 0; i<arr.size(); i++)
	{
		if (arr[i][0] == a)
		{

			if (arr[i][1] == tmp)
			{
				return count;
			}
			count++;
			fun(arr[i][1], arr,count,tmp);
			return count;
		}
	}
}
int main()
{
	char a;
	int n;
	while (cin >> a)
	{
		cin >> n;
		vector<string> v;
		v.resize(n);
		vector<vector<char>> arr(n, vector<char>(2));
		int count = 0;
		for (int i = 0; i<v.size(); ++i)
		{
			cin >> v[i];
			arr[i][0] = v[i][0];
			arr[i][1] = v[i][3];
		}

		char tmp = a;
		cout << fun(a, arr, count,tmp) << endl;


	}
	return 0;
}
#endif

#if 0
//整数分解
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX 20
int res[MAX];
int p = 0;

void resolve(int n, int min, int k, int& res_num)
{
	if (n <= 0)
	{
		/*for (int i = 0; i < p && p<=k; i++)
		{
			cout << res[i] << " ";
		}
		cout << endl;*/
		if (p <= k)
		{
			res_num++;
		}
		
	}

	for (int i = min; i <= n; i++)
	{
		res[p] = i;
		p++;
		resolve(n - i, i, k, res_num);
		p--;
	}

}
int main()
{
	while (1)
	{
		int n,k;
		cin >> n>>k;
		int res_num = 0;
		int p = 0;
		resolve(n, 1, k, res_num);
		cout << res_num << endl;
		res_num = 0;
	}
}

#endif
