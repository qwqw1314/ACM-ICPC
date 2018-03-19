#include<iostream>

using namespace std;

int a[1010], cnt;
bool check[1010];

int main()
{
	int t, T, n, i;
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cnt = 0;
		cin >> n;
		for (i = 1; i <= n; i++)
			cin >> a[i];
		for (i = 1; i <= n; i++)
		{
			int start = i, now = i;
			if (check[i] == true)
				continue;
			check[now] = true;
			while (a[now] != start && check[a[now]] == false)
			{
				now = a[now];
				check[now] = true;
			}
			if (a[now] == start)
				cnt++;
		}
		for (i = 1; i <= n; i++)
		{
			check[i] = false;
			a[i] = 0;
		}
		cout << cnt << endl;
	}
	return 0;
}