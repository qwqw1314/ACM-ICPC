#include<iostream>

using namespace std;

long long int dy[110][25];
int arr[110], n;

int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> arr[i];
	dy[1][arr[1]] = 1;
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j <= 20; j++)
		{
			if (dy[i - 1][j] > 0)
			{
				if (j + arr[i] <= 20)
					dy[i][j + arr[i]] += dy[i - 1][j];
				if (j - arr[i] >= 0)
					dy[i][j - arr[i]] += dy[i - 1][j];
			}
		}
	}
	cout << dy[n - 1][arr[n]];
	return 0;
}