using namespace std;
#include<iostream>
#include<string>
#include<vector>
#if 0
//class Solution {
//public:
	string toLowerCase(string str) {
		int i = 0;
		for (; i<str.size(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}
		}
		cout << str << endl;
		return str;
	}
//};

int main()
{
	string s;
	s = "HELlo";
	toLowerCase(s);
	cout << s << endl;
	return 0;
}
#endif

//class Solution {
//public:
	void rotate(vector<int>& nums, int k) {
		//1.ÏÂ±ê
		//2¡£Êä³ö
		int i = 0,j=0;
		int n = 1;
		while (n <= k)
		{
			int tmp = nums[0];
			int pre = nums[nums.size() - 1];
			for (; i<nums.size(); i++)
			{
				/*if (i == nums.size() - 1)
				{
					nums[0] = tmp;
					return;
				}*/
				tmp = nums[i];
				nums[i] = pre;
				pre = tmp;

				/*
				for (int j = 0; j < nums.length; j++) {
				temp = nums[j];
				nums[j] = previous;
				previous = temp;
				}
				*/
			}
			n++;
		}

		for (i = 0; i<nums.size(); i++)
		{
			cout << nums[i];
		}
	}
//};
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	rotate(v,3);
	return 0;
}