#include<iostream>

using namespace std;

int n, m, maxint;
char a[1010][1010];
int dy[1010][1010];

int minx(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] == '1')
			{
				dy[i][j] = minx(dy[i - 1][j], minx(dy[i][j - 1], dy[i - 1][j - 1])) + 1;
				maxint = maxx(maxint, dy[i][j]);
			}
		}
	}
	cout << maxint * maxint;
	return 0;
}