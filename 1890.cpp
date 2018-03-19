#include<iostream>

using namespace std;

int a[110][110];
long long int dy[110][110];

int main()
{
	int i, j, n;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> a[i][j];
	dy[0][0] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == n - 1 && j == n - 1)
				break;
			if (dy[i][j] != 0)
			{
				if (i + a[i][j] < n)
					dy[i + a[i][j]][j] += dy[i][j];
				if (j + a[i][j] < n)
					dy[i][j + a[i][j]] += dy[i][j];
			}
		}
	}
	cout << dy[n - 1][n - 1];
	return 0;
}