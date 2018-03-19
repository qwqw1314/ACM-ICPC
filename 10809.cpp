#include<iostream>
#include<string.h>

using namespace std;

int len, chk[30];
char a[101];

int main()
{
	int i;
	for (i = 0; i < 26; i++)
	{
		chk[i] = -1;
	}
	cin >> a;
	len = strlen(a);
	for (i = 0; i < len; i++)
	{
		int b = (int)(a[i] - 'a');
		if (chk[b] == -1)
			chk[b] = i;
	}
	for (i = 0; i < 26; i++)
		cout << chk[i] << " ";
	return 0;
}

//baekjoon