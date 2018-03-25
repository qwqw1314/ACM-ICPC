#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, chk[1010], cnt;
vector<int> v[1010];
queue<int> q;

void BFS(int x)
{
	int i;
	q.push(x);
	chk[x] = 1;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (i = 0; i < v[temp].size(); i++)
		{
			if (chk[v[temp][i]] == 0)
			{
				chk[v[temp][i]] = cnt;
				q.push(v[temp][i]);
			}
		}
	}
}

int main()
{
	int i;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	for (i = 1; i <= n; i++)
	{
		if (chk[i] == 0)
		{
			cnt++;
			BFS(i);
		}
	}
	cout << cnt;
	return 0;
}