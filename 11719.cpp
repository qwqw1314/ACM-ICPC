#include<iostream>
#include<string>

using namespace std;

string a;

int main()
{
	while (1)
	{
		getline(cin, a);
		if (cin.eof())
			break;
		cout << a << endl;
	}
	return 0;
}