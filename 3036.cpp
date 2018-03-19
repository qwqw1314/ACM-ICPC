#include<iostream>

using namespace std;

int a[110];

int gcd(int x, int y)
{
	int a = x, b = y;
	while (b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 1; i < n; i++)
	{
		int g = gcd(a[0], a[i]);
		cout << a[0] / g << "/" << a[i] / g << endl;
	}
	return 0;
}