// 스택 공부 더하셈
// 긁어온 코드
#include<iostream>

using namespace std;

long long int sum = 0;
bool prime[10010];

int main()
{
	int n, m, i, j;
	prime[1] = true;
	for (i = 2; i <= 10000; i++)
	{
		for (j = i + i; j <= 10000; j+=i)
		{
			prime[j] = true;
		}
	}
	cin >> n >> m;
	int temp;
	bool flag = false;
	for (i = n; i <= m; i++)
	{
		if (prime[i] == false)
		{
			sum += i;
			if (flag == false)
			{
				flag = true;
				temp = i;
			}
		}
	}
	if (flag == false)
		cout << -1;
	else
		cout << sum << endl << temp;
	return 0;
}