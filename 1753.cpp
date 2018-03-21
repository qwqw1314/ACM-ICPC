#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int start;

vector<int> edge[20010], dis[20010];
int dy[20010];
priority_queue<pair<int, int> > pq;
queue<int> nodes;

int main()
{
	int i, j;
	cin >> n >> m >> start;
	for (i = 0; i < m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		edge[t1].push_back(t2);
		dis[t1].push_back(t3);
	}
	fill(dy + 1, dy + n + 1, 0x7fffffff);
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
	for (i = 1; i <= n; i++)
	{
		if (dy[i] == 0x7fffffff)
			cout << "INF";
		else
			cout << dy[i];
		if (i != n)
			cout << endl;
	}
	return 0;
}