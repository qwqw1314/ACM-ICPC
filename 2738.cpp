#include<iostream>

using namespace std;

int a[101][101], b[101][101];

int main()
{
	int n, m, i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> b[i][j];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cout << a[i][j] + b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}