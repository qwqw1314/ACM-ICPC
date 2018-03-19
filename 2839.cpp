#include<iostream>

using namespace std;

int a, b;

void func(int x, int y,int z)
{
	if (x != 0)
	{
		if (x % 3 == 0)
		{
			b = y + x / 3;
		}
		else
		{
			if(y > 0)
				func(x + 5, y - 1, z);
		}
	}
}

int main()
{
	int temp1, temp2;
	cin >> a;
	temp1 = a / 5;
	temp2 = a % 5;
	if (a % 5 != 0)
		func(temp2, temp1, 0);
	else
		b = temp1;
	if (b == 0)
		cout << "-1";
	else
		cout << b;
	return 0;
}