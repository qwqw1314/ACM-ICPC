#include<iostream>
#include<string.h>

using namespace std;

#define larger(x, y) ((x) > (y) ? (x) : (y))

char a[10010], b[10010], c[10010];

int main()
{
	int lena, lenb, i;
	cin >> a >> b;
	lena = strlen(a);
	lenb = strlen(b);
	for (i = 0; i < lena / 2; i++)
	{
		char t = a[i];
		a[i] = a[lena - i - 1];
		a[lena - i - 1] = t;
	}
	for (i = 0; i < lenb / 2; i++)
	{
		char t = b[i];
		b[i] = b[lenb - i - 1];
		b[lenb - i - 1] = t;
	}
	for (i = 0; i < larger(lena, lenb); i++)
	{
		char temp = (a[i] - '0') + (b[i] - '0');
		if (temp + c[i] >= 10)
		{
			c[i] += (temp - 10);
			c[i + 1] += 1;
		}
		else
		{
			c[i] += temp;
		}
	}
	bool flag = false;
	for (i = 10001; i >= 0; i--)
	{
		if (c[i] != 0)
			flag = true;
		if (flag == true)
			cout << (int)c[i];
	}
	return 0;
}