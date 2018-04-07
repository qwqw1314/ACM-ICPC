#include<iostream>
#include<string.h>

using namespace std;

char magic[30], angel[110], devil[110];
int dy[2][110] = { {1},{1} } , n, m;

int main()
{
	int i, j;
	cin >> magic >> angel >> devil;
	n = strlen(magic);
	m = strlen(angel);
	for (i = 0; i < m; i++)
	{
		for (j = n - 1; j >= 0; j--)
		{
			if (magic[j] == angel[i])
				dy[1][j + 1] += dy[0][j];
			if (magic[j] == devil[i])
				dy[0][j + 1] += dy[1][j];
		}
	}
	cout << dy[0][n] + dy[1][n];
	return 0;
}

/*
#include<iostream>
#include<string.h>

using namespace std;

char magic[30], angel[110], devil[110];
int dy[2][110];

int main()
{
	int n, m, i, j, k;
	cin >> magic >> angel >> devil;
	n = strlen(magic);
	m = strlen(angel);
	for (i = 0; i < m; i++)
	{
		if (magic[0] == angel[i])
			dy[0][i] = 1;
		if (magic[0] == devil[i])
			dy[1][i] = 1;
	}
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (magic[i] == angel[j])
			{
				for (k = 0; k < j; k++)
					if (magic[i - 1] == devil[k])
						dy[0][j] += dy[1][k];
			}
			if (magic[i] == devil[j])
			{
				for (k = 0; k < j; k++)
					if (magic[i - 1] == angel[k])
						dy[1][j] += dy[0][k];
			}
		}
	}
	int ans = 0;
	for (i = 0; i < m; i++)
	{
		if (magic[n - 1] == angel[i])
			ans += dy[0][i];
		if (magic[n - 1] == devil[i])
			ans += dy[1][i];
	}
	cout << ans;
	return 0;
}
*/