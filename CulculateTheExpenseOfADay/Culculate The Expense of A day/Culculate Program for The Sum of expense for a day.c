#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>




int main()
{
	printf("Type your expenses here, I'll culculate the sum of them for you.\n");
	double arr[100] = { 0 };
	double sum = 0;
	for (int i = 0; i <= 30; i++)
	{
		scanf_s("%lf", &arr[i], 4);
		if (arr[i] == 0)
			break;
		sum += arr[i];
	}
	printf("sum = %lf", sum);
	return 0;
}