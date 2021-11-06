#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int r, c;
string map[22];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int alpa[27];
int ans = 1;

void DFS(int x, int y, int dis)
{
    ans = max(ans, dis);
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            continue;
        if (alpa[map[nx][ny] - 65])
            continue;
        alpa[map[nx][ny] - 65] = 1;
        DFS(nx, ny, dis + 1);
        alpa[map[nx][ny] - 65] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> map[i];
    alpa[map[0][0] - 65] = 1;
    DFS(0, 0, 1);
    cout << ans << '\n';
}