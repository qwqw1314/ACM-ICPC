#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a;

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		a.push_back(i);
	while (1)
	{
		for (i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
		if (!next_permutation(a.begin(), a.end()))
			break;
		printf("\n");
	}
	return 0;
}