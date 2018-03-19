#include<iostream>

using namespace std;

int dy[1000010];

int minx(int x, int y)
{
	if (x > y) return y;
	return x;
}

int main()
{
	int n, i;
	cin >> n;
	for (i = 2; i <= n; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
			dy[i] = minx(minx(dy[i / 2], dy[i / 3]), dy[i - 1]) + 1;
		else if (i % 2 == 0)
			dy[i] = minx(dy[i / 2], dy[i - 1]) + 1;
		else if (i % 3 == 0)
			dy[i] = minx(dy[i / 3], dy[i - 1]) + 1;
		else
			dy[i] = dy[i - 1] + 1;
	}
	cout << dy[n];
	return 0;
}