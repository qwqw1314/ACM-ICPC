#include<iostream>

using namespace std;

int main()
{
	int n, k, i;
	int a[20];
	int cnt = 0;
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = n - 1; i >= 0; i--)
	{
		if (k == 0) break;
		if (k >= a[i])
		{
			cnt += k / a[i];
			k = k % a[i];
		}
	}
	cout << cnt;
	return 0;
}