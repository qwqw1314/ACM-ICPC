#include<iostream>

using namespace std;

long long int fibo[70];

int main()
{
	int n, t, i;
	fibo[0] = fibo[1] = 1;
	fibo[2] = 2, fibo[3] = 4;
	for (i = 4; i < 68; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2] + fibo[i - 3] + fibo[i - 4];
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << fibo[n] << endl;
	}
	return 0;
}