#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	double num1 = 0;
	double num2 = 0;
	scanf("%lf%lf", &num1, &num2);
	double sum = 0;
	sum = num1 + num2;
	printf("sum=%lf", sum);
	return 0;
}