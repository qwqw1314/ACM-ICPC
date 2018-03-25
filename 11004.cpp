#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

int n, m;
int* arr;

int main()
{
	int i;
	scanf("%d %d", &n, &m);
	arr = new int[n];
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	printf("%d", arr[m - 1]);
	delete arr;
	return 0;
}