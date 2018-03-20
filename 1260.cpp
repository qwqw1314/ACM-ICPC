#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m, start;
vector<int> v[1010];
queue<int> q;
int chk_d[1010], chk_b[1010];

/*DFS탐색*/
void DFS(int x)
{
	int i;
	// 매 Level마다 출력
	cout << x << " ";
	for (i = 0; i < v[x].size(); i++)
	{
		if (chk_d[v[x][i]] == 0)
		{// 다음 이동 가능 노드 발견시
			chk_d[v[x][i]] = 1; // 이동노드 체크 후
			DFS(v[x][i]);		// 다음노드로 이동
		}
	}
}

/*BFS탐색*/
void BFS(int y)
{
	int i;
	// 큐에 가장 먼저 출발할 노드 푸시
	q.push(y);
	// 가장 먼저 출발할 노드로 되돌아 오는 경우 방지를 위해
	// 다음 노드에 체크
	chk_b[y] = 1;
	while (!q.empty())
	{
		int now = q.front();
		for (i = 0; i < v[now].size(); i++)
		{
			// 다음 노드 발견시 큐에 모두 푸시
			if (chk_b[v[now][i]] == 0)
			{
				chk_b[v[now][i]] = 1;
				q.push(v[now][i]);
			}
		}
		// 연결된 모든 노드에 대한 탐색이 끝난 노드부터 출력
		cout << q.front() << " ";
		q.pop();
	}
}

int main()
{
	int i;
	cin >> n >> m >> start;
	for (i = 1; i <= m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	// 각 노드의 연결 노드들을 오름차순으로 정렬
	for (i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());
	chk_d[start] = 1;
	DFS(start);
	cout << endl;
	BFS(start);
	return 0;
}