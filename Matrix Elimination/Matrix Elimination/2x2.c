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
	if (arr[0][0] == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			double tmp = 0;
			tmp = arr[0][i];
			arr[0][i] = arr[1][i];
			arr[1][i] = tmp;
		}
		if (arr[0][0] == 0)
		{
			printf("it does not have pivot on its first column, hense unsolvable.");
			goto end;
		}
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
end:;
}