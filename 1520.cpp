#include<iostream>

using namespace std;

int n, m, a[510][510], dy[510][510];
int mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };

int DFS(int x, int y)
{
	int i;
	if (x == n && y == m)
		return 1;
	if (dy[x][y] >= 0)
		return dy[x][y];
	if (dy[x][y] == -1)
		dy[x][y] = 0;
	for (i = 0; i < 4; i++)
	{
		int nx = x + mx[i], ny = y + my[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] < a[x][y])
			dy[x][y] += DFS(nx, ny);
	}
	return dy[x][y];
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			dy[i][j] = -1;
			cin >> a[i][j];
		}
	}
	dy[n][m] = 1;
	DFS(1, 1);
	cout << dy[1][1];
	return 0;
}

/*이미 틀린 방식
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
*/