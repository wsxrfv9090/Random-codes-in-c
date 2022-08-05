#include <stdio.h>


double Add(double ar[], int x)
{
	double result = ar[0];
	for (int i = 1; ar[i] != 0; i++)
		result += ar[i];
	return result;
}