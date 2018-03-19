#include<iostream>

using namespace std;

long long int a[100];

int main()
{
	int i, n;
	a[1] = 1;
	a[2] = 1;
	cin >> n;
	for (i = 3; i <= n; i++)
		a[i] = a[i - 1] + a[i - 2];
	cout << a[n];
	return 0;
}