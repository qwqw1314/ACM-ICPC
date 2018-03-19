#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;

int a[1010];

int main()
{
	int t, T, i, n;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		int cnt = 0, sum = 0;
		float ave, per;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		ave = (float)sum / (float)n;
		for (i = 0; i < n; i++)
			if ((float)a[i] > ave)
				cnt++;
		per = (float)cnt / (float)n * 100.0;
		printf("%.3f%%\n", per);
	}
	return 0;
}