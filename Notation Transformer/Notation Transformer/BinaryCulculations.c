#include <math.h>
#include <string.h>

int BinaryToDecimal()
{
	char arr[9] = { 0 };
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