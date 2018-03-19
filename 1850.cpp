#include<iostream>

using namespace std;

int main()
{
	long long int a, b;
	cin >> a >> b;
	while (b != 0)
	{
		if (b > a)
		{
			long long int t = a;
			a = b;
			b = t;
		}
		a = a - b;
	}
	for (int i = 0; i < a; i++)
	{
		cout << "1";
	}
	return 0;
}