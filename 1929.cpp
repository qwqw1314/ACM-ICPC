#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

bool prime[1000010];

int main()
{
	int i, j, n, m;
	prime[0] = prime[1] = true;
	for (i = 2; i <= 1000000; i++)
	{
		for (j = i + i; j <= 1000000; j += i)
		{
			prime[j] = true;
		}
	}
	scanf("%d %d", &n, &m);
	for (i = n; i <= m; i++)
	{
		if (prime[i] == false)
			printf("%d\n", i);
	}
	return 0;
}