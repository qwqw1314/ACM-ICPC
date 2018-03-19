#include<iostream>

using namespace std;

int dy[1010][3], rgb[1010][3];

int minx(int x, int y)
{
	if (x > y)
		return y;
	return x;
}

int min_3(int x, int y, int z)
{
	if (x > y)
		if (y > z)
			return z;
		else
			return y;
	else
		if (x > z)
			return z;
		else
			return x;
}

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin >> rgb[i][j];
		}
	}
	dy[0][0] = rgb[0][0], dy[0][1] = rgb[0][1], dy[0][2] = rgb[0][2];
	for (i = 1; i < n; i++)
	{
		dy[i][0] = rgb[i][0] + minx(dy[i-1][1], dy[i-1][2]);
		dy[i][1] = rgb[i][1] + minx(dy[i-1][0], dy[i-1][2]);
		dy[i][2] = rgb[i][2] + minx(dy[i-1][0], dy[i-1][1]);
	}
	cout << min_3(dy[n - 1][0], dy[n - 1][1], dy[n - 1][2]);
	return 0;
}