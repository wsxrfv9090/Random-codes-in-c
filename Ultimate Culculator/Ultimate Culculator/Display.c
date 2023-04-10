#include <stdio.h>
#include <Windows.h>

void Menu()
{
	for (int i = 0; i < 4; i++)
		printf("************************************************************************\n");
	for (int i = 0; i < 4; i++)
		printf("******************  Welcome to Davy's Culculator!!!   ******************\n");
	for (int i = 0; i < 4; i++)
		printf("************************************************************************\n");
	Sleep(2000);
}

int Options()
{
	system("cls");
	int tmp = NULL;
	do
	{
		printf("******    Please choose one   *******\n");
		printf("*************************************\n");
		printf("******    1. Double Float     *******\n");
		printf("******    2. Interger         *******\n");
		printf("******    3. Float            *******\n");
		printf("*************************************\n");
		scanf_s("%d", &tmp, 4);
		system("cls");
		if ((tmp != 1 && tmp != 2 && tmp != 3) != 0)
			printf("Input incorrect! Please try again\n\n");
		else
			break;
		char tmp1;
		while ((tmp1 = getchar()) != '\n') {}
	} while (1);
	return tmp;
}