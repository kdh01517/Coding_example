#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int a, b;
int ans = 1;
int last_first;
int last_second;
struct cmp
{
	bool operator()(pair<int, int>a, pair<int,int> b)
	{
		if (a.first > b.first)
			return 1;
		else if (a.first == b.first)
			if (a.second > b.second)
				return 1;
		return 0;
	}
};
priority_queue <int, vector<int>, greater<int> > room;
priority_queue<pair<int, int>, vector<pair <int, int> >, cmp> q;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		q.push({a, b});
	}
	
	for (int i = 0; q.size() != 0; i++)
	{
		if (room.empty())
			room.push(q.top().second);
		q.pop();
		if (!q.empty())
		{
			last_first = q.top().first;
			last_second = q.top().second;
		}
		else
		{
			cout << ans << '\n';
			return 0;
		}
		if (room.top() <= last_first && room.top() <= last_second)
		{
			ans++;
			room.pop();
		}
		else
			if (room.top() > last_second)
				room.pop();
	}
	return 0;
}