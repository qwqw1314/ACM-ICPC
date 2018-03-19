#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;

int a[524300];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	return 0;
}