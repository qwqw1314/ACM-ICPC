#include<iostream>
#include<string.h>

using namespace std;

char a[110], b[110], c[110];
int dy[110][110][110];
int n, m, l;

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int i, j, k;
	cin >> a + 1 >> b + 1 >> c + 1;
	a[0] = b[0] = c[0] = '1';
	n = strlen(a) - 1;
	m = strlen(b) - 1;
	l = strlen(c) - 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			for (k = 1; k <= l; k++)
			{
				dy[i][j][k] = maxx(dy[i][j][k], dy[i - 1][j][k]);
				dy[i][j][k] = maxx(dy[i][j][k], dy[i][j - 1][k]);
				dy[i][j][k] = maxx(dy[i][j][k], dy[i][j][k - 1]);
				if (a[i] == b[j] && b[j] == c[k] && dy[i][j][k] < dy[i - 1][j - 1][k - 1] + 1)
					dy[i][j][k] = dy[i - 1][j - 1][k - 1] + 1;
			}
		}
	}
	cout << dy[n][m][l];
	return 0;
}