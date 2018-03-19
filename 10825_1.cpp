#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<string>

using namespace std;

struct abc
{
	string a;
	int b, c, d;
};

bool comp(const abc &x, const abc &y)
{
	if (x.b < y.b)
		return false;
	else if (x.b > y.b)
		return true;
	else
	{
		if (x.c > y.c)
			return false;
		else if (x.c < y.c)
			return true;
		else
		{
			if (x.d < y.d)
				return false;
			else if (x.d > y.d)
				return true;
			else
			{
				if (x.a < y.a)
					return true;
				else
					return false;
			}
		}
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	abc *stu = new abc[n + 1];
	for (i = 0; i < n; i++)
		scanf("%s %d %d %d", stu[i].a, &stu[i].b, &stu[i].c, &stu[i].d);
	sort(stu, stu + n, comp);
	for (i = 0; i < n; i++)
		printf("%s\n", stu[i].a);
	return 0;
}