#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int dy[20][11], a[100], sum[100], make[100], cnt;
int newcnt, to, n;

void back(int x)
{
	int i, j;
	if (x == to)
	{
		newcnt++;
		if (newcnt == n)
		{
			for (i = 0; i < to; i++)
				cout << make[i];
		}
	}
	else
	{
		for (i = 0; i < 10; i++)
		{
			bool flag = false;
			for (j = 0; j < x; j++)
			{
				if (make[j] <= i)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				make[x] = i;
				back(x + 1);
			}
		}
	}
}

int main()
{
	int i, j, k, max = 0, temp;
	cin >> n;
	temp = n;
	for (i = 0; i <= 9; i++)
		dy[1][i] = 1;
	for (i = 2;i <= 10; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			int sum = 0;
			for (k = 0; k < j; k++)
				sum += dy[i - 1][k];
			dy[i][j] = sum;
		}
	}
	for (i = 1; i <= 10; i++)
		for (j = 0; j <= 9; j++)
			sum[i] += dy[i][j];
	n++;
	for (i = 1;; i++)
	{
		if (n > sum[i])
			n -= sum[i];
		else
			break;
	}
	if (temp >= 1023)
		cout << -1;
	else
	{
		to = i;
		back(0);
	}
	return 0;
}