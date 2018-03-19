#include<iostream>
#include<string.h>

using namespace std;

char a[10010], b[10010];
int aa[10010], bb[10010];
int lena, lenb;
long long int sum1, sum2;

int main()
{
	int i;
	cin >> a >> b;
	lena = strlen(a), lenb = strlen(b);
	for (i = 0; i < lena; i++)
	{
		sum1 += (int)(a[i] - '0');
	}
	for (i = 0; i < lenb; i++)
	{
		sum2 += (int)(b[i] - '0');
	}
	cout << sum1 * sum2;
	return 0;
}