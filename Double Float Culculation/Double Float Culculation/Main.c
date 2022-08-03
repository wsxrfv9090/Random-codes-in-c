#include <stdio.h>

int main()
{
	char BUFFER[100] = { 0 };
	
	for (int i = 0; i <= 3; i++)
	{
		 x = 0;
		scanf_s("%d", &x, 1);
		BUFFER[i] = x;
	}
	printf("BUFFER = %s", BUFFER, 100);
	return 0;
}