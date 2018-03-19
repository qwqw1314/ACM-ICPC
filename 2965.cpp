#include<iostream>

using namespace std;

int a[4];

int main()
{
	int i, j;
	cin >> a[0] >> a[1] >> a[2];
	if (a[1] - a[0] > a[2] - a[1])
	{
		cout << a[1] - a[0] - 1;
	}
	else
	{
		cout << a[2] - a[1] - 1;
	}
	return 0;
}