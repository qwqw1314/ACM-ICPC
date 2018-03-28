#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int a[110][110];
vector<int> v[110];
int n, m;

void BFS(int start)
{
	int i;
	bool check[110] = { false, };
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (i = 0; i < v[temp].size(); i++)
		{
			if (check[v[temp][i]] == false)
			{
				check[v[temp][i]] = true;
				a[start][v[temp][i]] = a[start][temp] + 1;
				q.push(v[temp][i]);
			}
		}
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	for (i = 1; i <= n; i++)
	{

		BFS(i);
	}
	int minx = 0x7ffffff, mini;
	for (i = 1; i <= n; i++)
	{
		int sum = 0;
		for (j = 1; j <= n; j++)
		{
			sum += a[i][j];
		}
		if (minx > sum)
		{
			minx = sum;
			mini = i;
		}
	}
	cout << mini;
	return 0;
}