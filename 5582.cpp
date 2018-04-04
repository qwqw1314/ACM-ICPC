#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char a[4010], b[4010];
int dy[4010][4010], maxint;

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int n, m, i, j;
	scanf("%s %s", a + 1, b + 1);
	a[0] = b[0] = '1';
	n = strlen(a) - 1, m = strlen(b) - 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
			{
				dy[i][j] = dy[i - 1][j - 1] + 1;
				maxint = maxx(maxint, dy[i][j]);
			}
		}
	}
	printf("%d", maxint);
	return 0;
}