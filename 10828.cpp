#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stack>

using namespace std;

char a[20];
int b;
stack<int> s;

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
				s.push(b);
			}
			else
			{
				if (!s.empty())
				{
					printf("%d\n", s.top());
					s.pop();
				}
				else
					printf("-1\n");
			}
		}
		else if (a[0] == 's')
		{
			printf("%d\n", s.size());
		}
		else if (a[0] == 'e')
		{
			if (s.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else
		{
			if (s.empty())
				printf("-1\n");
			else
				printf("%d\n", s.top());
		}
	}
	return 0;
}