#define _CRT_SECURE_NO_WARININGS
#include<stdio.h>
#include<math.h>

int a[60][2];

int main()
{
	int i, j, k, t, T, n;
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d %d",&a[i][0], &a[i][1]);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < n; k++)
				{
					if (i == j || j == k || i == k) continue;
					if (sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0])) > sqrt((a[i][0] - a[k][0]) * (a[i][0] - a[k][0])))
					{
						int t1 = a[j][0], t2 = a[j][1];
						a[j][0] = a[k][0], a[j][1] = a[k][1];
						a[k][0] = t1, a[k][1] = t2;
					}
				}
			}
		}
	}
	return 0;
}