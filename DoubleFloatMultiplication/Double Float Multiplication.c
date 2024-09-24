#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	double num1 = 1;
	double num2 = 1;
	scanf_s ("%lf%lf", &num1, &num2,sizeof(num1),sizeof(num2));
	double mult = 1;
	mult = num1 * num2;
	printf("mult=%lf", mult);
	return 0;
}