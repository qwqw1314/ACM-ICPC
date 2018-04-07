#include<iostream>

using namespace std;

int arr[1010][1010], dy_left[1010], dy[1010][1010];
int n, m;

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
			cin >> arr[i][j];
	for (i = 1; i <= m; i++)
	{
		if (i > 1)
			dy[1][i] = dy[1][i - 1] + arr[1][i];
		else
			dy[1][i] = arr[1][i];
	}
	for (i = 2; i <= n; i++)
	{
		dy[i][1] = dy[i - 1][1] + arr[i][1];
		for (j = 2; j <= m; j++)
			dy[i][j] = maxx(dy[i - 1][j], dy[i][j - 1]) + arr[i][j];
		dy_left[m] = dy[i - 1][m] + arr[i][m];
		for (j = m - 1; j >= 1; j--)
			dy_left[j] = maxx(dy[i - 1][j], dy_left[j + 1]) + arr[i][j];
		for (j = 1; j <= m; j++)
			dy[i][j] = maxx(dy[i][j], dy_left[j]);
	}
	cout << dy[n][m];
	return 0;
}