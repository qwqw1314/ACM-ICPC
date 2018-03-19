#include<stdio.h>

int a[1026][1026];
int sum[1026][1026];

int main()
{
	int n, m;
	int i, j;
	int t1, t2, t3, t4;
	int temp;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
		}
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
		temp = sum[t3][t4] - sum[t1 - 1][t4] - sum[t3][t2 - 1] + sum[t1 - 1][t2 - 1];
		printf("%d", temp);
		if (i < m)
			printf("\n");
	}
	return 0;
}