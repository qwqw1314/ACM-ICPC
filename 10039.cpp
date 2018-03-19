#include<iostream>

using namespace std;

int sum, a[6];

int main()
{
	int i;
	for (i = 0; i < 5; i++)
	{
		cin >> a[i];
		if (a[i] < 40)
			sum += 40;
		else
			sum += a[i];
	}
	cout << sum / 5;
	return 0;
}