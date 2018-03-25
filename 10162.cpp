#include<iostream>

using namespace std;

int a, b, c;

int main()
{
	int n;
	cin >> n;
	a = n / 300;
	n = n % 300;
	b = n / 60;
	n = n % 60;
	c = n / 10;
	n = n % 10;
	if (n == 0)
		cout << a << " " << b << " " << c;
	else
		cout << -1;
	return 0;
}