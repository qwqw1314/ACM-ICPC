#include<iostream>
#include<queue>

using namespace std;

int n, m, mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };
int a[310][310], cnt[310][310], chk[310][310], allcnt;
queue<pair<int, int> > q1, q2;

void later()
{
	int i;
	while (!q1.empty())
	{
		pair<int, int> temp = q1.front();
		q1.pop();
		q2.push(temp);
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				if (a[nx][ny] == 0)
					cnt[temp.first][temp.second]++;
			}
		}
	}
}

void BFS(int x, int y)
{
	int i;
	queue<pair<int, int> > q3;
	q3.push(make_pair(x, y));
	chk[x][y] = allcnt;
	while (!q3.empty())
	{
		pair<int, int> temp = q3.front();
		q3.pop();
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				if (chk[nx][ny] == 0 && a[nx][ny] > 0)
				{
					chk[nx][ny] = allcnt;
					q3.push(make_pair(nx, ny));
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
	{
		for (j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] > 0)
				q1.push(make_pair(i, j));
		}
	}
	int cnt1 = 0;
	while (1)
	{
		later();
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (a[i][j] > 0 && chk[i][j] == 0)
				{
					allcnt++;
					BFS(i, j);
				}
			}
		}
		if (allcnt >= 2)
			break;
		allcnt = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				chk[i][j] = 0;
		while (!q2.empty())
		{
			pair<int, int> temp = q2.front();
			q2.pop();
			int x = temp.first, y = temp.second;
			if (a[x][y] > cnt[x][y])
			{
				q1.push(temp);
				a[x][y] -= cnt[x][y];
				cnt[x][y] = 0;
			}
			else
			{
				a[x][y] = 0;
				cnt[x][y] = 0;
			}
		}
		cnt1++;
	}
	cout << cnt1;
	return 0;
}