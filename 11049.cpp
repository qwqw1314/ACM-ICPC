// Àç±ÍÇü DP
#include<iostream>

using namespace std;

int arr[510][2], n;
long long int dy[510][510];

long long int dynamic(int from, int to)
{
	int i;
	if (dy[from][to] > 0)
		return dy[from][to];
	for (i = from; i < to; i++)
	{
		long long int t = dynamic(from, i) + dynamic(i + 1, to) + arr[from][0] * arr[i][1] * arr[to][1];
		if (dy[from][to] == 0 || dy[from][to] > t)
			dy[from][to] = t;
	}
	return dy[from][to];
}

int main()
{
	int i;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];
	cout << dynamic(1, n) << endl;
	return 0;
}

/* for¹® DP
#include<iostream>

using namespace std;

long long int dy[510][510], n;
int arr[510][2];

int minx(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int main()
{
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];
	for (i = 0; i < n; i++)
	{
		for (j = 1; j + i <= n; j++)
		{
			if (j == j + i)
			{
				dy[j][j + i] = 0;
				continue;
			}
			dy[j][j + i] = 0x7ffffff;
			for (k = j; k < j + i; k++)
				dy[j][j + i] = minx(dy[j][j + i], dy[j][k] + dy[k + 1][j] + arr[j][0] * arr[k][1] * arr[j + i][1]);
		}
	}
	cout << dy[1][n];
	return 0;
}
*/