#include<iostream>
#include<string.h>

using namespace std;

int n, m;
char angel[110], devil[110];
char magic[30];
long long int dy[2][110];

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int i, j, k;
	cin >> magic >> angel >> devil;
	n = strlen(magic);
	m = strlen(angel);
	for (i = 0; i < m; i++)
	{
		if (angel[i] == magic[0])
			dy[0][i] = 1;
		if (devil[i] == magic[0])
			dy[1][i] = 1;
	}
	for (k = 1; k < n; k++)
	{
		for (i = 0; i < m; i++)
		{
			if (angel[i] == magic[k])
			{
				int sum = 0;
				for (j = 0; j < i; j++)
				{
					if (devil[j] == magic[k - 1])
						sum += dy[1][j];
				}
				dy[0][i] += sum;
			}
			if (devil[i] == magic[k])
			{
				int sum = 0;
				for (j = 0; j < i; j++)
				{
					if (angel[j] == magic[k - 1])
						sum += dy[0][j];
				}
				dy[1][i] += sum;
			}
		}
	}
	int sum = 0;
	for (i = 0; i < m; i++)
	{
		if (angel[i] == magic[n - 1])
			sum += dy[0][i];
		if (devil[i] == magic[n - 1])
			sum += dy[1][i];
	}
	cout << sum;
	return 0;
}