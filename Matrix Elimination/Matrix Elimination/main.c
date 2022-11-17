#include <stdio.h>
#include "Culculations.h"


int main()
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
	return 0;

}