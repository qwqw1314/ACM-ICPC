#include<iostream>
#include<string.h>

#define modular 1000000

using namespace std;

char a[5010];
long long int dy[5010];

int main()
{
	int i;
	cin >> a;
	int len = strlen(a);
	dy[0] = 1;
	int num;
	for (i = 0; i < len; i++)
	{
		if (i == 0)
			num = a[i] - '0';
		else
			num = a[i] - '0' + (a[i - 1] - '0') * 10;
		if (num % 10 >= 1 && num % 10 <= 9)
			dy[i + 1] = (dy[i + 1] + dy[i]) % modular;
		if (a[i - 1] == '0' || i == 0)
			continue;
		if (num >= 10 && num <= 26)
			dy[i + 1] = (dy[i + 1] + dy[i - 1]) % modular;
	}
	cout << dy[len];
	return 0;
}