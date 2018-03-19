#include<iostream>

using namespace std;

int a[100010];

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int max = -10000;
	int i, n;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i <= n; i++)
	{
		if (a[i - 1] > 0)
			if (a[i - 1] + a[i] > 0)
				a[i] += a[i - 1];
		if (max < a[i])
			max = a[i];
	}
	cout << max;
	return 0;
}