#include<iostream>

using namespace std;

char a[4], b[4];

int main()
{
	int i;
	cin >> a >> b;
	if (a[2] < b[2])
		cout << b[2] << b[1] << b[0];
	else if (a[2] > b[2])
		cout << a[2] << a[1] << a[0];
	else
	{
		if (a[1] < b[1])
			cout << b[2] << b[1] << b[0];
		else if (a[1] > b[1])
			cout << a[2] << a[1] << a[0];
		else
		{
			if (a[0] < b[0])
				cout << b[2] << b[1] << b[0];
			else if (a[0] > b[0])
				cout << a[2] << a[1] << a[0];
		}
	}
	return 0;
}