#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

int matching[40];
int depths[40];
char a[40];
int len, cnt1, cnt2;
int all[100];
char allabout[100];

stack<char> st;


int main()
{
	int i, j;
	cin >> a;
	len = strlen(a);
	int x = 0;
	while (x < len)
	{
		if (a[x] == '(')
			st.push('(');
		else if (a[x] == '[')
			st.push('[');
		if (st.top() == '(' && a[x] == ')')
		{
			st.pop();
			all[cnt1++] = 2;
			if (a[x + 1] == '[' || a[x + 1] == '(')
				allabout[cnt2++] = '+';
			else
				allabout[cnt2++] = '*';
		}
		else if (st.top() == '[' && a[x] == ']')
		{
			st.pop();
			all[cnt1++] = 3;
			if (a[x + 1] == '[' || a[x + 1] == '(')
				allabout[cnt2++] = '+';
			else
				allabout[cnt2++] = '*';
		}
		x++;
	}
	int sum = 0;
	x = 0;
	return 0;
}