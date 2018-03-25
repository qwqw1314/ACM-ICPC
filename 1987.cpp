#include<iostream>

using namespace std;

char alpha[30][30];
int chk[30], mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };
int n, m, maxx;

void DFS(int x, int y, int cnt)
{
	int i;
	if (cnt > maxx)
		maxx = cnt;
	for (i = 0; i < 4; i++)
	{
		int nx = x + mx[i], ny = y + my[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (chk[alpha[nx][ny] - 'A'] == 0)
			{
				chk[alpha[nx][ny] - 'A'] = 1;
				DFS(nx, ny, cnt + 1);
				chk[alpha[nx][ny] - 'A'] = 0;
			}
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> alpha[i][j];
	chk[alpha[0][0] - 'A'] = 1;
	DFS(0, 0, 1);
	cout << maxx;
	return 0;
}