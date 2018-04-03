#include<iostream>

using namespace std;

int arr[310][310], sum[310][310];

int main()
{
	int n, m, t, i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + arr[i][j] - sum[i - 1][j - 1];
	cin >> t;
	while (t--)
	{
		int t1, t2, t3, t4;
		cin >> t1 >> t2 >> t3 >> t4;
		cout << sum[t3][t4] - sum[t1 - 1][t4] - sum[t3][t2 - 1] + sum[t1 - 1][t2 - 1] << endl;
	}
	return 0;
}