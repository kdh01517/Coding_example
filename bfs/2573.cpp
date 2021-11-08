#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int map[302][302];
int vis[302][302];
int ans;
int chk;
queue<pair<int, int>> q;
int ice_count()
{
    int ice[302][302] = {0};
    queue<pair<int, int>> iq;
    int cnt = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int flag = 0;
            if (map[i][j] != 0 && ice[i][j] == 0)
            {
                iq.push(make_pair(i, j));
                ice[i][j] = cnt;
            }
            else
                continue;
            while (!iq.empty())
            {
                pair<int, int> cur2 = iq.front();
                iq.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur2.first + dx[dir];
                    int ny = cur2.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (map[nx][ny] == 0)
                        continue;
                    if (ice[nx][ny])
                        continue;
                    ice[nx][ny] = cnt;
                    iq.push(make_pair(nx, ny));
                }
                flag = 1;
            }
            if (flag == 1)
                cnt++;
        }
    }
    if (cnt == 1)
        chk = 1;
    return cnt;
}

void BFS()
{
    while (true)
    {
        if (ice_count() >= 3)
        {
            ans++;
            return;
        }
        else
            ans++;
        if (chk == 1)
            return;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 0) continue;
                int temp = 0;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (map[nx][ny] == 0)
                        temp++;
                }
                vis[i][j] = temp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                map[i][j] = max(map[i][j] - vis[i][j], 0);
            }
        }
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    BFS();
    if (chk == 1)
        cout << 0 << '\n';
    else
        cout << ans - 1 << '\n';
}