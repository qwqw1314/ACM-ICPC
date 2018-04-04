#include<iostream>

using namespace std;

#define MOD 1000000000

int dy[110][10];

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 0; i <= 9; i++)
		dy[1][i] = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dy[i + 1][j + 1] = (dy[i + 1][j + 1] + dy[i][j]) % MOD;
				continue;
			}
			if (j == 9)
			{
				dy[i + 1][j - 1] = (dy[i + 1][j - 1] + dy[i][j]) % MOD;
				continue;
			}
			dy[i + 1][j - 1] = (dy[i + 1][j - 1] + dy[i][j]) % MOD;
			dy[i + 1][j + 1] = (dy[i + 1][j + 1] + dy[i][j]) % MOD;
		}
	}
	int ans = 0;
	for (i = 0; i <= 9; i++)
		ans = (ans + dy[n][i]) % MOD;
	cout << ans % MOD;
	return 0;
}