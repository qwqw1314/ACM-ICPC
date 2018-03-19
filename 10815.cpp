#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a;

int main()
{
	int i, n, m;
	int t;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &t);
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &t);
		bool found = binary_search(a.begin(), a.end(), t);
		if (found)
			printf("1 ");
		else
			printf("0 ");
	}
	return 0;
}