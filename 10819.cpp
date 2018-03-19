#include<iostream>
#include<math.h>

using namespace std;

int a[10];
int b[10];
int n, maxx;

void back(int x)
{
	int i, j;
	if (x == n)
	{
		int sum = 0;
		for (i = 0; i < n - 1; i++)
		{
			sum += abs(a[b[i]] - a[b[i + 1]]);
		}
		if (maxx < sum)
			maxx = sum;
	}
	else if (x == 0)
	{
		for (i = 0; i < n; i++)
		{
			b[x] = i;
			back(x + 1);
		}
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			bool flag = false;
			for (j = 0; j < x; j++)
			{
				if (i == b[j])
				{
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				b[x] = i;
				back(x + 1);
			}
		}
	}
}

int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	back(0);
	cout << maxx;
	return 0;
}