#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int test_case;
vector <int> adj[510];
bool check[510];
int inDegree[510];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> test_case;
	while (test_case--)
	{
		fill(check, check+510, 0);
		fill(inDegree, inDegree+510, 0);
		for (int i = 0; i < 510; i++)
			adj[i].clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int ranking;
			cin >> ranking;
			check[ranking] = 1;
			for (int j = 1; j <= n; j++)
			{
				if (check[j] == false)
				{
					adj[ranking].push_back(j);
					inDegree[j]++;
				}
			}
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			vector <int>::iterator it = find(adj[b].begin(), adj[b].end(), a);
			if (it != adj[b].end())
			{
				adj[b].erase(it);
				inDegree[a]--;
				adj[a].push_back(b);
				inDegree[b]++;
			}
			else
			{
				it = find(adj[a].begin(), adj[a].end(), b);
				adj[a].erase(it);
				inDegree[b]--;
				adj[b].push_back(a);
				inDegree[a]++;
			}
		}
		vector <int> rs;
		queue <int> q;
		for (int i = 1; i <= n; i++)
			if (inDegree[i] == 0)
				q.push(i);
		bool sw = false;
		while (!q.empty())
		{
			if (q.size() > 1)
			{
				sw = true;
				break;
			}
			int eq = q.front();
			q.pop();
			rs.push_back(eq);
			for (int x : adj[eq])
			{
				inDegree[x]--;
				if (inDegree[x] == 0)
					q.push(x);
			}
		}
		if (sw == true)
			cout << '?' << '\n';
		else if (rs.size() != n)
			cout << "IMPOSSIBLE" << '\n';
		else
		{
			for (int x : rs)
				cout << x << ' ';
			cout << '\n';
		}
	}
	return 0;
}