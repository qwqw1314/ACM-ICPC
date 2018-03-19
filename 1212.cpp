#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

string a;

int main()
{
	int i = 0;
	cin >> a;
	if (a[0] == '0' && a.length() == 1)
		cout << '0';
	else
	{
		for (i = 0; i < a.length(); i++)
		{
			if (i != 0)
			{
				if (a[i] == '0')
					cout << "000";
				if (a[i] == '1')
					cout << "001";
				if (a[i] == '2')
					cout << "010";
				if (a[i] == '3')
					cout << "011";
				if (a[i] == '4')
					cout << "100";
				if (a[i] == '5')
					cout << "101";
				if (a[i] == '6')
					cout << "110";
				if (a[i] == '7')
					cout << "111";
			}
			else
			{
				if (a[i] == '1')
					cout << "1";
				if (a[i] == '2')
					cout << "10";
				if (a[i] == '3')
					cout << "11";
				if (a[i] == '4')
					cout << "100";
				if (a[i] == '5')
					cout << "101";
				if (a[i] == '6')
					cout << "110";
				if (a[i] == '7')
					cout << "111";
			}
		}
	}
	return 0;
}