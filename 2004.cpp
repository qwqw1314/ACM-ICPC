#include<iostream>

using namespace std;

long long int a, b;
long long int two, five;

long long int minx(long long int x, long long int y)
{
	if (x > y)
		return y;
	return x;
}

int main()
{
	long long int i;
	cin >> a >> b;
	if (a - b < b)
		b = a - b;
	for (i = 2; i <= a; i *= 2)
		two += (a / i);
	for (i = 2; i <= b; i *= 2)
		two -= (b / i);
	for (i = 2; i <= (a - b); i *= 2)
		two -= ((a - b) / i);

	for (i = 5; i <= a; i *= 5)
		five += (a / i);
	for (i = 5; i <= b; i *= 5)
		five -= (b / i);
	for (i = 5; i <= (a - b); i *= 5)
		five -= ((a - b) / i);

	cout << minx(two, five);
	return 0;
}