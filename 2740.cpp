#include<iostream>

using namespace std;

int a[110][110], b[110][110], c[110][110];

int main()
{
	int n, m, l;
	int i, j, k;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];
	cin >> m >> l;
	for (i = 0; i < m; i++)
		for (j = 0; j < l; j++)
			cin >> b[i][j];
	for (i = 0; i < n; i++)
		for (k = 0; k < m; k++)
			for (j = 0; j < l; j++)
				c[i][j] += a[i][k] * b[k][j];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < l; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	return 0;
}