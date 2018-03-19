#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

char a[100010];
int b;
bool checkzero = false;
vector<int> v;

int main()
{
	int i;
	scanf("%s", a);
	int len = strlen(a);
	for (i = 0; i < len; i++)
	{
		b += (int)(a[i] - '0');
		v.push_back(a[i] - '0');
		if ((int)(a[i] - '0') == 0)
			checkzero = true;
	}
	sort(v.begin(), v.end());
	if (b % 3 == 0 && checkzero == true)
	{
		for (i = 0; i < len; i++)
		{
			printf("%d", v[len - i - 1]);
		}
	}
	else
		printf("-1");
	return 0;
}