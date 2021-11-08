#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
char map[101][101];
char map2[101][101];
int n;
int rgb; // 정상
int rg;  // 색약
int vis[101][101];
int vis2[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            map2[i][j] = map[i][j];
            if (map[i][j] == 'R')
                map2[i][j] = 'G';
        }
    }
    queue<pair<int, int> > q;
    queue<pair<int, int> > q2;
    
    int index = 0;
    int index2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0)
            {
                index++;
                q.push(make_pair(i, j));
                vis[i][j] = index;
            }
            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (vis[nx][ny] != 0)
                        continue;
                    if (map[nx][ny] == map[cur.first][cur.second])
                    {
                        vis[nx][ny] = index;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            if (vis2[i][j] == 0)
            {
                index2++;
                q2.push(make_pair(i, j));
                vis2[i][j] = index2;
            }
            while (!q2.empty())
            {
                pair<int, int> cur = q2.front();
                q2.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (vis2[nx][ny] != 0)
                        continue;
                    if (map2[nx][ny] == map2[cur.first][cur.second])
                    {
                        vis2[nx][ny] = index2;
                        q2.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rgb < vis[i][j])
                rgb = vis[i][j];
            if (rg < vis2[i][j])
                rg = vis2[i][j];
        }
    }
    cout << rgb << ' ' << rg << '\n';
    return 0;
}