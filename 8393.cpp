#include<iostream>

using namespace std;

int sum;

int main()
{
	int i, n;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		sum += i;
	}
	cout << sum;
	return 0;
}