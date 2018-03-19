#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a;
	while (!cin.eof())
	{
		getline(cin, a);
		cout << a << endl;
	}
	return 0;
}