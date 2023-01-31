#include <stdio.h>
#include <Windows.h>

double last_ans = 0;
main()
{
	while (1)
	{
		system("cls");
		if (last_ans != 0)
			printf("last answer is: %lf\n", last_ans);
		printf("1. ADD\n");
		printf("2. SUB\n");
		printf("3. MUL\n");
		printf("4. DIV\n");
		int ans = 0;
		while (1)
		{
			scanf_s("%d", &ans, 4);
			if (ans < 1)
				printf("input incorrect\n");
			else if (ans > 4)
				printf("input incorrect\n");
			else
				break;
		}
		printf("input two numbers\n");
		double arr[] = { 0 };
		for (int i = 0; i < 2; i++)
			scanf_s("%lf", &arr[i], 4);
		switch (ans)
		{
		case 1:
			last_ans = arr[0] + arr[1];
			break;
		case 2:
			last_ans = arr[0] - arr[1];
			break;
		case 3:
			last_ans = arr[0] * arr[1];
			break;
		case 4:
			last_ans = arr[0] / arr[1];
			break;
		default:
			printf("Input incorrect");
		}
	}
	
	return 0;
}