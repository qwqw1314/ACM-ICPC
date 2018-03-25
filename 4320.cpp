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
		bool isminus = false, flag = false;
		scanf("%lld", &a);
		if (a == 0) break;
		if (a < 0)
			isminus = true;
		int cnt = 0;
		if (isminus == false)
		{
			for (i = 2; i <= sqrt(a); i++)
			{
				cnt = 0;
				if (a % i == 0)
				{
					long long int temp = a;
					while (1)
					{
						if (temp == 1)
						{
							flag = true;
							break;
						}
						if (temp % i == 0)
						{
							temp /= i;
							cnt++;
						}
					}
				}
				if (flag == true)
					break;
			}
		}
		else if (isminus == true)
		{
			for (i = -2; i >= -sqrt(-a); i--)
			{
				cnt = 0;
				if (a % i == 0)
				{
					long long int temp = a;
					while (1)
					{
						if (temp == 1)
						{
							flag = true;
							break;
						}
						if (temp == -1)
						{
							cnt = 1;
							break;
						}
						if (temp % i == 0)
						{
							temp /= i;
							cnt++;
						}
					}
				}
				if (flag == true)
					break;
			}
		}
		if (cnt == 0)
			printf("1\n");
		else
			printf("%d\n", cnt);
	}
	return 0;
}