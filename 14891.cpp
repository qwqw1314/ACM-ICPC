#include<iostream>

using namespace std;

char a[5][10], b[5][10];
int n, how, c[5], sum, score[5] = { 0, 1,2,4,8 };

void turnleft(int wheel)
{
	int i;
	//10101111 -> 01011111
	char t = a[wheel][1];
	for (i = 1; i <= 8; i++)
	{
		a[wheel][i - 1] = a[wheel][i];
	}
	a[wheel][8] = a[wheel][0];
	a[wheel][0] = 0;
}

void turnright(int wheel)
{
	int i;
	//10101111 -> 11010111
	for (i = 8; i >= 1; i--)
	{
		a[wheel][i + 1] = a[wheel][i];
	}
	a[wheel][1] = a[wheel][9];
	a[wheel][9] = 0;
}

int main()
{
	int i, j;
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			cin >> a[i][j];
		}
	}
	cin >> n;
	//3, 7
	for (i = 0; i < n; i++)
	{
		int whe, to;
		cin >> whe >> to;
		b[1][3] = a[1][3];
		b[1][7] = a[1][7];
		b[2][3] = a[2][3];
		b[2][7] = a[2][7];
		b[3][3] = a[3][3];
		b[3][7] = a[3][7];
		b[4][3] = a[4][3];
		b[4][7] = a[4][7];
		c[whe] = to;
		if (whe == 1)
		{
			if (b[1][3] == b[2][7])
				c[2] = 0;
			else
				c[2] = -c[1];
			if (b[2][3] == b[3][7])
				c[3] = 0;
			else
				c[3] = -c[2];
			if (b[3][3] == b[4][7])
				c[4] = 0;
			else
				c[4] = -c[3];
		}
		else if(whe == 2)
		{
			if (b[2][7] == b[1][3])
				c[1] = 0;
			else
				c[1] = -c[2];
			if (b[2][3] == b[3][7])
				c[3] = 0;
			else
				c[3] = -c[2];
			if (b[3][3] == b[4][7])
				c[4] = 0;
			else
				c[4] = -c[3];
		}
		else if (whe == 3)
		{
			if (b[3][3] == b[4][7])
				c[4] = 0;
			else
				c[4] = -c[3];
			if (b[3][7] == b[2][3])
				c[2] = 0;
			else
				c[2] = -c[3];
			if (b[2][7] == b[1][3])
				c[1] = 0;
			else
				c[1] = -c[2];
		}
		else if (whe == 4)
		{
			if (b[4][7] == b[3][3])
				c[3] = 0;
			else
				c[3] = -c[4];
			if (b[2][3] == b[3][7])
				c[2] = 0;
			else
				c[2] = -c[3];
			if (b[1][3] == b[2][7])
				c[1] = 0;
			else
				c[1] = -c[2];
		}
		for (j = 1; j <= 4; j++)
		{
			if (c[j] == 1)
				turnright(j);
			else if (c[j] == -1)
				turnleft(j);
		}
	}
	for (i = 1; i <= 4; i++)
	{
		if (a[i][1] == '1')
			sum += score[i];
	}
	cout << sum;
	return 0;
}
/*
10101111
01111101
11001110
00000010
1
1 -1

10101111
01111101
11001110
00000010
2
3 -1
1 1

*/