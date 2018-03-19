#include<iostream>
#include<algorithm>

using namespace std;

int comp(const int &a, const int &b)
{
	if (a > b)
		return 1;
	return 0;
}

int arr1[60], arr2[60];

int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr1[i];
	for (i = 0; i < n; i++)
		cin >> arr2[i];
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n, comp);
	int sum = 0;
	for (i = 0; i < n; i++)
		sum += (arr1[i] * arr2[i]);
	cout << sum;
	return 0;
}