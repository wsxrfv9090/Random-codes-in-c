#include <math.h>
#include <string.h>

int BinaryToDecimal()
{
	char arr[8] = { 0 };
	printf("8 digits number is required: ");
	scanf_s("%s", &arr, 32);
	int subscript = 7;
	int tmp_answer = 0;
	int i = 0;
	for (int subscript = 7; subscript >= 0; subscript--)
	{
		if (arr[i] == '1')
		{
			tmp_answer += pow(2, subscript);
		}
		i++;
	}
	return tmp_answer;
}

void DecimalToBinary(int a, char* p)
{
	printf(" digits number is required: ");
	int count = 1;
	int BPower = 0;
	do
	{
		count *= 2;
		BPower++;
	} while (count * 2 < a);
	for (int i = BPower; i >= 0; i--)
	{
		int BValue = pow(2, i);
		if (a >= BValue)
		{
			*(p + 7 - i) = '1';
			a -= BValue;
		}
		else
			*(p + 7 - i) = '0';

	}
}
	//char outputarr[9] = { 0 };
	//for (int i = 7; i >= 0; i--)
	//{
	//	if (x >= pow(2, i))
	//	{
	//		outputarr[i] = 1;
	//		x -= pow(2, i);
	//	}
	//	else
	//		outputarr[i] = 0;
	//}
	//for (int i = 0; i < 9; i++)
	//	*(p + i) = outputarr[i];
		//x >= pow(2, i) ? outputarr[i] = 1 : outputarr[0];




//char OPERATION_ANSWER[2];
//char BINARY[16];
//int BINARY_DECIMALVALUE = 1;
//short BINARY_REPEAT = 0;
//int BIT_VALUE;
//int BIT_INDEX;
//int DECIMAL;
//scanf_s("%d", &DECIMAL, 4);
//
//	while (BINARY_DECIMALVALUE <= DECIMAL)
//	{
//		BINARY_DECIMALVALUE = BINARY_DECIMALVALUE * 2;
//		BINARY_REPEAT++;
//	}
//
//	BINARY_DECIMALVALUE = BINARY_DECIMALVALUE / 2;
//
//	printf("BINARY RESULT --> ");
//
//	for (int i = BINARY_REPEAT - 1; i >= 0; i--)
//	{
//		BIT_VALUE = pow(2, i);
//
//		if (DECIMAL >= BIT_VALUE)
//		{
//			printf("1");
//			DECIMAL = DECIMAL - BIT_VALUE;
//		}
//		else
//		{
//			printf("0");
//		}
//	}
//	printf("\n"); // | LINE BREAKER |