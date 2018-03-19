#include<iostream>

using namespace std;

char a[60][60];
int n, m;

int minx(int x, int y)
{
	if (x > y)
		return y;
	return x;
}

int main()
{
	int i, j, k, small, maxx = 1;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	small = minx(n, m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			for (k = 1; k <= small; k++)
			{
				if (i + k > n || j + k > m) continue;
				if (a[i][j] == a[i][j + k] && a[i][j + k] == a[i + k][j] && a[i + k][j] == a[i + k][j + k])
				{
					if ((k + 1)*(k + 1) > maxx)
						maxx = (k + 1) * (k + 1);
				}
			}
		}
	}
	cout << maxx;
	return 0;
}