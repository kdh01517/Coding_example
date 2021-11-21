#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int K;
int W, H;
int board[201][201];
int vis[201][201][31];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct Info
{
    int x, y, cnt;
};
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(vis, -1, sizeof(vis));
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> board[i][j];
    if (board[0][0] == 1)
    {
        cout << -1 << '\n';
        return 0;
    }
    queue<Info> q;
    q.push({0, 0, 0});
    vis[0][0][0] = 0;
    while (!q.empty())
    {
        auto [x, y, cnt] = q.front();
        q.pop();
        if (x == H - 1 && y == W - 1)
        {
            cout << vis[x][y][cnt] << '\n';
            return 0;
        }
        if (cnt < K)
        {
            // 1
            if (board[x - 2][y + 1] != 1 && x - 2 >= 0 && x - 2 < H && y + 1 >= 0 && y + 1 < W)
            {
                if (vis[x - 2][y + 1][cnt + 1] == -1)
                {
                    vis[x - 2][y + 1][cnt + 1] = vis[x][y][cnt] + 1;
                    q.push({x - 2, y + 1, cnt + 1});
                }
            }
            // 2
            if (board[x - 1][y + 2] != 1 && x - 1 >= 0 && x - 1 < H && y + 2 >= 0 && y + 2 < W)
            {
                if (vis[x - 1][y + 2][cnt + 1] == -1)
                {
                    vis[x - 1][y + 2][cnt + 1] = vis[x][y][cnt] + 1;
                    q.push({x - 1, y + 2, cnt + 1});
                }
            }
            // 3
            if (board[x + 1][y + 2] != 1 && x + 1 >= 0 && x + 1 < H && y + 2 >= 0 && y + 2 < W)
            {
                if (vis[x + 1][y + 2][cnt + 1] == -1)
                {
                    vis[x + 1][y + 2][cnt + 1] = vis[x][y][cnt] + 1;
                    q.push({x + 1, y + 2, cnt + 1});
                }
            }
            // 4
            if (board[x + 2][y + 1] != 1 && x + 2 >= 0 && x + 2 < H && y + 1 >= 0 && y + 1 < W)
            {
                if (vis[x + 2][y + 1][cnt + 1] == -1)
                {
                    vis[x + 2][y + 1][cnt + 1] = vis[x][y][cnt] + 1;
                    q.push({x + 2, y + 1, cnt + 1});
                }
            }
            // 5
            if (board[x - 2][y - 1] != 1 && x - 2 >= 0 && x - 2 < H && y - 1 >= 0 && y - 1 < W)
            {
                if (vis[x - 2][y - 1][cnt + 1] == -1)
                {
                    vis[x - 2][y - 1][cnt + 1] = vis[x][y][cnt] + 1;
                    q.push({x - 2, y - 1, cnt + 1});
                }
            }
            // 6
            if (board[x - 1][y - 2] != 1 && x - 1 >= 0 && x - 1 < H && y - 2 >= 0 && y - 2 < W)
            {
                if (vis[x - 1][y - 2][cnt + 1] == -1)
                {
                    vis[x - 1][y - 2][cnt + 1] = vis[x][y][cnt] + 1;
                    q.push({x - 1, y - 2, cnt + 1});
                }
            }
            // 7
            if (board[x + 1][y - 2] != 1 && x + 1 >= 0 && x + 1 < H && y - 2 >= 0 && y - 2 < W)
            {
                if (vis[x + 1][y - 2][cnt + 1] == -1)
                {
                    vis[x + 1][y - 2][cnt + 1] = vis[x][y][cnt] + 1;
                    q.push({x + 1, y - 2, cnt + 1});
                }
            }
            // 8
            if (board[x + 2][y - 1] != 1 && x + 2 >= 0 && x + 2 < H && y - 1 >= 0 && y - 1 < W)
            {
                if (vis[x + 2][y - 1][cnt + 1] == -1)
                {
                    vis[x + 2][y - 1][cnt + 1] = vis[x][y][cnt] + 1;
                    q.push({x + 2, y - 1, cnt + 1});
                }
            }
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (board[nx][ny])
                continue;
            if (vis[nx][ny][cnt] != -1)
                continue;
            vis[nx][ny][cnt] = vis[x][y][cnt] + 1;
            q.push({nx, ny, cnt});
        }
    }
    cout << -1 << '\n';
    return 0;
}