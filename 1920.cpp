#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> a, b;

int main()
{
	int n, m, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		int t;
		scanf("%d", &t);
		if (binary_search(a.begin(), a.end(), t))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}