#include<iostream>

using namespace std;

int main()
{
	long long int a, b, c, x, y, t;
	cin >> x >> y;
	a = x;
	b = y;
	while (a != 0)
	{
		if (a < b)
		{
			t = a;
			a = b;
			b = t;
		}
		a = a - b;
	}
	c = x / b * y;
	cout << c;
	return 0;
}