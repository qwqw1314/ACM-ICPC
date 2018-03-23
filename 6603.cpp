#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int a[20];
vector<int> v1;

void back(int x)
{
	int i, j;
	if (x == 6)
	{
		for (i = 0; i < 6; i++)
		{
			cout << v1[a[i]] << " ";
		}
		cout << endl;
	}
	for (i = 0; i < n; i++)
	{
		bool flag = false;
		for (j = 0; j < x; j++)
		{
			if (a[j] == i || i < a[j])
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			a[x] = i;
			back(x + 1);
		}
	}
}

int main()
{
	int i;
	while (1)
	{
		v1.clear();
		cin >> n;
		if (n == 0)
			break;
		for (i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			v1.push_back(t);
		}
		back(0);
		cout << endl;
	}
	return 0;
}