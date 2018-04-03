#include<iostream>

using namespace std;

int dy[1010][10];

int main()
{
	int i, j, k, n;
	cin >> n;
	for (i = 0; i <= 9; i++)
		dy[1][i] = 1;
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			for (k = j; k <= 9; k++)
			{
				dy[i][j] += dy[i - 1][k];
				dy[i][j] %= 10007;
			}
		}
	}
	int sum = 0;
	for (i = 0; i <= 9; i++)
		sum += dy[n][i];
	cout << sum % 10007;
	return 0;
}