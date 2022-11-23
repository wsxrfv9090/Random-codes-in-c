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
			switch (ans2)
			{
			case 1:
			{
				system("cls");
				printf("Not an option, please try again!\n\n");
				continue;
			}
			case 2:
				return 12;
			case 3:
				return 13;
			case 4:
				return 14;
			}
			break;
		case 2:
			switch (ans2)
			{
			case 1:
				return 21;
			case 2:
			{
				system("cls");
				printf("Not an option, please try again!\n\n");
				continue;
			}
			case 3:
				return 23;
			case 4:
				return 24;
			}
			break;
		case 3:
			switch (ans2)
			{
			case 1:
				return 31;
			case 2:
				return 32;
			case 3:
			{
				system("cls");
				printf("Not an option, please try again!\n\n");
				continue;
			}
			case 4:
				return 34;
			}
			break;
		case 4:
			switch (ans2)
			{
			case 1:
				return 41;
			case 2:
				return 42;
			case 3:
				return 43;
			case 4:
			{
				system("cls");
				printf("Not an option, please try again!\n\n");
				continue;
			}
			break;
			default:
				system("cls");
				printf("Not an option, please try again!");
			}
		}
	} while (ans1 = ans2);
}