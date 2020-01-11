#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//#define PLAYER_COLOR X
//#define COMPUTER_COLOR O
#pragma warning (disable:4996)
void ShowMenu()
{
	printf("#################\n");
	printf("##1.Play 2.Exit##\n");
	printf("#################\n");
	printf("Please Select: ");
}
void InitBoard(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void ShowBoard(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("ÈçÍ¼£º\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		if (i < 2)
		{
			printf("---|---|---|");
		}
		printf("\n");
	}
}
void PlayerMove(char board[][COL], int row, int col)
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("Please Enter Pos<x,y>:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("Enter Error,Try Again!\n");
				continue;
			}
		}
	}
}
char Judge(char board[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <row; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] == board[i][j + 1]&&board[i][j]!=' ');
			else break;
		}
		if (j == col - 1)
		{
			return board[i][j];
			break;
		}
	}//ºáÅÐ¶Ï
	for (j = 0; j <col; j++)
	{
		for (i = 0; i< col - 1; i++)
		{
			if (board[i][j] == board[i + 1][j]&&board[i][j] != ' ');
			else break;
		}
		if (i == row - 1)
		{
			return board[i][j];
			break;
		}
	}//ÊúÅÐ¶Ï
	for (i = 0, j = 0; i < row - 1, j < col - 1; i++, j++)
	{
		if (board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ')
			;
		else break;
	}
	if (i == row - 1 && j == col - 1)
		return board[i][j];
	//\ÅÐ¶Ï
	for (i = row - 1, j = 0; i >0, j < col - 1; i--, j++)
	{
		if (board[i][j] == board[i - 1][j + 1] && board[i][j] != ' ')
			;
		else break;
	}
	if (i == 0 && j == col - 1)
		return board[i][j];
	// /ÅÐ¶Ï
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'N';
				break;
			}	
		}
	}//Æå²»Âú
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				;
			}
		}
	}
	if (i == row&&j == col)
		return 'E';
	//ÆåÂú
}
int GetRandom(int start, int end)
{
	return rand() %(end-start+1)+start;
}
void ComputerMove(char board[][COL], int row, int col)
{
	while (1){
		int x = GetRandom(1, 3);
		int y = GetRandom(1, 3);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("Computer Enter Error,Try Again!\n");
			}
		}
	}
}
	void Game()
	 {
		char result = 0;
		char board[ROW][COL];
		InitBoard(board, ROW, COL);
		ShowBoard(board, ROW, COL);
		srand((unsigned int)time(NULL));
		while (1){
			PlayerMove(board, ROW, COL);
			ShowBoard(board, ROW, COL);
			result = Judge(board, ROW, COL);
			if (result != 'N')
			{
				break;
			}
			ComputerMove(board, ROW, COL);
			ShowBoard(board, ROW, COL);
			result = Judge(board, ROW, COL);
			if (result != 'N')
			{
				break;
			}
		}
			switch (result){
			case 'X':
				printf("you win!\n");
				break;
			case 'O':
				printf("computer win!\n");
				break;
			case 'E':
				printf("Equal!\n");
				break;
			default:
				printf("bug?\n");
				break;
			}
		printf("ÔÙÀ´Ò»°Ñ£¿");
	}
int main()
{
	int select = 0;
	int quit = 0;
	while (!quit){
		ShowMenu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			break;
		case 2:
			printf("Bye bye!\n");
			quit = 1;
			break;
		default:
			printf("Select error,try again!\n");
			break;
		}
	}
	system("pause");
	return 0;
}