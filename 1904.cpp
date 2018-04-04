#include<iostream>

using namespace std;

int dy[1000010];

int main()
{
	int n, i;
	cin >> n;
	dy[0] = dy[1] = 1;
	for (i = 2; i <= n; i++)
		dy[i] = (dy[i - 1] + dy[i - 2]) % 15746;
	cout << dy[n] % 15746;
	return 0;
}