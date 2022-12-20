#include "game.h"

void boardInit(char board[ROW][COL],int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}
void boardDisplay(char board[ROW][COL],int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j < COL - 1)
				printf(" %c |",board[i][j]);
			if (j == COL - 1)
				printf(" %c ",board[i][j]);
		}
		printf("\n");
		if (i < ROW - 1)
			for (int j = 0; j < COL; j++)
			{
				if (j < COL - 1)
					printf("---|");
				if (j == COL - 1)
					printf("---\n");
			}
	}
}

void playerMove(char board[ROW][COL], int row, int col)
{
	printf("It's your move, please input a coordinate: ");
	while (1)
	{
		int x = 0;
		int y = 0;
		scanf_s("%d %d", &x, &y, 4, 4);
		if (x > 0 && x <= ROW && y > 0 && y <= COL)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '@';
				break;
			}
			else
				printf("Input incorrect, please input again.\n");
		}
		else
			printf("Input incorrect, please input again.\n");
	}
}

void computerMove(char board[ROW][COL], int row, int col)
{
	printf("Computer's move.\n");

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int gameDef(char board[ROW][COL], int row, int col)
{
	//Player Win = 0;
	//Computer Win = 1;
	//On going = 2;
	//Draw = 3;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j + 3] == board[i][j + 4] && board[i][j] != ' ')
			{
				if (board[i][j] == '@')
				{
					return 0;
				}
				else if (board[i][j] == '#')
				{
					return 1;
				}
			}
			else if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 2][j] == board[i + 3][j] && board[i + 3][j] == board[i + 4][j] && board[i][j] != ' ')
			{
				if (board[i][j] == '@')
				{
					return 0;
				}
				else if (board[i][j] == '#')
				{
					return 1;
				}
			}
			else if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i + 3][j + 3] == board[i + 4][j + 4] && board[i][j] != ' ')
			{
				if (board[i][j] == '@')
				{
					return 0;
				}
				else if (board[i][j] == '#')
				{
					return 1;
				}
			}
			else if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 2][j - 2] == board[i - 3][j + 3] && board[i + 3][j - 3] == board[i + 4][j - 4] && board[i][j] != ' ')
			{
				if (board[i][j] == '@')
				{
					return 0;
				}
				else if (board[i][j] == '#')
				{
					return 1;
				}
			}
			else
			{
				for (int m = 0; m < row; m++)
				{
					for (int n = 0; n < col; n++)
					{
						if (board[m][n] == ' ')
							return 2;
					}
				}
			}
		}
	}
	return 3;
}
void game()
{
	char board[ROW][COL];
	boardInit(board, ROW, COL);
	boardDisplay(board, ROW, COL);
	int tmp = -1;
	while (1)
	{
		playerMove(board, ROW, COL);
		boardDisplay(board, ROW, COL);
		tmp = gameDef(board, ROW, COL);
		if (tmp != 2)
			break;
		computerMove(board, ROW, COL);
		boardDisplay(board, ROW, COL);
		tmp = gameDef(board, ROW, COL);
		if (tmp != 2)
			break;
	}
	if (tmp == 0)
		youWon();
	if (tmp == 1)
		computerWon();
	if (tmp == 3)
		draw();
}