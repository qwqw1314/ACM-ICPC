#include<iostream>
#include<algorithm>
using namespace std;
int n, cnt;
int step[400], dp[400];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> step[i];
	}
	dp[1] = step[1];
	dp[2] = step[1] + step[2];
	dp[3] = max(step[1] + step[3], step[2] + step[3]);
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 3] + step[i - 1] + step[i], dp[i - 2] + step[i]);
	}
	cout << dp[n] << endl;
	return 0;
}