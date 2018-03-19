#include<iostream>
#include<string.h>

using namespace std;

char a[12];

int main()
{
	int i, j, len;
	char temp;
	cin >> a;
	len = strlen(a);
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (i = 0; i < len; i++)
	{
		cout << a[i];
	}
	return 0;
}