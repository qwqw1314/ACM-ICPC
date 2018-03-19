#include<iostream>

using namespace std;

int a[20];
int b, c, d, e;
int n, maxx = -0x7fffffff, minx = 0x7fffffff;

void back(int x, int res, int add, int sub, int mul, int div)
{
	if (x == n)
	{
		if (res > maxx)
			maxx = res;
		if (res < minx)
			minx = res;
	}
	if (add + 1 <= b)
		back(x + 1, res + a[x], add + 1, sub, mul, div);
	if (sub + 1 <= c)
		back(x + 1, res - a[x], add, sub + 1, mul, div);
	if (mul + 1 <= d)
		back(x + 1, res * a[x], add, sub, mul + 1, div);
	if (div + 1 <= e)
		back(x + 1, res / a[x], add, sub, mul, div + 1);
}

int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c >> d >> e;
	back(1, a[0], 0, 0, 0, 0);
	cout << maxx << endl << minx;
	return 0;
}