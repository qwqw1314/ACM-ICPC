#include<iostream>
#include<queue>

using namespace std;

int n, m, mx[4] = { -1,1,0,0 }, my[4] = { 0,0,-1,1 };
int maxx = 0;
char arr[55][55];

void BFS(int x, int y)
{
	int i;
	bool chk[55][55] = { false, };
	queue<pair<int, int> > q;
	int cnt[55][55] = { -1, };
	chk[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		if (maxx < cnt[temp.first][temp.second])
			maxx = cnt[temp.first][temp.second];
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				if (arr[nx][ny] == 'L' && chk[nx][ny] == false)
				{
					chk[nx][ny] = true;
					cnt[nx][ny] = cnt[temp.first][temp.second] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (arr[i][j] == 'L')
				BFS(i, j);
		}
	}
	cout << maxx;
	return 0;
}