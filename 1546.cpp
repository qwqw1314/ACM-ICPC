#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int maxx(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int m, sum, max;

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		sum += t;
		if (t >= max)
			max = t;
	}
	printf("%.2lf", (double)sum / (double)max / (double)n * (double)100.0000);
	return 0;
}