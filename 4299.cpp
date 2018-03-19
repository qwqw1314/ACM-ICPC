#include<iostream>   

using namespace std;

int main()
{
	int h, m, i, a, b;
	bool flag = false;
	cin >> h >> m;
	for (i = 0; i <= h; i++)
	{
		a = i;
		b = h - i;
		if (a + b == h && a - b == m)
		{
			flag = true;
			break;
		}
	}
	if (flag == false)
		cout << -1;
	else
		cout << a << " " << b;
	return 0;
}