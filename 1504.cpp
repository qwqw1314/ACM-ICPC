#include<iostream>
#include<vector>
#include<queue>

#define INF 0x7fffffff

using namespace std;

vector<pair<int, int> > edges[1000];
long long int dis[1000], n, m;
queue<int> q;

long long int dijk(int start, int end)
{
	int i;
	fill(dis + 1, dis + n + 1, INF);
	dis[start] = 0;
	q.push(start);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (i = 0; i < edges[now].size(); i++)
		{
			if (dis[edges[now][i].first] > dis[now] + edges[now][i].second)
			{
				dis[edges[now][i].first] = dis[now] + edges[now][i].second;
				q.push(edges[now][i].first);
			}
		}
	}
	return dis[end];
}

long long int minx(long long int x, long long int y)
{
	if (x > y)
		return y;
	return x;
}

int main()
{
	int i, first, second;
	cin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		edges[t1].push_back({ t2, t3 });
		edges[t2].push_back({ t1, t3 });
	}
	cin >> first >> second;
	long long int far1 = dijk(1, first) + dijk(first, second) + dijk(second, n);
	long long int far2 = dijk(1, second) + dijk(second, first) + dijk(first, n);
	long long int far = minx(far1, far2);
	if (far > INF)
		cout << -1;
	else
		cout << far;
	return 0;
}

/*E log V 다익스트라 실패작 ( 왜틀린지 감도안옴 )
#include<iostream>
#include<vector>
#include<queue>

#define INF 2000000000

using namespace std;

int n, m;
int st;

vector<int> edge[1000], dis[1000];
int dy[1000], visited[1000];
priority_queue<pair<int, int> > pq;
queue<int> nodes;

int dijk(int start, int end)
{
	int i;
	fill(dy + 1, dy + n + 1, INF);
	dy[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		pair<int, int> temp = pq.top();
		int now = temp.second;
		pq.pop();
		for (i = 0; i < dis[now].size(); i++)
		{
			int next = edge[now][i];
			if (dy[next] > dy[now] + dis[now][i])
			{
				dy[next] = dy[now] + dis[now][i];
				pq.push(make_pair(dis[now][i], next));
			}
		}
	}
	return dy[end];
}

int minx(int x, int y)
{
	if (x > y)
		return y;
	return x;
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
		dis[t1].push_back(t3);
		dis[t2].push_back(t3);
	}
	int first, second;
	cin >> first >> second;
	int far = minx(dijk(1, first) + dijk(first, second) + dijk(second, n), dijk(1, second) + dijk(second, first) + dijk(first, n));
	if (far > INF)
		cout << -1;
	else
		cout << far;
	return 0;
}
*/
/* N^2 다익스트라 실패작
#include<iostream>

#define INF 2000000000

using namespace std;

int n, m;
int st;
int a[810][810], dy[1010];
int tofirst, tosecond, to1_2, to2_1, to1_end, to2_end;
int disfirst, dissecond;

void dijk(int start)
{
	int i, j;
	fill(dy + 1, dy + n + 1, INF);
	dy[start] = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j || a[i][j] == 0)
				continue;
			if (dy[j] > a[i][j] + dy[i])
				dy[j] = dy[i] + a[i][j];
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		a[t1][t2] = t3;
	}
	int first, second;
	cin >> first >> second;
	dijk(1);
	tofirst = dy[first];
	tosecond = dy[second];

	dijk(first);
	to1_2 = dy[second];
	to1_end = dy[n];
	dijk(second);
	to2_1 = dy[first];
	to2_end = dy[n];

	disfirst = tofirst + to1_2 + to2_end;
	dissecond = tosecond + to2_1 + to1_end;

	int minx = ((disfirst > dissecond) ? dissecond : disfirst);
	if (minx >= INF)
		cout << -1;
	else
		cout << minx;
	return 0;
}
*/