#include<iostream>
#include<string.h>

using namespace std;

char a[1000010];
char b[333334];
int cnt;

int main()
{
	int i;
	cin >> a;
	int len = strlen(a);
	for (i = len - 1; i >= 0; i -= 3)
	{
		if (i == 0)
			b[cnt++] = (a[i] - '0');
		else if (i == 1)
			b[cnt++] = (a[i] - '0') + (a[i - 1] - '0') * 2;
		else
			b[cnt++] = (a[i] - '0') * 1 + (a[i - 1] - '0') * 2 + (a[i - 2] - '0') * 4;
	}
	for (i = cnt - 1; i >= 0; i--)
		cout << (int)b[i];
	return 0;
}