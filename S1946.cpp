#include<iostream>

using namespace std;

int b[20];
char a[20];

int main()
{
	int t, T, i, j, n;
	cin >> T;
	for (t = 1; t <= T; t++)
	{
		int cnt = 0;
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		cout << "#" << t << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < b[i]; j++)
			{
				cout << a[i];
				cnt++;
				if (cnt == 10)
				{
					cout << endl;
					cnt = 0;
				}
			}
		}
	}
	return 0;
}