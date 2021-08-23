//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define X first;
#define Y second;
int n, m, v;
int o, p;
int board[1002][1002];
int board2[1002][1002];
int vis[1002];
int vis2[1002];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v;
    fill(&board[0][0], &board[1001][1001], 0);
    fill(&board2[0][0], &board2[1001][1001], 0);
    fill(&vis[0], &vis[1001], 0);
    fill(&vis2[0], &vis2[1001], 0);
    for(int i = 0; i < m; i++)
    {
        cin >> o >> p;
        board[o][p] = 1;
        board[p][o] = 1;
        board2[o][p] = 1;
        board2[p][o] = 1;
    }
    //vis[v] = 1;
    vis2[v] = 1;
    queue<int> Q;
    Q.push(v);
    stack<int> S;
    S.push(v);
    while(!S.empty())
    {
        int cur = S.top(); S.pop();
        if (vis[cur]) continue;
		vis[cur] = 1;
        cout << cur << " ";
        for(int dir = n; dir >= 1; dir--)
        {
            if (vis[dir] || board[cur][dir] != 1) continue;
            S.push(dir);
        }
    }
    cout << '\n';
    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        cout << cur << " ";
        for(int dir = 1; dir <= n; dir++)
        {
            if (vis2[dir] || board2[cur][dir] != 1) continue;
            vis2[dir] = 1;
            Q.push(dir);
        }
    }
}