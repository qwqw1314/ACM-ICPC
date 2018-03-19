#include<iostream>
#include<string.h>

using namespace std;

char a[110];
char b[11];

int main()
{
	int i = 0, j;
	int flag = 0;
	cin >> a;
	int lena = strlen(a);
	while(i <= lena){
		for (j = 0; j < 10; j++)
		{
			b[j] = a[i++];
			if (i > lena)
			{
				flag = 1;
				break;
			}
		}
		b[j] = '\0';
		if (flag == 1)
		{
			cout << b;
			break;
		}
		else
		{
			cout << b << endl;
		}
	}
	return 0;
}