#include<iostream>
#include<vector>

using namespace std;

#define IMAX 0x7ffffff

int arr[510], sum[510][510];
int dy[510][510];

int minx(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int main()
{
	int t, i, j, k, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 1; i <= n; i++)
			cin >> arr[i];
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				int tsum = 0;
				for (k = i; k <= j; k++)
					tsum += arr[k];
				sum[i][j] = tsum;
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j + i <= n; j++)
			{
				dy[j][j + i] = 0x7fffffff;
				for (k = j; k < j + i; k++)
				{
					dy[j][j + i] = minx(dy[j][j + i], dy[j][k] + dy[k + 1][j + i] + sum[j][j + i]);
				}
			}
		}
		cout << dy[1][n] << endl;
	}
	return 0;
}