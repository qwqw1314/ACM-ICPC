#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> v[101];
queue<int> q;
int check[101], cnt;

int main()
{
	int n, m, i;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		// 양방향 간선이기 때문에 양쪽에 간선 추가
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	q.push(1);
	check[1] = 1;
	// 일반적인 BFS 탐색방식 이용
	while (!q.empty())
	{
		int temp = q.front();
		for (i = 0; i < v[temp].size(); i++)
		{
			// 다음 노드가 이동 가능할 경우
			if (check[v[temp][i]] == 0)
			{
				// 다음 노드의 재방문 방지용 체크
				check[v[temp][i]] = 1;
				q.push(v[temp][i]);
				cnt++;
			}
		}
		q.pop();
	}
	cout << cnt;
	return 0;
}