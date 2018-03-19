#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int a[20][11] ={{10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				{9, 1, 2, 3, 4, 5, 6, 7, 8, 9},
				{8, 1, 3, 6, 10 ,15 ,21 ,28 ,35},
				{7, 1, 4, 10, 20, 25, 46 ,74},
				{6, 1 ,5 ,15, 35 ,60, 106},
				{5, 1, 6, 21, 56, 116},
				{4, 1, 7, 28, 84},
				{3, 1, 8, 36},
				{2, 1, 9},
				{1, 1}};
long long int b[20][11] = { {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
				{10, 20, 30, 40, 50, 60, 70, 80, 90},
				{210, 310, 410, 510, 610, 710, 810, 910},
				{3210, 4210, 5210, 6210, 7210, 8210, 9210},
				{43210, 53210, 63210, 73210, 83210, 93210},
				{543210, 643210, 743210, 843210, 943210},
				{6543210, 7543210, 8543210, 9543210},
				{76543210, 86543210, 96543210},
				{876543210, 976543210},
				{9876543210} };

void nextchar(char* x)
{
	int len = strlen(x);
	for (int i = len - 1; i > 0; i--)
	{
		int now = x[i] - '0', before = x[i - 1] - '0';
		if (now + 1 < before)
		{
			x[i]++;
		}
		else
			continue;
	}
}

int main()
{
	int n, i, j, max = 0;
	int sum = 0;
	char c[20];
	bool flag = false;
	cin >> n;
	for (i = 0; i < 10; i++)
	{
		for (j = 1; j <= a[i][0]; j++)
		{
			max += a[i][j];
		}
	}
	if (n >= max)
		cout << -1;
	else if (n >= 0 && n < 10)
		cout << n;
	else
	{
		for (i = 0; i < 10; i++)
		{
			for (j = 1; j <= a[i][0]; j++)
			{
				sum += a[i][j];
				if (sum == n)
				{
					if (j == a[i][0])
					{
						j = 0;
						i++;
					}
					flag = true;
					break;
				}
				if (sum + a[i][j + 1] > n && (j + 1) <= a[i][0])
				{
					flag = true;
					break;
				}
				else if ((j + 1) > 10 - i)
				{
					if (sum + a[i + 1][j] > n && (i + 1) <= 10)
					{
						flag = true;
						break;
					}
				}
			}
			if (flag)
				break;
		}
		if (sum == 951)
		{
			cout << b[i][j];
			return 0;
		}
		long long int set = b[i][j];
		int much = n - sum;
		int count = 0;
		char d[20];
		while (set != 0)
		{
			d[count++] = (set % 10) + '0';
			set /= 10;
		}
		for (i = 0; i < count; i++)
			c[i] = d[count - i - 1];
		c[count] = '\0';
		for (i = 0; i < much; i++)
		{
			nextchar(c);
		}
		cout << c;
	}
	return 0;
}