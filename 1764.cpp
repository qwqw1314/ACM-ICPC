#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<string> a, b;

int main()
{
	int i;
	cin >> n >> m;
	a.resize(n);
	int cnt = 0;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	string temp;
	for (i = 0; i < m; i++)
	{
		cin >> temp;
		if (binary_search(a.begin(), a.end(), temp))
			b.push_back(temp);
	}
	sort(b.begin(), b.end());
	cout << b.size() << endl;
	for (i = 0; i < b.size(); i++)
		cout << b[i] << endl;
	return 0;
}
/*
3 4
ohhenrie
charlie
baesangwook
obama
baesangwook
ohhenrie
clinton
*/