#include<iostream>

using namespace std;

int a[1002];

int main()
{
	int n, i, t1, t2;
	int sum = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> t1 >> t2;
		a[t2] = t1;
	}
	for (i = 1; i <= 1000; i++)
	{
		if (a[i] != 0)
		{
			sum += i * a[i];
		}
	}
	cout << sum;
	return 0;
}