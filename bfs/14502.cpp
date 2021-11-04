#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;
int map[10][10];
int map2[10][10];
int vis[10][10];
int vis2[10][10];
int n, m;
int ans, max_ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> bq;

void BFS(int &zero)
{
    int afterMap[10][10];
    memcpy(afterMap, map2, sizeof(map2));
    int zC = zero;
    queue<pair<int, int>> q = bq;

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
            if (afterMap[nx][ny] == 0)
            {
                afterMap[nx][ny] = 2;
                --zC;
                q.push(make_pair(nx,ny));
            }
        }
    }
    ans = max(ans, zC);
}

void DFS(int cnt, int &zero)
{
    if (cnt == 3)
    {
        BFS(zero);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map2[i][j] == 0)
            {
                map2[i][j] = 1;
                --zero;
                DFS(cnt + 1, zero);
                map2[i][j] = 0;
                ++zero;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    max_ans = n* m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 0)
            {
                --max_ans;
                if (map[i][j] == 2)
                    bq.push(make_pair(i, j));
            }
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == 0)
            {
                memcpy(map2, map, sizeof(map));
                map2[i][j] = 1;
                --max_ans;
                DFS(1, max_ans);
                map2[i][j] = 0;
                ++max_ans;
            }
    cout << ans << '\n';
    return 0;
}