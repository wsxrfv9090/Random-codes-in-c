#include <stdio.h>

void threebytwo()
{
	double arr[3][2] = { 0 };
	printf("please input six numbers: \n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
			scanf_s("%lf", &arr[i][j], 8);
	}
	for (int i = 0; i < 3; i++)
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