#include<iostream>

using namespace std;

int a[1500010];
long long int n;

int main()
{
	int i, n;
	cin >> n;
	a[1] = 1;
	a[2] = 1;
	for (i = 3; i <= 1500000; i++)
	{
		a[i] = (a[i - 2] + a[i - 1]) % 1000000;
	}
	int index = n % 1500000;
	cout << a[index];
	return 0;
}