#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int map[102][102];
int vis[102][102];
int m, n, k;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector <int> v;

void cr_map(int a, int b, int c, int d)
{
    for (int i = b; i < d; i++)
        for (int j = a; j < a + c - a; j++)
        {
            map[i][j] = 1;
            vis[i][j] = 1;
        }
}

void BFS(int x, int y, int ind)
{
    int cnt = 1;
    queue <pair<int, int> > q;
    q.push(make_pair(x, y));
    while(!q.empty())
    {
        pair <int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny] || map[nx][ny] != 0)
                continue;
            vis[nx][ny] = 1;
            map[nx][ny] = ind;
            q.push(make_pair(nx, ny));
            cnt++;
        }
    }
    v.push_back(cnt);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k;
    int a, b, c, d;
    int ind = 2;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b >> c >> d;
        cr_map(a, b, c, d);
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 0 && vis[i][j] == 0)
            {
                map[i][j] = ind;
                vis[i][j] = 1;
                BFS(i,j, ind);
                ind++;
            }
        }
    int ans = ind -2;
    cout << ans << "\n";
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
}