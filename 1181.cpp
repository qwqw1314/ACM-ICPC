#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<string> v;

bool strcomp(string &c, string &d)
{
	if (c.size() == d.size())
		return c < d;
	return c.size() < d.size();
}

int main()
{
	int n, i, j;
	cin >> n;
	string temp;
	for (i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), strcomp);
	vector<string>::iterator it;
	vector<string>::iterator endit;
	endit = unique(v.begin(), v.end());

	for (it = v.begin(); it != endit; it++)
		cout << *it << endl;
	return 0;
}