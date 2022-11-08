#include "Menu.h"
#include <Windows.h>

int print(int x, int *p)
{
	if (x > 9)
	{
		print(x / 10);
	}
	int inputarr[9] = 0;
	for (int i = 0; i < 8; i++)

}
int main()
{
	int ans;
	ans = Menu();
	switch (ans)
	{
	case 12:
		system("cls");
		printf("B to O:");
		int B = 0;
		scanf_s("%d", &B, 32);
		while (B<9999999 && B>99999999)
		{
				printf("incorrect input, please try again\n");
				printf("8 digits");
		}
		
		int ans = 0;
		for (int i = 0; i < 8; i++)
			ans = inputarr[i] * 2 ^ (7 - i);
		printf("answer is %d", ans);
	case 13:
	case 14:
	case 21:
	case 23:
	case 24:
	case 31:
	case 32:
	case 34:
	case 41:
	case 42:
	case 43:;
	}
	return 0;
}