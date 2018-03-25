#include<iostream>
#include<queue>

using namespace std;

int from, to, found;
queue<int> q;
int check[200010];

int absx(int x)
{
	if (x < 0)
		return -x;
	return x;
}

void BFS(int x)
{
	q.push(x);
	if (from == to)
		return;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		if (temp >= 1)
		{
			if (check[temp - 1] == 0 || check[temp - 1] > check[temp] + 1)
			{
				q.push(temp - 1);
				check[temp - 1] = check[temp] + 1;
				if (temp - 1 == to)
					return;
			}
		}
		if (temp <= 200000 && check[temp + 1] == 0)
		{
			if (check[temp + 1] == 0 || check[temp + 1] > check[temp] - 1)
			{
				q.push(temp + 1);
				check[temp + 1] = check[temp] + 1;
				if (temp + 1 == to)
					return;
			}
		}
		if (temp <= 100000 && check[temp * 2] == 0)
		{
			if (check[temp * 2] == 0 || check[temp * 2] > check[temp] + 1)
			{
				q.push(temp * 2);
				check[temp * 2] = check[temp] + 1;
				if (temp * 2 == to)
					return;
			}
		}
	}
}

int main()
{
	cin >> from >> to;
	BFS(from);
	cout << check[to];
	return 0;
}