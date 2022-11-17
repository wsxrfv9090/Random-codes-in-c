#include <stdio.h>

void threebythreeaug()
{
	double arr[3][4] = { 0 };
	printf("please input twelve numbers: \n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			scanf_s("%lf", &arr[i][j], 8);
	}
	for (int i = 0; i < 3; i++)
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