#include<iostream>

using namespace std;

int dy[205][205];
int n, k;

int main()
{
	int i, j;
	cin >> n >> k;
	for (i = 1; i <= n; i++)
		dy[i][1] = 1;
	for (i = 1; i <= k; i++)
		dy[1][i] = i;
	for (i = 2; i <= n; i++)
		for (j = 1; j <= k; j++)
			dy[i][j] = (dy[i - 1][j] + dy[i][j - 1]) % 1000000000;
	cout << dy[n][k];
	return 0;
}