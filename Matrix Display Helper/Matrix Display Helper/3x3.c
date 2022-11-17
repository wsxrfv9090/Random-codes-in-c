#include <stdio.h>

void threebythree()
{
	double arr[3][3] = { 0 };
	printf("please input nine numbers: \n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf_s("%lf", &arr[i][j], 8);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("|    ");
		for (int j = 0; j < 3; j++)
		{
			printf("%lf     ", arr[i][j]);
		}
		printf("|");
		printf("\n");
	}
}