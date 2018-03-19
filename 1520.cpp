#include<iostream>

using namespace std;

int a[510][510], dy[510][510], check[510][510];
int n, m;

int DFS(int x, int y)
{
	int i;
	int movex[5] = { 0, 0, 1, 0, -1 };
	int movey[5] = { 0, 1, 0, -1, 0 };
	if (x == n && y == m)
	{
		return 1;
	}
	if (dy[x][y] != 0)
	{
		return dy[x][y];
	}
	for (i = 1; i <= 4; i++)
	{
		int tox = x + movex[i];
		int toy = y + movey[i];
		if (a[tox][toy] < a[x][y] && tox > 0 && tox <= n && toy > 0 && toy <= m)
		{
			dy[x][y] += DFS(tox, toy);
		}
	}
	return dy[x][y];
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	int result = DFS(1, 1);
	cout << result;
	return 0;
}