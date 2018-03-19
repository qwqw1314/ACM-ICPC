#include<iostream>

using namespace std;

int a[10][10];
int co[10][10];
int n, m;
int mx[4] = {-1, 0, 1, 0}, my[4] = {0, -1, 0, 1};
int maxx = 0;

void spread(int c[][10], int x, int y)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (c[x + mx[i]][y + my[i]] == 0 && (x + mx[i] >= 0 && x + mx[i] < n) && (y + my[i] >= 0 && y + my[i] < m))
		{
			c[x + mx[i]][y + my[i]] = 2;
			spread(c, x + mx[i], y + my[i]);
		}
	}
}

void makewall(int b[][10], int cnt)
{
	int i, j;
	if (cnt == 3)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				co[i][j] = b[i][j];
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (co[i][j] == 2)
					spread(co, i, j);
		int zero;
		zero = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (co[i][j] == 0)
					zero++;
		if (maxx < zero)
			maxx = zero;
		return;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (b[i][j] == 0)
			{
				b[i][j] = 1;
				makewall(b, cnt + 1);
				b[i][j] = 0;
			}
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> a[i][j];
			co[i][j] = a[i][j];
		}
	}
	makewall(a, 0);
	cout << maxx;
	return 0;
}