#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

int main()
{
	int t, T, i, j;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		int n, xyz[3001][3], group[3001];
		vector<int> v[3001];
		scanf("%d", &n);
		fill(group, group + n, 0);
		for (i = 0; i < n; i++)
			for (j = 0; j < 3; j++)
				scanf("%d", &xyz[i][j]);
		for (i = 0; i < n - 1; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				int tempx1 = xyz[i][0], tempx2 = xyz[j][0], tempy1 = xyz[i][1], tempy2 = xyz[j][1], tempz1 = xyz[i][2], tempz2 = xyz[j][2];
				int minusx = abs(tempx2 - tempx1), minusy = abs(tempy2 - tempy1);
				if (tempz1 + tempz2 >= sqrt(minusx*minusx + minusy*minusy))
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		int cnt = 1;
		queue<int> q;
		for (i = 0; i < n; i++)
		{
			if (group[i] != 0)
				continue;
			q.push(i);
			while (!q.empty())
			{
				int temp = q.front();
				q.pop();
				group[temp] = cnt;
				for (j = 0; j < v[temp].size(); j++)
				{
					if (group[v[temp][j]] == 0)
						q.push(v[temp][j]);
				}
			}
			cnt++;
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}