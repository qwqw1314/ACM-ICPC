#include<iostream>

using namespace std;

int cnt[50][2];

int main()
{
	int t, i;
	cin >> t;
	cnt[0][0] = 1, cnt[0][1] = 0;
	cnt[1][0] = 0, cnt[1][1] = 1;
	for (i = 2; i <= 40; i++)
	{
		cnt[i][0] = cnt[i - 1][0] + cnt[i - 2][0];
		cnt[i][1] = cnt[i - 1][1] + cnt[i - 2][1];
	}
	for (i = 0; i < t; i++)
	{
		int temp;
		cin >> temp;
		cout << cnt[temp][0] << " " << cnt[temp][1] << endl;
	}
	return 0;
}