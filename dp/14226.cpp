#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int s;
int vis[1001][1001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    memset(vis, -1, sizeof(vis));
    queue<pair<int, int> > q;
    q.push({1, 0});
    vis[1][0] = 0;
    
    while (!q.empty())
    {
        int dis = q.front().first;
        int clip = q.front().second;
        q.pop();
        if (dis == s)
        {
            cout << vis[dis][clip];
            break;
        }
        if (vis[dis][dis] == -1)
        {
            vis[dis][dis] = vis[dis][clip] + 1;
            q.push({dis,dis});
        }
        if (dis + clip < 1001 && vis[dis + clip][clip] == -1)
        {
            vis[dis + clip][clip] = vis[dis][clip] + 1;
            q.push({dis+clip, clip});
        }
        if (dis > 0 && vis[dis-1][clip] == -1)
        {
            vis[dis-1][clip] = vis[dis][clip] + 1;
            q.push({dis-1, clip});
        } 
    }
}