#include<iostream>

using namespace std;

int a[2][100010], dy[2][100010];

int maxx(int x, int y)
{
	return ((x > y) ? x : y);
}

int main()
{
	int t, T, i, n;
	cin >> T;
	for (t = 0; t < T; t++)
	{
		int res = 0;
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> a[0][i];
		for (i = 0; i < n; i++)
		{
			cin >> a[1][i];
			dy[0][i] = dy[1][i] = 0;
		}
		dy[0][0] = a[0][0];
		dy[1][0] = a[1][0];
		for (i = 1; i < n; i++)
		{
			dy[0][i] = maxx(dy[1][i - 2], maxx(dy[0][i - 2], dy[1][i - 1])) + a[0][i];
			dy[1][i] = maxx(dy[0][i - 2], maxx(dy[1][i - 2], dy[0][i - 1])) + a[1][i];
			res = maxx(maxx(res, dy[0][i]), dy[1][i]);
		}
		cout << res << endl;
	}
	return 0;
}