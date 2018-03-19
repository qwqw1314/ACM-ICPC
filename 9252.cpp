#include<iostream>
#include<cstring>

using namespace std;

char a[1010], b[1010],c[1010];
int dy[1010][1010], to[1010][1010], cnt;

int main()
{
	int i, j;
	cin >> &a[1] >> &b[1];
	a[0] = ' ', b[0] = ' ';
	int lena = strlen(a) - 1;
	int lenb = strlen(b) - 1;
	for (i = 1; i <= lena; i++)
	{
		for (j = 1; j <= lenb; j++)
		{
			if (dy[i - 1][j] < dy[i][j - 1])
			{
				dy[i][j] = dy[i][j - 1];
				to[i][j] = 1;
			}
			else
			{
				dy[i][j] = dy[i - 1][j];
				to[i][j] = 2;
			}
			if (a[i] == b[j] && dy[i][j] < dy[i - 1][j - 1] + 1)
			{
				dy[i][j] = dy[i - 1][j - 1] + 1;
				to[i][j] = 3;
			}
		}
	}
	cout << dy[lena][lenb] << endl;
	int x = lena, y = lenb;
	while (x > 0 && y > 0)
	{
		if (to[x][y] == 1) y--;
		else if (to[x][y] == 2) x--;
		else
		{
			c[cnt++] = a[x];
			x--;
			y--;
		}
	}
	for (i = cnt - 1; i >= 0; i--)
		cout << c[i];
	return 0;
}