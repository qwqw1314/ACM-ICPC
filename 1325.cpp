#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

vector<int> v[10001];
int n, m, virus[10001], maxx = 0;

int main()
{
	int i, j;
	queue<int> q;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		v[t2].push_back(t1);
	}
	for (i = 1; i <= n; i++)
	{
		bool check[10001] = { false };
		if (v[i].size() == 0)
			continue;
		check[i] = true;
		int cnt = 0;
		q.push(i);
		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			for (j = 0; j < v[temp].size(); j++)
			{
				if (check[v[temp][j]] == false)
				{
					check[v[temp][j]] = true;
					q.push(v[temp][j]);
					cnt++;
				}
			}
		}
		virus[i] = cnt;
		if (virus[i] > maxx)
			maxx = virus[i];
	}
	for (i = 1; i <= n; i++)
	{
		if (virus[i] == maxx)
			printf("%d ", i);
	}
	return 0;
}