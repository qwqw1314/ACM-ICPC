#include<iostream>

using namespace std;

int arr[1010][1010], dy_left[1010][1010], dy_right[1010][1010], dy[1010][1010];
int n, m;

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (i = 1; i <= n - 1; i++)
	{
		
	}
	return 0;
}