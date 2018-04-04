#include<iostream>

using namespace std;

#define MAX 100000000

int n, k;
int dy[10010], coin[110];

int minx(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int main()
{
	int i, j;
	cin >> n >> k;
	for (i = 1; i <= n; i++)
		cin >> coin[i];
	dy[0] = 0;
	fill(dy + 1, dy + k + 1, MAX);
	for (i = 1; i <= k; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if(i - coin[j] >= 0)
				dy[i] = minx(dy[i - coin[j]] + 1, dy[i]);
		}
	}
	if (dy[k] == MAX)
		cout << -1;
	else
		cout << dy[k];
	return 0;
}