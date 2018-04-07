

/*
#include<iostream>

using namespace std;

#define IMAX 0x7fffffff;

int check[20], n, dis[20][20], dy[20][20];
int start;

int minx(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

void DFS(int x, int cnt, int sum)
{
	int i;
	if (cnt == n)
	{
		dy[start][x] = minx(dy[start][x], sum);
	}
	for (i = 1; i <= n; i++)
	{
		if (i == x)
			continue;
		if (check[i] == 0 && dis[x][i])
		{
			check[i] = 1;
			DFS(i, cnt + 1, sum + dis[x][i]);
			check[i] = 0;
		}
	}
}

int main()
{
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> dis[i][j];
			dy[i][i] = IMAX;
		}
	}
	for (i = 1; i <= n; i++)
	{
		check[i] = 1;
		start = i;
		DFS(i, 1, 0);
		for (j = 1; j <= n; j++)
			check[i] = 0;
	}
	return 0;
}
*/