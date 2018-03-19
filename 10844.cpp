#include<iostream>

using namespace std;

long long int dy[110][10], sum;

int main()
{
	int i, j, n;
	cin >> n;
	for (i = 1; i <= 9; i++)
		dy[1][i] = 1;
	for (i = 2; i <= n; i++)
	{
		dy[i][0] = dy[i - 1][1] % 1000000000;
		dy[i][9] = dy[i - 1][8] % 1000000000;
		for (j = 1; j <= 8; j++)
			dy[i][j] = (dy[i - 1][j - 1] + dy[i - 1][j + 1]) % 1000000000;
	}
	for (i = 0; i <= 9; i++)
	{
		sum = (sum + dy[n][i]) % 1000000000;
	}
	cout << sum;
	return 0;
}