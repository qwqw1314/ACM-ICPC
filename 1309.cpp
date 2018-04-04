#include<iostream>

using namespace std;

int dy[100010];

int main()
{
	int i, n;
	cin >> n;
	dy[0] = 1;
	dy[1] = 3;
	for (i = 2; i <= n; i++)
		dy[i] = (dy[i - 1] * 2 + dy[i - 2]) % 9901;
	cout << dy[n] % 9901;
	return 0;
}