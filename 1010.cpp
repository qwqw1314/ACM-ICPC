#include<iostream>

using namespace std;

int a[40][40];

int main()
{
	int i, j, t, T, c, b;
	for (i = 0; i <= 30; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
		for (j = 1; j < i; j++)
		{
			a[i][j] = a[i-1][j] + a[i - 1][j - 1];
		}
	}
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> b >> c;
		cout << a[c][b] << endl;
	}
	return 0;
}