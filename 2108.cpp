#include<iostream>

using namespace std;

int a[8010], cnt;
int maxx, maxi, isthere[2] = { -1, -1 };
int maxy, miny = 0x7fffffff;

int main()
{
	long long int sum = 0;
	int n, i, mid = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		t = t + 4000;
		a[t]++;
		cnt++;
	}
	for (i = 0; i <= 8000; i++)
	{
		sum += ((i - 4000) * a[i]);
		if (a[i] > maxx)
		{
			maxx = a[i];
			maxi = i;
		}
		if (maxy < i && a[i] > 0)
			maxy = i;
		if (miny > i && a[i] > 0)
			miny = i;
	}
	for (i = 0; i <= 8000; i++)
	{
		if (a[i] == maxx)
		{
			if (isthere[0] == -1)
				isthere[0] = i;
			else if(isthere[1] == -1)
				isthere[1] = i;
		}
	}
	int nsum = 0, ni;
	cout << sum / n << endl;
	for (i = 0; i <= 8000; i++)
	{
		if ((nsum + a[i]) > (cnt / 2))
		{
			ni = i;
			break;
		}
		nsum += a[i];
	}
	cout << ni - 4000 << endl;
	if (isthere[1] == -1)
		cout << isthere[0] - 4000 << endl;
	else
		cout << isthere[1] - 4000 << endl;
	cout << (maxy - 4000) - (miny - 4000);
	return 0;
}