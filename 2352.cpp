#include<iostream>

using namespace std;

int arr[40010], n;
int dy[40010];

int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> arr[i];
	int cnt = 1;
	dy[1] = arr[1];
	for (i = 2; i <= n; i++)
	{
		if (arr[i] < dy[cnt])
		{
			for (j = cnt; j >= 0 && dy[j - 1] > arr[i]; j--);
			dy[j] = arr[i];
			continue;
		}
		dy[++cnt] = arr[i];
	}
	cout << cnt;
	return 0;
}
/*
아이디어는 기본적으로 binary_serach를 통한 제일 적절한 위치
현재 탐색중인곳의 MAX값보다는 크면서 차이가 제일 적은 곳 찾기
*/
/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[40010], dy[40010], index[40010], minx = 0x7fffffff, cnt;
vector<int> v[40010];

int absx(int x)
{
	if (x < 0)
		return -x;
	return x;
}


int main()
{
	int i, j, n;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (i = 1; i <= n; i++)
	{
		if (cnt == 0)
		{
			v[0].push_back(arr[i]);
			index[0] = arr[i];
			cnt++;
		}
		else
		{
			 lower_bound(index, index + cnt, arr[i]);
		}
	}
	return 0;
}
*/