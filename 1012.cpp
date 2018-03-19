#include<iostream>

using namespace std;

int cnt;
bool a[60][60], chk[60][60];
int nx[4] = { -1,1,0,0 }, ny[4] = { 0,0,-1,1 };
int n, m, k;

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (x + nx[i] >= 0 && x + nx[i] < n && y + ny[i] >= 0 && y + ny[i] < m)
		{
			if (a[x + nx[i]][y + ny[i]] == true && chk[x + nx[i]][y + ny[i]] == false)
			{
				chk[x + nx[i]][y + ny[i]] = true;
				DFS(x + nx[i], y + ny[i]);
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
		cnt = 0;
		int t1, t2;
		cin >> m >> n >> k;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				a[i][j] = false;
				chk[i][j] = false;
			}
		}
		for (i = 0; i < k; i++)
		{
			cin >> t2 >> t1;
			a[t1][t2] = true;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (chk[i][j] == true) continue;
				if (a[i][j] == true)
				{
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}