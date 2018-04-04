#include<iostream>
#include<algorithm>

using namespace std;

int fibo[45], vip[45];
int n, m;

int main()
{
	int i;
	cin >> n >> m;
	fibo[0] = fibo[1] = 1;
	for (i = 2; i <= 40; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	for (i = 1; i <= m; i++)
		cin >> vip[i];
	if (m > 0)
	{
		sort(vip + 1, vip + m);
		int mul = fibo[vip[1] - 1];
		for (i = 2; i <= m; i++)
			mul *= fibo[vip[i] - vip[i - 1] - 1];
		mul *= fibo[n - vip[m]];
		cout << mul;
	}
	else
		cout << fibo[n];
	return 0;
}