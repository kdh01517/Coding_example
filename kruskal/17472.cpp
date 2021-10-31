#include <queue>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int map[11][11];
int group_island[11][11];
int p[7];
vector<pair<int, pair<int, int> > > vt;

int findParent(int a)
{
    if (p[a] == a) return a;
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

void getMinDist(int u, int v)
{
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (group_island[i][j] == u)
                q.push(make_pair(i, j));

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
        vt.push_back(make_pair(mindist, make_pair(u, v)));
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
            q.push(make_pair(nx, ny));
            group_island[nx][ny] = num;
        }
    }
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
    
    int size = vt.size();
    sort(vt.begin(), vt.end());

    for (int i = 1; i <= num; i++)
        p[i] = i;
    
    int sum = 0;
    int cnt = 0;
    int index = 0;

    int u, v, dist;
    while (cnt < num -1)
    {
        if (index == size)
        {
            cout << -1 << '\n';
            return 0;
        }
        dist = vt[index].first;
        u = vt[index].second.first;
        v = vt[index].second.second;

        index++;
        if (findParent(u) == findParent(v))
            continue;
        else
        {
            unionParent(u, v);
            cnt++;
            sum += dist;
        }
    }
    cout << sum << '\n';
    return 0;
}