#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, s, first[410][410];
vector<int> v[410];
queue<int> q;

void BFS(int now)
{
	int i;
	bool chk[410] = { false, };
	q.push(now);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (i = 0; i < v[temp].size(); i++)
		{
			if (chk[v[temp][i]] == false)
			{
				q.push(v[temp][i]);
				chk[v[temp][i]] = true;
				first[now][v[temp][i]] = 1;
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
	}
	for (i = 1; i <= n; i++)
		BFS(i);
	cin >> s;
	for (i = 1; i <= s; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		if (first[t1][t2] == 1 && first[t2][t1] == 0)
			cout << -1 << endl;
		else if (first[t1][t2] == 0 && first[t2][t1] == 1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}

/* DFS 시간초과, Floyd 오답
#include<iostream>
#include<vector>

using namespace std;

int first[410][410];
int a[410][410], f[410][410];
int n, m, s;

vector<int> v[410];

void DFS(int start, int now)
{
	int i;
	bool chk[410] = { false, };
	for (i = 0; i < v[now].size(); i++)
	{
		if (!chk[v[now][i]])
		{
			chk[v[now][i]] = true;
			first[start][v[now][i]] = 1;
			DFS(start, v[now][i]);
			chk[v[now][i]] = false;
		}
	}
}

int main()
{
	int i, j, k;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		//v[t1].push_back(t2);
		a[t1][t2] = 1;
	}
	for (i = 1; i <= n; i++)
		DFS(i, i);
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (a[i][k] + a[k][j] < a[i][j] && !a[i][k] && !a[k][j] && !a[i][j])
					a[i][j] = a[i][k] + a[k][j];
	cin >> s;
	for (i = 1; i <= s; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		if (a[t1][t2] >= 1 && a[t2][t1] == 0)
			cout << -1 << endl;
		else if (a[t1][t2] == 0 && a[t2][t1] >= 1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
*/