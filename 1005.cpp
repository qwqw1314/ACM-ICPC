#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int tech[1010][1010];
int time[1010], make[1010];
int check[100010][2];

int minx(int x, int y)
{
	if(x > y) return y;
	return x;
}

int main()
{
	int t, T, i, j, n, m, to;
	scanf("%d",&T);
	for (t = 0; t < T; t++)
	{
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &time[i]);
			make[i] = 1000000;
		}
		for (i = 1; i <= m; i++)
		{
			scanf("%d %d", &check[i][0], &check[i][1]);
			tech[check[i][1]][++tech[check[i][1]][0]] = check[i][0];
		}
		scanf("%d", &to);
		make[1] = time[1];
		for (i = 2; i <= n; i++)
		{
			for (j = 1; j <= tech[i][0]; j++)
			{
				make[i] = minx(make[tech[i][j]] + time[i], make[i] + time[i]);
			}
		}
	}
	return 0;
}