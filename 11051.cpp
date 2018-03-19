#include<iostream>

using namespace std;

int a[1010][1010];

int main()
{
	int n, k, i, j;
	cin >> n >> k;
	a[0][0] = 1;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j < i; j++)
		{
			a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % 10007;
		}
		a[i][i] = 1;
	}
	cout << a[n][k];
	return 0;
}