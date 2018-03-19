#include<iostream>

using namespace std;

int main()
{
	int n, i;
	int a = 1, b = 2, c = 3;
	cin >> n;
	if (n == 1)
		cout << 1;
	else if (n == 2)
		cout << 2;
	else
	{
		for (i = 3; i <= n; i++)
		{
			c = (a + b) % 10007;
			a = b;
			b = c;
		}
		cout << b;
	}
	return 0;
}