#include<iostream>

using namespace std;

int main()
{
	int a, b, x, y;
	cin >> a >> b;
	x = a;
	y = b;
	while (b != 0)
	{
		if (b > a)
		{
			int t = a;
			a = b;
			b = t;
		}
		a = a - b;
	}
	cout << a << endl;
	cout << x * y / a;
	return 0;
}