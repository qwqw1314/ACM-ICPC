#include<iostream>

using namespace std;

int a[10010];

int main()
{
	int n, m, i;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
	{
		if (a[i] < m)
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}