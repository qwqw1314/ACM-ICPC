#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> v[110];
int a[110][110];

void DFS(int start, int x)
{
	int i;
	for (i = 0; i < v[x].size(); i++)
	{
		int temp = v[x][i];
		if (a[start][temp] == 0)
		{
			a[start][temp] = 1;
			DFS(start, temp);
		}
	}
}

int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			int t;
			cin >> t;
			if (t == 1)
			{
				v[i].push_back(j);
			}
		}
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (v[i].size())
				DFS(i, i);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}