#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

using namespace std;

long long int a;

int main()
{
	int i;
	while (1)
	{
		int t = 2, sqa;
		scanf("%lld", &a);
		if (a == 0)
			break;
		if (a % 2 == 1)
			t++;
		sqa = sqrt(a);
		bool flag = false;
		for (i = t; i <= sqa; i += 2)
		{
			long long int x = i;
			int cnt = 1;
			if (a % i != 0)
				continue;
			while (1)
			{
				x *= i;
				cnt++;
				if (x >= a)
					break;
			}
			if (x == a)
			{
				printf("%d\n", cnt);
				flag = true;
				break;
			}
		}
		if (flag == false)
			printf("1\n");
	}
	return 0;
}