#include <stdio.h>

void twobyfouraug()
{
	double arr[2][5] = { 0 };
	printf("please input ten numbers: \n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
			scanf_s("%lf", &arr[i][j], 8);
	}
	for (int i = 0; i < 2; i++)
	{
		printf("|    ");
		for (int j = 0; j < 5; j++)
		{
			printf("%lf     ", arr[i][j]);
		}
		printf("|");
		printf("\n");
	}
}