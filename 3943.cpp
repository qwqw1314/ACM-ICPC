#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int max;

int func(int x)
{
	if (x == 1)
		return max;
	if (x > max)
		max = x;
	if (x % 2 == 0)
		func(x / 2);
	else
		func(x * 3 + 1);
}

int main()
{
	int t, T, i;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		max = 0;
		int temp;
		scanf("%d", &temp);
		if (temp == 1)
		{
			printf("1\n");
			continue;
		}
		printf("%d\n", func(temp));
	}
	return 0;
}