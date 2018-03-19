#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<string>

using namespace std;

struct abc
{
	string a;
	int b, c, d;
	bool operator < (const abc &other)
	{
		if (this->b < other.b)
			return false;
		else if (this->b > other.b)
			return true;
		else
		{
			if (this->c > other.c)
				return false;
			else if (this->c < other.c)
				return true;
			else
			{
				if (this->b < other.b)
					return false;
				else if (this->b > other.b)
					return true;
				else
				{
					if (this->a > other.a)
						return false;
					else
						return true;
				}
			}
		}
	}
};

abc stu[100010];

int main()
{
	int n, i;
	scanf("%d\n", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", stu[i].a);
		scanf("%d", &stu[i].b);
		scanf("%d", &stu[i].c);
		scanf("%d", &stu[i].d);
	}
	sort(stu, stu + n);
	for (i = 0; i < n; i++)
		printf("%s\n", stu[i].a);
	return 0;
}