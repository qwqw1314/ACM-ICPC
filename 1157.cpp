#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char a[1000010];
int alpha[30];
int maxx = 0, maxi;

int main()
{
	int i;
	scanf("%s", a);
	int len = strlen(a);
	for (i = 0; i < len; i++)
	{
		if (a[i] >= 'a')
			alpha[a[i] - 97]++;
		else
			alpha[a[i] - 65]++;
	}
	bool flag = false;
	int maxcnt = 0;
	for (i = 0; i < 26; i++)
	{
		if (alpha[i] > maxx)
		{
			maxx = alpha[i];
			maxi = i;
		}
	}
	for (i = 0; i < 26; i++)
	{
		if (alpha[i] == maxx)
			maxcnt++;
	}
	if (maxcnt > 1)
		printf("?");
	else
		printf("%c", maxi + 'A');
	return 0;
}