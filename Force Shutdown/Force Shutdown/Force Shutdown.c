#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


void DAVYISAGOD()
{
	system("cls");
	char arr1[] = "����������ְ�������������������������";
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
	printf("�������벻Ҫ�رմ˴��ڣ�����\n��ע����Խ���һ�����ڹػ�\nͬʱɾ�������㡰���ܡ�����Ҫ��ϵͳ�ļ�������������������룺����������ĳ�����\n");
	Sleep(5000);
	DAVYISAGOD();
	Sleep(2000);

again:
	Sleep(2000);
	printf("�������벻Ҫ�رմ˴��ڣ�����\n�ٴ���ʾ������ע����Խ���һ�����ڹػ�\nͬʱɾ�������㡰���ܡ�����Ҫ��ϵͳ�ļ�������������������룺����������ĳ�����\n");
	char tmp[20] = { 0 };
	scanf("%s", tmp);
	if (strcmp(tmp, "����������ĳ�����") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}