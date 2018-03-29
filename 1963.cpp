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