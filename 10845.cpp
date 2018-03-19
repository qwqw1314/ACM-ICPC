#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;

queue<int> q;
char a[10];
int b;

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", a);
		if (a[0] == 'p')
		{
			if (a[1] == 'u')
			{
				scanf("%d", &b);
				q.push(b);
			}
			else
			{
				if (!q.empty())
				{
					printf("%d\n", q.front());
					q.pop();
				}
				else
					printf("-1\n");
			}
		}
		else if (a[0] == 's')
		{
			printf("%d\n", q.size());
		}
		else if (a[0] == 'e')
		{
			if (q.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (a[0] == 'f')
		{
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		else
		{
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.back());
		}
	}
	return 0;
}