#include "game.h"

int main()
{
	int tmp1 = 1;
	srand((unsigned int)time(NULL));
	do
	{
		int tmp = Menu();
		system("cls");
		switch (tmp)
		{
		case 1:
			printf("Let the game start!\n");
			game();
			int tmp2 = again();
			switch (tmp2)
			{
			case 1:
				break;
			case 2:
				tmp1 = 4;
				break;
			default:
				printf("Input is not an option, please try again.\n");
			}
			break;
		case 2:
			printf("Okay, see you next time.\n");
			tmp1 = 5;
			break;
		default:
			printf("Input is not an option, please try again.\n");
			break;
		}
	} while (tmp1 == 1);
	system("cls");
	printf("Welcome back next time.\n");
	Sleep(20000);
	return 0;
}