#include<iostream>

using namespace std;

int arr[1010], dy_asc[1010], dy_desc[1010];

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int n, i, j, maxasc, maxdesc;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> arr[i], dy_asc[i] = dy_desc[i] = 1;
	for (i = 2; i <= n; i++)
	{
		maxasc = 0;
		for (j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
				maxasc = maxx(maxasc, dy_asc[j]);
		}
		dy_asc[i] = maxasc + 1;
	}
	for (i = n - 1; i >= 1; i--)
	{
		maxdesc = 0;
		for (j = n; j > i; j--)
		{
			if (arr[i] > arr[j])
				maxdesc = maxx(maxdesc, dy_desc[j]);
		}
		dy_desc[i] = maxdesc + 1;
	}
	int maxint = 0;
	for (i = 1; i <= n; i++)
		maxint = maxx(maxint, dy_asc[i] + dy_desc[i] - 1);
	cout << maxint;
	return 0;
}