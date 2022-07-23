#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	double entry1 = 1;
	double entry2 = 1;
	double entry3 = 1;
	double entry4 = 1;
	double entry5 = 1;
	double entry6 = 1;
	double entry7 = 1;
	double entry8 = 1;
	double entry9 = 1;
	
	double matrix[3][3] = { entry1,entry2,entry3,entry4,entry5,entry6,entry7,entry8,entry9 };
	
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &entry1, &entry2, &entry3, &entry4, &entry5, &entry6, &entry7, &entry8, &entry9);
	
	int i = 0;
	while (i < 3)
	{
		printf("%lf\t", matrix[1][i]);
		i++;
	}
	
	return 0;
}