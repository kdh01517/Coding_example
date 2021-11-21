#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unistd.h>
#include <cstring>
using namespace std;
int n, m; // 가로 세로
char map[51][51];
int vis[51][51];
queue<pair<int, int> > q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;
int dis;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            memset(vis, false, sizeof(vis));
            if (vis[i][j] == 0 && map[i][j] == 'L')
            {
                q.push(make_pair(i, j));
                vis[i][j] = 1;
            }
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
                    if (map[nx][ny] == 'W')
                        continue;
                    if (vis[nx][ny])
                        continue;
                    q.push(make_pair(nx, ny));
                    vis[nx][ny] = vis[cur.first][cur.second] + 1;
                    if (dis < vis[nx][ny])
                        dis = vis[nx][ny];
                }
            }
            ans = max(ans, dis);
        }
    }
    cout << ans - 1 << '\n';
}