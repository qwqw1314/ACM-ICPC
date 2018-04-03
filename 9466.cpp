#include<iostream>
#include<queue>

using namespace std;

int n, start;
int like[100010];
bool chk[100010];
int cycle[100010];
bool flag;
queue<int> q;

void DFS(int now)
{
	if (like[now] == start && chk[like[now]] == false)
	{
		q.push(like[now]);
		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			cycle[temp] = 1;
		}
	}
	if (chk[like[now]] == false)
	{
		chk[like[now]] = true;
		q.push(like[now]);
		DFS(like[now]);
		chk[like[now]] = false;
	}
}

int main()
{
	int t, i;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			cycle[i] = 0;
			cin >> like[i];
		}
		for (i = 1; i <= n; i++)
		{
			if (cycle[i] == 0)
			{
				flag = false;
				start = i;
				DFS(i);
				while (!q.empty())
					q.pop();
			}
		}
		int cnt = 0;
		for (i = 1; i <= n; i++)
			if (cycle[i] == 0)
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}

/*
#include<iostream>
#include<vector>

using namespace std;

int n;
int a[100010];
bool save[100010], chk[100010];
vector<int> v;

int DFS(int now)
{
	if (chk[now] == true)
		return now;
	chk[now] = true;
	return DFS(a[now]);
}

int main()
{
	int t, T, i;
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> n;
		int cnt = 0;
		for (i = 1; i <= n; i++)
		{
			cin >> a[i];
			chk[i] = false;
			save[i] = false;
		}
		for (i = 1; i <= n; i++)
		{
			if (chk[i] == false || save[i] == false)
			{
				if (DFS(i) == i)
				{
					save[i] = true;
					cnt++;
				}
			}
		}
		cout << n - cnt << endl;
	}
	return 0;
}
*/
/*
#include<iostream>

using namespace std;

int n, cnt;
int a[100010];
int chk[100010], chk2[100010];

void DFS_no_re(int start)
{
	int now = start;
	bool iscycle = false;
	chk[now] = -1;
	while(true)
	{
		chk[now] = -1;
		if (a[now] == start)
		{
			iscycle = true;
			break;
		}
		if (chk[a[now]] == -1)
			break;
		now = a[now];
	}
	if (!iscycle)
	{
		for (int i = 1; i <= n; i++)
			if (chk[i] == -1)
				chk[i] = 0;
	}
	else
	{
		cnt++;
		for (int i = 1; i <= n; i++)
		{
			if (chk[i] == -1)
			{
				chk[i] = 0;
				chk2[i] = 1;
			}
		}
	}
}

int main()
{
	int t, T, i, j;
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> n;
		for (i = 1; i <= n; i++)
			cin >> a[i];
		for (i = 1; i <= n; i++)
		{
			if (chk[i] == 0 && chk2[i] == 0)
				DFS_no_re(i);
		}
		int cnt2 = 0;
		for (i = 1; i <= n; i++)
		{
			if (chk2[i] == 0)
			{
				cnt2++;
				chk[i] = chk2[i] = 0;
			}
		}
		cout << cnt2 << endl;
	}
	return 0;
}
*/