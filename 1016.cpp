#include<iostream>
#include<math.h>

using namespace std;

long long int a, b, c, d;

int main()
{
	long long int i, cnt = 0;
	cin >> a >> b;
	c = sqrt(a);
	d = sqrt(b);
	cout << (long long int)(b - a- (d - c));
	return 0;
}