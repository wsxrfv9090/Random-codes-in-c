#include <stdio.h>

void twobytwo()
{
	double arr[2][2] = { 0 };
	printf("please input four numbers: \n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			scanf_s("%lf", &arr[i][j], 8);
	}
	for (int i = 0; i < 2; i++)
	{
		printf("|    ");
		for (int j = 0; j < 2; j++)
		{
			printf("%lf     ", arr[i][j]);
		}
		printf("|");
		printf("\n");
	}
}