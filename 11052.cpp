#include<iostream>

using namespace std;

int main()
{
	int n, i;
	int a[1010], dy[1010];
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dy[1] = a[1] * n;
	for (i = 2; i <= n; i++)
	{
		dy[i] = n / i * a[i];
		if (n % i != 0)
		{

		}
	}
	return 0;
}