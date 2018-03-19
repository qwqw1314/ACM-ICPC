#include<iostream>
#include<math.h>

using namespace std;

int n, r, c;
int bix, biy;

int absx(int x)
{
	if (x < 0)
		return -x;
	return x;
}

int isthere(int lx, int ly, int rx, int ry)
{
	int halfx = (lx + rx) / 2, halfy = (ly + ry) / 2;
	if (rx - lx == 2 && ry - ly == 2)
	{
		if (absx(lx - r) == 0)
		{
			return absx(ly - c);
		}
		else
		{
			return 2 + absx(ly - c);
		}
	}
	if (r < halfx)
	{
		if (c < halfy)
		{
			return isthere(lx, ly, halfx, halfy);
		}
		else
		{
			return absx(halfx - lx) * absx(halfy - ly) + isthere(lx, halfy, halfx, ry);
		}
	}
	else
	{
		if (c < halfy)
		{
			return 2 * absx(halfx - lx) * absx(halfy - ly) + isthere(halfx, ly, rx, halfy);
		}
		else
		{
			return 3 * absx(halfx - lx) * absx(halfy - ly) + isthere(halfx, halfy, rx, ry);
		}
	}
}

int main()
{
	cin >> n >> r >> c;
	bix = biy = pow(2, n);
	int sum = isthere(0, 0, bix, biy);
	cout << sum;
	return 0;
}