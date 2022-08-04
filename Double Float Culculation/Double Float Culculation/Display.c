#include <stdio.h>
int Menu()
{
	printf("Welcome to Davy's culculator!!!\n");
	printf("Which kind of operation would you like to do first?\n\n\n");
	printf("         1.Addition\n");
	printf("         2.Subtraction\n");
	printf("         3.Multiplication\n");
	printf("         4.Divition\n\n");
	int ans = 0;
	while (1)
	{
		scanf_s("%d", &ans, 1);
		if (ans != 1 && ans != 2 && ans != 3 && ans != 4)
			printf("%d is not an option please try again!", ans);
		else
			break;
	}
	return ans;
}


