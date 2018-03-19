#include<iostream>

using namespace std;

int main()
{
	int a = 1, b = 3, c = 5, n;
	cin >> n;
	if (n == 1)
		cout << 1;
	else
	{
		for (int i = 3; i <= n; i++)
		{
			c = (a * 2 + b) % 10007;
			a = b;
			b = c;
		}
		cout << b;
	}
	return 0;
}