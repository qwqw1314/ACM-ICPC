#include<iostream>

using namespace std;

#define cutting 1000000000
long long int a[110][110][4];
int n, m;

int main()
{
	int i, j, k;
	cin >> n >> m;
	a[0][0][0] = 1;
	a[1][0][0] = 1;
	a[1][1][0] = 1;
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			for (k = 0; k < 4; k++)
			{
				int t1 = a[i - 1][j][k], t2 = a[i - 1][j - 1][k];
				if (i == 100 && j == 6)
					a[0][0][0] = 1;
				if (t1 + t2 > cutting)
				{
					a[i][j][k + 1] += (t1 + t2) / cutting;
					a[i][j][k] += (t1 + t2) % cutting;
				}
				else
					a[i][j][k] += t1 + t2;
			}
		}
	}
	for (i = 3; i >= 0; i--)
	{
		if (a[n][m][i] == 0)
			continue;
		cout << a[n][m][i];
	}
	return 0;
}