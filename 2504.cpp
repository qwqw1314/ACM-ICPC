#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

int matching[40];
int depths[40];
char a[40];
int len, cnt1, cnt2;

stack<char> st;
stack<int> sum;

int main()
{
	int i, j, total = 0;
	cin >> a;
	len = strlen(a);
	int x = 0;
	while (x < len)
	{
		if (a[x] == '(' || a[x] == '[')
		{
			st.push(a[x]);
			sum.push(0);
		}
		if (a[x] == ')')
		{
			if (st.top() != '(')
			{
				cout << 0;
				return 0;
			}
			st.pop();
			total = 0;
			while (sum.top() != 0)
			{
				total += sum.top();
				sum.pop();
			}
			sum.pop();
			if (total == 0)
				sum.push(2);
			else
				sum.push(total * 2);
		}
		if (a[x] == ']')
		{
			if (st.top() != '[')
			{
				cout << 0;
				return 0;
			}
			st.pop();
			total = 0;
			while (sum.top() != 0)
			{
				total += sum.top();
				sum.pop();
			}
			sum.pop();
			if (total == 0)
				sum.push(3);
			else
				sum.push(total * 3);
		}
		x++;
	}
	if (!st.empty())
		cout << 0;
	else
	{
		total = 0;
		while (!sum.empty())
		{
			total += sum.top();
			sum.pop();
		}
		cout << total;
	}
	return 0;
}