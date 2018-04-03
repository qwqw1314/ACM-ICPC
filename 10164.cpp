#include<iostream>

using namespace std;

int arr[20][20], dy[20][20];
int n, m, k, there[2];

int main()
{
	int i, j, cnt = 1;
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (cnt == k)
				there[0] = i, there[1] = j;
			arr[i][j] = cnt++;
		}
	}
	dy[1][1] = 1;
	if (k > 0)
	{
		for (i = 1; i <= there[0]; i++)
			for (j = 1; j <= there[1]; j++)
			{
				if (i == 1 && j == 1)
					continue;
				dy[i][j] = dy[i - 1][j] + dy[i][j - 1];
			}
		int temp = dy[there[0]][there[1]];
		dy[there[0]][there[1]] = 1;
		for (i = there[0]; i <= n; i++)
			for (j = there[1]; j <= m; j++)
			{
				if (i == there[0] && j == there[1])
					continue;
				dy[i][j] = dy[i - 1][j] + dy[i][j - 1];
			}
		cout << temp * dy[n][m];
	}
	else
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				if (i == 1 && j == 1)
					continue;
				dy[i][j] = dy[i - 1][j] + dy[i][j - 1];
			}
		cout << dy[n][m];
	}
	return 0;
}

/*잘못된 점화식
#include<iostream>

using namespace std;

int arr[20][20], dy[20][20];
int n, m, k, there[2];

int main()
{
	int i, j, cnt = 1;
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (cnt == k)
				there[0] = i, there[1] = j;
			arr[i][j] = cnt++;
		}
	}
	dy[1][1] = 1;
	if (k > 0)
	{
		for (i = 1; i <= there[0]; i++)
		{
			for (j = 1; j <= there[1]; j++)
			{
				dy[i + 1][j] += dy[i][j];
				dy[i][j + 1] += dy[i][j];
			}
		}
		for (i = there[0]; i <= n; i++)
		{
			for (j = there[1]; j <= m; j++)
			{
				dy[i + 1][j] = dy[i][j];
				dy[i][j + 1] = dy[i][j];
			}
		}
		cout << dy[there[0]][there[1]] * dy[n][m];
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				dy[i + 1][j] += dy[i][j];
				dy[i][j + 1] += dy[i][j];
			}
		}
		cout << dy[n][m];
	}
	return 0;
}*/