#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int a[110];

int gcd(int x, int y)
{
	while (y != 0)
	{
		if (x < y)
		{
			int t = x;
			x = y;
			y = t;
		}
		x = x - y;
	}
	return x;
}

int main()
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (i = 1; i < n; i++)
		a[i] -= a[0];
	int g = a[1];
	for (i = 2; i < n; i++)
		g = gcd(g, a[i]);
	for (i = 2; i <= sqrt(g); i++)
	{
		if (g % i == 0)
			printf("%d ",i);
	}
	printf("%d", g);
	return 0;
}