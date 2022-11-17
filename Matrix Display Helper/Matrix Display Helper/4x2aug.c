#include <stdio.h>

void fourbytwoaug()
{
	double arr[4][3] = { 0 };
	printf("please input twelve numbers: \n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf_s("%lf", &arr[i][j], 8);
	}
	for (int i = 0; i < 4; i++)
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