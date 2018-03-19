#include<iostream>
#include<string.h>

using namespace std;

int n;
char b[1000];

int main()
{
	int i, len, sum = 0, pow = 1;
	cin >> b >> n;
	len = strlen(b);
	for (i = 0; i < len; i++)
	{
		if (b[len - i - 1] >= 'A' && b[len - i - 1] <= 'Z')
		{
			int temp = b[len - i - 1] - 'A' + 10;
			sum += (temp * pow);
		}
		else
			sum += ((b[len - i - 1] - '0') * pow);
		pow *= n;
	}
	cout << sum;
	return 0;
}