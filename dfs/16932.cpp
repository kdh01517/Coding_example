#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <set>
using namespace std;
int map2[1001][1001];
int dfs[1001][1001];
int vis[1001][1001];
int N, M;
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector <pair<int, int> > v;
map <int, int> m;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map2[i][j];
	queue <pair<int, int> > q;
	
	int cnt = 0;
	int color = 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map2[i][j] == 1)
			{
				cnt = 0;
				q.push(make_pair(i, j));
				map2[i][j] = color;
				dfs[i][j] = 1;
				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();
					cnt++;
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M)
							continue;
						if (map2[nx][ny] != 1)
							continue;
						if (dfs[nx][ny])
							continue;
						dfs[nx][ny] = 1;
						map2[nx][ny] = color;
						q.push(make_pair(nx,ny));
					}
				}
				m.insert(make_pair(color, cnt));
				color++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map2[i][j] == 0)
			{
				int sum = 1;
				set <int> s;
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M)
						continue;
					
					s.insert(map2[nx][ny]);
				}
				for (auto k : s)
				{
					sum += m[k];
				}
				ans = max(sum, ans);
			}
		}
	}
	cout << ans << '\n';
}