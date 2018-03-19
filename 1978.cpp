#include<iostream>
#include<math.h>

using namespace std;

int cnt;

int main()
{
	int i, j, n, t;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> t;
		bool flag = false;
		if (t == 1) continue;
		for (j = 2; j <= sqrt(t); j++)
		{
			if (t % j == 0)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
			cnt++;
	}
	cout << cnt;
	return 0;
}