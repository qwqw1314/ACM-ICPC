#include<iostream>
#include<vector>
#include<queue>

using namespace std;

char a[110][110];
int n, m, chk[110][110], cnt[110][110];
int mx[4] = { -1, 0, 1, 0 }, my[4] = { 0, -1, 0, 1 };
struct abc
{
	int x, y;
};

// x, y 방향을 가지고 있는 struct를 이용해 벡터 및 큐 정의
vector<abc> v;
queue<abc> q;

void BFS()
{
	int i;
	abc temp;
	temp.x = 1, temp.y = 1;
	chk[1][1] = 1;
	q.push(temp);
	while (!q.empty())
	{
		abc temp2 = q.front();
		for (i = 0; i < 4; i++)
		{
			// mx, my를 이용해 다음 탐색 노드 고려
			int nx = temp2.x + mx[i], ny = temp2.y + my[i];
			// 다음 위치가 범위 밖이 아닐 경우
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				// 다음 위치가 이동 가능한 위치이면서
				// 방문하지 않은 노드일 경우
				if (chk[nx][ny] == 0 && a[nx][ny] == '1')
				{
					abc temp3 = { nx, ny };
					chk[nx][ny] = 1;
					cnt[nx][ny] = cnt[temp2.x][temp2.y] + 1;
					q.push(temp3);
				}
			}
		}
		q.pop();
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	cnt[1][1] = 1;
	BFS();
	cout << cnt[n][m];
	return 0;
}

/*
DFS 실패작
#include<iostream>

using namespace std;

int	n, m;
char a[110][110];
int chk[110][110], dy[110][110], minx = 0x7fffffff, maxx;
int mx[4] = { -1, 0, 1, 0 }, my[4] = { 0, -1, 0, 1 };

void dfs(int x, int y, int cnt)
{
	int i;
	if (x == n && y == m)
	{
		if (cnt < minx)
			minx = cnt;
	}
	for (i = 0; i < 4; i++)
	{
		int nx = x + mx[i], ny = y + my[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
		{
			if (chk[nx][ny] == 0 && a[nx][ny] == '1')
			{
				if (dy[nx][ny] == 0)
					dy[nx][ny] = cnt + 1;
				if (dy[nx][ny] < cnt + 1)
					break;
				else
					dy[nx][ny] = cnt + 1;
				chk[nx][ny] = 1;
				dfs(nx, ny, cnt + 1);
				chk[nx][ny] = 0;
			}
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	dy[1][1] = 0;
	dfs(1, 1, 1);
	cout << minx;
	return 0;
}
*/