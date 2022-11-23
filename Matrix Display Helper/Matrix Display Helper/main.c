#include <stdio.h>
#include <Windows.h>
#include "Culculations.h"


int main()
{
	printf("type 0 or 1 to decide if its an augmented matrix:\n");
	printf("(0 for non-augmented matrix): ");
	int augdef = 0;
	scanf_s("%d", &augdef, 4);
	if (augdef == 0)
	{
		printf("Type your squire matrix form: (Example: 2 2): ");
		int rownum = 1;
		int colnum = 1;
		scanf_s("%d", &rownum, 4);
		scanf_s("%d", &colnum, 4);
		if (rownum == 2)
		{
			if (colnum == 2)
				twobytwo();
			if (colnum == 3)
				twobythree();
			if (colnum == 4)
				twobyfour();
		}
		else if (rownum == 3)
		{
			if (colnum == 2)
				threebytwo();
			if (colnum == 3)
				threebythree();
			if (colnum == 4)
				threebyfour();
		}
		else if (rownum == 4)
		{
			if (colnum == 2)
				fourbytwo();
			if (colnum == 3)
				fourbythree();
			if (colnum == 4)
				fourbyfour();
		}
		else
			printf("input wrong, please try again.");
	}
	else if (augdef == 1)
	{
		printf("Type your squire matrix form: (Example: 2 2): ");
		int rownum = 1;
		int colnum = 1;
		scanf_s("%d", &rownum, 4);
		scanf_s("%d", &colnum, 4);
		if (rownum == 2)
		{
			if (colnum == 2)
				twobytwoaug();
			if (colnum == 3)
				twobythreeaug();
			if (colnum == 4)
				twobyfouraug();
		}
		else if (rownum == 3)
		{
			if (colnum == 2)
				threebytwoaug();
			if (colnum == 3)
				threebythreeaug();
			if (colnum == 4)
				threebyfouraug();
		}
		else if (rownum == 4)
		{
			if (colnum == 2)
				fourbytwoaug();
			if (colnum == 3)
				fourbythreeaug();
			if (colnum == 4)
				fourbyfouraug();
		}
		else
			printf("input wrong, please try again.");
	}

	Sleep("1000000");
	return 0;

}