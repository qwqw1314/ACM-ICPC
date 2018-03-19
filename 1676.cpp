#include<iostream>

using namespace std;

int two, five;
int minx(int x, int y)
{
	return ((x > y) ? y : x);
}

int main()
{
	int n, i;
	cin >> n;
	for (i = 2; i <= n; i++)
	{
		int x = i;
		while (x % 2 == 0)
		{
			two++;
			x /= 2;
		}
		while (x % 5 == 0)
		{
			five++;
			x /= 5;
		}
	}
	cout << minx(two, five);
	return 0;
}