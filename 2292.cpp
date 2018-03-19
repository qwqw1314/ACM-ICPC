#include<iostream>

using namespace std;

int main()
{
	int between = 2, term  = 6;
	int n;
	cin >> n;
	if (n == 1) cout << n;
	else
	{
		for (int i = 2; ; i++)
		{
			if (n >= between && n < between + term)
			{
				cout << i;
				break;
			}
			else
			{
				between += term;
				term += 6;
			}
		}
	}
	return 0;
}