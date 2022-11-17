#include <stdio.h>

void fourbythreeaug()
{
	double arr[4][4] = { 0 };
	printf("please input sixteen numbers: \n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			scanf_s("%lf", &arr[i][j], 8);
	}
	for (int i = 0; i < 4; i++)
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