#include<iostream>
#include<string.h>

using namespace std;

char a[11];
int b[100][11];
int c[11];

int main()
{
	int i = 0;
	cin >> a;
	while (i < strlen(a))
	{
		if (a[i] == '0')
		{
			c[0]++;
		}
		else if (a[i] == '1')
		{
			c[1]++;
		}
		else if (a[i] == '2')
		{
			c[2]++;
		}
		else if (a[i] == '3')
		{
			c[3]++;
		}
		else if (a[i] == '4')
		{
			c[4]++;
		}
		else if (a[i] == '5')
		{
			c[5]++;
		}
		else if (a[i] == '7')
		{
			c[7]++;
		}
		else if (a[i] == '8')
		{
			c[8]++;
		}
		else if (a[i] == '6' || a[i] == '9')
		{
			if (c[6] > c[9])
				c[9]++;
			else
				c[6]++;
		}
		i++;
	}
	int max = 0;
	for (int j = 0; j < 10; j++)
	{
		if (c[j] > max)
			max = c[j];
	}
	cout << max;
	return 0;
}