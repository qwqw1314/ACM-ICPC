#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int a[1000010];
int b[1010];
long long int cnt = 0;

int main()
{
	int n, m, i, sum = 0;
	scanf("%d %d", &n, &m);
	b[0] = 1;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		sum %= m;
		b[sum]++;
	}
	for (i = 0; i <= 1000; i++)
	{
		if (b[i] != 0)
			cnt += (long long int)b[i] * (long long int)(b[i] - 1) / 2;
	}
	printf("%lld", cnt);
	return 0;
}