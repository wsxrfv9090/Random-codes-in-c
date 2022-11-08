#include <stdio.h>
#include <Windows.h>

int Menu()
{
	int ans1 = 0;
	int ans2 = 0;
	do
	{
		printf("Welcome to Davy's transformer!\n");
		printf("Which two would you like to transform?\n");
		printf("We have Binary, Octal, Decimal, Hexadecimal notations tranformation\n");
		printf("          1. Binary\n");
		printf("          2. Octal\n");
		printf("          3. Decimal\n");
		printf("          4. Hexadecimal\n");
		printf("\nChoose two and place the existed notation at front, and the notation you want to transform to at the back, with a space in the middle\n\n");
		printf("ex: '1 2' means to transform Binary codes in to Octal codes\n");
		printf("Type your answer here: ");
		scanf_s("%d %d", &ans1, &ans2, 4, 4);
		switch (ans1)
		{
		case 1:
			if (ans2 == 1)
			{
				system("cls");
				printf("Not an option, please try again!\n\n");
				continue;
			}
			if (ans2 = 2)
				return 12;
			if (ans2 = 3)
				return 13;
			if (ans2 = 4)
				return 14;
			break;
		case 2:
			if (ans2 == 2)
			{
				system("cls");
				printf("Not an option, please try again!\n\n");
				continue;
			}
			if (ans2 = 1)
				return 21;
			if (ans2 = 3)
				return 23;
			if (ans2 = 4)
				return 24;
			break;
		case 3:
			if (ans2 == 3)
			{
				system("cls");
				printf("Not an option, please try again!\n\n");
				continue;
			}
			if (ans2 = 1)
				return 31;
			if (ans2 = 2)
				return 32;
			if (ans2 = 4)
				return 34;
			break;
		case 4:
			if (ans2 == 4)
			{
				system("cls");
				printf("Not an option, please try again!\n\n");
				continue;
			}
			if (ans2 = 1)
				return 41;
			if (ans2 = 2)
				return 42;
			if (ans2 = 3)
				return 43;
			break;
		default:
			system("cls");
			printf("Not an option, please try again!");
		}
	} while (ans1 = ans2);
	
}