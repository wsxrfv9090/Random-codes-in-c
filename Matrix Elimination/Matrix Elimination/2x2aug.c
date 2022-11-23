#include <stdio.h>

void twobytwoaug()
{
	double arr[2][3] = { 0 };
	printf("please input six numbers: \n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf_s("%lf", &arr[i][j], 8);
	}
	if (arr[0][0] == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			double tmp = 0;
			tmp = arr[0][i];
			arr[0][i] = arr[1][i];
			arr[1][i] = tmp;
		}
	}
	if (arr[0][0] == 0)
	{
		printf("x1 is Convenience Variable\n");
		if (arr[0][1] == 0)
		{

		}
		if (arr[0][1] == 0)
		{
			if (arr[0][2] != arr[1][2])
				printf("ERROR: Unsolvable\n");
			else
			{
				printf("x1 is Convenience Variable");
				printf("x2 is Convenience Variable");
			}
		}
		else
		{
			if (arr[1][1] != 0)
			{
				arr[0][2] /= arr[0][1];
				arr[0][1] = 1;
				arr[1][2] -= arr[0][2] * arr[1][1];
				arr[1][1] = 0;
				if ()
			}
		}
	}
	else
	{

	}
	//if (arr[0][0] == 0)
	//{
	//	for (int i = 0; i < 3; i++)
	//	{
	//		double tmp = 0;
	//		tmp = arr[0][i];
	//		arr[0][i] = arr[1][i];
	//		arr[1][i] = tmp;
	//	}
	//	if (arr[0][0] == 0)
	//	{
	//		printf("x1 is Convenience Variable\n");
	//		if (arr[0][1] != 0 && arr[1][1] != 0)
	//		{
	//			if (arr[0][1] / arr[0][2] == arr[1][1] / arr[1][2])
	//			{
	//				arr[0][2] = arr[0][2] / arr[0][1];
	//				arr[0][1] = 1;
	//				arr[1][2] = arr[1][2] / arr[1][1];
	//				arr[1][1] = 1;
	//				printf("x2 = %lf", arr[0][2]);
	//			}
	//			else
	//				printf("It's an unsolvable matrix since x2 has no probable solution\n");
	//		}
	//		else if (arr[0][1] == 0 || arr[1][1] == 0)
	//		{
	//			if (arr[0][1] == 0 && arr[0][2] == 0)
	//				printf("It's an unsolvable matrix since the first equation doesn't add up\n");
	//			if (arr[1][1] == 0 && arr[1][2] == 0)
	//				printf("It's an unsolvable matrix since the second equation doesn't add up\n");
	//			//if (arr[0][1] == 0 && arr[1][1] == 0 && (arr[0][2] != arr[1][2]))
	//			if (arr[0][1] == 0)
	//			{
	//				for (int i = 1; i < 3; i++)
	//				{
	//					int tmp = arr[0][i];
	//					arr[0][i] = arr[1][i];
	//					arr[1][i] = tmp;
	//				}
	//				if (arr[0][1] != 0 && arr[1][2] == 0)
	//				{
	//					arr[0][2] = arr[0][2] / arr[0][1];
	//					arr[0][1] = 1;
	//					printf("x2 = %lf\n", arr[0][2]);
	//				}
	//				else
	//				{
	//					if (arr[1][2] != 0)
	//						printf("It's an unsolvable matrix since the second equation doesn't add up\n");
	//					else
	//					{
	//						arr[0][2] = arr[0][2] / arr[0][1];
	//						arr[0][1] = 1;
	//						printf("x2 = %lf\n", arr[0][2]);
	//					}
	//				}
	//			}
	//			else
	//			{
	//				if (arr[1][2] != 0)
	//					printf("It's an unsolvable matrix since the second equation doesn't add up\n");
	//				else
	//				{
	//					arr[0][2] = arr[0][2] / arr[0][1];
	//					arr[0][1] = 1;
	//					printf("x2 = %lf\n", arr[0][2]);
	//				}
	//			}
	//		}
	//		else 
	//			printf("It's an unsolvable matrix since x2 is not possible to have a solution\n");
	//	}
	//}
	//else if (arr[0][1] == 0 && arr[1][1] == 0)
	//	printf("error: it does not have pivot on its second column\n");
	//else if (arr[0][0] / arr[1][0] == arr[0][1] / arr[1][1])
	//	printf("error: it's two same direction, hence two of them are convenience variable.\n");
	//else
	//{
	//	arr[0][1] = arr[0][1] / arr[0][0];
	//	arr[0][2] = arr[0][3] / arr[0][0];
	//	arr[0][0] = 1;
	//	arr[1][1] = arr[1][1] - arr[0][1] * arr[1][0];
	//	arr[1][2] = arr[1][2] - arr[0][2] * arr[1][0];
	//	arr[1][0] = 0;
	//	arr[0][2] = arr[0][2] - arr[0][1] * arr[1][2];
	//	arr[0][1] = 0;
	//	printf("x1 = %lf", arr[0][2]);
	//	printf("x2 = %lf", arr[1][2]);
	//}
	for (int i = 0; i < 2; i++)
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