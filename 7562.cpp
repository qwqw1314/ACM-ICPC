#include<iostream>
#include<queue>

using namespace std;

int n, mx[8] = {1,2,2,1,-1,-2,-2,-1}, my[8] = {-2,-1,1,2,2,1,-1,-2};
int a[310][310];
int sx, sy, ex, ey;

void BFS()
{
	int i;
	queue<pair<int, int> > q;
	q.push(make_pair(sx, sy));
	a[sx][sy] = 0;
	if (sx == ex && sy == ey)
		return;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (i = 0; i < 8; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 0 && nx <= n && ny >= 0 && ny <= n && a[nx][ny] == 0)
			{
				a[nx][ny] = a[temp.first][temp.second] + 1;
				if (nx == ex && ny == ey)
					return;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	int t, T, i, j;
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> n;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				a[i][j] = 0;
		cin >> sx >> sy >> ex >> ey;
		BFS();
		cout << a[ex][ey] << endl;
	}
	return 0;
}