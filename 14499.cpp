#include<iostream>

using namespace std;

int dice[5][4], arr[30][30];
int mx[5] = {0, 0, 0, -1, 1 }, my[5] = {0, 1, -1, 0, 0 };

void roll(int x)
{
	if (x == 1)
	{
		int temp = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = temp;
	}
	else if (x == 2)
	{
		int temp = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = temp;
	}
	else if (x == 3)
	{
		int temp = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = dice[0][1];
		dice[0][1] = temp;
	}
	else
	{
		int temp = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = temp;
	}
}

int main()
{
	int n, m, k, x, y;
	int i, j;
	cin >> n >> m >> x >> y >> k;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> arr[i][j];
	for (i = 0; i < k; i++)
	{
		int t;
		cin >> t;
		int nx = x + mx[t], ny = y + my[t];
		if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
			continue;
		roll(t);
		if (arr[nx][ny] == 0)
		{
			arr[nx][ny] = dice[3][1];
		}
		else
		{
			dice[3][1] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		cout << dice[1][1] << endl;
		x = nx, y = ny;
	}
	return 0;
}