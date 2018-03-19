#include<iostream>

using namespace std;

int main()
{
	int n, b, t[40], cnt = 0;
	cin >> n >> b;
	while (n != 1 && n != 0)
	{
		t[cnt++] = n % b;
		n /= b;
	}
	if (n == 1)
		t[cnt++] = 1;
	for (int i = cnt - 1; i >= 0; i--)
	{
		if (t[i] >= 10)
			cout << (char)(t[i] - 10 + 'A');
		else
			cout << t[i];
	}
	return 0;
}