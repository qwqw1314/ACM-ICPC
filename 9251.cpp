#include<iostream>
#include<cstring>

using namespace std;

char a[1010], b[1010];
int dy[1010][1010];

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
				dy[i][j] = dy[i][j - 1];
			else
				dy[i][j] = dy[i - 1][j];
			if (a[i] == b[j] && dy[i][j] < dy[i - 1][j - 1] + 1)
				dy[i][j] = dy[i - 1][j - 1] + 1;
		}
	}
	cout << dy[lena][lenb];
	return 0;
}