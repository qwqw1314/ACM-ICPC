#include<iostream>

using namespace std;

int n, w;
int dy[1010][3][40], arr[1010];

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int i, j, k;
	cin >> n >> w;
	for (i = 1; i <= n; i++)
		cin >> arr[i];
	for (i = 1; i <= n; i++)
	{
		for (k = 0; k <= w; k++)
		{
			if (arr[i] == 1)
			{
				dy[i][1][k] = maxx(dy[i][1][k], dy[i - 1][1][k] + 1);
				dy[i][1][k] = maxx(dy[i][1][k], dy[i - 1][2][k - 1] + 1);
				dy[i][2][k] = maxx(dy[i][2][k], dy[i - 1][2][k]);
				dy[i][2][k] = maxx(dy[i][2][k], dy[i - 1][1][k - 1]);
			}
			else
			{
				dy[i][1][k] = maxx(dy[i][1][k], dy[i - 1][1][k]);
				dy[i][1][k] = maxx(dy[i][1][k], dy[i - 1][2][k - 1]);
				dy[i][2][k] = maxx(dy[i][2][k], dy[i - 1][2][k] + 1);
				dy[i][2][k] = maxx(dy[i][2][k], dy[i - 1][1][k - 1] + 1);
			}
		}
	}
	int maxint = 0;
	for (i = 0; i <= w; i++)
		maxint = maxx(maxint, maxx(dy[n][1][i], dy[n][2][i]));
	cout << maxint;
	return 0;
}