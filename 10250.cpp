#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int h, w, n, t, i;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> h >> w >> n;
		if (n % h == 0)
			w = h;
		else
			w = n % h;
		cout << w * 100 + (int)ceil((float)n / h) << endl;
	}
	return 0;
}