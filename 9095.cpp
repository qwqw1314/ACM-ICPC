#include<iostream>

using namespace std;

int dy[11];

int main()
{
	int t, T, n, i;
	dy[1] = 1;
	dy[2] = 2;
	dy[3] = 4;
	for (i = 4; i < 11; i++)
		dy[i] = dy[i - 1] + dy[i - 2] + dy[i - 3];
	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> n;
		cout << dy[n] << endl;
	}
	return 0;
}