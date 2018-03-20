#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<deque>

using namespace std;

deque<int> d;

int main()
{
	int n, i, temp2;
	char temp[11];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", temp);
		if (temp[0] == 'p' && temp[1] == 'u')
		{
			scanf("%d",&temp2);
			if (temp[5] == 'f')
				d.push_front(temp2);
			else if (temp[5] == 'b')
				d.push_back(temp2);
		}
		else if (temp[0] == 'p' && temp[1] == 'o')
		{
			if (temp[4] == 'f')
			{
				if (d.empty())
					printf("-1\n");
				else
				{
					printf("%d\n", d.front());
					d.pop_front();
				}
			}
			else if (temp[4] == 'b')
			{
				if (d.empty())
					printf("-1\n");
				else
				{
					printf("%d\n", d.back());
					d.pop_back();
				}
			}
		}
		else if (temp[0] == 's')
		{
			printf("%d\n", d.size());
		}
		else if (temp[0] == 'e')
		{
			if (d.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (temp[0] == 'f')
		{
			if (d.empty())
				printf("-1\n");
			else
				printf("%d\n", d.front());
		}
		else if (temp[0] == 'b')
		{
			if (d.empty())
				printf("-1\n");
			else
				printf("%d\n", d.back());
		}
	}
	return 0;
}