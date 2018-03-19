#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

using namespace std;

char a;

int main()
{
	int t, T, i;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		int b, sum = 0, len;
		char temp;
		scanf("%d\n", &b);
		while (1)
		{
			scanf("%c", &a);
			if (a == 10)
				break;
			if (b == 2) continue;
			sum += (int)(a - '0');
		}
		printf("%d\n", sum % (b - 1));
	}
	return 0;
}