#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t;
int n;
int a, b;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first < b.first)
		return 1;
	return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> t;
	while (t--)
	{
		int ans = 0;
		cin >> n;
		vector <pair<int, int> > v;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			v.push_back({a, b});
		}
		sort(v.begin(), v.end(), cmp);
		int tmp = 1000000;
		for (int i = 0; i < n; i++)
		{
			if (tmp > v[i].second)
			{
				tmp = v[i].second;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}