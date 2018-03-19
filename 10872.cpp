#include<iostream>

using namespace std;

int n;
long long int a = 1;

int main()
{
	int i;
	cin >> n;
	for (i = 2; i <= n; i++)
	{
		a *= i;
	}
	cout << a;
	return 0;
}