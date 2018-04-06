#include<iostream>

int n, l, cnt;
int arr[110][110];

using namespace std;

int main()
{
	int i, j, k;
	cin >> n >> l;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> arr[i][j];
	
	return 0;
}