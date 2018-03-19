#include<iostream>

using namespace std;

int day;
int month[14] = { 0, 31, 28, 31, 30, 31,30,31, 31, 30,31,30,31 };
char week[10][5] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };

int main()
{
	int m, d, i;
	cin >> m >> d;
	for (i = 1; i < m; i++)
	{
		day += month[i];
	}
	day += d;
	day %= 7;
	cout << week[day];
	return 0;
}