#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char num1 = 0;
	char num2 = 0;
	scanf("%s%s", &num1, &num2);
	char sum = 0;
	sum = num1 + num2;
	printf("sum=%s", sum);
	return 0;
}