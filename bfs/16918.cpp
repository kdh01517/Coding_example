#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char map[201][201];
int vis[201][201];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int R, C, N;
int ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> N;
    queue<pair<int, int> > q;
    int dis = 1;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'O')
            {
                q.push(make_pair(i, j));
                vis[i][j] = dis;
            }
        }
    dis++;
    while (1)
    {
        if (dis > N)
        {
            break;
        }
        dis++;
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                    continue;
                if (map[nx][ny] == 'O')
                    continue;
                vis[nx][ny] = dis;
                map[nx][ny] = 'O';
                q.push(make_pair(nx, ny));
            }
        }
        if (dis > N)
        {
            break;
        }
        dis++;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (vis[i][j] == dis - 3 && map[i][j] == 'O')
                {
                    q.push(make_pair(i, j));
                    vis[i][j] = dis;
                    map[i][j] = '.';
                }
            }
        }
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                    continue;
                if (map[nx][ny] == '.')
                    continue;
                vis[nx][ny] = dis;
                map[nx][ny] = '.';
            }
        }
        if (dis > N)
        {
            break;
        }
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (map[i][j] == '.')
                {
                    q.push(make_pair(i, j));
                    vis[i][j] = dis;
                }
            }
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }
}