#include<iostream>

using namespace std;

long long int a[110] = { 0, 1,1,1,2,2,3,4,5,7,9 };

int main()
{
	int t, T, n, i;
	for (i = 11; i <= 100; i++)
	{
		a[i] = a[i - 5] + a[i - 1];
	}
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> n;
		cout << a[n] << endl;
	}
	return 0;
}