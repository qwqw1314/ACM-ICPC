#include<iostream>
#include<string.h>

using namespace std;

char a[100];

int main()
{
	int t, T, len, i;
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> a;
		len = strlen(a);
		int cnt = 0, sum = 0;
		for (i = 0; i < len; i++)
		{
			if (a[i] == 'O')
			{
				cnt++;
				sum += cnt;
			}
			else
			{
				cnt = 0;
			}
		}
		cout << sum << endl;
	}
	return 0;
}