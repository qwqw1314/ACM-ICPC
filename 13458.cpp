#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[1000010];
long long int n, cnt;
int m, s;

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d %d", &m, &s);
	for (i = 0; i < n; i++)
		arr[i] -= m;
	cnt += n;
	for (i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			if (arr[i] % s == 0) // 총감독관을 제외한 부감독관이 딱 맞을 경우
				cnt += arr[i] / s;
			else // 부감독관으로 나눠도 나누어 떨어지지 않을 경우
				cnt += (arr[i] / s) + 1;
		}
	}
	printf("%lld", cnt);
	return 0;
}