#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		while (n%i == 0)
		{
			printf("%d\n", i);
			n /= i;
		}
	}
	return 0;
}