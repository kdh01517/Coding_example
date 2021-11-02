#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define INF 2147483647
using namespace std;

int map[11][11];
int group_island[11][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > ad[11]; // ad[i]: i 노드가 출발지인 간선들, first 비용 second 목적지
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > dist;
// priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > dist; // dist 선택될 가능성이 있는 간선들
bool selected[11]; //selected[i]: i가 이전에 선택된 노드인가?
int m, n;

void add_edge(int node)
{
    for (auto edge : ad[node])
        dist.push(edge);
}

void getMinDist(int u, int v)
{
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (group_island[i][j] == u)
                q.push(make_pair(i, j));
        }
    int mindist = 10;
    int x, y;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            int dist = 0;
            while (true)
            {
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    break;
                if (group_island[nx][ny] == u)
                    break;
                if (group_island[nx][ny] == v)
                {
                    if (dist > 1 && mindist > dist)
                        mindist = dist;
                    break;
                }
                else if (group_island[nx][ny] == 0)
                {
                    dist++;
                    nx += dx[dir];
                    ny += dy[dir];
                }
                else
                    break;
            }
        }
    }
    if (mindist != 10)
    {
        ad[u].push_back(make_pair(mindist, v));
        ad[v].push_back(make_pair(mindist, u));
    }
}

void BFS(int x, int y, int num)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    group_island[x][y] = num;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (map[nx][ny] == 0)
                continue;
            if (group_island[nx][ny] != 0)
                continue;
            group_island[nx][ny] = num;
            q.push(make_pair(nx, ny));
        }
    }
}

int prim(int pn)
{
    int ret = 0;
    int mindist = 0;
    for (int i = 1; i <= pn; i++)
        selected[i] = false;
    dist.push(make_pair(0, 1));
    for (int i = 1; i <= pn; i++)
	{
		int now;
		int min_dist = INF;
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
		if (min_dist == INF)
			return INF;
		ret += min_dist;
		selected[now] = true;
		add_edge(now);
	}
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    int num = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
                continue;
            if (group_island[i][j] != 0)
                continue;
            BFS(i, j, ++num);
        }
    for (int i = 1; i <= num - 1; i++)
        for (int j = i + 1; j <= num; j++)
            getMinDist(i, j);
    int tmp = prim(num);
    if (tmp == INF)
        cout << -1  << '\n';
    else
        cout << tmp << '\n';
    return 0;
}


// 4 4 
// 4 3 
// 2 4 