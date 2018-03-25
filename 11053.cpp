#include<iostream>

using namespace std;

int n, a[1010], dy[1010], maxx;

int larger(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int main()
{
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	dy[0] = 1;
/*	이따위로 짜면 반례 있음 1 2 4 5 3  << 3 나옴
	for (i = 0; i < n - 1; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (a[j] > a[i] && dy[j] < dy[i] + 1)
			{
				dy[j] = dy[i] + 1;
			}
		}
	}*/
	for (i = 1; i < n; i++)
	{
		int maxx = 0;
		for (j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				if (maxx < dy[j])
					maxx = dy[j];
			}
		}
		dy[i] = maxx + 1;
	}
	for (i = 0; i < n; i++)
		maxx = larger(maxx, dy[i]);
	cout << maxx;
	return 0;
}