#include<iostream>

using namespace std;

int dy[100], arr[30][2], n;

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int i, j;
	cin >> n;

	for (i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];
	for (i = 1; i <= n; i++)
	{
		for (j = i + arr[i][0]; j <= n + 1; j++)
		{
			dy[j] = maxx(dy[j], dy[i] + arr[i][1]);
		}
	}
	int maxint = 0;
	for (i = 1; i <= n + 1; i++)
		maxint = maxx(maxint, dy[i]);
	cout << maxint;
	return 0;
}