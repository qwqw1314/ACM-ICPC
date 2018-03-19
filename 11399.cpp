#include<iostream>

using namespace std;

int main()
{
	int n, i, j;
	int a[1001], sum = 0, sum2 = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		sum += a[i];
		sum2 += sum;
	}
	cout << sum2;
	return 0;
}