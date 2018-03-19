#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct abc
{
	int x, y;
};

int comp1(const abc &A, const abc &B)
{
	if (A.x < B.x)
		return 1;
	return 0;
}

int comp2(const abc &A, const abc &B)
{
	if (A.y < B.y)
		return 1;
	return 0;
}

vector<abc> v;
abc a;

int main()
{
	int i, n, cnt = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a.x >> a.y;
		v.push_back(a);
	}
	vector<abc>::iterator iter;
	sort(v.begin(), v.end(), comp1);
	for (iter = v.begin(); (iter+1) != v.end(); iter++)
	{
		if ((*iter).x == (*(iter + 1)).x)
			cnt++;
	}
	sort(v.begin(), v.end(), comp2);
	for (iter = v.begin(); (iter + 1) != v.end(); iter++)
	{
		if ((*iter).y == (*(iter + 1)).y)
			cnt++;
	}
	cout << cnt;
	return 0;
}