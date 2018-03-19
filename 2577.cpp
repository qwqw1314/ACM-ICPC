#include<iostream>

using namespace std;

int arr[11];

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c;
	d = a*b*c;
	while (d != 0)
	{
		arr[d % 10]++;
		d /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;
	return 0;
}