#include<iostream>

using namespace std;

int a[30][30], sum[30][30], lotto[30], lotto2[30];
int minx = 0x7fffffff;
int n;

int absx(int x)
{
	if (x < 0)
		return -x;
	return x;
}

void back(int x)
{
	int i, j;
	bool flag = false;
	if (x - 1 == n / 2)
	{
		int check[30], cnt = 1;
		for (i = 1; i <= n; i++)
			check[i] = 0;
		for (i = 1; i <= n / 2; i++)
			check[lotto[i]] = 1;
		for (i = 1; i <= n; i++)
			if (check[i] != 1)
				lotto2[cnt++] = i;
		int add1 = 0, add2 = 0;
		for (i = 1; i <= n / 2; i++)
			for (j = 1; j <= n / 2; j++)
			{
				if (i == j)
					continue;
				add1 += a[lotto[i]][lotto[j]];
				add2 += a[lotto2[i]][lotto2[j]];
			}
		if (absx(add1 - add2) < minx)
			minx = absx(add1 - add2);
		return;
	}
	for (i = 1; i <= n; i++)
	{
		bool flag = false;
		for (j = 1; j < x; j++)
		{
			if (i <= lotto[j])
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			lotto[x] = i;
			back(x + 1);
		}
	}
}

int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> a[i][j];
	for (i = 1; i <= n; i++)
	back(1);
	cout << minx;
	return 0;
}