#include<iostream>

using namespace std;

int arr[1010], sum[1010];

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
		cin >> arr[i];
	sum[1] = arr[1];
	for (i = 2; i <= n; i++)
	{
		int maxint = 0;
		for (j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
				maxint = maxx(maxint, sum[j]);
		}
		sum[i] = maxint + arr[i];
	}
	int maxint = 0;
	for (i = 1; i <= n; i++)
		maxint = maxx(maxint, sum[i]);
	cout << maxint;
	return 0;
}