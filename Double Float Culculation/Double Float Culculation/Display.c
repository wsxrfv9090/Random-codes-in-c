#include <stdio.h>

int Menu()
{
	printf("Welcome to Davy's culculator!!!\n");
	printf("Which kind of operation would you like to do first?\n\n\n");
	printf("         1.Addition\n");
	printf("         2.Subtraction\n");
	printf("         3.Multiplication\n");
	printf("         4.Divition\n\n");
	printf("Type your answer here: ");
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

void DisplayResult(double x)
{
	printf("The result is %lf", x);
}

int More()
{
	int tmp = 0;
	while (1)
	{
		printf("Would you like futher culculation?\n");
		printf("         1.Yes,Addition!\n");
		printf("         2.Yes,Subtraction!\n");
		printf("         3.Yes,Multiplication!\n");
		printf("         4.Yes,Division!\n");
		printf("         5.No,the result is good enough!\n\n");
		printf("Type your answer here: ");
		scanf_s("%d", &tmp, 1);
		if (tmp == 5)
			break;
		else if (tmp != 1 && tmp != 2 && tmp != 3 && tmp != 4)
			printf("Incorrect input,please try again.");
		else
			break;
	}
	return tmp;
}




