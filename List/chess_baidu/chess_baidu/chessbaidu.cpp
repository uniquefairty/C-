//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#define ROW 3
//#define COL 3
//
//void init_board(char arr[ROW][COL])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			arr[i][j] = ' ';
//		}
//	}
//}
//void display_board(char arr[ROW][COL])
//{
//	int i = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		printf(" %c|%c |%c\n", arr[i][0], arr[i][1], arr[i][2]);
//		if (i < 2)
//		{
//			printf("--|--|--");
//		}
//		printf("\n");
//	}
//
//}
//void player_chess(char arr[ROW][COL])
//{
//	int x = 0;
//	int y = 0;
//	while (1)
//	{
//		printf("请输入你所要下棋的方位：");
//		scanf("%d%d", &x, &y);
//		x--;
//		y--;
//		if (arr[x][y] == ' ')
//		{
//			arr[x][y] = '#';
//			break;
//		}
//		else
//		{
//			printf("这个位置已经被占，请重新下棋。\n");
//			continue;
//		}
//	}
//}
//void computer_chess(char arr[ROW][COL])
//{
//	srand((unsigned)time(NULL));
//	while (1)
//	{
//		int x = 0;
//		int y = 0;
//		srand((unsigned)time(NULL));
//		x = rand() % 3;
//		y = rand() % 3;
//		if (arr[x][y] == ' ')
//		{
//			arr[x][y] = '@';
//			break;
//		}
//		else
//		{
//			printf("这个位置已经被占，请重新下棋。\n");
//			continue;
//		}
//	}
//}
//
//
//int check_full(char arr[ROW][COL])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			if (arr[i][j] == ' ')
//			{
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
//char check_win(char arr[ROW][COL])
//{
//	int i = 0;
//	int ret = 0;
//
//	for (i = 0; i < ROW; i++)
//	{
//		if ((arr[i][0] == arr[i][1]) && (arr[i][2] == arr[i][1]))
//		{
//			return arr[i][0];
//		}
//	}
//	for (i = 0; i < COL; i++)
//	{
//		if ((arr[0][i] == arr[1][i]) && (arr[2][i] == arr[1][i]))
//		{
//			return arr[0][i];
//		}
//	}
//	if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]))
//	{
//		return arr[0][0];
//	}
//	if ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]))
//	{
//		return arr[2][0];
//	}
//	ret = check_full(arr);
//	if (ret == 1)
//	{
//		return 'q';
//	}
//	return ' ';
//}
//int main()
//{
//	char arr[ROW][COL] = { 0 };
//	int input = 1;
//	while (input)
//	{
//
//		printf("请选择是否开始游戏：");
//		printf("1:继续游戏，0：结束游戏");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:{
//				   char ret = 0;
//				   init_board(arr);
//				   do
//				   {
//
//					   display_board(arr);
//					   player_chess(arr);
//					   display_board(arr);
//					   if (check_win(arr) != ' ')
//					   {
//						   ret = check_win(arr);
//						   break;
//					   }
//					   computer_chess(arr);
//					   ret = check_win(arr);
//				   } while (ret == ' ');
//				   display_board(arr);
//				   if (ret == '#')
//				   {
//					   printf("玩家赢的游戏\n");
//				   }
//				   else if (ret == '@')
//				   {
//					   printf("电脑赢的游戏\n");
//				   }
//				   else if (ret == 'q')
//				   {
//					   printf("游戏平局\n");
//				   }
//		}
//
//			break;
//		case 0:
//			break;
//		}
//
//	}
//	system("pause");
//	return 0;
//}
