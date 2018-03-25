#include<iostream>

using namespace std;

int n, m;
double up, down, res;

int main()
{
	int i;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		if (n - m < m)
			m = n - m;
		res = 1;
		up = n;
		for (i = 1; i <= m; i++)
		{
			res *= (up - i + 1);
			res /= i;
		}
		cout << (int)res << endl;
	}
	return 0;
}