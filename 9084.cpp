#include<iostream>

using namespace std;

int coin[10010], arr[30];
int n, m;

int main()
{
	int t, i, j;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 1; i <= n; i++)
			cin >> arr[i];
		cin >> m;
		for (i = 0; i <= m; i++)
			coin[i] = 0;
		for (i = 1; i <= n; i++)
		{
			coin[arr[i]]++;
			for (j = arr[i] + 1; j <= m; j++)
				coin[j] += coin[j - arr[i]];
		}
		cout << coin[m] << endl;
	}
	return 0;
}