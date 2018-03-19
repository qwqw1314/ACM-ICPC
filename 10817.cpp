#include<iostream>

using namespace std;

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

int minx(int x, int y)
{
	if (x < y)
		return x;
	return y;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	sum = sum - maxx(a, maxx(b, c)) - minx(a, minx(b, c));
	cout << sum;
	return 0;
}