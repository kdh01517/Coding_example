#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int n;
int board[101][101];
int vis[101];
int o, p, q;
int ans;
#define X first
#define Y second

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> n;
    cin >> o >> p >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        board[x][y] = 1;
        board[y][x] = 1;
    }
    queue<pair<int, int> > Q;
    Q.push(make_pair(o, 0));
    vis[o] = 1;
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        if (cur.X == p)
        {
            cout << cur.Y << '\n';
            return (0);
        }
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i] && board[cur.X][i])
            {
                vis[i] = 1;
                Q.push(make_pair(i, cur.Y + 1));
            }
        }
    }
    cout << -1 << '\n';
}