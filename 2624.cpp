#include<iostream>
#include<algorithm>

using namespace std;

int dy[10010][110], n, m;
pair<int, int> arr[1010];

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.first > b.first)
		return false;
	return true;
}

int main()
{
	int i, j, k;
	cin >> m >> n;
	for (i = 1; i <= n; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		arr[i] = make_pair(t1, t2);
	}
	sort(arr + 1, arr + n + 1, comp);
	for (i = 1; i <= n; i++)
	{
		dy[0][i - 1] = 1;
		for (j = 1; j <= arr[i].second; j++)
		{
			for (k = arr[i].first * j; k <= m; k++)
			{
				dy[k][i] += dy[k - arr[i].first * j][i - 1];
			}
		}
		for (j = 1; j <= m; j++)
			dy[j][i] += dy[j][i - 1];
	}
	cout << dy[m][n];
	return 0;
}