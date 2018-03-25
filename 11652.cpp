#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

int n;
long long int* a;
long long int cnt, maxi, maxx;

int main()
{
	int i;
	scanf("%d", &n);
	a = new long long int[n + 1];
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	for (i = 0; i < n; i++)
	{
		cnt++;
		if (a[i] == a[i + 1])
		{
			if (maxx < cnt)
			{
				maxx = cnt;
				maxi = a[i];
			}
		}
		else
		{
			if (maxx < cnt)
			{
				maxx = cnt;
				maxi = a[i];
			}
			cnt = 0;
		}
	}
	printf("%lld", maxi);
	return 0;
}