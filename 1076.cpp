#include<iostream>
#include<string.h>

using namespace std;

char a[4][10];
long long int b;
char color[12][10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
long long int c[12] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
long long int d[12] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

int main()
{
	int i;
	for (i = 0; i < 3; i++)
		cin >> a[i];
	for (i = 0; i < 10; i++)
	{
		if (strcmp(a[0], color[i]) == 0)
			b += (i * 10);
	}
	for (i = 0; i < 10; i++)
	{
		if (strcmp(a[1], color[i]) == 0)
			b += i;
	}
	for (i = 0; i < 10; i++)
	{
		if (strcmp(a[2], color[i]) == 0)
			b *= d[i];
	}
	cout << b;
	return 0;
}