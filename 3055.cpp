#include<iostream>
#include<queue>

#define m(x, y) make_pair(x, y)

using namespace std;

struct w
{
	int x, y, cnt;
};

struct g
{
	int x, y, cnt;
};

char land[60][60];
int mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 }, n, m;
int check[60][60];
queue<w> water;
queue<g> gosm;

bool isRange(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

void BFS()
{
	int count = 0, i;
	check[gosm.front().x][gosm.front().y] = 1;
	while (1)
	{
		while (!water.empty())
		{
			if (water.front().cnt > count)
				break;
			w temp = water.front();
			water.pop();
			for (i = 0; i < 4; i++)
			{
				int nx = temp.x + mx[i], ny = temp.y + my[i];
				if (isRange(nx, ny))
				{
					if (land[nx][ny] == '.' || land[temp.x][temp.y] == 'S')
					{
						land[nx][ny] = '*';
						water.push({ nx, ny, temp.cnt + 1 });
					}
				}
			}
		}
		bool flag = false;
		while (!gosm.empty())
		{
			if (gosm.front().cnt > count)
				break;
			g temp = gosm.front();
			gosm.pop();
			if(land[temp.x][temp.y] == '.' || land[temp.x][temp.y] == 'S')
			{
				for (i = 0; i < 4; i++)
				{
					int nx = temp.x + mx[i], ny = temp.y + my[i];
					if (isRange(nx, ny))
					{
						if (land[nx][ny] == '.')
						{
							flag = true;
							land[nx][ny] = 'S';
							gosm.push({ nx, ny, temp.cnt + 1 });
						}
						if (land[nx][ny] == 'D')
						{
							cout << count + 1;
							return;
						}
					}
				}
			}
 		}
		if (flag == false)
		{
			cout << "KAKTUS";
			return;
		}
		count++;
	}
}

int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> land[i][j];
			if (land[i][j] == '*')
				water.push({ i, j, 0 });
			if (land[i][j] == 'S')
				gosm.push({ i, j, 0 });
		}
	}
	BFS();
	return 0;
}