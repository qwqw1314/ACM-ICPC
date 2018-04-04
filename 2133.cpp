#include<iostream>

using namespace std;

int dy[35];

int main()
{
	int n;
	int i, j;
	dy[0] = 1;
	dy[2] = 3;
	cin >> n;
	for (i = 4; i <= n; i += 2)
	{
		dy[i] = dy[i - 2] * 3;
		for (j = 4; j <= i; j += 2)
			dy[i] += (dy[i - j] * 2);
	}
	cout << dy[n];
	return 0;
}