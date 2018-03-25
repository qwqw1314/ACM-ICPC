#include<iostream>

using namespace std;

bool prime[300000];

int main()
{
	int i, j;
	prime[1] = true;
	for (i = 2; i <= 123456 * 2; i++)
	{
		for (j = i + i; j <= 123456 * 2; j+=i)
		{
			prime[j] = true;
		}
	}
	while (1)
	{
		int n, cnt = 0;
		cin >> n;
		if (n == 0) break;
		for (i = n + 1; i <= n * 2; i++)
		{
			if (prime[i] == false)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}