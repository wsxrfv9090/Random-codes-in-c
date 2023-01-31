#include <stdio.h>


int count = 0;
void jump(int x)
{
	count++;
	int one = 1;
	int two = 2;

}
int main()
{
	int stairs = 0;
	scanf_s("%d", &stairs, 4);

	jump(stairs - 1);
}
