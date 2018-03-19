#include<iostream>
#include<string.h>

using namespace std;

char a[20];
int arr[] = { 1,2,3,4,5,6,7,8,9};

int main()
{
	int i, sum = 0;
	cin >> a;
	int len = strlen(a);
	for (i = 0; i < len; i++)
	{
		if (a[i] >= 'A' && a[i] <= 'C')
			sum += 3;
		else if (a[i] >= 'D' && a[i] <= 'F')
			sum += 4;
		else if (a[i] >= 'G' && a[i] <= 'I')
			sum += 5;
		else if (a[i] >= 'J' && a[i] <= 'L')
			sum += 6;
		else if (a[i] >= 'M' && a[i] <= 'O')
			sum += 7;
		else if (a[i] >= 'P' && a[i] <= 'S')
			sum += 8;
		else if (a[i] >= 'T' && a[i] <= 'V')
			sum += 9;
		else if (a[i] >= 'W' && a[i] <= 'Z')
			sum += 10;
	}
	cout << sum;
	return 0;
}