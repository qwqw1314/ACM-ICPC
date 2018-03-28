#include<iostream>
#include<queue>

using namespace std;

int n, mx[4] = { -1, 1, 0, 0 }, my[4] = { 0 ,0 ,-1, 1 };
char a[110][110];
int chkRGB[110][110], chkRB[110][110];
int cnt1, cnt2;

void RGB(int x, int y)
{
	int i;
	char arr[5] = { 0, 'R', 'G','B' };
	queue<pair<int, int> > q;
	chkRGB[x][y] = cnt1;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				if (a[nx][ny] == arr[cnt1] && chkRGB[nx][ny] == 0)
				{
					chkRGB[nx][ny] = cnt1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void RB(int x, int y)
{
	int i;
	char arr[5] = { 0, 'R','B' };
	queue<pair<int, int> > q;
	chkRB[x][y] = cnt2;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				if (a[nx][ny] == arr[cnt2] && chkRB[nx][ny] == 0)
				{
					chkRB[nx][ny] = cnt2;
					q.push(make_pair(nx, ny));
				}
			}
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
	int cntRGB = 0, cntRB = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (chkRGB[i][j] == 0 && a[i][j] == 'R')
			{
				cnt1 = 1;
				cntRGB++;
				RGB(i, j);
			}
			else if (chkRGB[i][j] == 0 && a[i][j] == 'G')
			{
				cnt1 = 2;
				cntRGB++;
				RGB(i, j);
			}
			else if (chkRGB[i][j] == 0 && a[i][j] == 'B')
			{
				cnt1 = 3;
				cntRGB++;
				RGB(i, j);
			}
		}
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (a[i][j] == 'G')
				a[i][j] = 'R';
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (chkRB[i][j] == 0 && a[i][j] == 'R')
			{
				cnt2 = 1;
				cntRB++;
				RB(i, j);
			}
			else if (chkRB[i][j] == 0 && a[i][j] == 'B')
			{
				cnt2 = 2;
				cntRB++;
				RB(i, j);
			}
		}
	}
	cout << cntRGB << " " << cntRB;
	return 0;
}