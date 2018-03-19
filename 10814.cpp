#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<string>

using namespace std;

struct abc
{
	int age;
	char name[101];
	int num;
}stu[100010];

bool compare(const abc& a, const abc& b)
{
	if (a.age < b.age)
		return true;
	else if (a.age == b.age)
		if (a.num < b.num)
			return true;
		else
			return false;
	else
		return false;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %s", &stu[i].age, stu[i].name);
		stu[i].num = i;
	}
	sort(stu, stu + n, compare);
	for (i = 0; i < n; i++)
	{
		printf("%d %s\n", stu[i].age, stu[i].name);
	}
	return 0;
}