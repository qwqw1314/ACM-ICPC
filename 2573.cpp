// ¾ÆÁ÷µµ ÀÌÇØ¾ÈµÊ ÄÚµå ±Ü¾î¿È
// https://blog.naver.com/kokoxg2/221097959119
#include <cstdio>
#include <vector>

typedef struct {  //ÁÂÇ¥ ±¸Á¶Ã¼
	int x, y;
}Pos;

const int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

std::pair<int, int> ice[301][301];
bool visit[301][301];

int n, m;

std::vector<Pos> vec;

void dfs(const Pos& p);

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &ice[i][j].first);
			if (ice[i][j].first != 0)
				vec.push_back({ i,j });
		}
	}

	int count = 0, len2;

	while (!vec.empty()) {

		len2 = vec.size(); 
		dfs(vec[0]);
		for (int i = 0; i < len2; ++i)
			if (!visit[vec[i].x][vec[i].y])
				return 0 & printf("%d\n", count);

		count++;
		for (int i = 0; i < len2; ++i) {
			visit[vec[i].x][vec[i].y] = false;
			ice[vec[i].x][vec[i].y].first -= ice[vec[i].x][vec[i].y].second;
			ice[vec[i].x][vec[i].y].second = 0;
			if (ice[vec[i].x][vec[i].y].first < 1) {
				ice[vec[i].x][vec[i].y].first = 0;
				vec.erase(vec.begin() + i--);
				len2 -= 1;
			}
		}
	}
	printf("0\n");

	return 0;
}

void dfs(const Pos& p) {

	visit[p.x][p.y] = true;
	for (int i = 0; i < 4; ++i) {
		int x = p.x + dx[i];
		int y = p.y + dy[i];
		if (ice[x][y].first == 0) ice[p.x][p.y].second++;
		if (x <= 1 || y <= 1 || n < x || m < y || ice[x][y].first == 0 || visit[x][y]) continue;
		dfs({ x,y });
	}
}

/*
#include<iostream>

using namespace std;

int n, m;
int ice[310][310], melt[310][310];
int mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };
bool chk[310][310];

int cntzero(int x, int y)
{
	int i, cnt = 0;
	for (i = 0; i < 4; i++)
	{
		int nx = x + mx[i], ny = y + my[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
		{
			if (ice[nx][ny] == 0)
				cnt++;
		}
	}
	return cnt;
}

void DFS(int x, int y)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		int nx = x + mx[i], ny = y + my[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
		{
			if (ice[nx][ny] > 0 && !chk[nx][ny])
			{
				chk[nx][ny] = true;
				DFS(nx, ny);
			}
		}
	}
}

int main()
{
	int i, j, decade = 0, group = 0;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> ice[i][j];
	while (1)
	{
		group = 0;
		decade++;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				chk[i][j] = false;
				if (ice[i][j] > 0)
					melt[i][j] = cntzero(i, j);
			}
		}
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				if (ice[i][j] > 0 && melt[i][j] > 0)
					ice[i][j] -= melt[i][j];
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (ice[i][j] > 0 && !chk[i][j])
				{
					group++;
					chk[i][j] = true;
					DFS(i, j);
				}
			}
		}
		if (group >= 2)
			break;
		else if (group == 0)
		{
			decade = 0;
			break;
		}
	}
	cout << decade;
	return 0;
}*/


/*
#include<iostream>
#include<queue>

using namespace std;

#define m(x, y) make_pair(x, y)

int ice[310][310], chk[310][310], melt[310][310];
int n, m;
int mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };
queue<pair<int, int> > q;

int allcheck()
{
	int i, j;
	bool flag = false;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (ice[i][j] > 0)
				flag = true;
			if (ice[i][j] > 0 && chk[i][j] == 0)
				return 0;
		}
	}
	if (flag == true)
		return 1;
	else if (flag == false)
		return 2;
}
int checkzero(int x, int y);

void dfs(int x, int y)
{
	q.push(m(x, y));
	for (int i = 0; i < 4; i++)
	{
		int nx = x + mx[i], ny = y + my[i];
		if (ice[nx][ny] > 0 && chk[nx][ny] == 0)
		{
			chk[nx][ny] = 1;
			melt[nx][ny] = checkzero(nx, ny);
			dfs(nx, ny);
		}
	}
}

int checkzero(int x, int y)
{
	int i;
	int cnt = 0;
	for (i = 0; i < 4; i++)
	{
		int nx = x + mx[i], ny = y + my[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			if (ice[nx][ny] == 0)
				cnt++;
	}
	return cnt;
}

void decade()
{
	int i;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		int x = temp.first, y = temp.second;
		ice[x][y] -= melt[x][y];
		melt[x][y] = 0;
		chk[x][y] = 0;
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> ice[i][j];
	int cnt = 0;
	while (1)
	{
		bool flag = false;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (ice[i][j] > 0)
				{
					chk[i][j] = 1;
					melt[i][j] = checkzero(i, j);
					dfs(i, j);
					if (allcheck() == 0)
					{
						cout << cnt;
						return 0;
					}
					else if (allcheck() == 2)
					{
						cout << 0;
						return 0;
					}
					decade();
					cnt++;
				}
			}
		}
		if (allcheck() == 2)
		{
			cout << 0;
			break;
		}
	}
	return 0;
}
*/
/*
5 2
0 1 1 1 0
0 0 0 0 0
*/
/*
#include<iostream>
#include<queue>

using namespace std;

int n, m, mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };
int a[310][310], cnt[310][310], chk[310][310], allcnt;
queue<pair<int, int> > q1, q2;

void later()
{
	int i;
	while (!q1.empty())
	{
		pair<int, int> temp = q1.front();
		q1.pop();
		q2.push(temp);
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
			{
				if (a[nx][ny] == 0)
					cnt[temp.first][temp.second]++;
			}
		}
	}
}

void BFS(int x, int y)
{
	int i;
	queue<pair<int, int> > q3;
	q3.push(make_pair(x, y));
	chk[x][y] = allcnt;
	while (!q3.empty())
	{
		pair<int, int> temp = q3.front();
		q3.pop();
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
			{
				if (chk[nx][ny] == 0 && a[nx][ny] > 0)
				{
					chk[nx][ny] = allcnt;
					q3.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] > 0)
				q1.push(make_pair(i, j));
		}
	}
	int cnt1 = 0;
	while (1)
	{
		later();
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (a[i][j] > 0 && chk[i][j] == 0)
				{
					allcnt++;
					BFS(i, j);
				}
			}
		}
		if (allcnt >= 2)
			break;
		allcnt = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				chk[i][j] = 0;
		while (!q2.empty())
		{
			pair<int, int> temp = q2.front();
			q2.pop();
			int x = temp.first, y = temp.second;
			if (a[x][y] > cnt[x][y])
			{
				q1.push(temp);
				a[x][y] -= cnt[x][y];
				cnt[x][y] = 0;
			}
			else
			{
				a[x][y] = 0;
				cnt[x][y] = 0;
			}
		}
		cnt1++;
	}
	cout << cnt1;
	return 0;
}
*/