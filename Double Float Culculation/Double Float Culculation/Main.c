#include <stdio.h>
#include "Display.h"
#include "DoubleFADD.h"
#include "DoubleFSUB.h"
#include "DoubleFMUL.h"
#include "DoubleFDIV.h"

int main()
{
	double Result = 0;
	for (int tmp1 = Menu(); tmp1 == 1 || tmp1 == 2 || tmp1 == 3 || tmp1 == 4; tmp1 = More())
	{
		switch (tmp1)
		{
		case 1:
			double arr1[1000] = { 0 };
			arr1[0] = Result;
			int i1 = 1;
			while (i1 <= 1000)
			{
				scanf_s("%lf", &arr1[i1], 1);
				if (arr1[i1] == 0)
					break;
				i1++;
			}
			int size1 = 0;
			for (int tmp2 = 1; 1; tmp2++)
			{
				if (arr1[tmp2] == 0)
				{
					size1 = tmp2 - 1;
					break;
				}
			}
			Result = Add(arr1, size1);
			DisplayResult(Result);
			break;
		case 2:
			double arr2[1000] = { 0 };
			arr2[0] = Result;
			int i2 = 1;
			while (i2 <= 1000)
			{
				scanf_s("%lf", &arr2[i2], 1);
				if (arr2[i2] == 0)
					break;
				i2++;
			}
			int size2 = 0;
			for (int tmp2 = 1; 1; tmp2++)
			{
				if (arr2[tmp2] == 0)
				{
					size2 = tmp2 - 1;
					break;
				}
			}
			Result = Sub(arr2, size2);
			DisplayResult(Result);
			break;
		case 3:
			double arr3[1000] = { 0 };
			arr3[0] = Result;
			int i3 = 1;
			while (i3 <= 1000)
			{
				scanf_s("%lf", &arr3[i3], 1);
				if (arr3[i3] == 0)
					break;
				i3++;
			}
			int size3 = 0;
			for (int tmp2 = 1; 1; tmp2++)
			{
				if (arr3[tmp2] == 0)
				{
					size3 = tmp2 - 1;
					break;
				}
			}
			Result = Mul(arr3, size3);
			DisplayResult(Result);
			break;
		case 4:
			double arr4[1000] = { 0 };
			arr4[0] = Result;
			int i4 = 1;
			while (i4 <= 1000)
			{
				scanf_s("%lf", &arr4[i4], 1);
				if (arr4[i4] == 0)
					break;
				i4++;
			}
			int size4 = 0;
			for (int tmp2 = 1; 1; tmp2++)
			{
				if (arr4[tmp2] == 0)
				{
					size4 = tmp2 - 1;
					break;
				}
			}
			Result = Div(arr4, size4);
			DisplayResult(Result);
			break;
		}
	}
	printf("Result is %lf\n", Result);
	return 0;
}