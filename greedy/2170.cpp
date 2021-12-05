#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a, b;
long long ans;
int start, last;
vector <pair<int, int> > v;

bool cmp(pair<int,int> a, pair<int, int> b)
{
	if (a.first < b.first)
		return 1;
	else if (a.first == b.first)
		if (a.second < b.second)
			return 1;
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end(), cmp);
	start = v[0].first;
	last = v[0].second;
	for (int i = 1; i <= n; i++)
	{
		if (i != n && last >= v[i].first && last <= v[i].second)
		{
			last = v[i].second;
		}
		else if (last <= v[i].first || i == n)
		{
			if (start < 0)
			{
				start *= -1;
				ans += last + start;
			}
			else
			{
				ans += last - start;
			}
		}
		if (last <= v[i].first)
		{
			start = v[i].first;
			last = v[i].second;
		}
	}
	cout << ans << '\n';
}