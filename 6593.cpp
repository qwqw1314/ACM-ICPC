#include<iostream>
#include<queue>

using namespace std;

struct pos
{
	int z, x, y;
};

int miro[35][35][35];
int cnt[35][35][35];
int L, R, C;
int s[3], e[3], mx[6] = { -1, 1, 0, 0, 0, 0 }, my[6] = { 0, 0, -1, 1, 0, 0 }, mz[6] = { 0, 0, 0, 0, -1, 1 };
queue<pos> q;

void BFS(int z, int x, int y)
{
	bool chk[35][35][35] = { false, };
	q.push({ z, x, y });
	chk[z][x][y] = true;
	while (!q.empty())
	{
		pos a = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = a.x + mx[i], ny = a.y + my[i], nz = a.z + mz[i];
			if (nx >= 1 && nx <= R && ny >= 1 && ny <= C && nz >= 1 && nz <= L)
			{
				if (chk[nz][nx][ny] == false && (!miro[nz][nx][ny] || miro[nz][nx][ny] == 2))
				{
					chk[nz][nx][ny] = true;
					cnt[nz][nx][ny] = cnt[a.z][a.x][a.y] + 1;
					q.push({ nz,nx,ny });
				}
			}
		}
	}
}

int main()
{
	int i, j, k;
	while (1)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		for (k = 1; k <= L; k++)
		{
			for (i = 1; i <= R; i++)
			{
				for (j = 1; j <= C; j++)
				{
					char t;
					cin >> t;
					if (t == 'S')
					{
						miro[k][i][j] = 1;
						s[0] = k, s[1] = i, s[2] = j;
					}
					else if (t == '#')
						miro[k][i][j] = -1;
					else if (t == 'E')
					{
						miro[k][i][j] = 2;
						e[0] = k, e[1] = i, e[2] = j;
					}
				}
			}
		}
		BFS(s[0], s[1], s[2]);
		int ans = cnt[e[0]][e[1]][e[2]];
		if (ans == 0)
			cout << "Trapped!";
		else
			cout << "Escaped in " << ans << " minute(s).";
	}
	return 0;
}