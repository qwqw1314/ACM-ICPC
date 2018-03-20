#include<iostream>
#include<queue>

using namespace std;

int a[110][110][110], cnt[110][110][110], visited[110][110][110], n, m, o, maxx;
int mx[6] = { -1, 0, 1, 0, 0, 0 }, my[6] = { 0, -1, 0, 1, 0, 0 }, mz[6] = { 0, 0, 0, 0, 1, -1 };

struct abc
{
	int x, y, z;
};

queue<abc> q;

void BFS()
{
	while (!q.empty())
	{
		abc temp2 = q.front();
		for (int i = 0; i < 6; i++)
		{
			int nx = temp2.x + mx[i], ny = temp2.y + my[i], nz = temp2.z + mz[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && nz >= 1 && nz <= o)
			{
				if (a[nx][ny][nz] == 0/* && cnt[nx][ny][nz] == 0*/)
				{
					a[nx][ny][nz] = 1;
					cnt[nx][ny][nz] = cnt[temp2.x][temp2.y][temp2.z] + 1;
					abc temp3 = { nx, ny, nz };
					q.push(temp3);
				}
			}
		}
		q.pop();
	}
}

int main()
{
	int i, j, k;
	cin >> m >> n >> o;
	for (k = 1; k <= o; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				cin >> a[i][j][k];
				if (a[i][j][k] == 1)
				{
					abc temp = { i, j, k };
					q.push(temp);
				}
			}
		}
	}
	BFS();
	bool flag = false;
	for (k = 1; k <= o; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (a[i][j][k] == 0)
					flag = true;
				else if (a[i][j][k] == 1)
				{
					if (maxx < cnt[i][j][k])
						maxx = cnt[i][j][k];
				}
			}
		}
	}
	if (flag == true)
		cout << -1;
	else
		cout << maxx;
	return 0;
}
/*
5 3 1
1 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1
*/