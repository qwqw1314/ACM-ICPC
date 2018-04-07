#include<iostream>

using namespace std;

int arr[110], dy[110][1010];
int n, s, m;

int main()
{
	int i, j;
	cin >> n >> s >> m;
	dy[0][s] = 1;
	for (i = 1; i <= n; i++)
		cin >> arr[i];
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			if (dy[i - 1][j] == 1)
			{
				if (j + arr[i] <= m)
					dy[i][j + arr[i]] = 1;
				if (j - arr[i] >= 0)
					dy[i][j - arr[i]] = 1;
			}
		}
	}
	int maxx = -1;
	for (i = 0; i <= m; i++)
		if (dy[n][i] == 1)
			maxx = i;
	cout << maxx;
	return 0;
}