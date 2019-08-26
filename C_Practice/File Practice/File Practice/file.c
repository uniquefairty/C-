#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<math.h>
#pragma warning(disable:4996)





//int sum = 1;
//for (i = 1; sum< 7; i++)
//{
//	sum += i;
//	count++;
//}
#if 0
sum = sum*10 + i*m;//求回文数
进制数可以为负

1.数字遍历
for (i = a; i < n; i++);
i完成了对[a,b]的遍历
2.数组遍历
for (i = 0; i < n;i++)
a[i]对数组遍历
3.字符串的遍历
for (i = 0; str[];i++)
str[i]完成了对字符串str的遍历
4.数位遍历
for (i = src; i;i/10)
i%10完成了对十进制数字src中每一位数字的遍历
for (i = src; i; i / m)
i % m完成了对m进制数字src中每一位数字的遍历
5.链表遍历
for (cur = head; cur;cur=cur->next)
cur完成了对head为头的链表的遍历
是无头遍历
6.容器遍历
for (iter = v.begin(); iter != v.end();iter++)
iter完成了对容器v的遍历
int main()
{
	int m = 1;
	int n = 7;
	int i = 0;
	int sum = 0,tmp=0;
	for (i = 0; i < n; i++)
	{
		tmp = tmp * 10 + m;
		sum += tmp;
		//sum += m*pow(10.0, i);
	}
	printf("%d", &sum);
	system("pause");
	return 0;
}
#endif


#if 0
typedef unsigned double u8;
typedef struct Time
{
	u8 year;
	u8 mon : 4;


};
int main_()
{
	time_t tim=time(NULL);
	int data = time(&tim);
	struct data
	{
		int year;
		int month;
		int day;
		int hour;
		int min;
		int scn;
	}Data = {1970,1,1,0,0,0};
	Data.year+= data / (365 * 24 * 60 * 60);
	data -= data / (365 * 24 * 60 * 60);
	Data.month += data / (30 * 24 * 60 * 60);
	data -= data / (30 * 24 * 60 * 60);
	//("cls")
	printf("%d_%d", Data.year,Data.month);
	
	/*int yearadd = tim / (365 * 24 * 60 * 60);
	int monthadd = (tim - yearadd) / (30 * 24 * 60 * 60);
	int dayadd = (tim - yearadd - monthadd) / (24 * 60*60); 
	int houradd = (tim - yearadd - monthadd-dayadd) / (60*60);
	int minadd = (tim - yearadd - monthadd - dayadd-houradd) / (60);
	int sedadd = (tim - yearadd - monthadd - dayadd-houradd-minadd) ;
	printf("%d", &yearadd);*/
	//printf("%d_%d_%d  %d:%d:%d", &yearadd+1970,&monthadd,&dayadd,&houradd,&minadd,&sedadd);

	/*int a = 1000;
	FILE *pf = fopen("test.txt", "wb");
	fwrite(&a, 4, 1, pf);
	fclose(pf);
	pf = NULL;*/
	system("pause");
	return 0;
}
#endif