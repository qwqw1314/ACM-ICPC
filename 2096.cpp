#include<iostream>

using namespace std;

int a[100010][3];
int dy_max[5], dy_min[5], temp[5];

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int minx(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int main()
{
	int i, j, n;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= 3; j++)
			cin >> a[i][j];
	dy_min[0] = dy_min[4] = 0x7fffffff;
	for (i = 1; i <= 3; i++)
		dy_max[i] = dy_min[i] = a[1][i];
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j <= 3; j++)
			temp[j] = maxx(dy_max[j - 1], maxx(dy_max[j], dy_max[j + 1]));
		for (j = 1; j <= 3; j++)
			dy_max[j] = temp[j] + a[i][j];
		for (j = 1; j <= 3; j++)
			temp[j] = minx(dy_min[j - 1], minx(dy_min[j], dy_min[j + 1]));
		for (j = 1; j <= 3; j++)
			dy_min[j] = temp[j] + a[i][j];
	}
	int maxint = 0, minint = 0x7fffffff;
	for (i = 1; i <= 3; i++)
	{
		maxint = maxx(maxint, dy_max[i]);
		minint = minx(minint, dy_min[i]);
	}
	cout << maxint << " " << minint;
	return 0;
}