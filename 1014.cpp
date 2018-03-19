#include<iostream>

using namespace std;

int chk[15][15];
int n, m;
int max = 0;
char a[15][15];
int mx[4] = {-1,0,1,0}, my[4] = {0,-2,0,2};

void back(int x, int y, int cnt)
{
	int i;
	if (cnt > max)
		max = cnt;
	for (i = 0; i < 4; i++)
	{
		int tox = x + mx[i], toy = y + my[i];
		if (chk[tox - 1][toy - 1] == 1 || chk[tox - 1][toy + 1] == 1 || chk[tox][toy - 1] == 1 || chk[tox][toy + 1] == 1)
			continue;
		if (a[tox][toy] == '.' && chk[tox][toy] == 0)
		{
			chk[tox][toy] = 1;
			back(tox, toy, cnt + 1);
			chk[tox][toy] = 0;
		}
	}
}

int main()
{
	int t, T, i, j;
	cin >> T;
	for (t = 0; t < T; t++)
	{
		max = 0;
		cin >> n >> m;
		for (i = 1; i <= n; i++)
			cin >> a[i];
		bool flag = false;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (a[i][j] == '.')
				{
					flag = true;
					chk[i][j] = 1;
					back(i, j, 1);
					chk[i][j] = 0;
				}
			}
			if (flag == true)
				break;
		}
		cout << max << endl;
	}
	return 0;
}