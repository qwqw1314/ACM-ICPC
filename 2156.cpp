#include<iostream>

using namespace std;

int a[10010], dy[10010];

int maxx(int x, int y, int z)
{
	if (x > y)
		if (x > z)
			return x;
		else
			return z;
	else
		if (y > z)
			return y;
		else
			return z;
}

int main()
{
	int i, n;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	dy[1] = a[1];
	dy[2] = a[1] + a[2];
	for (i = 3; i <= n; i++)
	{
		dy[i] = maxx(dy[i - 3] + a[i - 1] + a[i], dy[i - 2] + a[i], dy[i - 1]);
	}
	cout << dy[n];
	return 0;
}