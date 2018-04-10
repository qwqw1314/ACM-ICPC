#include<iostream>
#include<string.h>

using namespace std;

int check[2510][2510], dy[2510];
char arr[2510];

int main()
{
	int n, i, j;
	cin >> arr + 1;
	n = strlen(arr + 1);
	for (i = 1; i < n; i++)
	{
		check[i][i] = 1;
		if (arr[i] == arr[i + 1])
			check[i][i + 1] = 1;
	}
	check[n][n] = 1;
	for (j = 1; j < n; j++)
	{
		for (i = 1; i <= n - j; i++)
		{
			int k = i + j;
			if (check[i + 1][k - 1] == 1 && arr[i] == arr[k])
				check[i][k] = 1;
		}
	}
	for (i = 1; i <= n; i++)
	{
		dy[i] = 0x7fffffff;
		for (j = 1; j <= i; j++)
		{
			if (check[j][i] == 1)
			{
				if (dy[i] == 0x7fffffff || dy[i] > dy[j - 1] + 1)
					dy[i] = dy[j - 1] + 1;
			}
		}
	}
	cout << dy[n];
	return 0;
}
/*
BBCDDECAECBDABADDCEBACCCBDCAABDBADD
ABACABA
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

using namespace std;

char a[2510];
int dy[2510][2510], dy2[2510][2510], check[2510];
int n, m;

int absx(int x)
{
	if (x < 0)
		return -x;
	return x;
}

int main()
{
	int i, j;
	scanf("%s", a + 1);
	a[0] = '1';
	n = strlen(a) - 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i == j)
			{
				dy[i][j] = 1;
				continue;
			}
			if (absx(i - j) <= 2)
			{
				if (a[i] == a[j])
					dy[j][i] = 1;
				continue;
			}
			else
			{
				if (a[i] == a[j] && dy[j + 1][i - 1] == 1)
					dy[j][i] = 1;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%d ", dy[i][j]);
		printf("\n");
	}
	return 0;
}*/