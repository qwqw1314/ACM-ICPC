#include<iostream>

using namespace std;

int n, m;
int	candy[1010][1010], dy[1010][1010];

#define maxx(x, y) (((x) > (y)) ? (x) : (y))

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> candy[i][j];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			dy[i][j] = maxx(dy[i - 1][j], maxx(dy[i][j - 1], dy[i - 1][j - 1])) + candy[i][j];
	cout << dy[n][m];
	return 0;
}