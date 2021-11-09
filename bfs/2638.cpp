#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int map[102][102];
int n, m;
int time;
int vis2[102][102];
int map2[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void BFS()
{
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            fill(vis2[i], vis2[i] + m, 0);
            fill(map2[i], map2[i] + m, 0);
        }
        queue<pair<int, int>> q2;
        q2.push(make_pair(0, 0));
        vis2[0][0] = 1;
        while (!q2.empty())
        {
            pair<int, int> cur = q2.front();
            q2.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (vis2[nx][ny])
                    continue;
                if (map[nx][ny] == 0)
                {
                    vis2[nx][ny] = 1;
                    q2.push(make_pair(nx, ny));
                }
                else
                    map2[nx][ny]++;
            }
        }
        // 치즈 공간 계산
        int flag = 1;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (map2[x][y] >= 2)
                {
                    map[x][y] = 0;
                    flag = 0;
                }
            }
        }
        if (flag)
            return;
        time++;
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
    BFS();
    cout << time << '\n';
}