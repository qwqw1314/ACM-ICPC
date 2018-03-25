#include<iostream>
#include<queue>

using namespace std;

int a[110][110], b[110][110], cnt;
int minx = 0x7fffffff, maxx;
int n, mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };

void BFS(int x, int y, int height)
{
	int i;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	b[x][y] = cnt;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				if (a[nx][ny] - height >= 1 && b[nx][ny] == 0)
				{
					b[nx][ny] = cnt;
					q.push(make_pair(nx, ny));
				}
			}
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
			cin >> a[i][j];
			if (a[i][j] < minx)
				minx = a[i][j];
			if (a[i][j] > maxx)
				maxx = a[i][j];
		}
	}
	int count = 1;
	for (k = minx; k < maxx; k++)
	{
		cnt = 0;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (a[i][j] - k >= 1 && b[i][j] == 0)
				{
					cnt++;
					BFS(i, j, k);
				}
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (b[i][j] > count)
					count = b[i][j];
				b[i][j] = 0;
			}
		}
	}
	cout << count;
	return 0;
}