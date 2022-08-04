#include <stdio.h>
#include "Display.h"

int main()
{
	int tmp1 = Menu();
	switch (tmp1)
	{
	case 1:
		double arr[20] = { 0 };
		int i = 0;
		while (i <= 1000)
		{
			scanf_s("%lf", arr[i], 1);
			if (arr[i] == -1)
				break;
			i++;
		}
		int tmp = 0;
		for (int tmp = 0; arr[tmp] != 0; tmp++)
		{
			printf("%lf ", arr[tmp]);
		}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
	return 0;
}