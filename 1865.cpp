//https://blog.naver.com/whgksdyd112/220935305719 Âü°í
#include<iostream>
#include<vector>

#define m(x, y) make_pair(x, y)

using namespace std;

int v, e, m;
vector<pair<int, int> > arr[510];
int dis[510];

bool dijk(int start)
{
	int i, j, k;
	fill(dis, dis + v + 1, 0x7fffffff);
	dis[start] = 0;
	bool flag;
	for (k = 1; k <= v - 1; k++)
	{
		flag = false;
		for (i = 1; i <= v; i++)
		{
			if (dis[i] == 0x7fffffff) continue;
			for (j = 0; j < arr[i].size(); j++)
			{
				pair<int, int> next = arr[i][j];
				if (dis[next.first] > dis[i] + next.second)
				{
					dis[next.first] = dis[i] + next.second;
					flag = true;
				}
			}
		}
		if (!flag) break;
	}
	return flag;
}

int main()
{
	int t, i;
	cin >> t;
	while (t--)
	{
		cin >> v >> e >> m;
		for (i = 0; i < e; i++)
		{
			int t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			arr[t1].push_back(m(t2, t3));
			arr[t2].push_back(m(t1, t3));
		}
		for (i = 0; i < m; i++)
		{
			int t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			arr[t1].push_back(m(t2, -t3));
		}
		if (dijk(1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		for (i = 1; i <= v; i++)
			arr[i].clear();
	}
	return 0;
}