#include<iostream>

using namespace std;

long long int dy[110][11];

int main()
{
	int t, n, i, j, k;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 0; i <= 9; i++)
			dy[1][i] = 1;
		for (i = 2; i <= n; i++)
		{
			dy[i][0] = 1;
			for (j = 1; j <= 9; j++)
				dy[i][j] = dy[i - 1][j] + dy[i][j - 1];
		}
		long long ans = 0;
		for (i = 0; i <= 9; i++)
			ans += dy[n][i];
		cout << ans << endl;
	}
	return 0;
}