#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct abc
{
	int from;
	int to;
	int distance;
};

int v, e;
int dis[20010];


struct compare
{
	bool operator () (const abc &a, const abc &b)
	{
		if (a.distance > b.distance)
			return true;
		return false;
	}
};

priority_queue < abc, vector<abc>, compare> pq;

int main()
{
	abc temp;
	int start, i;
	cin >> v >> e;
	cin >> start;
	for (i = 0; i < e; i++)
	{
		cin >> temp.from >> temp.to >> temp.distance;
		pq.push(temp);
	}
	cout << endl;
	for (i = 0; i < e; i++)
	{
		temp = pq.top();
		pq.pop();
		cout << temp.from << " " << temp.to << " " << temp.distance << endl;
	}
	return 0;
}