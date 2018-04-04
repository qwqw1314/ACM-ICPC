#include<iostream>

using namespace std;

int	a[2000], dy[2000];
int n;

int minx(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	dy[1] = 0;
	fill(dy + 2, dy + n + 1, 1000000);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= a[i]; j++)
			dy[i + j] = minx(dy[i + j], dy[i] + 1);
	if (dy[n] == 1000000)
		cout << -1;
	else
		cout << dy[n];
	return 0;
}