#include<iostream>

using namespace std;

#define maxx(x, y) ((x) > (y)) ? (x) : (y)

int main()
{
	int n, i, j;
	int a[1010], dy[1010];
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		dy[i] = a[i];
	}
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j < i; j++)
		{
			dy[i] = maxx(dy[i], dy[i - j] + a[j]);
		}
	}
	cout << dy[n];
	return 0;
}