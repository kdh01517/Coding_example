#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

long long map[1001][1001];
int p[10001];
int n;
long long ans;
vector <pair<int, pair<int, int> > > v;

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
		p[start] = end;
	else
		p[end] = start;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++)
		p[i] = i;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			v.push_back(make_pair(map[i][j], make_pair(i, j)));
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
			if (++index == n-1)
				break;
		}
	}
	cout << ans << '\n';
	return 0;
}