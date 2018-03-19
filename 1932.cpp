#include<iostream>

using namespace std;

int a[510][510], dy[510][510];

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int i, j, n;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
			cin >> a[i][j];
	dy[1][1] = a[1][1];
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			dy[i][j] = maxx(dy[i - 1][j], dy[i - 1][j - 1]) + a[i][j];
		}
	}
	int maxnum = 0;
	for (i = 1; i <= n; i++)
	{
		if (dy[n][i] > maxnum)
			maxnum = dy[n][i];
	}
	cout << maxnum;
	return 0;
}