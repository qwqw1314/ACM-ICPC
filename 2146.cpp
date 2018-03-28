#include<iostream>
#include<queue>

using namespace std;

#define m(x, y) make_pair(x, y)

int n, cnt_fill;
int a[110][110], chk_fill[110][110], mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };
int flood[110][110], minx = 0x7fffffff;
queue<pair<int, int> > q;

void filling(int x, int y)
{
	q.push(m(x, y));
	chk_fill[x][y] = cnt_fill;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				if (chk_fill[nx][ny] == 0 && a[nx][ny] == 1)
				{
					chk_fill[nx][ny] = cnt_fill;
					q.push(m(nx, ny));
				}
			}
		}
	}
}

void flood_fill()
{
	int flow[110][110] = { 0, };
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		if (flow[temp.first][temp.second] > minx)
		{
			while (!q.empty())
				q.pop();
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				if (flood[nx][ny] != flood[temp.first][temp.second] && flood[nx][ny] != 0 && flood[temp.first][temp.second] != 0)
				{
					if (minx > flow[temp.first][temp.second])
						minx = flow[temp.first][temp.second];
				}
				if (flood[nx][ny] == 0 && flow[nx][ny] == 0)
				{
					flood[nx][ny] = flood[temp.first][temp.second];
					flow[nx][ny] = flow[temp.first][temp.second] + 1;
					q.push(m(nx, ny));
				}
			}
		}
	}
}

int main()
{
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> a[i][j];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (a[i][j] > 0 && chk_fill[i][j] == 0)
			{
				cnt_fill++;
				filling(i, j);
			}
		}
	}
	for (k = 1; k <= cnt_fill; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				flood[i][j] = chk_fill[i][j];
				if (chk_fill[i][j] == k)
				{
					bool flag = false;
					for (int f = 0; f < 4; f++)
					{
						int nx = i + mx[f], ny = j + my[f];
						if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
						{
							if (flood[nx][ny] == 0)
							{
								flag = true;
								break;
							}
						}
					}
					if (flag == true)
						q.push(m(i, j));
				}
			}
		}
		flood_fill();
	}
	cout << minx;
	return 0;
}

/* 틀렸습니다
#include<iostream>
#include<queue>

using namespace std;

int a[110][110];
int bridge[110][110];
int cnt[110][110];
int minx = 0x7fffffff;
int n, mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };
int mx2[8] = { -1, -1, -1, 0, 1, 1, 1, 0 }, my2[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int check[110][110], land, check2[110][110];
queue<pair<int, int> > q;
queue<pair<int, int> > q2;

void edge(int x, int y)
{
	int i, j;
	q.push(make_pair(x, y));
	q2.push(make_pair(x, y));
	check[x][y] = land;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (i = 0; i < 8; i++)
		{
			int nx2 = temp.first + mx2[i], ny2 = temp.second + my2[i];
			if (a[nx2][ny2] == 1 && nx2 >= 1 && nx2 <= n && ny2 >= 1 && ny2 <= n && check[nx2][ny2] == 0)
			{
				bool chkzero = false;
				for (j = 0; j < 4; j++)
				{
					int nx1 = nx2 + mx[j], ny1 = ny2 + my[j];
					if (a[nx1][ny1] == 0 && nx1 >= 1 && nx1 <= n && ny1 >= 1 && ny1 <= n)
						chkzero = true;
				}
				if (chkzero)
				{
					check[nx2][ny2] = land;
					q.push(make_pair(nx2, ny2));
					q2.push(make_pair(nx2, ny2));
				}
			}
		}
	}
}

void BFS()
{
	int i;
	while (!q2.empty())
	{
		pair<int, int> temp = q2.front();
		q2.pop();
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				if (check[temp.first][temp.second] != check[nx][ny] && check[temp.first][temp.second] != 0 && check[nx][ny] != 0)
				{
					if (minx > check2[temp.first][temp.second] + check2[nx][ny])
						minx = check2[temp.first][temp.second] + check2[nx][ny];
				}
				if (a[nx][ny] == 0 && check2[nx][ny] == 0)
				{
					a[nx][ny] = 1;
					check[nx][ny] = check[temp.first][temp.second];
					check2[nx][ny] = check2[temp.first][temp.second] + 1;
					q2.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (a[i][j] == 1 && check[i][j] == 0)
			{
				bool flag = false;
				for (k = 0; k < 4; k++)
				{
					int nx = i + mx[k], ny = j + my[k];
					if (a[nx][ny] == 0 && nx >= 1 && nx <= n && ny >= 1 && ny <= n)
						flag = true;
				}
				if (flag)
				{
					land++;
					edge(i, j);
				}
			}
		}
	}
	BFS();
	cout << minx;
	return 0;
}
*/

/* 시간초과
#include<iostream>
#include<queue>

using namespace std;

int n, a[110][110], minx = 0x7fffffff;
int mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };
int chk[110][110] = { false, };

void BFS_O(int x, int y)
{
	int i;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	chk[x][y] = true;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (a[nx][ny] == 1 && chk[nx][ny] == false && nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				chk[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void BFS_Z(int x, int y)
{
	int i;
	int cnt[110][110] = { 0, };
	queue<pair<int, int> > q;

	bool chk2[110][110] = { false, };
	q.push(make_pair(x, y));
	cnt[x][y] = 1;
	chk2[x][y] = true;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (a[nx][ny] == 1 && chk[nx][ny] == false)
			{
				if (minx > cnt[temp.first][temp.second])
					minx = cnt[temp.first][temp.second];
			}
			if (a[nx][ny] == 0 && chk2[nx][ny] == false && nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				cnt[nx][ny] = cnt[temp.first][temp.second] + 1;
				chk2[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> a[i][j];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (a[i][j] == 1)
			{
				for (k = 0; k < 4; k++)
				{
					int nx = i + mx[k], ny = j + my[k];
					if (a[nx][ny] == 0)
					{
						BFS_O(i, j);
						BFS_Z(nx, ny);
						for (int x = 1; x <= n; x++)
							for (int y = 1; y <= n; y++)
								chk[x][y] = false;
					}
				}
			}
		}
	}
	cout << minx;
	return 0;
}
*/