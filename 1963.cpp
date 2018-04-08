#include<iostream>
#include<queue>

using namespace std;

int arr[4], check[10010];
bool prime[10010];
queue<pair<int, int> > q;

void makearray(int x, int num[4])
{
	num[0] = x / 1000;
	num[1] = x / 100 % 10;
	num[2] = x / 10 % 10;
	num[3] = x % 10;
}

int main()
{
	int i, j, t;
	for (i = 2; i <= 100; i++)
	{
		if (prime[i] == true)
			continue;
		for (j = i + i; j <= 10000; j+= i)
			prime[j] = true;
	}
	cin >> t;
	while (t--)
	{
		int from, to;
		cin >> from >> to;
		q.push(make_pair(from, 0));
		while (!q.empty())
		{
			pair<int, int> temp = q.front();
			if (temp.first == to)
			{
				cout << temp.second << endl;
				break;
			}
			q.pop();
			for (i = 0; i < 4; i++)
			{
				makearray(temp.first, arr);
				for (j = 0; j <= 9; j++)
				{
					if (i == 0 && j == 0)
						continue;
					arr[i] = j;
					int temp2 = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
					if (prime[temp2] == false && check[temp2] == 0)
					{
						q.push(make_pair(temp2, temp.second + 1));
						check[temp2] = 1;
					}
				}
			}
		}
		while (!q.empty())
			q.pop();
		for (i = 1000; i < 10000; i++)
			check[i] = 0;
	}
	return 0;
}

/*
#include<iostream>
#include<queue>

using namespace std;

int cnt[10010];
bool arr[10010];
int a, b;
queue<int> q;
int ten[4] = { 1000, 100, 10, 1 };

int main()
{
	int i, j, k, t, T;
	for (i = 2; i <= 10000; i++)
		for (j = i + i; j <= 10000; j += i)
		{
			arr[j] = true;
		}
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> a >> b;
		if (a == b)
		{
			cout << 0;
			continue;
		}
		q.push(a);
		fill(cnt + 1000, cnt + 10000, -1);
		cnt[a] = 0;
		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			int n[4] = { temp / 1000, temp % 1000 / 100, temp % 100 / 10, temp % 10 };
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j <= 9; j++)
				{
					if ((i == 0 && j == 0) || n[i] == j) continue;
					int sum = 0;
					for (k = 0; k < 4; k++)
					{
						if (i == k)
						{
							sum += j * ten[k];
							continue;
						}
						sum += n[k] * ten[k];
					}
					if (arr[sum] == false && (cnt[sum] == -1 || cnt[sum] > cnt[temp] + 1))
					{
						q.push(sum);
						cnt[sum] = cnt[temp] + 1;
					}
				}
			}
		}
		if (cnt[b] == -1)
			cout << "Impossible" << endl;
		else
			cout << cnt[b] << endl;
	}
	return 0;
}
*/