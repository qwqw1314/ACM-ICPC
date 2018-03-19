#include<iostream>

using namespace std;

int a[1000001], b[1000001];

int main()
{
	int n, m, i, t;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < m; i++)
		cin >> b[i];
	int cnt1 = 0, cnt2 = 0;
	while (1)
	{
		if (cnt1 == n && cnt2 == m)
		{
			break;
		}
		else if (cnt1 == n)
		{
			cout << b[cnt2++];
		}
		else if (cnt2 == m)
		{
			cout << a[cnt1++];
		}
		else
		{
			if (a[cnt1] < b[cnt2])
			{
				cout << a[cnt1];
				cnt1++;
			}
			else if (a[cnt1] > b[cnt2])
			{
				cout << b[cnt2];
				cnt2++;
			}
			else
			{
				cout << a[cnt1++] << " " << b[cnt2++];
			}
		}
		if (!(cnt1 == n && cnt2 == m))
		{
			cout << " ";
		}
	}
	return 0;
}