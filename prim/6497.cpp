#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits>
#define PII pair<long long, long long>
using namespace std;

const int N = 200005;
vector<PII> ad[N];									 // ad[i]: i 노드가 출발지인 간선들, first 비용 second 목적지
priority_queue<PII, vector<PII>, greater<PII>> dist; // dist: 선택될 가능성이 있는 간선들
bool selected[N];									 //selected[i]: i가 이전에 선택된 노드인가?
int m, n;
long long x, y, z;

void add_edge(int node)
{
	for (auto edge : ad[node])
		dist.push(edge);
}

long long prim(int pn)
{
	long long ret = 0;
	long long min_dist = 0;
	for (int i = 1; i <= pn; i++)
		selected[i] = false;
	dist.push(PII(0, 1));
	for (int i = 1; i <= pn; i++)
	{
		int now = -1;
		while (!dist.empty())
		{
			now = dist.top().second;
			if (!selected[now])
			{
				min_dist = dist.top().first;
				break;
			}
			dist.pop();
		}
		ret += min_dist;
		selected[now] = true;
		add_edge(now);
	}
	return ret;
}

int main()
{
	while (1)
	{
		long long total = 0;
		for (int i = 0; i < N; i++)
		{
			while (!ad[i].empty())
				ad[i].pop_back();
		}
		while (!dist.empty())
			dist.pop();
		
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		while (n--)
		{	
			cin >> x >> y >> z;
			ad[x + 1].push_back(PII(z, y + 1));
			ad[y + 1].push_back(PII(z, x + 1));
			total += z;
		}
		cout << total - prim(m) << "\n";
	}
	return 0;
}