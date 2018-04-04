#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct bambu
{
	int x, y, z;
};

bool comp(const bambu &now, const bambu &other)
{
	if (now.z < other.z)
		return true;
	return false;
}

int maxx(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

vector<bambu> v;
int a[510][510], dy[510][510];
int mx[4] = { -1, 1, 0, 0 }, my[4] = { 0, 0, -1, 1 };

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			bambu temp = { i, j, a[i][j] };
			v.push_back(temp);
		}
	}
	sort(v.begin(), v.end(), comp);
	int ans = 0;
	for (i = 0; i < v.size(); i++)
	{
		int maxint = 0;
		for (j = 0; j < 4; j++)
		{
			int x = v[i].x + mx[j], y = v[i].y + my[j];
			if (a[x][y] < a[v[i].x][v[i].y])
				maxint = maxx(maxint, dy[x][y]);
		}
		dy[v[i].x][v[i].y] = maxint + 1;
		ans = maxx(ans, dy[v[i].x][v[i].y]);
	}
	cout << ans;
	return 0;
}