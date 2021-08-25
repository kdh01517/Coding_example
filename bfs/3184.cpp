#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define X first;
#define Y second;
int r,c;
string board[251];
int vis[251][251]; // 늑대
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int sheep_max;
int wolf_max;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;

    for(int i=0; i<r; i++)
        cin >> board[i];
    queue<pair<int,int> > Q1;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            int wolf=0;
            int sheep=0;
            if(!vis[i][j] && board[i][j] == '#')
            {
                vis[i][j] = 1;
                Q1.push(make_pair(i,j));
            }
            while(!Q1.empty())
            {
                pair<int,int> cur = Q1.front(); Q1.pop();
                if (board[cur.first][cur.second] == 'v') wolf += 1;
                for(int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if(!vis[nx][ny] && board[nx][ny] == 'o')
                    {
                        vis[nx][ny] = 1;
                        Q1.push(make_pair(nx,ny));
                        sheep += 1;
                    } 
                    if(vis[nx][ny] || board[nx][ny] == '#') continue;
                    vis[nx][ny] = 1;
                    Q1.push(make_pair(nx,ny));
                }
            }
            if (sheep <= wolf)
                wolf_max += wolf;
            else
                sheep_max += sheep;
        }
    }
    cout << sheep_max << ' ' << wolf_max << '\n';
}