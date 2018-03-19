#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

int a[10010];

int main()
{
	int n, t, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &t);
		a[t]++;
	}
	for (i = 1; i <= 10000; i++)
	{
		if (a[i] > 0)
		{
			for (j = 1; j <= a[i]; j++)
				printf("%d\n", i);
		}
	}
	return 0;
}