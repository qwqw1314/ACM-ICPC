#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m, k, cnt;
int arr[101][101];
vector<int> v;
queue<pair<int, int> > q;

int mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };

void filling(int sx, int sy, int ex, int ey)
{
	int i, j;
	for (i = sx; i < ex; i++)
		for (j = sy; j < ey; j++)
			arr[i][j] = -1;
}

void BFS(int x, int y)
{
	int i, cnt2 = 1;
	q.push(make_pair(x, y));
	arr[x][y] = cnt;
	while (!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int nx = temp.first + mx[i], ny = temp.second + my[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (arr[nx][ny] == 0)
				{
					arr[nx][ny] = cnt;
					cnt2++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	v.push_back(cnt2);
}

int main()
{
	int i, j;
	cin >> m >> n >> k;
	for (i = 0; i < k; i++)
	{
		int t1x, t1y, t2x, t2y;
		cin >> t1x >> t1y >> t2x >> t2y;
		filling(t1x, t1y, t2x, t2y);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				cnt++;
				BFS(i, j);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}