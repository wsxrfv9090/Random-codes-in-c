#include <stdio.h>

void threebyfouraug()
{
	double arr[3][5] = { 0 };
	printf("please input fifteen numbers: \n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
			scanf_s("%lf", &arr[i][j], 8);
	}
	for (int i = 0; i < 3; i++)
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