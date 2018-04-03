#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;

int a[2010], dy[2010][2010];
int n, m;

int absx(int x)
{
	if (x < 0)
		return -x;
	return x;
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i == j)
			{
				dy[i][j] = 1;
				continue;
			}
			if (absx(i - j) <= 2)
			{
				if (a[i] == a[j])
					dy[j][i] = 1;
				continue;
			}
			else
			{
				if (a[i] == a[j] && dy[j + 1][i - 1] == 1)
					dy[j][i] = 1;
			}
		}
	}
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		printf("%d\n", dy[t1][t2]);
	}
	return 0;
}