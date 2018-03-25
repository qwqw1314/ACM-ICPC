#include<iostream>
#include<vector>

using namespace std;

int a[11][11];
vector<pair<int, int> > v;
bool flag = false;

bool check_row(int x, int y)
{
	int check[10] = { 0, };
	for (int i = 1; i <= 9; i++)
		check[a[i][y]]++;
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] > 1)
			return false;
	}
	return true;
}

bool check_col(int x, int y)
{
	int check[10] = { 0, };
	for (int i = 1; i <= 9; i++)
		check[a[x][i]]++;
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] > 1)
			return false;
	}
	return true;
}

bool check_square(int x, int y)
{
	int check[10] = { 0, };
	int sx, sy, ex, ey;
	if (x >= 1 && x <= 3)
		sx = 1, ex = 3;
	else if (x >= 4 && x <= 6)
		sx = 4, ex = 6;
	else
		sx = 7, ex = 9;
	if (y >= 1 && y <= 3)
		sy = 1, ey = 3;
	else if (y >= 4 && y <= 6)
		sy = 4, ey = 6;
	else
		sy = 7, ey = 9;
	for (int i = sx; i <= ex; i++)
		for (int j = sy; j <= ey; j++)
			check[a[i][j]]++;
	for (int i = 1; i <= 9; i++)
	{
		if (check[i] > 1)
			return false;
	}
	return true;
}

void back(int next)
{
	int i, j, k;
	if (next == v.size() && flag == false)
	{
		for (i = 1; i <= 9; i++)
		{
			for (j = 1; j <= 9; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		flag = true;
	}
	if (flag == false)
	{
		pair<int, int> pos = v[next];
		int x = pos.first, y = pos.second;
		for (i = 1; i <= 9; i++)
		{
			bool flag2 = false;
			a[x][y] = i;
			for (j = 1; j <= 9; j++)
			{
				for (k = 1; k <= 9; k++)
				{
					if (!check_row(j, k) || !check_col(j, k) || !check_square(j, k))
					{
						flag2 = true;
						break;
					}
				}
				if (flag2 == true)
					break;
			}
			if (flag2 == false)
			{
				back(next + 1);
				a[x][y] = 0;
			}
		}
	}
}

int main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 0)
			{
				v.push_back(make_pair(i, j));
			}
		}
	}
	back(0);
	return 0;
}