#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

int len;
stack<char> s;
char a[100];

bool check(int x, bool chk)
{
	if (x == len)
	{
		if (chk && s.empty())
			return true;
		else
			return false;
	}
	if (a[x] == '(')
	{
		s.push('(');
		check(x + 1, chk);
	}
	else if(a[x] == ')')
	{
		if (s.empty())
			check(x + 1, false);
		else
		{
			s.pop();
			check(x + 1, chk);
		}
	}
}

int main()
{
	int t, T;
	cin >> T;
	for (t = 0; t < T; t++)
	{
		while (!s.empty())
			s.pop();
		cin >> a;
		len = strlen(a);
		bool right = check(0, true);
		if (right == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}