#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int t, T, i, n;
	int sx, sy, ex, ey;
	cin >> T;
	for (t = 0; t < T; t++)
	{
		int cnt = 0;
		cin >> sx >> sy >> ex >> ey;
		cin >> n;
		for (i = 0; i < n; i++)
		{
			int x, y, r;
			cin >> x >> y >> r;
			double dis1 = sqrt((sx - x) * (sx - x) + (sy - y) * (sy - y));
			double dis2 = sqrt((ex - x) * (ex - x) + (ey - y) * (ey - y));
			if (dis1 < r && dis2 < r)
				continue;
			if (dis1 < r)
				cnt++;
			if (dis2 < r)
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
/*
1
-2 0 2 0
2
-2 0 1
2 0 1

1
-2 0 2 0
1
0 0 3

1
-2 0 2 0
2
-2 0 1
-2 0 2
*/