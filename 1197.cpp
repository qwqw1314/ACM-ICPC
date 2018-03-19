#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct dataset
{
	int from;
	int to;
	int dis;
	bool operator<(const dataset &other);
};

bool dataset::operator < (const dataset &other)
{
	if (this->dis < other.dis)
		return true;
	return false;
}

int v, e;

priority_queue<dataset, vector<dataset>> pq;

int main()
{
	int n, i;
	dataset temp;
	cin >> v >> e;
	for (i = 0; i < e; i++)
	{
		cin >> temp.from >> temp.to >> temp.dis;
		pq.push(temp);
	}
	cout << pq.top().from << " " << pq.top().to << " " << pq.top().dis << endl;
	return 0;
}