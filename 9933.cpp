#include<iostream>
#include<string>

using namespace std;

string arr[210];

string reverse(string a)
{
	string b;
	b.clear();
	for (int i = 0; i < a.size(); i++)
	{
		b.push_back(a[a.size() - i - 1]);
	}
	return b;
}

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[n + i] = reverse(arr[i]);
	}
	n = n * 2;
	for (i = 1; i <= n - 1; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (arr[i] == arr[j])
			{
				cout << arr[i].size() << " " << arr[i][arr[i].size() / 2];
				return 0;
			}
		}
	}
	return 0;
}