#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, from, to;
int a[110];
vector<int> v[110];

void BFS(int x)
{
	int i;
	bool check[110] = { false, };
	queue<int> q;
	check[x] = 1;
	q.push(x);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (i = 0; i < v[temp].size(); i++)
		{
			if (check[v[temp][i]] == false)
			{
				a[v[temp][i]] = a[temp] + 1;
				check[v[temp][i]] = true;
				q.push(v[temp][i]);
			}
		}
	}
}

int main()
{
	int i;
	cin >> n;
	cin >> from >> to;
	cin >> m;
	for (i = 1; i <= m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	BFS(from);
	if (a[to] > 0)
		cout << a[to];
	else
		cout << -1;
	return 0;
}
/*
9
7 3
7
1 2
1 3
2 7
2 8
2 9
4 5
4 6
*/