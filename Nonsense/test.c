#include <stdio.h>
#include <string.h>

int main()
{
	char arr[400] = { "qq" };
	int le = strlen(arr);
	arr[400] = arr[le];
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("%d", sz);
	printf("%s", arr);
	printf("%d", le);
	return 0;
}