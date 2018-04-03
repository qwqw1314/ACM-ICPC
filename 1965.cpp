#include<iostream>

using namespace std;

int arr[1010], cnt[1010];
int n;

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
		cin >> arr[i];
	fill(cnt + 1, cnt + n + 1, 1);
	for (i = 2; i <= n; i++)
	{
		int maxint = 0;
		for (j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
				maxint = maxx(maxint, cnt[j]);
		}
		cnt[i] = maxint + 1;
	}
	int maxint = 0;
	for (i = 1; i <= n; i++)
		maxint = maxx(maxint, cnt[i]);
	cout << maxint;
	return 0;
}