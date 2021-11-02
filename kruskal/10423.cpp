#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int n, m, electric;
int electric_num[1001];
vector <pair<int, pair<int, int> > > v;
int p[1001];
int ans;
int u, t, w;
int findParent(int a)
{
	if (p[a] == a)
		return a;
	return p[a] = findParent(p[a]);
}

void unionParent(int a, int b)
{
	int start = findParent(a);
	int end = findParent(b);
	if (start < end)
		p[end] = start;
	else
		p[start] = end;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> electric;

	for (int i = 0; i < electric; i++)
		cin >> electric_num[i];
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < electric - 1; i++)
		unionParent(electric_num[i], electric_num[i+1]);
	for (int i = 0; i < m; i++)
	{
		cin >> u >> t >> w;
		v.push_back(make_pair(w, make_pair(u, t)));
	}
	sort(v.begin(), v.end());
	int index = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int start = v[i].second.first;
		int end = v[i].second.second;
		int weight = v[i].first;
		if (findParent(start) != findParent(end))
		{
			ans += weight;
			unionParent(start, end);
			if (++index == n-electric)
				break;
		}
	}
	cout << ans;
}