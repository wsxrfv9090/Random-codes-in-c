#include <math.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>

void DoubleFloat()
{
	int det = 1;
	do
	{
		printf("Please input your alrithmatic expressions: ");
		char exps[4000] = { 0 };
		char t1left[4000] = { 0 };
		int le = strlen(exps);
		char ef[le]
		scanf_s("%s", &exps, 4000);
		printf("%s\n", exps);
		Sleep(1000);
		char type1[] = { '0','1','2','3','4','5','6','7','8','9' };
		char type2[] = { '+','-','*','/','^' };
		char type3[] = { '(',')','[',']','{', '}' };
		char* t1 = strtok_s(exps, type1, &t1left);
		for (int i = 0; i < 100; i++)
		{
			if ((exps[i] != '0' && exps[i] != '1' && exps[i] != '2' && exps[i] != '3' && exps[i] != '4' && exps[i] != '5' && exps[i] != '6' && exps[i] != '7' && exps[i] != '8' && exps[i] != '9' && exps[i] != '+' && exps[i] != '-' && exps[i] != '*' && exps[i] != '/' && exps[i] != '(' && exps[i] != ')' && exps[i] != '[' && exps[i] != ']' && exps[i] != '{' && exps[i] != '}' && exps[i] != '^' && exps[i] != ' ') != 0)
			{
				printf("Input formality ex.: {[(1+3)/2+(2+4)*5]^2+3^3}\n");
				printf("It can only contains following symbol: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '^', '(', ')', '[', ']', '{', '}', ' '");
				break;
			}
		}
	} while (det);
}