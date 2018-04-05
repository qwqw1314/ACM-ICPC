#include<iostream>

using namespace std;

int arr[60][60], chk[60][60];
int dirx[4] = {-1, 0, 1, 0}, diry[4] = {0, 1, 0, -1};
int n, m, r, c, d;

int minusd(int x)
{
	if (x == 0)
		return 3;
	else
		return x - 1;
}

int main()
{
	int i, j;
	int cnt = 0;
	cin >> n >> m;
	cin >> r >> c >> d;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> arr[i][j];
	int x = r, y = c;
	while (1)
	{
		if (chk[x][y] == 0)
		{
			chk[x][y] = 1;
			cnt++;
		}
		int temp = d;
		while (1)
		{
			d = minusd(d);
			int nx = x + dirx[d], ny = y + diry[d];
			if (chk[nx][ny] == 0 & arr[nx][ny] == 0)
			{
				x = nx, y = ny;
				break;
			}
			if (temp == d)
			{
				int temp2 = d;
				temp2 = minusd(temp2);
				temp2 = minusd(temp2);
				nx = x + dirx[temp2], ny = y + diry[temp2];
				if (arr[nx][ny] == 1)
				{
					cout << cnt;
					return 0;
				}
				else
				{
					x = nx, y = ny;
					break;
				}
			}
		}
	}
	return 0;
}