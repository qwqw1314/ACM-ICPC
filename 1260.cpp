#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m, start;
vector<int> v[1010];
queue<int> q;
int chk_d[1010], chk_b[1010];

/*DFSŽ��*/
void DFS(int x)
{
	int i;
	// �� Level���� ���
	cout << x << " ";
	for (i = 0; i < v[x].size(); i++)
	{
		if (chk_d[v[x][i]] == 0)
		{// ���� �̵� ���� ��� �߽߰�
			chk_d[v[x][i]] = 1; // �̵���� üũ ��
			DFS(v[x][i]);		// �������� �̵�
		}
	}
}

/*BFSŽ��*/
void BFS(int y)
{
	int i;
	// ť�� ���� ���� ����� ��� Ǫ��
	q.push(y);
	// ���� ���� ����� ���� �ǵ��� ���� ��� ������ ����
	// ���� ��忡 üũ
	chk_b[y] = 1;
	while (!q.empty())
	{
		int now = q.front();
		for (i = 0; i < v[now].size(); i++)
		{
			// ���� ��� �߽߰� ť�� ��� Ǫ��
			if (chk_b[v[now][i]] == 0)
			{
				chk_b[v[now][i]] = 1;
				q.push(v[now][i]);
			}
		}
		// ����� ��� ��忡 ���� Ž���� ���� ������ ���
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
	// �� ����� ���� ������ ������������ ����
	for (i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());
	chk_d[start] = 1;
	DFS(start);
	cout << endl;
	BFS(start);
	return 0;
}