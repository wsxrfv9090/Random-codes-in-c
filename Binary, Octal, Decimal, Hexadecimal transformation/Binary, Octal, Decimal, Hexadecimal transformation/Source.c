#include "Menu.h"
#include <Windows.h>
#include <math.h>

int main()
{
	int M_ans;
	M_ans = Menu();
	char Bnum[9] = { 0 };
	int veriable = 0;
	int middle_veriable = 0;
	switch (M_ans)
	{
		int Dnum = 0;
	case 12:
		system("cls");
		printf("B to O: ");
		Dnum = BinaryToDecimal();
		printf("answer is %o", Dnum);
		break;
	case 13:
		system("cls");
		printf("B to D: ");
		Dnum = BinaryToDecimal();
		printf("answer is %d", Dnum);
		break;
	case 14:
		system("cls");
		printf("B to H: ");
		Dnum = BinaryToDecimal();
		printf("answer is %x", Dnum);
		break;
	case 21:
		system("cls");
		printf("O to B: ");
		scanf_s("%o", &veriable, 4);
		DecimalToBinary(veriable,Bnum);
		printf("the answer is ");
		printf("%s", Bnum);
		break;
	case 23:
		system("cls");
		printf("O to D: ");
		scanf_s("%o", &veriable, 4);
		printf("answer is %d", veriable);
		break;
	case 24:
		system("cls");
		printf("O to X: ");
		scanf_s("%x", &veriable, 4);
		printf("answer is %d", veriable);
		break;
	case 31:
		system("cls");
		printf("D to B: ");
		scanf_s("%d", &veriable, 4);
		DecimalToBinary(veriable,Bnum);
		printf("the answer is ");
		printf("%s", Bnum);
		break;
	case 32:
		system("cls");
		printf("D to O: ");
		scanf_s("%d", &veriable, 4);
		printf("%o", veriable);
		break;
	case 34:
		system("cls");
		printf("D to X: ");
		scanf_s("%d", veriable, 4);
		printf("%x", &veriable, 4);
		break;
	case 41:
		system("cls");
		printf("X to B: ");
		scanf_s("%x", &veriable, 4);
		DecimalToBinary(veriable, Bnum);
		printf("the answer is ");
		printf("%s", Bnum);
		break;
	case 42:
		system("cls");
		printf("X to O: ");
		scanf_s("%x", &veriable, 4);
		printf("%o", veriable);
		break;
	case 43:
		system("cls");
		printf("X to D: ");
		scanf_s("%x", &veriable, 4);
		printf("%d", veriable);
		break;
	}
	Sleep(10000);
	return 0;
}