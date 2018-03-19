#include<iostream>
#include<queue>

using namespace std;

int a[1010][1010], cnt[1010][1010], n, m, maxx;
int mx[4] = { -1, 0, 1, 0 }, my[4] = { 0, -1, 0, 1 };

struct abc
{
	int x, y;
};

queue<abc> q;

void BFS()
{
	while (!q.empty())
	{
		abc temp2 = q.front();
		for (int i = 0; i < 4; i++)
		{
			int nx = temp2.x + mx[i], ny = temp2.y + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				if (a[nx][ny] == 0)
				{
					a[nx][ny] = 1;
					cnt[nx][ny] = cnt[temp2.x][temp2.y] + 1;
					abc temp3 = { nx, ny };
					q.push(temp3);
				}
			}
		}
		q.pop();
	}
}

int main()
{
	int i, j;
	cin >> m >> n;
	for(i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				abc temp = { i, j };
				q.push(temp);
			}
		}
	}
	BFS();
	bool flag = false;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] == 0)
				flag = true;
			else if (a[i][j] == 1)
			{
				if (maxx < cnt[i][j])
					maxx = cnt[i][j];
			}
		}
	}
	if (flag == true)
		cout << -1;
	else
		cout << maxx;
	return 0;
}