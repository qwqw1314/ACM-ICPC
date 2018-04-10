#include<iostream>
#include<algorithm>

using namespace std;

int dy[10010], n, m;
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
	dy[0] = 1;
	int sum = 0;
	for (i = 1; i <= n; i++)
	{
		
	}
	return 0;
}