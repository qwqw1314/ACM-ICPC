#include<iostream>
#include<queue>

using namespace std;

int n, s, g, u, d;
int stairs[1000010];

void BFS(int now)
{
	queue<int> q;
	q.push(now);
	fill(stairs + 1, stairs + n + 1, 0x7fffffff);
	stairs[now] = 0;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		if (temp + u <= n)
		{
			if (stairs[temp + u] > stairs[temp] + 1)
			{
				stairs[temp + u] = stairs[temp] + 1;
				q.push(temp + u);
			}
		}
		if (temp - d >= 1)
		{
			if (stairs[temp - d] > stairs[temp] + 1)
			{
				stairs[temp - d] = stairs[temp] + 1;
				q.push(temp - d);
			}
		}
	}
}

int main()
{
	cin >> n >> s >> g >> u >> d;
	BFS(s);
	if (stairs[g] == 0x7fffffff)
		cout << "use the stairs";
	else
		cout << stairs[g];
	return 0;
}