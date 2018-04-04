#include<iostream>

using namespace std;

int arr[1010], dy[1010];

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> arr[i], dy[i] = 1;
	for (i = 2; i <= n; i++)
	{
		int maxint = 0;
		for (j = 1; j < i; j++)
		{
			if (arr[i] < arr[j])
				maxint = maxx(maxint, dy[j]);
		}
		dy[i] = maxint + 1;
	}
	int maxint = 0;
	for (i = 1; i <= n; i++)
		maxint = maxx(maxint, dy[i]);
	cout << maxint;
	return 0;
}