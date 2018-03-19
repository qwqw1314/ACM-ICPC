/*
#include<iostream>
#include<string.h>

using namespace std;

char a[5010];
int dy[5010];

int main()
{
	int i;
	cin >> a;
	int len = strlen(a);
	dy[0] = 1;
	for (i = 0; i < len; i++)
	{
		if (a[i] >= '1' && a[i] <= '9')
			dy[i + 1] = (dy[i + 1] + dy[i]) % 1000000;
		if (i == 0 || a[i - 1] == '0') continue;
		if (((a[i - 1] == '1' && (a[i] >= '0' && a[i] <= '9')) || (a[i - 1] == '2' && (a[i] >= '1' && a[i] <= '6'))))
			dy[i + 1] = (dy[i + 1] + dy[i - 1]) % 1000000;
	}
	cout << dy[i];
	return 0;
}
*/

#include <cstdio>
#include <cstring>

const int MOD = 1000000;

long long dp[5001] = { 1 }, i;

char st[5001];

int main() {

	scanf("%s", st);

	int len = strlen(st);

	for (i = 0; i < len; ++i) {
		int idx = st[i] - '0';

		if (1 <= idx && idx <= 9)
			dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;

		if (i == 0) continue;

		if (st[i - 1] == '0') continue;

		idx = (st[i - 1] - '0') * 10 + (st[i] - '0');

		if (10 <= idx && idx <= 26)
			dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
	}
	printf("%lld\n", dp[i]);
	return 0;
}