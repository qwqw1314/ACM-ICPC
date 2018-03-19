#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	for (i = 0; i < n; i++)
	{
		printf("%d\n", v[i]);
	}
	return 0;
}