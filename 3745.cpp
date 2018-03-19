#include<iostream>

using namespace std;

int a[100010], dy[100010];

int main()
{
	int n, i;
	while (!cin.eof())
	{
		int max = 0;
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			cin >> a[i];
			dy[i] = 1;
		}
		for (i = 2; i <= n; i++)
		{
			if (a[i] > a[i - 1])
				dy[i] = dy[i - 1] + 1;
			if (dy[i] > max)
				max = dy[i];
		}
		cout << max << endl;
	}
	return 0;
}