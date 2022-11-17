#include <stdio.h>

void twobyfour()
{
	double arr[2][4] = { 0 };
	printf("please input eight numbers: \n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
			scanf_s("%lf", &arr[i][j], 8);
	}
	for (int i = 0; i < 2; i++)
	{
		printf("|    ");
		for (int j = 0; j < 4; j++)
		{
			printf("%lf     ", arr[i][j]);
		}
		printf("|");
		printf("\n");
	}
}