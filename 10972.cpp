#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a;

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		a.push_back(t);
	}
	if (!next_permutation(a.begin(), a.end()))
	{
		printf("-1");
		return 0;
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}