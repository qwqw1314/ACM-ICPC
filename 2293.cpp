#include<iostream>

using namespace std;

int a[110], dy[10010];

int main()
{
	int n, k, i, j;
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	dy[0] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= k; j++)
		{
			if (j >= a[i] && dy[j - a[i]] > 0)
			{
				dy[j] += dy[j - a[i]];
			}
		}
	}
	cout << dy[k];
	return 0;
}