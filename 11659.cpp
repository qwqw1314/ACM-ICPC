#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int a[100010], b[100010];

int main()
{
	int i;
	int n, m;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = b[i - 1] + a[i];
	}
	int t1, t2;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &t1, &t2);
		printf("%d", b[t2] - b[t1 - 1]);
		if (i < m)
			printf("\n");
	}
	return 0;
}