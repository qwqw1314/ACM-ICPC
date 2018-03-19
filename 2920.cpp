#include<iostream>

using namespace std;

int a[10];
char how;

int main()
{
	bool flag = false;
	int i;
	for (i = 0; i < 8; i++)
		cin >> a[i];
	if (a[0] > a[1])
		how = 'd';
	else if (a[0] < a[1])
		how = 'a';
	else
		how = 'm';
	for (i = 1; i < 7; i++)
	{
		if (a[i] < a[i + 1] && how == 'a')
		{
			continue;
		}
		else if (a[i] > a[i + 1] && how == 'd')
		{
			continue;
		}
		else
		{
			flag = true;
			break;
		}
	}
	if (flag == true)
		cout << "mixed";
	else
	{
		if (how == 'a')
			cout << "ascending";
		else if (how == 'd')
			cout << "descending";
	}
	return 0;
}