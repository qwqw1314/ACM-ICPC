#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n, m, maxint[3], maxi[3];
int w[50010], dy[50010][4], sum[50010];

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int i,j,k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
		sum[m] += w[i];
	for (i = m + 1; i <= n; i++)
		sum[i] = sum[i - 1] + w[i] - w[i - m];
	/* 시간초과
	for (i = m; i <= n - (m * 2); i++)
		for (j = i + m; j <= n - m; j++)
			for (k = i + (m * 2); k <= n; k++)
				maxint = maxx(maxint, sum[i] + sum[j] + sum[k]);*/
	for (i = m; i <= n; i++)
		dy[i][1] = sum[i];
	for (j = 1; j <= 3; j++)
	{
		for (i = m; i <= n; i++)
		{
			dy[i][j] = maxx(dy[i - 1][j], dy[i - m][j - 1] + sum[i]);
		}
	}
	printf("%d", dy[n][3]);
	return 0;
}
/*
7
35 40 50 10 30 45 60
2
   75 90 60 40 75 105
*/