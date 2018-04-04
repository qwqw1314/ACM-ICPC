#include<iostream>

using namespace std;

int dy[101];

int main()
{
	int i, j;
	for(i = 1; i <= 10; i++)
		for (j = i * i; j < (i + 1)*(i + 1); j++)
			dy[j] = i;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << dy[n] << endl;
	}
	return 0;
}