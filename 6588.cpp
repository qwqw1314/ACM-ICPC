#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;

int n;
bool a[1000010] = { false, };
vector<int> v;

int main()
{
	int i, j;
	int temp = 1000;
	for (i = 2; i <= temp; i++)
	{
		for (j = i + i; j <= 1000000; j += i)
		{
			a[j] = true;
		}
	}
	for (i = 3; i <= 1000000; i+= 2)
	{
		if (a[i] == false)
			v.push_back(i);
	}
	while (1)
	{
		bool flag = false;
		scanf("%d", &n);
		if (n == 0)
			break;
		for (i = 0; i < v.size(); i++)
		{
			int temp = v[i];
			if (a[n - v[i]] == false)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
			printf("Goldbach's conjecture is wrong.\n");
		else
			printf("%d = %d + %d\n", n, v[i], n - v[i]);
	}
	return 0;
}