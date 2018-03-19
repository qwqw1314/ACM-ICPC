#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct abc
{
	int x, y;
};

int n, cnt;
char a[30][30];
int chk[30][30];
int mx[4] = { 0, -1, 0, 1 }, my[4] = { -1, 0, 1, 0 };

queue<abc> q;
vector<int> v;

void BFS(int x, int y)
{
	int i, cnt2 = 1;
	abc temp;
	temp.x = x, temp.y = y;
	q.push(temp);
	chk[temp.x][temp.y] = cnt;
	while (!q.empty())
	{
		abc temp2 = q.front();
		for (i = 0; i < 4; i++)
		{
			int nx = temp2.x + mx[i], ny = temp2.y + my[i];
			if (a[nx][ny] == '1' && chk[nx][ny] == 0)
			{
				chk[nx][ny] = cnt;
				abc temp3 = { nx, ny };
				q.push(temp3);
				cnt2++;
			}
		}
		q.pop();
	}
	v.push_back(cnt2);
}

int main()
{
	int i, j, k;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> a[i][j];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (a[i][j] == '1' && chk[i][j] == 0)
			{
				cnt++;
				BFS(i, j);
			}
		}
	}
	cout << cnt << endl;
	sort(v.begin(), v.end());
	for (i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}
/*
7
1010101
0101010
1010101
0101010
1010101
0101010
1010101
*/