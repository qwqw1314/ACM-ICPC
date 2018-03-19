#include<stdio.h>
#include<string.h>

int chk[31];

int main()
{
	int i, j;
	int n, num;
	char temp[21];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", temp);
		if (temp[0] == 'a' && temp[1] == 'd')
		{
			scanf("%d", num);
			chk[num] = 1;
		}
		else if (temp[0] == 'a' && temp[1] == 'l')
		{
			for (j = 1; j <= 20; j++)
				chk[j] = 1;
		}
		else if (temp[0] == 'r')
		{
			scanf("%d", num);
			chk[num] = 0;
		}
		else if (temp[0] == 'c')
		{
			scanf("%d", num);
			printf("%d\n", chk[num]);
		}
		else if (temp[0] == 't')
		{
			scanf("%d", num);
			if (chk[num] == 1)
				chk[num] = 0;
			else
				chk[num] = 1;
		}
		else if (temp[0] == 'e')
		{
			for (j = 1; j <= 20; j++)
				chk[j] = 0;
		}
	}
	return 0;
}