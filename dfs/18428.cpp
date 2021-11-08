#include <iostream>
#include <string>
#include <queue>
#include <utility>
#define fastio cin.tie(0)->sync_with_stdio(0);
using namespace std;
char map[7][7];
int n;
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > v;
int check()
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = v[i].first;
            int ny = v[i].second;
            for (int j = 0; j < n; j++)
            {
                nx += dx[dir];
                ny += dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    break;
                if (map[nx][ny] == 'O' || map[nx][ny] == 'T')
                    break;
                if (map[nx][ny] == 'S')
                    return ans;
            }
        }
    }
    ans = 1;
    return ans;
}

void DFS(int cnt)
{
    if (ans == 1)
        return;
    if (cnt == 3)
    {
        if (ans == 0)
            check();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 'X')
            {
                map[i][j] = 'O';
                DFS(cnt + 1);
                map[i][j] = 'X';
            }
        }
    }
}

int main(void)
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'T')
                v.push_back(make_pair(i, j));
        }
    }
    DFS(0);
    if (ans == 1)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}