#include<iostream>

using namespace std;

int arr[100010];

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j * j <= i; j++)
		{
			if (arr[i] > arr[i - j * j] + 1 || arr[i] == 0)
				arr[i] = arr[i - j * j] + 1;
		}
	}
	cout << arr[n];
	return 0;
}