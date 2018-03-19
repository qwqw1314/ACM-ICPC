#include<iostream>

using namespace std;

long long int a, b;

int main()
{
	int i, sum = 0;
	cin >> a >> b;
	if (b < a)
		sum = (a - b + 1)*(a + b) / 2;
	else
		sum = (b - a + 1)*(a + b) / 2;
	cout << sum;
	return 0;
}