#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int t, T, i, j, n;
	cin >> T;
	for (t = 0; t < T; t++)
	{
		int n, len;
		char a[30];
		cin >> n >> a;
		len = strlen(a);
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < n; j++)
				cout << a[i];
		}
		cout << endl;
	}
	return 0;
}