#include <math.h>

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

int DecimalToBinary()
{
	int x = 0;
}