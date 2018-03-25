#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>

using namespace std;

vector<int> v[20001];
int coloring[20001];
int n, m;
bool flag = false;

void DFS(int x, int color)
{
	int i;
	for (i = 0; i < v[x].size(); i++)
	{
		if (coloring[x] == coloring[v[x][i]])
			flag = true;
		if (coloring[v[x][i]] == 0)
		{
			coloring[v[x][i]] = 3 - color;
			DFS(v[x][i], 3 - color);
		}
	}
}

int main()
{
	int t, T, i;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			v[i].clear();
			coloring[i] = 0;
		}
		for (i = 0; i < m; i++)
		{
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			v[t1].push_back(t2);
			v[t2].push_back(t1);
		}
		flag = false;
		for (i = 1; i <= n; i++)
		{
			if (coloring[i] == 0)
			{
				coloring[i] = 1;
				DFS(i, 1);
			}
		}
		if (flag == true)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}